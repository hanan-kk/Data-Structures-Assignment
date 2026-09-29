# Graph Representation Using Adjacency Matrix and Adjacency List

## Aim

To implement a graph using an adjacency matrix and an adjacency list in C, perform BFS and DFS traversals, and search for a vertex.

## Problem

Consider a small social network with the following connections:

A-B, A-C, B-D, B-E, C-F, E-F

Implement the graph using two representations and compare their space and time complexity.

## Vertices

A, B, C, D, E, F

## Edges

A-B, A-C, B-D, B-E, C-F, E-F

## Features

* Adjacency Matrix representation
* Adjacency List representation
* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Vertex search operation
* Time and space complexity analysis

## Expected Output

### BFS Traversal

A B C D E F

### DFS Traversal

A B D E F C

### Vertex Search

Search for vertex E

Vertex E found at index 4
Comparisons required: 5

## Complexity Analysis

| Operation     | Adjacency Matrix | Adjacency List |
| ------------- | ---------------- | -------------- |
| Space         | O(V²)            | O(V + E)       |
| BFS           | O(V²)            | O(V + E)       |
| DFS           | O(V²)            | O(V + E)       |
| Vertex search | O(V)             | O(V)           |
| Edge checking | O(1)             | O(degree)      |

## Conclusion

The adjacency list is more space-efficient for sparse graphs because it stores only the existing edges. It also provides efficient BFS and DFS traversal. The adjacency matrix is useful when frequent edge checking is required.

## How to Compile and Run

Compile the program:

```bash
gcc graph.c -o graph
```

Run the program:

```bash
./graph
```

## Language

C

