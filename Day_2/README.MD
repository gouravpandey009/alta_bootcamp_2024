# Prefix Sum Technique

## What is Prefix Sum?

A **Prefix Sum** array stores the cumulative sum of elements from the beginning of the array up to a given index.

**Definition:**

```text
prefix[i] = sum of elements from index 0 to i
```

---

## Why Do We Need Prefix Sum?

Suppose we need to answer multiple range sum queries.

Example:

```text
Array = [2, 5, 3, 1, 4, 6]

Query 1 → Sum(1,4)
Query 2 → Sum(0,3)
Query 3 → Sum(2,5)
...
```

### Brute Force

For every query:

- Traverse from `L` to `R`
- Time Complexity = **O(N)** per query

For `Q` queries:

```text
O(N × Q)
```

When both `N` and `Q` are large, this becomes inefficient.

---

## Prefix Sum Idea

Instead of calculating the same sums repeatedly,

**Precompute once and reuse forever.**

Build an additional array:

```text
Array  :  2   5   3   1   4   6

Prefix :  2   7  10  11  15  21
```

Each element stores the sum till that index.

---

## Prefix Array Construction

```cpp
prefix[0] = arr[0];

for(int i = 1; i < n; i++)
{
    prefix[i] = prefix[i - 1] + arr[i];
}
```

### Time Complexity

```text
O(N)
```

---

## Range Sum Query Formula

### Case 1

If

```text
L == 0
```

then

```cpp
answer = prefix[R];
```

---

### Case 2

Otherwise

```cpp
answer = prefix[R] - prefix[L - 1];
```

---

## Why Does This Formula Work?

```text
Prefix[R]

contains

0 ------------ R
```

We only need

```text
L ------------ R
```

So remove

```text
0 -------- L-1
```

Therefore,

```text
Range Sum = Prefix[R] - Prefix[L-1]
```

---

## Example

```text
Array

Index : 0 1 2 3 4 5

Value : 2 5 3 1 4 6
```

Prefix Array

```text
2 7 10 11 15 21
```

Find:

```text
Sum(2,5)
```

Solution:

```text
prefix[5] - prefix[1]

21 - 7

= 14
```

Verification:

```text
3 + 1 + 4 + 6 = 14
```

---

## Complexity

| Operation | Complexity |
|----------|------------|
| Build Prefix Array | O(N) |
| One Range Query | O(1) |
| Extra Space | O(N) |

---

## When Should You Think About Prefix Sum?

Prefix Sum is a strong candidate when you see:

- Multiple range sum queries
- Static array (array does not change)
- Repeated calculations
- Running/Cumulative sum
- Sum from index `L` to `R`

---

## When Prefix Sum is NOT the Best Choice

Avoid Prefix Sum when:

- Array is updated frequently
- Only one range query is asked
- The problem requires dynamic updates

---

## Common Mistakes

### 1. Forgetting the edge case

```cpp
L == 0
```

Do **not** subtract `prefix[-1]`.

---

### 2. Memorizing the formula

Understand the idea:

```text
Remove the unnecessary left part.
```

The formula becomes obvious.

---

### 3. Building Prefix Sum for a single query

If there is only one range query,

a simple loop is often sufficient.

---

## Interview Recognition Checklist

Ask yourself:

- Are there many range queries?
- Am I recalculating the same sum repeatedly?
- Can I preprocess once?
- Is the array static?

If the answer is **Yes**, Prefix Sum is worth considering.

---

## Key Takeaways

- Prefix Sum is a **preprocessing technique**.
- It stores the **running cumulative sum**.
- Build once in **O(N)**.
- Answer each range query in **O(1)**.
- Best suited for **static arrays with multiple range queries**.

---

## Summary

```text
Repeated Range Queries
        ↓
Repeated Work
        ↓
Preprocessing
        ↓
Build Prefix Array
        ↓
Range Sum = Prefix[R] - Prefix[L-1]
        ↓
O(1) Per Query
```