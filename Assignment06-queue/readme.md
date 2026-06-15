# 🚶 Assignment 06 — Queue

**Author:** M.B.Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle — the element inserted **first** is the first to be removed. Think of it like a queue of people at a ticket counter: the person who arrives first gets served first.

```
REAR →  [40] [30] [20] [10]  ← FRONT
       (Enqueue here)   (Dequeue here)
```

Elements are **inserted at the REAR** and **removed from the FRONT**.

---

## ⚙️ Queue Operations

| Operation | Description |
|---|---|
| **Enqueue(x)** | Insert element `x` at the rear of the queue |
| **Dequeue()** | Remove and return the element from the front |
| **Peek() / Front()** | Return front element without removing |
| **isEmpty()** | Check if queue is empty |
| **isFull()** | Check if queue is full (array-based) |

---

## 🏗️ Types of Queues

1. **Linear Queue** (Simple Queue)
2. **Circular Queue**
3. **Double-Ended Queue (Deque)**
4. **Priority Queue** (advanced — not covered here)

---

## 1️⃣ Linear Queue (Simple Queue)

### Structure (Array-based)
```c
#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};
// Initialize: front = -1, rear = -1
```

### Enqueue Operation
```
Enqueue(x):
  if rear == MAX - 1:
      print "Queue Overflow"     // Queue is full
  else:
      if front == -1:
          front = 0             // First element being inserted
      rear = rear + 1
      arr[rear] = x
```
**Time Complexity: O(1)**

### Dequeue Operation
```
Dequeue():
  if front == -1 OR front > rear:
      print "Queue Underflow"   // Queue is empty
  else:
      x = arr[front]
      front = front + 1
      return x
```
**Time Complexity: O(1)**

### Conditions
- **Queue Overflow:** `rear == MAX - 1`
- **Queue Underflow:** `front == -1` or `front > rear`

### 🚨 Problem with Linear Queue: Memory Wastage
After several enqueue and dequeue operations, `front` moves forward, leaving empty slots at the beginning that **cannot be reused**.

```
Initial: [_][_][_][_][_]   front=-1, rear=-1
After 3 Enqueues: [10][20][30][_][_]   front=0, rear=2
After 2 Dequeues: [__][__][30][_][_]   front=2, rear=2
                   ↑ These slots are wasted!
```

**Solution → Circular Queue**

---

## 2️⃣ Circular Queue

### Concept
A **Circular Queue** treats the array as a circle — when the `rear` reaches the end, it wraps around to the beginning (index 0), reusing empty slots left by dequeued elements.

```
        [0]
     [4]   [1]
     [3]   [2]
        
rear wraps: after index 4, next is 0
```

### Key Formula
```
rear  = (rear  + 1) % MAX     // Wrap rear
front = (front + 1) % MAX     // Wrap front
```

### Structure
```c
struct Queue {
    int arr[MAX];
    int front, rear;
};
// Initialize: front = -1, rear = -1
```

### Enqueue Operation (Circular)
```
Enqueue(x):
  if (rear + 1) % MAX == front:
      print "Queue Full"           // Circular full condition
  else:
      if front == -1:
          front = 0
      rear = (rear + 1) % MAX
      arr[rear] = x
```
**Time Complexity: O(1)**

### Dequeue Operation (Circular)
```
Dequeue():
  if front == -1:
      print "Queue Empty"
  else:
      x = arr[front]
      if front == rear:            // Last element being removed
          front = -1
          rear  = -1
      else:
          front = (front + 1) % MAX
      return x
```
**Time Complexity: O(1)**

### Full and Empty Conditions

| Condition | State |
|---|---|
| `front == -1` | Queue is **Empty** |
| `(rear + 1) % MAX == front` | Queue is **Full** |

### Why Circular Queue is Better Than Linear Queue?
- **No memory wastage** — freed slots are reused via circular wrap-around.
- Efficient for fixed-size buffers.
- **Same O(1) time complexity** for enqueue and dequeue.

