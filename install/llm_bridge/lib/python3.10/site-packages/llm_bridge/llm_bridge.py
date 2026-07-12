import os
import json

import rclpy
from rclpy.node import Node

from mission_interfaces.msg import Mission

from google import genai


class LLMBridge(Node):

    def __init__(self):
        super().__init__("llm_bridge")

        api_key = os.getenv("GEMINI_API_KEY")
        self.get_logger().info(f"GEMINI key found: {api_key is not None}")

        self.client = genai.Client(api_key=api_key)

        self.publisher = self.create_publisher(
            Mission,
            "/mission",
            10,
        )

        self.get_logger().info("LLM Bridge Started")

        while rclpy.ok():

            prompt = input("\nEnter command: ")

            try:

                response = self.client.models.generate_content(
                    model="gemini-2.5-flash",
                    contents=f"""
You are a robot command parser.

Convert the user's instruction into ONLY valid JSON.

Return ONLY JSON.

Format:

{{
    "command":"MOVE",
    "target":"forward",
    "distance":2.0,
    "angle":0.0
}}

Rules:

1. command must always be one of :
MOVE 
TURN 
INSPECT

2. target must ALWAYS be a string.

Allowed targets:
forward
backward
left
right
inspect

Never output null.
Never output None.
Never leave target empty.

Examples:

Move forward 5 meters

{{
"command":"MOVE",
"target":"forward",
"distance":5.0,
"angle":0.0
}}

Move backward 2 meters

{{
"command":"MOVE",
"target":"backward",
"distance":2.0,
"angle":0.0
}}

Turn left 90 degrees

{{
"command":"TURN",
"target":"left",
"distance":0.0,
"angle":90.0
}}

Turn right 90 degrees

{{
"command":"TURN",
"target":"right",
"distance":0.0,
"angle":-90.0
}}

Rotate clockwise 45 degrees

{{
"command":"TURN",
"target":"right",
"distance":0.0,
"angle":-45.0
}}

Rotate anticlockwise 45 degrees

{{
"command":"TURN",
"target":"left",
"distance":0.0,
"angle":45.0
}}

Inspect the bookstore

{{
"command":"INSPECT",
"target":"BOOKSTORE",
"distance":0.0,
"angle":0.0
}}
 
Inspect the office

{{
"command":"INSPECT",
"target":"OFFICE",
"distance":0.0,
"angle":0.0
}}

Return ONLY JSON.

Instruction:
{prompt}
""",
                )
                text = response.text.strip()
                text = text.replace("```json", "")
                text = text.replace("```", "")
                text = text.strip()

                self.get_logger().info(f"Gemini:\n{text}")

                data = json.loads(text)

                msg = Mission()
                msg.command = data["command"]
                msg.target = str(data.get("target", "forward"))
                msg.distance = float(data["distance"])
                msg.angle = float(data["angle"])

                self.publisher.publish(msg)

                self.get_logger().info(f"Published: {msg}")
                
            except Exception as e:
                self.get_logger().error(str(e))


def main(args=None):
    rclpy.init(args=args)

    node = LLMBridge()

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
