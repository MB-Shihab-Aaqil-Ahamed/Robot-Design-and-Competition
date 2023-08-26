# Robot Design and Competition

Welcome to the repository for the Robot Design and Competition project! This repository contains all the information, code, and resources related to the design and implementation of a virtual and physical robot for various tasks.

## Overview

This project consists of two main tasks: Simulation and Physical Tasks. The tasks involve a series of challenges that the robot must complete, showcasing its capabilities in navigation, decision-making, and interaction with the environment.

### Simulation Task

In the simulation task, the robot is designed and tested within the Webots Open-Source Simulator (Version R2021b). The tasks include:

- Line Following
- Segmented Wall Following
- Slotted Line Following
- Chess Board Arena Challenge

## Subtask Details

### Line Following

The robot must accurately follow a white line on a black surface. The path may include straight and curved lines.

![Line Following](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Line_Following.png)


### Segmented Wall Following

The robot should follow a segmented wall with varying shapes, such as straight or curved segments.

![Segmented wall following](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Segmented_Wall_Following.png)


### Slotted Line Following

The robot must follow a colored dotted line path. The path has two options, and the correct one should be chosen based on a random color assigned at the beginning of the task.

![Slotted line](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Slotted_Line.png)


### Chess Board Arena Challenge

The robot plays the role of a black rook in a chess game. It needs to deliver checkmate in one move and open a secret chamber door on a virtual chessboard.

![Chess board area](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Chess_Board_Arena.png)


## Broken Bridge Crossing

After completing the Chess Board Puzzle, the robot's next challenge is to cross a broken bridge. The bridge is divided into two sections, each with a hole. The robot must place two blocks to cover these holes and create a path to the destination square. The two bloks can find in the chamber after we complete the sub task on chess board arena.

### Specifications

- The width of the bridge is 40 cm.
- Each hole measures 11 cm x 15 cm with the shorter side parallel to the guide line.
- The holes have a depth of 10.5 cm.
- The robot should carry two cubes, each with dimensions 10 cm x 10 cm x 10 cm and a weight of 150g.

### Crossing Procedure

1. The robot needs to approach the bridge and position the cubes to cover the holes.
2. The blocks must be carefully placed to ensure stability and proper coverage.
3. Once the holes are covered, the robot will be able to cross the bridge safely.
4. The robot's objective is to stop inside the white destination square after crossing the bridge.

## Sample Task Overview

For a visual representation of the subtasks and their order, refer to the provided diagram below:

![Sample Task Overview](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Webot_Arena.png)

The highlight of this task is the chess board challenge, where the robot must place the black rook and  deliver checkmate the white king in one move to open a secret chamber.

### Physical Task

#### Physical Task Overview

![Physical Task Overview](https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition/blob/master/Images/Task.png)

In the physical task, the real robot is deployed to complete a set of challenges. These challenges include:

- Line Maze Exploration
- Line Maze Speeding
- Curved Wall Following
- Blind Box Challenge

The physical task presents obstacles such as line maze navigation, precise wall following, and decision-making in the blind box challenge.

### Line Maze
Exploration Stage
In this stage, the robot starts from the white starting square. It embarks on a journey to explore the maze, using 90-degree turns at intersections. The goal is to reach the white checkpoint square on the opposite side of the maze. Once the checkpoint is reached, the exploration stage concludes.

### Speeding Stage
Having completed the exploration, the robot employs the gathered data to compute the shortest path back to the starting square. The time it takes for the robot to return to the starting square influences its score in this stage.

### Curved Wall
The robot leaves the starting square of the maze to follow a curved wall, which is situated to the robot's left. The robot must navigate the wall without crossing the red line that marks the boundary. A penalty will be incurred if the robot crosses the line. The curved wall leads to the entrance of the blind box challenge.

### Blind Box
Within the blind box, the robot encounters three openings: an entrance, a wrong exit, and a correct exit. The robot's task is to exit through the correct opening and follow a line on the floor to reach the final destination square. Collisions with the blind box walls trigger penalties, so precise control is essential.

### Code Organization
The repository is structured as follows:

- Line following test code
- Wall following test code
- Fully structured code

## Repository Structure

- `simulation/`: Contains code and resources for the simulation task.
- `physical/`: Contains code and resources for the physical task.
- `docs/`: Documentation and diagrams related to the project.
- `src/`: Source code for the robot's control and decision-making.
- `resources/`: Additional resources such as images and models.

## Getting Started

To get started with the project, follow these steps:

1. Clone this repository: `git clone https://github.com/MB-Shihab-Aaqil-Ahamed/Robot-Design-and-Competition.git`
2. Navigate to the relevant task directories: `cd simulation` or `cd physical`
3. Follow the README files in each directory for detailed instructions on setting up and running the robot.

## Task Details

For detailed information about the tasks, specifications, rules, and challenges, please refer to the [task details document](/docs/EN2533_Task_Description.pdf).

Feel free to explore the code, documentation, and resources in this repository to understand the design and implementation of the robot for the competition.

For inquiries or assistance, please contact [Shihab Aaqil Ahamed](mailto:shihabaaqilahamed@gmail.com).

Happy Robot Designing and Competing!
