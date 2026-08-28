# Minimum Cost for Cutting Cake I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 28, 2026 |
| **Tags** | Array, Two Pointers, Dynamic Programming, Greedy, Sorting |
| **Link** | [View Problem](https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/) |
| **Runtime** | 0 ms |
| **Memory** | 29.8 MB |

## Approach

rowCount=1, colCount=1;

Use two pointers to iterate through the sorted horizontal and vertical cuts.
At each step, choose the cut with the highest cost.
If the chosen cut is horizontal, add its cost multiplied by the current column count to the result, then increment the row count.
If the chosen cut is vertical, add its cost multiplied by the current row count to the result, then increment the column count.

## Problem Description

<p>There is an <code>m x n</code> cake that needs to be cut into <code>1 x 1</code> pieces.</p>

<p>You are given integers <code>m</code>, <code>n</code>, and two arrays:</p>

<ul>
	<li><code>horizontalCut</code> of size <code>m - 1</code>, where <code>horizontalCut[i]</code> represents the cost to cut along the horizontal line <code>i</code>.</li>
	<li><code>verticalCut</code> of size <code>n - 1</code>, where <code>verticalCut[j]</code> represents the cost to cut along the vertical line <code>j</code>.</li>
</ul>

<p>In one operation, you can choose any piece of cake that is not yet a <code>1 x 1</code> square and perform one of the following cuts:</p>

<ol>
	<li>Cut along a horizontal line <code>i</code> at a cost of <code>horizontalCut[i]</code>.</li>
	<li>Cut along a vertical line <code>j</code> at a cost of <code>verticalCut[j]</code>.</li>
</ol>

<p>After the cut, the piece of cake is divided into two distinct pieces.</p>

<p>The cost of a cut depends only on the initial cost of the line and does not change.</p>

<p>Return the <strong>minimum</strong> total cost to cut the entire cake into <code>1 x 1</code> pieces.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]</span></p>

<p><strong>Output:</strong> <span class="example-io">13</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/04/ezgifcom-animated-gif-maker-1.gif" style="width: 280px; height: 320px;"></p>

<ul>
	<li>Perform a cut on the vertical line 0 with cost 5, current total cost is 5.</li>
	<li>Perform a cut on the horizontal line 0 on <code>3 x 1</code> subgrid with cost 1.</li>
	<li>Perform a cut on the horizontal line 0 on <code>3 x 1</code> subgrid with cost 1.</li>
	<li>Perform a cut on the horizontal line 1 on <code>2 x 1</code> subgrid with cost 3.</li>
	<li>Perform a cut on the horizontal line 1 on <code>2 x 1</code> subgrid with cost 3.</li>
</ul>

<p>The total cost is <code>5 + 1 + 1 + 3 + 3 = 13</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 2, n = 2, horizontalCut = [7], verticalCut = [4]</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Perform a cut on the horizontal line 0 with cost 7.</li>
	<li>Perform a cut on the vertical line 0 on <code>1 x 2</code> subgrid with cost 4.</li>
	<li>Perform a cut on the vertical line 0 on <code>1 x 2</code> subgrid with cost 4.</li>
</ul>

<p>The total cost is <code>7 + 4 + 4 = 15</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>horizontalCut.length == m - 1</code></li>
	<li><code>verticalCut.length == n - 1</code></li>
	<li><code>1 &lt;= horizontalCut[i], verticalCut[i] &lt;= 10<sup>3</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy Video Solution (Pictorial Explanation) 🔥 || How to 🤔 in Interview || Priority_queue
**Author**: [@ayushnemmaniwar12](https://leetcode.com/ayushnemmaniwar12/)
**Upvotes**: 18 👍
**Link**: [View Original Post](https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/solutions/5474149/)

---

***If you like the solution Please Upvote and subscribe to my youtube channel***

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Dry Run few examples and observe how you can calculate min operation cost



***Easy Video Explanation***
    
https://youtu.be/AEuvSLMJIzk

# Code


```C++ []
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
    priority_queue<pair<int, char>> cuts;
    for (int cost : horizontalCut) {
        cuts.push({cost, \'H\'});
    }
    for (int cost : verticalCut) {
        cuts.push({cost, \'V\'});
    }
    
    int horizontal_pieces = 1;
    int vertical_pieces = 1;
    
    long long total_cost = 0;
    
    while (!cuts.empty()) {
        auto cut = cuts.top();
        cuts.pop();
        
        int cost = cut.first;
        char cut_type = cut.second;
        if (cut_type == \'H\') {
            total_cost += (long long)(cost) * vertical_pieces;
            horizontal_pieces++;
        } else {
            total_cost += (long long)(cost) * horizontal_pieces;
            vertical_pieces++;
        }
    }

    return total_cost;
    }
};
```
```python []
import heapq

class Solution:
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        # Create a max-heap for cuts by negating the costs
        cuts = [(-cost, \'H\') for cost in horizontalCut] + [(-cost, \'V\') for cost in verticalCut]
        heapq.heapify(cuts)
        
        horizontal_pieces = 1
        vertical_pieces = 1
        
        total_cost = 0
        
        while cuts:
            cost, cut_type = heapq.heappop(cuts)
            cost = -cost  # Convert back to positive cost
            
            if cut_type == \'H\':
                total_cost += cost * vertical_pieces
                horizontal_pieces += 1
            else:
                total_cost += cost * horizontal_pieces
                vertical_pieces += 1
                
        return total_cost

```
```Java []
import java.util.PriorityQueue;
import java.util.List;
import java.util.Collections;

class Solution {
    public int minimumCost(int m, int n, List<Integer> horizontalCut, List<Integer> verticalCut) {
        PriorityQueue<int[]> cuts = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        
        for (int cost : horizontalCut) {
            cuts.add(new int[]{cost, \'H\'});
        }
        for (int cost : verticalCut) {
            cuts.add(new int[]{cost, \'V\'});
        }
        
        int horizontal_pieces = 1;
        int vertical_pieces = 1;
        
        long total_cost = 0;
        
        while (!cuts.isEmpty()) {
            int[] cut = cuts.poll();
            int cost = cut[0];
            char cut_type = (char) cut[1];
            
            if (cut_type == \'H\') {
                total_cost += (long) cost * vertical_pieces;
                horizontal_pieces++;
            } else {
                total_cost += (long) cost * horizontal_pieces;
                vertical_pieces++;
            }
        }
        
        return (int) total_cost;
    }
}


```

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
    O(N*log(N))
    

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
    O(N)

# ***If you like the solution Please Upvote and subscribe to my youtube channel***
***It Motivates me to record more videos***

*Thank you* \uD83D\uDE00

</details>
