PATHFINDING ALGORITHM VISUALIZER (C++/SFML)

A C++ project implementing classic graph pathfinding algorithms and visualizing their traversal order and highlighting shortest path using SFML.


![Pathfinding Visualizer Demo](https://github.com/Nileshh-01/Pathfinding-visualizer/blob/215853e28904f46f43d038890b9fad6d0ac34100/Demo_ss.png)

### Video Demo
(Click to play)

https://github.com/Nileshh-01/Pathfinding-visualizer/blob/215853e28904f46f43d038890b9fad6d0ac34100/Demo_video.mov

# Features

#### Algorithms:

- Dijkstra's Algorithm
- Breadth First Search (BFS)
- Bellman Ford Algorithm

#### Visualization:

Automatic node layout (Grid).

Animated traversal order.

Highlighted shortest path.

# How it works:

- A graph is constructed from the given file input (testcase).
- Algorithm selected by the user is executed.
- Results are returned in the form of PathResult.
   PathResult contains:
   dist[] - shortest distance
   parent[] - shortest path
   visitedOrder[] - traversal order

- Visualizer: Animates the node visits using visitedOrder[]
               Highlights shortest path using parent[]

# Project structure:

Pathfinding/
├── src/
│ ├── graph.cpp / graph.h
│ ├── bfs.cpp / bfs.h
│ ├── dijkstra.cpp / dijkstra.h
│ ├── bellman_ford.cpp / bellman_ford.h
│ ├── visualizer.cpp / visualizer.h
│ └── main.cpp
├── test_cases/
├── README.md

# Build & Run

#### Requirements:

- C++17 or newer
- SFML 3
- macOS (tested on macOS)

#### Compile:

From the src directory-
g++ *.cpp -std=c++17 -o graph \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system

#### Run:

./graph

# Input Format:

Graph input files are stored in test_cases/
Example:

    V E
    u v w
    u v w
    u v w
    ....

V - Number of vertices
E - Number of edges
w - Edge weight

# Possible extensions:

- Circular nodes layout
- Animation speed control
- Edge weight display
- Arrows display

# Final notes:

This project was built to strengthen and implement the undersatnding of:

- Graph algorithms 
- Event based rendering
- Path reconstruction

**It is intended as a learning and interview project not an advanced game engine. **
