# DAA-CU — Design and Analysis of Algorithms

C++ implementations of data structures and algorithms covered across lab sessions at Chandigarh University.

---

## Folder Structure

```
DAA-CU/
└── Session/
    ├── Experiment/         # Lab experiments — complexity analysis & data structures
    ├── Practice/           # Practice problems
    ├── Session7/           # Linked List problems
    ├── Session_18-19/      # Binary Search on Answer problems
    └── Session_20/         # Minimum Spanning Tree algorithms
```

---

## Session Details

### Experiment

| File | Topic | Description |
|------|-------|-------------|
| `Experiment1.cpp` | Recurrence Analysis | Implements a complex recursive function with recurrence `T(n) = 3T(n/2) + O(n)`. Tracks operation count, max recursion depth, and execution time. |
| `Experiment3.cpp` | Prefix Sum + HashMap | Finds the maximum length subarray with equal count of `'P'` and non-`'P'` characters. |
| `Experiment4.cpp` | Min-Heap | Manual min-heap implementation with `insert`, `deleteMin`, `deleteAtIndex`, `heapifyUp`, `heapifyDown`, and `search`. |

---

### Practice

| File | Topic | Description |
|------|-------|-------------|
| `Binary.cpp` | Binary Search | Standard binary search implementation on a sorted array. |

---

### Session 7 — Linked Lists

| File | Topic | Description |
|------|-------|-------------|
| `session7.cpp` | Linked List | Core linked list implementation (insertion, traversal, deletion). |
| `Reverse_linkedList.cpp` | Reverse a List | Iteratively reverses a singly linked list. |
| `LinkedList_cycle.cpp` | Cycle Detection | Floyd's Tortoise and Hare algorithm to detect a cycle. |
| `LinkeddListCycle2.cpp` | Cycle Start Node | Finds the node where the cycle begins in a linked list. |
| `iddleOfLinkedList.cpp` | Middle of List | Finds the middle node using the slow/fast pointer technique. |

---

### Session 18-19 — Binary Search on Answer

| File | Problem | Description |
|------|---------|-------------|
| `Aggressive_Cows.cpp` | Aggressive Cows (SPOJ) | Place `C` cows in `N` stalls to maximize the minimum distance between any two cows. Binary search on the answer. |
| `Koko_Banananas.cpp` | Koko Eating Bananas (LC 875) | Find the minimum eating speed `k` such that Koko finishes all bananas within `h` hours. Binary search on the answer. |

---

### Session 20 — Minimum Spanning Tree

| File | Algorithm | Description |
|------|-----------|-------------|
| `Kruskal.cpp` | Kruskal's Algorithm | Sort edges by weight; greedily add edges that don't form a cycle using **DSU** (path compression + union by rank). Time: `O(E log E)`. |
| `Prims.cpp` | Prim's Algorithm | Grow the MST from a source vertex using a **min-heap** (priority queue). Time: `O(E log V)`. |

---

## Concepts Covered

- Recursion & Recurrence Relations
- Sorting (Heap Sort via Min-Heap)
- Binary Search & Binary Search on Answer
- Linked Lists (cycle detection, reversal, middle node)
- Greedy Algorithms
- Graph Algorithms — Minimum Spanning Tree
- Disjoint Set Union (DSU) / Union-Find

---

## How to Compile & Run

```bash
g++ -std=c++17 -o output <filename>.cpp
./output
```

> For older compilers use `-std=c++14`. The code avoids C++17-only features where possible.
