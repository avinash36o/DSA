# Maximum Multiplication Score

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 5, 2026 |
| **Tags** | Array, Dynamic Programming |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-multiplication-score/) |
| **Runtime** | 100 ms |
| **Memory** | 198.1 MB |

## Approach

keep and not keep dp. multiply with current b elem or not.

## Problem Description

<p>You are given an integer array <code>a</code> of size 4 and another integer array <code>b</code> of size <strong>at least</strong> 4.</p>

<p>You need to choose 4 indices <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, <code>i<sub>2</sub></code>, and <code>i<sub>3</sub></code> from the array <code>b</code> such that <code>i<sub>0</sub> &lt; i<sub>1</sub> &lt; i<sub>2</sub> &lt; i<sub>3</sub></code>. Your score will be equal to the value <code>a[0] * b[i<sub>0</sub>] + a[1] * b[i<sub>1</sub>] + a[2] * b[i<sub>2</sub>] + a[3] * b[i<sub>3</sub>]</code>.</p>

<p>Return the <strong>maximum</strong> score you can achieve.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]</span></p>

<p><strong>Output:</strong> <span class="example-io">26</span></p>

<p><strong>Explanation:</strong><br>
We can choose the indices 0, 1, 2, and 5. The score will be <code>3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong><br>
We can choose the indices 0, 1, 3, and 4. The score will be <code>(-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>a.length == 4</code></li>
	<li><code>4 &lt;= b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= a[i], b[i] &lt;= 10<sup>5</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Recursion -> Memoization -> Iterative
**Author**: [@_sxrthakk](https://leetcode.com/_sxrthakk/)
**Upvotes**: 43 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-multiplication-score/solutions/5788387/)

---

# Use an Important Base Case 
``` 
if(b.size()==4){
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
}
```
# Intuition
###### The problem involves selecting 4 indices from an array b such that the chosen indices are in increasing order, and you maximize a score computed using another array a. This problem can be approached using recursion, memoization, and an iterative (dynamic programming) solution. Let\'s go through each method:

# 1. Recursive Approach
###### **Intuition :** The recursive approach explores all possible ways to pick indices from b to calculate the score. At each step, we decide whether to include the current element from b and move to the next element in a, or skip the current element in b.

###### **Detailed Approach :**

- Define a helper function that takes the current index in a (i1) and the current index in b (i2).
- If i1 reaches the size of a, it means we\'ve chosen 4 elements, so return 0 (base case).
- If i2 exceeds the size of b, it means it\'s not possible to choose enough elements, so return a very small number (INT_MIN) to indicate an invalid path.
- Calculate two scenarios:
- Take the current element: Add a[i1] * b[i2] to the result of the next recursive call (i1 + 1 and i2 + 1).
- Not take the current element: Call the function with i1 unchanged and move to the next element in b (i2 + 1).
- Return the maximum of the "take" and "not take" scenarios.

###### **Time Complexity :** O(2^n) where n is the size of b because we make a decision at each element whether to take it or not.


# Code
```cpp []
long long helper(vector<int> &a, vector<int>& b, int i1, int i2){
    if(i1==a.size()) return 0;
    if(i2>=b.size()) return INT_MIN;

    long long int take=(long long)a[i1]*(long long)b[i2]+ helper(a,b,i1+1,i2+1);
    long long int not_take=helper(a,b,i1,i2+1);

    return max(take,not_take);
}

long long maxScore(vector<int>& a, vector<int>& b){
    return helper(a,b,0,0);
}
```
```Python []
def helper(a, b, i1, i2):
    if i1 == len(a):
        return 0
    if i2 >= len(b):
        return float(\'-inf\')
    
    take = a[i1] * b[i2] + helper(a, b, i1 + 1, i2 + 1)
    not_take = helper(a, b, i1, i2 + 1)
    
    return max(take, not_take)

def maxScore(a, b):
    return helper(a, b, 0, 0)
```

```Java []
class Solution {
    private long helper(int[] a, int[] b, int i1, int i2) {
        if (i1 == a.length) return 0;
        if (i2 >= b.length) return Integer.MIN_VALUE;

        long take = (long) a[i1] * b[i2] + helper(a, b, i1 + 1, i2 + 1);
        long notTake = helper(a, b, i1, i2 + 1);

        return Math.max(take, notTake);
    }

    public long maxScore(int[] a, int[] b) {
        return helper(a, b, 0, 0);
    }
}

```
# 2. Memoization Approach
###### **Intuition :** The recursive approach has overlapping subproblems, which leads to redundant calculations. Memoization stores the results of subproblems to avoid recomputation, improving efficiency.

###### **Detailed Approach :**
- Use a 2D vector v to store results of subproblems. v[i1][i2] represents the maximum score using elements from a[i1] and b[i2].
-If i1 reaches the size of a, return 0 (base case).
-If i2 exceeds the size of b, return -1e9 (invalid path).
-Check if the value is already computed (v[i1][i2] != -1). If so, return it.
- Calculate "take" and "not take" scenarios as in the recursive approach and store the maximum result in v[i1][i2].
###### **Time Complexity :** O(4 * n) = O(n) where n is the size of b because each subproblem is solved only once.

``` cpp []
long long helper(vector<int> &a, vector<int>& b,int i1,int i2,vector<vector<long long int>>& v){
    if(i1==a.size()) return 0;
    if(i2>=b.size()) return -1e9;
    if(v[i1][i2]!=-1) return v[i1][i2];

    long long int take=(long long)a[i1]*(long long)b[i2]+ helper(a,b,i1+1,i2+1,v);
    long long int not_take=helper(a,b,i1,i2+1,v);

    return v[i1][i2]=max(take,not_take);
    }

long long maxScore(vector<int>& a, vector<int>& b) {
    vector<vector<long long int>> v(4,vector<long long int>(b.size(),-1));

    return helper(a,b,0,0,v);
}
```

```Python []
def helper(a, b, i1, i2, memo):
    if i1 == len(a):
        return 0
    if i2 >= len(b):
        return float(\'-inf\')
    
    if memo[i1][i2] != -1:
        return memo[i1][i2]
    
    take = a[i1] * b[i2] + helper(a, b, i1 + 1, i2 + 1, memo)
    not_take = helper(a, b, i1, i2 + 1, memo)
    
    memo[i1][i2] = max(take, not_take)
    return memo[i1][i2]

def maxScore(a, b):
    memo = [[-1] * len(b) for _ in range(4)]
    return helper(a, b, 0, 0, memo)

```

```Java []
class Solution {
    private long helper(int[] a, int[] b, int i1, int i2, long[][] memo) {
        if (i1 == a.length) return 0;
        if (i2 >= b.length) return (long) -1e9;
        
        if (memo[i1][i2] != -1) return memo[i1][i2];
        
        long take = (long) a[i1] * b[i2] + helper(a, b, i1 + 1, i2 + 1, memo);
        long notTake = helper(a, b, i1, i2 + 1, memo);
        
        memo[i1][i2] = Math.max(take, notTake);
        return memo[i1][i2];
    }

    public long maxScore(int[] a, int[] b) {
        long[][] memo = new long[4][b.length];
        for (int i = 0; i < 4; i++) {
            Arrays.fill(memo[i], -1);
        }
        return helper(a, b, 0, 0, memo);
    }
}

```

# 3. Iterative (Bottom Up)
###### **Intuition :** Using dynamic programming, we build up the solution iteratively, which helps to avoid the overhead of recursive calls and stack memory.

###### **Detailed Approach :**
- Define a 2D DP array dp where dp[i1][i2] represents the maximum score using the first i1 elements from a and first i2 elements from b.
- Initialize the base case: dp[0][j] = 0 for all j, representing the scenario where no elements are chosen from a.
- Iterate over i1 (1 to 4) and i2 (1 to n), where n is the size of b.
- For each (i1, i2), calculate:
- **Take the current element :** Add a[i1-1] * b[i2-1] to dp[i1-1][i2-1].
- **Not take the current element :** Use dp[i1][i2-1].
- Update dp[i1][i2] with the maximum value between "take" and "not take".

###### **Time Complexity :** O(4 * n) = O(n) since we are iterating over i1 and i2.

```C++ []
long long maxScore(vector<int>& a, vector<int>& b) {
    int n=b.size();
    vector<vector<long long>> dp(5, vector<long long>(n+1,-1e9));

    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

     for(int i1=1;i1<=4;i1++){
        for(int i2=1;i2<=n;i2++){
            long long int take=-1e9;
            take=dp[i1-1][i2-1]+(long long)a[i1-1]*(long long)b[i2-1];
            long long int not_take=dp[i1][i2-1];

            dp[i1][i2]=max(take,not_take);
        }
    }

    return dp[4][n];
}
```

```Python []
def maxScore(a, b):
    n = len(b)
    dp = [[float(\'-inf\')] * (n + 1) for _ in range(5)]
    
    for j in range(n + 1):
        dp[0][j] = 0
    
    for i1 in range(1, 5):
        for i2 in range(1, n + 1):
            take = dp[i1 - 1][i2 - 1] + a[i1 - 1] * b[i2 - 1]
            not_take = dp[i1][i2 - 1]
            dp[i1][i2] = max(take, not_take)
    
    return dp[4][n]

```

```Java []
class Solution {
    public long maxScore(int[] a, int[] b) {
        int n = b.length;
        long[][] dp = new long[5][n + 1];
        
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        
        for (int i1 = 1; i1 <= 4; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                long take = dp[i1 - 1][i2 - 1] + (long) a[i1 - 1] * b[i2 - 1];
                long notTake = dp[i1][i2 - 1];
                dp[i1][i2] = Math.max(take, notTake);
            }
        }
        
        return dp[4][n];
    }
}

```


</details>
