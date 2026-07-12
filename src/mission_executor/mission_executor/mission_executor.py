import math
import time

import rclpy
from rclpy.node import Node

from mission_interfaces.msg import Mission
from geometry_msgs.msg import Twist


class MissionExecutor(Node):

    LINEAR_SPEED = 0.2
    ANGULAR_SPEED = 0.5

    def __init__(self):
        super().__init__("mission_executor")

        self.subscription = self.create_subscription(
            Mission,
            "/mission",
            self.callback,
            10,
        )

        self.cmd_vel_pub = self.create_publisher(
            Twist,
            "/cmd_vel",
            10,
        )

        self.get_logger().info("Mission Executor Started")

    def callback(self, msg):

        self.get_logger().info("========== MISSION ==========")
        self.get_logger().info(f"Command : {msg.command}")
        self.get_logger().info(f"Target  : {msg.target}")
        self.get_logger().info(f"Distance: {msg.distance}")
        self.get_logger().info(f"Angle   : {msg.angle}")

        if msg.command == "MOVE":

            duration = msg.distance / self.LINEAR_SPEED

            if msg.target == "forward":
                self.move_forward(duration)

            elif msg.target == "backward":
                self.move_backward(duration)

        elif msg.command == "TURN":

            duration = math.radians(abs(msg.angle)) / self.ANGULAR_SPEED

            if msg.target == "left":
                self.turn_left(duration)

            elif msg.target == "right":
                self.turn_right(duration)

        elif msg.command == "INSPECT":

            if msg.target.upper() == "BOOKSTORE":
                self.inspect_bookstore()

            elif msg.target.upper() == "OFFICE":
                self.inspect_office()    
          


    def stop_robot(self):

        twist = Twist()

        for _ in range(5):
            self.cmd_vel_pub.publish(twist)
            time.sleep(0.05)

    def move_forward(self, seconds):

        twist = Twist()
        twist.linear.x = self.LINEAR_SPEED

        start = time.time()

        while time.time() - start < seconds:
            self.cmd_vel_pub.publish(twist)
            time.sleep(0.02)

        self.stop_robot()
    
    def move_backward(self, seconds):

        twist = Twist()
        twist.linear.x = -self.LINEAR_SPEED

        start = time.time()

        while time.time() - start < seconds:
            self.cmd_vel_pub.publish(twist)
            time.sleep(0.02)

        self.stop_robot()

    def turn_left(self, seconds):

        twist = Twist()
        twist.angular.z = self.ANGULAR_SPEED

        start = time.time()

        while time.time() - start < seconds:
            self.cmd_vel_pub.publish(twist)
            time.sleep(0.02)

        self.stop_robot()

    def turn_right(self, seconds):

        twist = Twist()
        twist.angular.z = -self.ANGULAR_SPEED
    
        start = time.time()

        while time.time() - start < seconds:
            self.cmd_vel_pub.publish(twist)
            time.sleep(0.02)

        self.stop_robot()

    def inspect_bookstore(self):

        self.get_logger().info("===== BOOKSTORE INSPECTION =====")

        self.move_forward(3)
        self.get_logger().info("Shelf A inspected")

        self.turn_left(2)
        self.move_forward(2)
        self.get_logger().info("Shelf B inspected")

        self.turn_right(2)
        self.move_forward(2)
        self.get_logger().info("Shelf C inspected")

        self.get_logger().info("Returning to Charging Dock")

        self.turn_right(3)
        self.move_forward(4)

        self.get_logger().info("Bookstore Inspection Completed")
    def inspect_office(self):

        self.get_logger().info("===== OFFICE INSPECTION =====")

        self.move_forward(2)
        self.get_logger().info("Office A inspected")

        self.turn_right(2)
        self.move_forward(2)

        self.get_logger().info("Office Inspection Completed")

def main(args=None):

    rclpy.init(args=args)

    node = MissionExecutor()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
