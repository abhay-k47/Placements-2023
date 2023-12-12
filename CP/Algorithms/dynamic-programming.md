## key-ideas

- $dp(i,constraint)$ e.g. weight (in knapsack), count etc.
- dp(state)$ e.g. decide whether winning or loosing state in a game
- $dp(i) \rightarrow$ ending at index $i$
- $dp(l,r) \rightarrow$ optimal value for $a[l...r]$
- $dp(i,j) \rightarrow$ mostly for strings $s1[0...i], s2[0...j]$

## L-R DP

- Base cases may be
  - $l>r \rightarrow$ empty range
  - $l=r \rightarrow$ one element
- Eaxmples
  - parenthesize given expression
  - merge $a_i$ and $a_{i+1}$ as $(a_i+a_{i+1})\%M$
  - merge $a_i$ and $a_{i+1}$ as $(X*a_i+Y*a_{i+1}+Z)\%M$
  - delete contiguous elements with equal values

## DP-Optimizations

- State
  - State Rotation e.g. $dp(i,W) \rightarrow$ max Cost $ \implies dp(i,C) \rightarrow$ min Weight
  - Reformulation e.g. remove dependent states
- Transition
  - Memory Optimization
  - Transition Table e.g. prefix/suffix sums,min,max etc.
- Looping order e.g. knapsack dp

## Digit DP

- append leading zeroes to low_num

```
dp(idx, low_tight, high_tight, ...)
  if idx = n then
    // base case
    return
  endif

  low = 0
  high = 9
  if low_tight then low = low_num[idx]
  if high_tight then high = high_num[idx]

  loop i in [low...high]
    nlow_tight = low_tight
    nhigh_tight = high_tight
    if i > low then nlow_tight = 0
    if i < high then nhigh_tight = 0
    dp(idx+1, nlow_tight, nhi-tight, ...)
  endloop
```

- consider leading zeroes
  - state $size \rightarrow$ count of digits in the number
    ```
    nsize = size
    if i > 0 or size > 0
      nsize++
    ```
  - state $is\_zero \rightarrow$ whether the number is zero
    ```
    nis_zero = is_zero
    if is_zero and i > 0
      nis_zero = 0
    ```

## Bitmask DP

- Generate Submasks: `for(submask = mask; submask; submask = (submask-1) & mask)`
- Bipartite matching
  - iterate on one set
  - keep mask of other set
- Hamiltonian path: dp(current node, mask of visited nodes)
- Intraset matching
- Generating permutation with some cost
- Profile DP
- Submask Decomposition
  - Pre-compute for each submask using precomputed submasks