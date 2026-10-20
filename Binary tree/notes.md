# 🌳 Lecture 1: Introduction to Binary Trees

These notes are based on the first lecture of the **Tree Series by Striver (Take U Forward)**.

---

## 📌 Table of Contents
1. [What is a Tree Data Structure?](#-1-what-is-a-tree-data-structure)
2. [What is a Binary Tree?](#-2-what-is-a-binary-tree)
3. [Basic Terminologies](#-3-basic-terminologies)
4. [Types of Binary Trees](#-4-types-of-binary-trees)
   - [Full Binary Tree](#1-full-binary-tree)
   - [Complete Binary Tree](#2-complete-binary-tree)
   - [Perfect Binary Tree](#3-perfect-binary-tree)
   - [Balanced Binary Tree](#4-balanced-binary-tree)
   - [Degenerate Tree](#5-degenerate-tree)
5. [Quick Summary Table](#-5-quick-summary-table)

---

## 📖 1. What is a Tree Data Structure?
* **Linear Data Structures:** Arrays, Stacks, Queues, and Linked Lists store data sequentially/linearly.
* **Hierarchical Data Structures:** **Trees** store data in a hierarchical manner. 
* **Real-world Analogy:** A computer's file system (folders inside folders) is structured like a tree. You have a main root folder, which contains sub-folders, which in turn contain more sub-folders or files.

---

## 🔢 2. What is a Binary Tree?
The term **"Binary"** relates to `2` (like 0 and 1). 
* **Definition:** A hierarchical data structure in which **every node can have at most 2 children** (i.e., a node can have `0`, `1`, or `2` children).
* **Importance:** Binary trees are one of the most frequently asked topics in software engineering coding interviews.

---

## 🏷️ 3. Basic Terminologies

Consider the following Binary Tree diagram as represented on the whiteboard in the lecture:

```text
          (A)          <-- Root Node (Starting point)
         /   \
       (B)   (C)       <-- Children of (A)
       /     / \
     (D)   (E) (F)     <-- (E) is a Leaf Node
       \         \
       (G)       (H)   <-- (H) is a Leaf Node
       /
     (I)               <-- Leaf Node (No children)
```

### Key Terms:
1. **Root:** The topmost/starting node of the tree (e.g., Node `A`).
2. **Children:** Nodes that are directly beneath a given node connected by an edge. 
   * *Example:* `B` and `C` are children of `A`. `G` is a child of `D`. `I` is a child of `G`.
3. **Parent:** The converse of a child. The node directly above a given node.
   * *Example:* `D` is the parent of `G`.
4. **Leaf Node:** A node that **does not have any children** (0 children).
   * *Example:* Nodes `I`, `E`, and `H` are leaf nodes.
5. **Subtree:** Any node in a tree along with all of its descendants (all nodes beneath it) forms a subtree.
   * *Example:* If you stand at node `C`, the portion containing `C`, `E`, `F`, and `H` forms the subtree of `C`.
   * *Example:* If you stand at node `B`, the portion containing `B`, `D`, `G`, and `I` forms the subtree of `B`.
6. **Ancestors:** All the nodes along the path from a given node up to the Root node (parent, grandparent, great-grandparent, etc.).
   * *Example:* For node `I`, its ancestors are `G`, `D`, `B`, and `A`.
   * *Example:* For node `E`, its ancestors are `C` and `A`.
   * *Example:* For node `H`, its ancestors are `F`, `C`, and `A`.

---

## 🗂️ 4. Types of Binary Trees

There are **5 main types** of Binary Trees covered in this lecture:

---

### 1. Full Binary Tree
> **Definition:** Every node in the tree must have **either `0` or `2` children**. No node can have just `1` child.

#### ✅ Valid Examples:
```text
   Example 1:                Example 2:
      (O)                       (O)
     /   \                     /   \
   (O)   (O)                 (O)   (O)
         / \                 / \   / \
       (O) (O)             (O) (O)(O) (O)
```
*Why Valid?* Every single node in both trees has either 2 children or 0 children.

#### ❌ Invalid Example:
```text
      (O)
     /   \
   (O)   (O)
   /     /
 (O)   (O)
```
*Why Invalid?* The nodes at the second level only have **1 child** each.

---

### 2. Complete Binary Tree
> **Definition:** 
> 1. **All levels** must be completely filled, **except possibly the last level**.
> 2. The **last level** must have all its nodes **as left as possible**.

*(Note: Levels are horizontal rows of nodes, indexed `0, 1, 2...` or `1, 2, 3...` from top to bottom).*

#### ✅ Valid Examples:
```text
   Example 1:                      Example 2:
      (O)       <-- Level 1           (O)       <-- Level 1 (Full)
     /   \                           /   \
   (O)   (O)    <-- Level 2        (O)   (O)    <-- Level 2 (Full)
   / \   / \                       / \   /
 (O) (O)(O) (O) <-- Level 3      (O) (O)(O)     <-- Level 3 (Filled from left)
```

#### ❌ Invalid Example:
```text
      (O)       <-- Level 1
     /   \
   (O)   (O)    <-- Level 2
   / \     \
 (O) (O)   (O)  <-- Level 3 (Missing left child of the right node!)
```
*Why Invalid?* In the last level, there is a node on the extreme right while the position to its immediate left is empty. The last level is not filled as left as possible.

---

### 3. Perfect Binary Tree
> **Definition:** All internal nodes have 2 children and **all leaf nodes are at the exact same level**.

#### ✅ Valid Examples:
```text
   Example 1:                      Example 2:
      (O)                             (O)
     /   \                           /   \
   (O)   (O)                       (O)   (O)
   / \   / \
 (O) (O)(O) (O)
```
*Why Valid?* All leaf nodes lie on the bottom-most level.

#### ❌ Invalid Example:
```text
      (O)
     /   \
   (O)   (O)    <-- Right node is a leaf at Level 2
   / \
 (O) (O)        <-- These leaves are at Level 3
```
*Why Invalid?* Leaf nodes are at different levels (Level 2 and Level 3).

---

### 4. Balanced Binary Tree
> **Definition:** A binary tree where the **height of the tree is at maximum $\log_2(N)$**, where $N$ is the total number of nodes in the tree.

* **Example Calculation:**
  * Suppose number of nodes $N = 8$.
  * $\log_2(8) = 3$.
  * Therefore, the maximum height of this tree should not exceed `3`.
* **Why is it important?** Keeping a tree balanced ensures that operations like searching, insertion, and deletion take $O(\log N)$ time complexity rather than degrading to $O(N)$. (This is explored deeper in Binary Search Trees / AVL / Red-Black Trees).

---

### 5. Degenerate Tree (or Skewed Tree)
> **Definition:** A tree where **every parent node has only a single child** (either all to the left, or all to the right). It essentially behaves like a **Linked List**.

#### ✅ Examples (for $N = 4$):
```text
  Left-Skewed:          Right-Skewed:
      (O)                  (O)
      /                      \
    (O)                      (O)
    /                          \
  (O)                          (O)
  /                              \
(O)                              (O)
```
*Characteristics:* It forms a straight line of nodes, losing the hierarchical advantage of trees and degrading time complexity to $O(N)$ (same as a Linked List).

---

## 📊 5. Quick Summary Table

| Tree Type | Core Condition |
| :--- | :--- |
| **Full BT** | Every node has `0` or `2` children. |
| **Complete BT** | All levels completely filled except the last; last level filled from **left to right**. |
| **Perfect BT** | All leaf nodes are at the **same level**. |
| **Balanced BT** | Height of the tree is at max **$\log_2(N)$** (where $N$ = number of nodes). |
| **Degenerate Tree** | Every non-leaf node has **only `1` child** (resembles a Linked List). |