# Omokai Robotics Assignment

## AI-Powered Natural Language Mission Execution using ROS2

This project demonstrates a Natural Language controlled autonomous robot built using **ROS2 Humble**, **Gazebo Classic**, and **Google Gemini API**.

The system converts human instructions into structured robot missions and executes them through a deterministic ROS2 controller.

---

# Project Overview

Instead of directly allowing an LLM to control the robot, the system follows a safe execution pipeline.

```
Natural Language
        │
        ▼
Google Gemini API
        │
        ▼
Validated JSON
        │
        ▼
ROS2 Mission.msg
        │
        ▼
Mission Executor
        │
        ▼
TurtleBot3 in Gazebo
```

The LLM is only responsible for understanding the user's instruction.

Actual robot motion is executed only by the deterministic Mission Executor.

---

# Features

- Natural language robot commands
- Gemini-powered command parsing
- JSON validation
- Custom ROS2 Mission message
- Deterministic robot execution
- TurtleBot3 simulation
- Custom Gazebo bookstore environment
- Multi-bookshelf inspection routine
- Automatic return to charging dock
- Modular ROS2 architecture

---

# Tech Stack

- Ubuntu 22.04
- ROS2 Humble
- Python
- Gazebo Classic
- TurtleBot3 Burger
- Google Gemini API
- Custom ROS2 Interfaces

---

# Project Structure

```
ros2_ws/
│
├── src/
│   ├── llm_bridge/
│   │      Converts natural language into Mission messages
│   │
│   ├── mission_executor/
│   │      Executes robot movements
│   │
│   └── mission_interfaces/
│          Custom Mission.msg
│
├── build/
├── install/
└── log/
```

---

# Mission Message

```
string command
string target
float32 distance
float32 angle
```

Supported Commands

- MOVE
- TURN
- INSPECT

---

# Supported Natural Language Commands

Examples

```
Move forward 2 meters

Move backward 1 meter

Turn left 90 degrees

Turn right 45 degrees

Inspect the bookstore

Inspect the office

Inspect all bookshelves and return to the charging dock.
```

---

# Inspection Workflow

The bookstore inspection mission performs the following sequence:

1. Navigate to Shelf A
2. Pause for inspection
3. Navigate to Shelf B
4. Pause for inspection
5. Navigate to Shelf C
6. Pause for inspection
7. Navigate to Shelf D
8. Pause for inspection
9. Return to charging dock

The robot follows a deterministic inspection path designed for the custom bookstore environment.

---

# Safety Design

The LLM **never** sends velocity commands directly.

Instead:

Natural Language

↓

Gemini

↓

Validated JSON

↓

Mission.msg

↓

Mission Executor

↓

Robot Motion

This prevents unpredictable robot behaviour and keeps execution deterministic.

---

# Custom Gazebo Environment

A custom bookstore environment was created in Gazebo Classic containing

- Bookshelves
- Walls
- Inspection route
- Charging dock location

The environment is designed for autonomous shelf inspection.

---

# How to Run

## Build

```bash
cd ~/omokai_task/ros2_ws

colcon build

source install/setup.bash
```

## Launch Gazebo

cd ~/omokai_task/ros2_ws

colcon build

source install/setup.bash

export TURTLEBOT3_MODEL=burger

ros2 launch turtlebot3_gazebo empty_world.launch.py
```

## Run Mission Executor

cd ~/omokai_task/ros2_ws

colcon build

source install/setup.bash

ros2 run mission_executor mission_executor
```

## Run LLM Bridge

cd ~/omokai_task/ros2_ws

colcon build

source install/setup.bash

export GEMINI_API_KEY=YOUR_API_KEY

ros2 run llm_bridge llm_bridge
```

---

# Demo Scenario

Operator Command

```
Inspect all bookshelves and return to the charging dock.
```

Execution Flow:

Operator

↓

Gemini

↓

Mission Message

↓

Mission Executor

↓

Shelf A

↓

Shelf B

↓

Shelf C

↓

Shelf D

↓

Charging Dock
```

---

# Future Improvements

- ROS2 Navigation2 integration
- SLAM-based autonomous navigation
- Real-time obstacle avoidance
- Camera-based bookshelf inspection
- QR code recognition
- Multi-room autonomous inspection
- Voice command interface

---

# Author

**Achal Metkari**

Final Year Engineering Student

Robotics & Automation

Savitribai Phule Pune University

---

# License

This project was developed as part of the OmokAI Robotics Assignment for educational purposes.
