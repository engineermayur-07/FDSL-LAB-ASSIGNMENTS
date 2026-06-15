# 📚 Assignment 04 — Stack ADT

**Author:** M.B.Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle — the element inserted **last** is the first to be removed. Think of it like a stack of plates: you always add/remove from the top.

```
        │   │  ← TOP
        │ 30│  ← Last inserted (removed first)
        │ 20│
        │ 10│  ← First inserted (removed last)
        └───┘
```

---

## 📌 What is an ADT?

**ADT (Abstract Data Type)** defines a data type purely by its **behavior** (operations), not by its implementation. A Stack ADT specifies:
- What operations are allowed: Push, Pop, Peek, isEmpty, isFull.
- What the result of each operation is.
- It does NOT say whether to use an array or linked list internally.

The same Stack ADT can be implemented using:
1. **Array** (static, fixed size)
2. **Linked List** (dynamic, variable size)

---

## ⚙️ Stack Operations

| Operation | Description |
|---|---|
| **Push(x)** | Insert element `x` onto the top of the stack |
| **Pop()** | Remove and return the top element |
| **Peek() / Top()** | Return the top element without removing it |
| **isEmpty()** | Check if the stack is empty |
| **isFull()** | Check if the stack is full (array-based only) |

---

## 🏗️ Implementation 1: Stack Using Array

### Structure
```c
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};
```

`top` is initialized to `-1` (indicates empty stack).

### Push Operation
```
Push(x):
  if top == MAX - 1:
      print "Stack Overflow"   // Stack is full
  else:
      top = top + 1
      arr[top] = x
```
**Time Complexity: O(1)**

### Pop Operation
```
Pop():
  if top == -1:
      print "Stack Underflow"  // Stack is empty
  else:
      x = arr[top]
      top = top - 1
      return x
```
**Time Complexity: O(1)**

### Peek Operation
```
Peek():
  if top == -1:
      print "Stack is Empty"
  else:
      return arr[top]
```
**Time Complexity: O(1)**

### Conditions
- **Stack Overflow:** Trying to push when `top == MAX - 1`
- **Stack Underflow:** Trying to pop when `top == -1`

### Advantages (Array-based)
- Simple, fast — O(1) for all operations.
- Cache-friendly (contiguous memory).

### Disadvantages (Array-based)
- **Fixed size** — size must be declared in advance.
- Wastes memory if stack is underused.

---

## 🏗️ Implementation 2: Stack Using Linked List

### Structure
```c
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
```
The `top` pointer always points to the most recently pushed node (the head of the list).

### Push Operation
```
Push(x):
  1. Create new node with data = x.
  2. new_node->next = top.
  3. top = new_node.
```
**Time Complexity: O(1)**

### Pop Operation
```
Pop():
  if top == NULL:
      print "Stack Underflow"
  else:
      temp = top
      top = top->next
      x = temp->data
      free(temp)
      return x
```
**Time Complexity: O(1)**

### Peek Operation
```
Peek():
  if top == NULL:
      print "Stack is Empty"
  else:
      return top->data
```
**Time Complexity: O(1)**

### Advantages (Linked List-based)
- **Dynamic size** — grows and shrinks as needed.
- No overflow (as long as memory is available).

### Disadvantages (Linked List-based)
- Extra memory for the `next` pointer in each node.
- Slightly slower due to dynamic memory allocation (`malloc`/`free`).

---

## 📊 Time & Space Complexity

| Operation | Array Stack | Linked List Stack |
|---|---|---|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| isEmpty | O(1) | O(1) |
| Space | O(n) — fixed | O(n) — dynamic |

All fundamental stack operations are **O(1)** in both implementations.

---

## 🔗 Comparison: Array vs Linked List Stack

| Feature | Array Stack | Linked List Stack |
|---|---|---|
| Size | Fixed (MAX) | Dynamic |
| Overflow | Possible | Not possible* |
| Memory usage | Fixed allocation | Grows with usage |
| Implementation | Simpler | Slightly complex |
| Access speed | Faster (cache) | Slightly slower |

*Until system memory runs out.

---

## 💡 Applications of Stack

### 1. Expression Evaluation & Conversion
Stacks are used to evaluate and convert arithmetic expressions.
- **Infix to Postfix** (e.g., `A+B*C` → `ABC*+`)
- **Infix to Prefix** (e.g., `A+B*C` → `+A*BC`)
- **Postfix Evaluation** (e.g., `2 3 4 * +` → `14`)

Why? Because stacks handle operator precedence and parentheses naturally.

### 2. Balanced Parentheses / Bracket Matching
Compilers use stacks to check if `{`, `[`, `(` are properly matched.
```
Expression: { [ ( ) ] }
Push '{', '[', '(' → Stack: [{[(]
Pop on ')' → match '(' ✓
Pop on ']' → match '[' ✓
Pop on '}' → match '{' ✓ → BALANCED
```

### 3. Function Call Stack (Recursion)
Every time a function is called, the return address and local variables are pushed onto the **call stack**. When the function returns, they are popped.

### 4. Undo / Redo Operations
Text editors store previous states on a stack. `Ctrl+Z` pops the last state.

### 5. Browser Back Button
Web browsers maintain a stack of visited pages. Going "back" pops the current page.

### 6. DFS (Depth First Search) in Graphs
Stacks (or recursion) are used to implement DFS traversal.

---

## 📝 Infix, Prefix, Postfix — Quick Reference

| Notation | Format | Example |
|---|---|---|
| Infix | Operator between operands | `A + B` |
| Prefix (Polish) | Operator before operands | `+ A B` |
| Postfix (Reverse Polish) | Operator after operands | `A B +` |

**Why Postfix?** Computers evaluate Postfix expressions easily using a stack — no need to handle operator precedence or parentheses.

---

## 📌 Key Takeaways

- Stack is a **LIFO** structure — last in, first out.
- All core operations (push, pop, peek) are **O(1)**.
- Two implementations exist: **array** (simple, fixed size) and **linked list** (dynamic).
- Stack is one of the most widely used data structures — underlying recursion, expression parsing, and undo mechanisms.

---

> *"The call stack is the invisible hero of every program — silently managing every function call you make."*
