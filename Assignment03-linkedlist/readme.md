# 🔗 Assignment 03 — Linked List

**Author:** M.B.Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is a Linked List?

A **Linked List** is a linear data structure where elements (called **nodes**) are stored in non-contiguous memory locations. Unlike arrays, elements are not stored at consecutive memory addresses — instead, each node holds:
1. **Data** — the actual value.
2. **Pointer (next)** — the address of the next node.

```
[Data | Next] → [Data | Next] → [Data | Next] → NULL
  Node 1           Node 2           Node 3
```

The first node is called the **Head**. The last node's `next` pointer is `NULL`, indicating the end of the list.

---

## 🔑 Why Linked Lists? (vs Arrays)

| Feature | Array | Linked List |
|---|---|---|
| Memory allocation | Static (fixed size) | Dynamic (grows/shrinks) |
| Insertion/Deletion | Expensive — O(n) shifting | Efficient — O(1) with pointer |
| Random access | O(1) via index | O(n) — must traverse |
| Memory usage | Less overhead | Extra memory for pointer |
| Size | Fixed at declaration | Dynamic |

**Use Linked List when:** frequent insertions/deletions are needed and size is unknown.  
**Use Array when:** frequent random access is needed and size is known.

---

## 🏗️ Node Structure (in C)

```c
struct Node {
    int data;
    struct Node *next;
};
```

---

## 📚 Types of Linked Lists

### 1. Singly Linked List
Each node points to the **next** node. Traversal is only in **one direction** (forward).
```
HEAD → [10|→] → [20|→] → [30|NULL]
```

### 2. Doubly Linked List
Each node has **two pointers**: one to the next node and one to the previous node. Traversal in both directions.
```
NULL ← [10|→] ↔ [20|→] ↔ [30|NULL]
```

### 3. Circular Linked List
The last node's `next` pointer points back to the **head**, forming a circle.
```
HEAD → [10|→] → [20|→] → [30|→] ─┐
  └──────────────────────────────┘
```

> This assignment focuses primarily on the **Singly Linked List**.

---

## ⚙️ Operations on Singly Linked List

### 1. Insertion

#### a) Insertion at the Beginning
```
New Node: [5|→]
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [5] → [10] → [20] → [30] → NULL

Steps:
  1. Create new node.
  2. Set new_node->next = head.
  3. Set head = new_node.
```
**Time Complexity: O(1)**

#### b) Insertion at the End
```
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [10] → [20] → [30] → [40] → NULL

Steps:
  1. Create new node; set new_node->next = NULL.
  2. Traverse to the last node.
  3. Set last_node->next = new_node.
```
**Time Complexity: O(n)** (traversal to the end)

#### c) Insertion at a Given Position
```
Insert 15 at position 2:
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [10] → [15] → [20] → [30] → NULL

Steps:
  1. Traverse to node at position-1.
  2. Set new_node->next = prev_node->next.
  3. Set prev_node->next = new_node.
```
**Time Complexity: O(n)**

---

### 2. Deletion

#### a) Deletion at the Beginning
```
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [20] → [30] → NULL

Steps:
  1. temp = head.
  2. head = head->next.
  3. free(temp).
```
**Time Complexity: O(1)**

#### b) Deletion at the End
```
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [10] → [20] → NULL

Steps:
  1. Traverse to second-last node.
  2. Set second_last->next = NULL.
  3. Free the last node.
```
**Time Complexity: O(n)**

#### c) Deletion of a Specific Node (by value)
```
Delete node with value 20:
Before: HEAD → [10] → [20] → [30] → NULL
After:  HEAD → [10] → [30] → NULL

Steps:
  1. Traverse to find the node with matching value.
  2. Set prev_node->next = target_node->next.
  3. Free target_node.
```
**Time Complexity: O(n)**

---

### 3. Traversal / Display
```
Steps:
  1. temp = head.
  2. while temp != NULL:
       print temp->data
       temp = temp->next
```
**Time Complexity: O(n)**

---

### 4. Search
```
Steps:
  1. temp = head.
  2. while temp != NULL:
       if temp->data == key: return found
       temp = temp->next
  3. return not found
```
**Time Complexity: O(n)**

---

### 5. Counting Nodes
Traverse the entire list, incrementing a counter for each node.  
**Time Complexity: O(n)**

---

## 📊 Time Complexity Summary

| Operation | Time Complexity |
|---|---|
| Insert at Beginning | **O(1)** |
| Insert at End | O(n) |
| Insert at Position | O(n) |
| Delete at Beginning | **O(1)** |
| Delete at End | O(n) |
| Delete Specific Node | O(n) |
| Search / Traversal | O(n) |
| Count Nodes | O(n) |

**Space Complexity: O(n)** — one node per element.

---

## 💡 Important Concepts

### Dynamic Memory in C (for Linked Lists)
```c
// Allocating memory for a new node
struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
new_node->data = value;
new_node->next = NULL;

// Freeing memory after deletion
free(ptr);
```

### Why Use `malloc()`?
Arrays in C are declared with a fixed size at compile time. Linked lists use `malloc()` to allocate memory **at runtime**, allowing the list to grow or shrink dynamically.

---

## ⚠️ Common Pitfalls

- Always check if `malloc()` returned `NULL` (allocation failure).
- Always update the `head` pointer when inserting/deleting at the beginning.
- Always `free()` deleted nodes to avoid **memory leaks**.
- Be careful about **dangling pointers** after deletion.

---

## 📌 Applications of Linked Lists

- Implementation of **Stacks** and **Queues**.
- **Dynamic memory allocation** structures.
- Implementation of **graphs** (adjacency list).
- **Music playlists** (next/previous song).
- **Browser history** (back/forward navigation).
- Polynomial representation in mathematics.

---

## 📌 Key Takeaways

- A linked list solves the **fixed-size limitation** of arrays.
- **Insertion and deletion at the beginning** are O(1) — a major advantage over arrays.
- **Random access is O(n)** — a disadvantage compared to arrays.
- Always manage memory carefully using `malloc()` and `free()` in C.
- Linked lists are the building blocks for advanced data structures: Stacks, Queues, Trees, and Graphs.

---

> *"A linked list teaches you the power of pointers — the fundamental building block of dynamic data structures."*
