# 🔺 Pattern Printing

**Author:** Mayur.B. Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is Pattern Printing?

**Pattern Printing** is a foundational programming exercise used to build a strong grip on **loops** (`for`, `while`), **nested iteration**, and **conditional logic** — all before moving into more complex data structures. Patterns are typically printed using stars (`*`), numbers, or characters arranged in shapes like triangles, pyramids, and diamonds.

While patterns don't form a "data structure" themselves, this practice is included in DSA fundamentals courses because:
- It builds intuition for **nested loops**, which are used everywhere (matrix traversal, sorting algorithms, 2D arrays).
- It strengthens understanding of **loop variables and their relationships** (row vs column count).
- It is the most common entry point for understanding **time complexity of nested loops**.

---

## 🔑 Core Idea Behind Every Pattern

Every pattern-printing program follows the same basic skeleton:

```
for each row (outer loop):
    for each column in that row (inner loop):
        decide whether to print a character or a space
    move to next line
```

The **outer loop** controls the number of rows.  
The **inner loop(s)** control what gets printed in each row — and this is where the "logic" of the pattern lies.

---

## 🔺 Common Pattern Categories

### 1. Star Patterns

**Right Triangle**
```
*
* *
* * *
* * * *
```
```c
for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++)
        printf("* ");
    printf("\n");
}
```

**Inverted Right Triangle**
```
* * * *
* * *
* *
*
```

**Pyramid (Symmetric Triangle)**
```
   *
  * *
 * * *
* * * *
```
Requires printing **leading spaces** before the stars — spaces = `n - i`.

**Inverted Pyramid**
```
* * * *
 * * *
  * *
   *
```

**Diamond**
```
   *
  * *
 * * *
* * * *
 * * *
  * *
   *
```
A diamond is simply a pyramid followed by an inverted pyramid (excluding the middle row repetition).

---

### 2. Number Patterns

**Simple Number Triangle**
```
1
1 2
1 2 3
1 2 3 4
```

**Number Triangle (Row Number Repeated)**
```
1
2 2
3 3 3
4 4 4 4
```

**Floyd's Triangle**
```
1
2 3
4 5 6
7 8 9 10
```
Uses a **single continuously incrementing counter** across rows, rather than resetting it each row.

**Pascal's Triangle**
```
      1
    1   1
  1   2   1
1   3   3   1
```
Each value is the sum of the two values above it. Often implemented using the **combination formula**:
```
C(row, col) = row! / (col! * (row - col)!)
```

---

### 3. Character Patterns

**Alphabet Triangle**
```
A
A B
A B C
A B C D
```
Uses character arithmetic: `'A' + j` to get successive letters.

**Alphabet Pyramid**
```
   A
  A B
 A B C
A B C D
```

---

### 4. Hollow Patterns

**Hollow Square**
```
* * * *
*     *
*     *
* * * *
```
Print `*` only on the **border** (first row, last row, first column, last column); print spaces everywhere else.

**Hollow Pyramid**
```
   *
  * *
 *   *
* * * *
```

---

## 📐 General Logic Building Approach

When approaching any pattern problem, ask these questions:

1. **How many rows?** → Controls the outer loop range.
2. **How many columns per row?** → Usually depends on the row number (`i`) — controls the inner loop range.
3. **Are there leading spaces?** → Common in pyramid-shaped patterns; usually `(n - i)` spaces.
4. **What gets printed — star, number, or character?** → Defines what goes inside the inner loop body.
5. **Is it hollow?** → Add a condition to print space instead of the character for inner cells.

---

## ⏱️ Time and Space Complexity

### Time Complexity
Pattern printing always involves **nested loops** — an outer loop running `n` times, and an inner loop running up to `n` times per outer iteration.

| Pattern Type | Time Complexity | Explanation |
|---|---|---|
| Any triangle/pyramid pattern (n rows) | **O(n²)** | Outer loop runs n times; inner loop runs ~i times on average, summing to n(n+1)/2 ≈ O(n²) |
| Patterns with constant-width rows | O(n) outer × O(1) inner = **O(n)** | Rare — most real patterns scale with row number |

**Why O(n²) and not O(n)?**
The total number of inner-loop iterations across all rows is:
```
1 + 2 + 3 + ... + n = n(n+1)/2
```
This sum is a quadratic expression in `n`, so the overall time complexity is **O(n²)**.

### Space Complexity
**O(1)** — Pattern printing typically uses only a few loop counter variables (`i`, `j`) and does not require extra data structures, regardless of pattern size.

---

## 💡 Why This Topic Matters for Data Structures

Even though pattern printing seems like a "beginner" exercise, it directly builds skills needed later:

| Skill Practiced Here | Used Later In |
|---|---|
| Nested loops | Matrix operations, 2D arrays, Bubble/Selection Sort |
| Loop bounds depending on another variable | Triangular traversal in DP, sorting algorithms |
| Conditional printing (hollow patterns) | Border/boundary traversal in matrices |
| Counting total inner-loop iterations | Time complexity analysis (O(n²) intuition) |

---

## 📌 Key Takeaways

- Pattern printing is fundamentally about mastering **nested loop control** — the outer loop for rows, the inner loop(s) for columns/content.
- Almost all standard patterns run in **O(n²)** time and **O(1)** space.
- The skill of relating inner-loop bounds to the outer-loop variable is the same skill used in analyzing nested loops in **sorting algorithms** (Assignment02) and matrix-based problems.
- Practicing patterns is one of the fastest ways to build comfort with loops before moving to pointer-based and dynamic data structures like Linked Lists, Stacks, and Queues.

---

> *"Before you can manipulate complex data structures, you must master the discipline of the loop — pattern printing is where that discipline begins."*
