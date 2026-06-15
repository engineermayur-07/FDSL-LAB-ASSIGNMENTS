# 🔢 Assignment 02 — Sorting

**Author:** M.B.Gund  
**LinkedIn:** [linkedin.com/in/mgund1920](https://linkedin.com/in/mgund1920)  
**Email:** mgund1920@gmail.com

---

## 📌 What is Sorting?

**Sorting** is the process of arranging elements of a collection in a specific order — either **ascending** or **descending**. Sorting is fundamental because many other algorithms (like Binary Search) require sorted data to work efficiently.

Sorting algorithms covered in this assignment:
1. **Bubble Sort**
2. **Insertion Sort**
3. **Selection Sort**

---

## 🔑 Key Terminology

- **In-place Sorting:** Sorting is done within the original array without needing extra memory. (Space: O(1))
- **Stable Sorting:** The relative order of equal elements is preserved after sorting.
- **Comparison-based Sorting:** Elements are compared with each other to determine order.

---

## 1️⃣ Bubble Sort

### Concept
Bubble Sort is the simplest sorting algorithm. It repeatedly **compares adjacent elements** and **swaps** them if they are in the wrong order. In each pass, the largest unsorted element "bubbles up" to its correct position at the end of the array.

### How It Works
```
Array: [64, 34, 25, 12, 22]

Pass 1:
  [34, 64, 25, 12, 22] → swap 64, 34
  [34, 25, 64, 12, 22] → swap 64, 25
  [34, 25, 12, 64, 22] → swap 64, 12
  [34, 25, 12, 22, 64] → swap 64, 22   → 64 is in place ✓

Pass 2:
  [25, 34, 12, 22, 64] → ...
  [25, 12, 22, 34, 64] → 34 in place ✓

... and so on until sorted.
Final: [12, 22, 25, 34, 64]
```

### Algorithm
```
BubbleSort(arr[], n):
    for i = 0 to n-2:
        swapped = false
        for j = 0 to n-2-i:
            if arr[j] > arr[j+1]:
                swap(arr[j], arr[j+1])
                swapped = true
        if swapped == false:
            break    // Array is already sorted, early exit
```

### Time Complexity

| Case | Complexity | Explanation |
|---|---|---|
| Best Case | **O(n)** | Array is already sorted (with swapped flag optimization) |
| Average Case | **O(n²)** | Elements are in random order |
| Worst Case | **O(n²)** | Array is in reverse order |

### Space Complexity
**O(1)** — In-place sorting.

### Is Bubble Sort Stable?
**Yes.** Equal elements are never swapped, so their original relative order is maintained.

### Advantages
- Simple to understand and implement.
- Can detect already sorted arrays efficiently (with optimization).

### Disadvantages
- Extremely inefficient for large datasets.
- Rarely used in practice due to O(n²) worst case.

---

## 2️⃣ Selection Sort

### Concept
Selection Sort works by repeatedly **selecting the minimum element** from the unsorted portion and placing it at the beginning. It divides the array into a sorted part (left) and unsorted part (right), expanding the sorted part one element at a time.

### How It Works
```
Array: [64, 25, 12, 22, 11]

Pass 1: Minimum of [64,25,12,22,11] = 11 → Swap with arr[0]
  → [11, 25, 12, 22, 64]

Pass 2: Minimum of [25,12,22,64] = 12 → Swap with arr[1]
  → [11, 12, 25, 22, 64]

Pass 3: Minimum of [25,22,64] = 22 → Swap with arr[2]
  → [11, 12, 22, 25, 64]

Pass 4: Minimum of [25,64] = 25 → Already in place
  → [11, 12, 22, 25, 64] ✓
```

### Algorithm
```
SelectionSort(arr[], n):
    for i = 0 to n-2:
        min_index = i
        for j = i+1 to n-1:
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            swap(arr[i], arr[min_index])
```

### Time Complexity

| Case | Complexity | Explanation |
|---|---|---|
| Best Case | **O(n²)** | Always scans remaining unsorted portion |
| Average Case | **O(n²)** | No special advantage from any ordering |
| Worst Case | **O(n²)** | Same behavior regardless |

### Space Complexity
**O(1)** — In-place sorting.

### Is Selection Sort Stable?
**No.** Swapping non-adjacent elements can disturb the relative order of equal elements.

### Advantages
- Makes the minimum number of swaps: O(n) swaps total.
- Simple implementation.
- Useful when write operations are costly (e.g., memory writes in flash storage).

### Disadvantages
- Always O(n²) — cannot detect if array is already sorted.
- Not suitable for large datasets.

---

## 3️⃣ Insertion Sort

### Concept
Insertion Sort builds the sorted array **one element at a time**. It picks each element and **inserts it into its correct position** among the previously sorted elements — similar to how we sort playing cards in hand.

### How It Works
```
Array: [12, 11, 13, 5, 6]

Step 1: Key = 11 → Insert into [12] → [11, 12, 13, 5, 6]
Step 2: Key = 13 → Insert into [11,12] → [11, 12, 13, 5, 6]
Step 3: Key = 5  → Insert into [11,12,13] → [5, 11, 12, 13, 6]
Step 4: Key = 6  → Insert into [5,11,12,13] → [5, 6, 11, 12, 13] ✓
```

### Algorithm
```
InsertionSort(arr[], n):
    for i = 1 to n-1:
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]    // Shift element right
            j = j - 1
        arr[j+1] = key           // Place key in correct position
```

### Time Complexity

| Case | Complexity | Explanation |
|---|---|---|
| Best Case | **O(n)** | Array is already sorted — no shifts needed |
| Average Case | **O(n²)** | Elements shifted on average n/2 times |
| Worst Case | **O(n²)** | Array is in reverse order — maximum shifts |

### Space Complexity
**O(1)** — In-place sorting.

### Is Insertion Sort Stable?
**Yes.** Equal elements are not moved past each other; relative order is preserved.

### Advantages
- Efficient for **small datasets** or **nearly sorted** arrays.
- Adaptive: O(n) when array is already sorted.
- Online: Can sort a list as it receives elements.
- Fewer comparisons in best case compared to Bubble and Selection sort.

### Disadvantages
- O(n²) worst case makes it impractical for large datasets.

---

## ⚖️ Comparison of Sorting Algorithms

| Property | Bubble Sort | Selection Sort | Insertion Sort |
|---|---|---|---|
| Best Case | O(n) | O(n²) | **O(n)** |
| Average Case | O(n²) | O(n²) | O(n²) |
| Worst Case | O(n²) | O(n²) | O(n²) |
| Space | O(1) | O(1) | O(1) |
| Stable | ✅ Yes | ❌ No | ✅ Yes |
| Adaptive | ✅ Yes | ❌ No | ✅ Yes |
| Swaps | O(n²) | **O(n)** | O(n²) |

---

## 📊 Practical Notes

- For **small arrays (n < 20):** Insertion Sort is generally fastest in practice.
- For **already sorted or nearly sorted data:** Insertion Sort is optimal.
- For **minimizing writes/swaps:** Selection Sort is best.
- For **large datasets:** Use advanced algorithms like Merge Sort (O(n log n)) or Quick Sort (O(n log n) average).

---

## 📌 Key Takeaways

- All three algorithms here are **O(n²)** in the average/worst case — they are simple but not efficient for large inputs.
- The **Bubble Sort optimization** (swapped flag) makes it O(n) best case — always use it.
- **Insertion Sort** is the most practically useful of the three for small/nearly-sorted data.
- Real-world sorting uses **hybrid algorithms** like Timsort (used in Python, Java) which combines Insertion Sort for small runs and Merge Sort for large data.

---

> *"Sorting is not just about ordering numbers — it's about organizing information for efficient retrieval."*