---

## 3️⃣ Double-Ended Queue (Deque)

### Concept
A **Deque** (pronounced "deck") is a generalized queue where elements can be **inserted and deleted from both ends** — the front and the rear.

```
INSERT FRONT ←  [10][20][30][40]  → INSERT REAR
DELETE FRONT ←                    → DELETE REAR
```

### Types of Deque
- **Input-Restricted Deque:** Insertion only at rear; deletion from both ends.
- **Output-Restricted Deque:** Deletion only from front; insertion at both ends.

### Operations

| Operation | Description | Time Complexity |
|---|---|---|
| Insert at Front | Add element at front | O(1) |
| Insert at Rear | Add element at rear | O(1) |
| Delete from Front | Remove element from front | O(1) |
| Delete from Rear | Remove element from rear | O(1) |
| Peek Front | View front element | O(1) |
| Peek Rear | View rear element | O(1) |

All Deque operations are **O(1)**.

### Deque Using Circular Array Logic
Same circular wrap-around as Circular Queue, but both `front` and `rear` can move in both directions:
- Insert at front: `front = (front - 1 + MAX) % MAX`
- Delete at rear: `rear = (rear - 1 + MAX) % MAX`

### Applications of Deque
- **Sliding Window Maximum** problem (classic algorithms problem).
- **Palindrome checking** — insert characters; compare front and rear.
- **Undo/Redo** in applications.
- **A-Steal job scheduling** algorithms.

---

## 📊 Time Complexity Summary

| Operation | Linear Queue | Circular Queue | Deque |
|---|---|---|---|
| Enqueue / Insert | O(1) | O(1) | O(1) |
| Dequeue / Delete | O(1) | O(1) | O(1) |
| Peek | O(1) | O(1) | O(1) |
| isEmpty | O(1) | O(1) | O(1) |

**Space Complexity: O(n)** for all implementations.

---

## ⚖️ Comparison

| Feature | Linear Queue | Circular Queue | Deque |
|---|---|---|---|
| Memory efficiency | ❌ Wastage | ✅ No wastage | ✅ No wastage |
| Insertions | Rear only | Rear only | Both ends |
| Deletions | Front only | Front only | Both ends |
| Complexity | Simple | Moderate | Moderate |
| Use case | Basic FIFO | OS buffers | Flexible queues |

---

## 💡 Applications of Queue

### 1. CPU Scheduling (Round Robin)
Operating systems use a **circular queue** to schedule processes in Round Robin scheduling — each process gets a fixed time slot (quantum) and goes back to the end of the queue.

### 2. Printer Spooling
Print jobs are enqueued; the printer processes them one by one in FIFO order.

### 3. BFS (Breadth First Search) in Graphs
BFS uses a queue to explore nodes level by level — nodes at distance 1 are processed before nodes at distance 2.

### 4. Keyboard Buffer
Keystrokes are stored in a queue; the CPU processes them in the order they were pressed.

### 5. Traffic Management
Toll booths, call centers, and bank queues all follow FIFO — first come, first served.

### 6. Inter-process Communication
Message queues in operating systems (POSIX, Windows) use FIFO to pass messages between processes.

---

## 🔑 Key Difference: Stack vs Queue

| Property | Stack | Queue |
|---|---|---|
| Principle | **LIFO** — Last In, First Out | **FIFO** — First In, First Out |
| Insert | Top | Rear |
| Delete | Top | Front |
| Example | Undo operation | Print queue |

---

## 📌 Key Takeaways

- Queue is a **FIFO** structure — first in, first out.
- **Linear Queue** wastes memory; use **Circular Queue** to solve this.
- **Deque** is the most flexible — allows operations at both ends.
- All queue operations are **O(1)** in properly implemented queues.
- Queues are fundamental to **OS scheduling**, **graph algorithms (BFS)**, and **network buffering**.

---

> *"A queue represents fairness — the first one in line is the first one served. This principle powers everything from operating systems to real-world service systems."*
