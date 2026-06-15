# 🔍 Assignment 01 — Searching

**Author:** Mayur. B. Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is Searching?

**Searching** is the process of finding the location of a target element (called the **key**) within a collection of elements (usually an array). It is one of the most fundamental operations in computer science.

Two classical searching algorithms covered in this assignment:
1. **Linear Search**
2. **Binary Search**

---

## 1️⃣ Linear Search

### Concept
Linear Search (also called **Sequential Search**) is the simplest searching algorithm. It checks **every element** of the array one by one from the beginning until either the key is found or the array ends.

It works on **both sorted and unsorted** arrays.

### How It Works
```
Array: [12, 45, 7, 23, 89, 3]
Key to search: 23

Step 1: Compare 12 with 23 → Not found
Step 2: Compare 45 with 23 → Not found
Step 3: Compare 7  with 23 → Not found
Step 4: Compare 23 with 23 → FOUND at index 3 ✓
```

### Algorithm
```
LinearSearch(arr[], n, key):
    for i = 0 to n-1:
        if arr[i] == key:
            return i       // Element found at index i
    return -1              // Element not found
```

### Time Complexity

| Case | Complexity | Explanation |
|---|---|---|
| Best Case | **O(1)** | Key found at the first position |
| Average Case | **O(n)** | Key found somewhere in the middle |
| Worst Case | **O(n)** | Key is at the last position or not present |

### Space Complexity
**O(1)** — No extra memory is needed; only a few variables are used.

### Advantages
- Simple to implement and understand.
- Works on **unsorted** data.
- No preprocessing required.

### Disadvantages
- Very slow for large datasets.
- Not suitable when fast search is needed repeatedly.

### When to Use Linear Search?
- When the array is small.
- When the array is unsorted and sorting is expensive.
- When search is done rarely.

---

## 2️⃣ Binary Search

### Concept
Binary Search is an efficient searching algorithm that works on a **sorted array**. It repeatedly divides the search interval in half. If the key is less than the middle element, the search continues in the left half; otherwise in the right half.

It is based on the **Divide and Conquer** paradigm.

> ⚠️ **Prerequisite:** The array **must be sorted** before applying Binary Search.

### How It Works
```
Sorted Array: [3, 7, 12, 23, 45, 89]
Key to search: 23

low = 0, high = 5
Step 1: mid = (0+5)/2 = 2 → arr[2] = 12
        23 > 12 → Search RIGHT half → low = 3

Step 2: mid = (3+5)/2 = 4 → arr[4] = 45
        23 < 45 → Search LEFT half → high = 3

Step 3: mid = (3+3)/2 = 3 → arr[3] = 23
        23 == 23 → FOUND at index 3 ✓
```

### Algorithm (Iterative)
```
BinarySearch(arr[], low, high, key):
    while low <= high:
        mid = (low + high) / 2
        if arr[mid] == key:
            return mid
        else if arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

### Algorithm (Recursive)
```
BinarySearch(arr[], low, high, key):
    if low > high:
        return -1
    mid = (low + high) / 2
    if arr[mid] == key:
        return mid
    else if arr[mid] < key:
        return BinarySearch(arr, mid+1, high, key)
    else:
        return BinarySearch(arr, low, mid-1, key)
```

### Time Complexity

| Case | Complexity | Explanation |
|---|---|---|
| Best Case | **O(1)** | Key is at the middle on the first attempt |
| Average Case | **O(log n)** | Halving the search space each step |
| Worst Case | **O(log n)** | Key is at extreme end or not present |

### Space Complexity

| Version | Space |
|---|---|
| Iterative | **O(1)** — no extra memory |
| Recursive | **O(log n)** — due to call stack |

### Why O(log n)?
In each step, the search space is **halved**. Starting with `n` elements:
- After 1st step: n/2 elements remain
- After 2nd step: n/4 elements remain
- After k steps: n/2^k = 1 → k = log₂(n)

So at most **log₂(n)** comparisons are needed.

### Advantages
- Extremely fast compared to linear search for large data.
- Very efficient for large sorted datasets.

### Disadvantages
- Only works on **sorted arrays**.
- If the array is unsorted, sorting it first costs O(n log n).
- Random access to elements is required (arrays, not linked lists).

### When to Use Binary Search?
- When the array is already sorted.
- When multiple search operations are performed on the same dataset.
- When the dataset is large and fast searching is critical.

---

## ⚖️ Comparison: Linear vs Binary Search

| Feature | Linear Search | Binary Search |
|---|---|---|
| Input requirement | Unsorted/Sorted | Must be **Sorted** |
| Best Case | O(1) | O(1) |
| Worst Case | **O(n)** | **O(log n)** |
| Space | O(1) | O(1) iterative / O(log n) recursive |
| Implementation | Simple | Moderate |
| Performance on large data | Poor | Excellent |

---

## 📌 Key Takeaways

- Use **Linear Search** when data is unsorted or small.
- Use **Binary Search** when data is sorted and large.
- Binary Search is one of the most important algorithms — its O(log n) complexity is the basis for many advanced data structures like **Binary Search Trees**, **Heaps**, and **Balanced Trees**.

---

> *"The efficiency of search determines the speed of any information retrieval system."*
