# Minimum Number of Seconds to Make Mountain Height Zero

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 10, 2026 |
| **Tags** | Array, Math, Binary Search, Greedy, Heap (Priority Queue) |
| **Link** | [View Problem](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/) |
| **Runtime** | 9 ms |
| **Memory** | 29.1 MB |

## Approach

min time to do work is 0 max is 1e18. do binary search int time if work can be done ( sum of work that can be done by each worker >= height) in t time then we'll check for lesser time. 

## Problem Description

<p>You are given an integer <code>mountainHeight</code> denoting the height of a mountain.</p>

<p>You are also given an integer array <code>workerTimes</code> representing the work time of workers in <strong>seconds</strong>.</p>

<p data-end="203" data-start="76">Each worker may reduce the mountain's height by any <strong>non-negative integer</strong> amount. If worker <code data-end="170" data-start="167">i</code> reduces the height by <code data-end="196" data-start="193">x</code>, then:</p>

<ul data-end="415" data-start="208">
	<li data-end="275" data-section-id="66oopy" data-start="208">reducing the first unit of height takes <code data-end="266" data-start="250">workerTimes[i]</code> seconds,</li>
	<li data-end="340" data-section-id="9o9grm" data-start="278">reducing the second unit takes <code data-end="331" data-start="311">workerTimes[i] * 2</code> seconds,</li>
	<li data-end="348" data-section-id="1o23ba" data-start="343">...</li>
	<li data-end="413" data-section-id="1brl21f" data-start="351">reducing the <code data-end="369" data-start="366">x</code>-th unit takes <code data-end="404" data-start="384">workerTimes[i] * x</code> seconds.</li>
</ul>

<p data-end="516" data-start="418">The total time spent by worker <code data-end="452" data-start="449">i</code> is the sum of the times required for all <code data-end="497" data-start="494">x</code> units they reduce.&nbsp;As all workers operate simultaneously, the total time required is the <strong>maximum</strong> time spent by any worker.</p>

<p>Return an integer representing the <strong>minimum</strong> number of seconds required for the workers to make the height of the mountain 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">mountainHeight = 4, workerTimes = [2,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>One way the height of the mountain can be reduced to 0 is:</p>

<ul>
	<li>Worker 0 reduces the height by 1, taking <code>workerTimes[0] = 2</code> seconds.</li>
	<li>Worker 1 reduces the height by 2, taking <code>workerTimes[1] + workerTimes[1] * 2 = 3</code> seconds.</li>
	<li>Worker 2 reduces the height by 1, taking <code>workerTimes[2] = 1</code> second.</li>
</ul>

<p>Since they work simultaneously, the minimum time needed is <code>max(2, 3, 1) = 3</code> seconds.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">mountainHeight = 10, workerTimes = [3,2,2,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Worker 0 reduces the height by 2, taking <code>workerTimes[0] + workerTimes[0] * 2 = 9</code> seconds.</li>
	<li>Worker 1 reduces the height by 3, taking <code>workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12</code> seconds.</li>
	<li>Worker 2 reduces the height by 3, taking <code>workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12</code> seconds.</li>
	<li>Worker 3 reduces the height by 2, taking <code>workerTimes[3] + workerTimes[3] * 2 = 12</code> seconds.</li>
</ul>

<p>The number of seconds needed is <code>max(9, 12, 12, 12) = 12</code> seconds.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">mountainHeight = 5, workerTimes = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<p>There is only one worker in this example, so the answer is <code>workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= mountainHeight &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= workerTimes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= workerTimes[i] &lt;= 10<sup>6</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy Explaination || Binary Search || 100%
**Author**: [@Adishka15](https://leetcode.com/Adishka15/)
**Upvotes**: 18 👍
**Link**: [View Original Post](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/solutions/5818296/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
##### **Since the relationship between the height reduction and the time is monotonic, binary search takes advantage of this property by eliminating half of the possible values with each decision. This property is not utilized in linear search, which checks each value sequentially.**

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Optimization Problem:** We\'re trying to minimize the time it takes for workers to reduce the mountain height.
2. **Guessing Time:** For a guessed time t, we check if all workers can finish reducing the mountain in that time.
- If they can, we try for a smaller \uD835\uDC61.
- If they can\'t, we need a larger \uD835\uDC61.
3. **Search Range:** We search from 0 to a large number (like 1\uD835\uDC5218).
4. **Feasibility Check:** For each \uD835\uDC61.
- Calculate how much each worker can reduce the height using the formula for the sum of the first \uD835\uDC65 numbers.
- Stop when the total height reduced meets or exceeds the mountain height.
5. **Narrowing Down:** By repeating this process with binary search, we find the smallest feasible \uD835\uDC61 to reduce the mountain height to zero

# Complexity
- Time complexity: O(N*og(N))+O(N)\u2248 **O(N)**
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:

    bool canfind(long long t, int h, vector<int>& wt){
        long long totalH = 0;

        for (int w : wt) {
            long long left = 0, right = 1e6;
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                if (w * mid * (mid + 1) / 2 <= t) left = mid + 1;
                else right = mid - 1;
            }
            totalH += right;
            if (totalH >= h) return true;
        }
        return totalH >= h;
    }

    long long minNumberOfSeconds(int h, vector<int>& wt) {
        long long s=0, e=1e18;
        long long ans=0;

        while(s<=e){
            long long mid=s+(e-s)/2;
            if(canfind(mid, h, wt)){
                e=mid-1;
                ans=mid;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
```

</details>
