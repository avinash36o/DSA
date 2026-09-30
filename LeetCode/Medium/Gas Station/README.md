# Gas Station

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 30, 2026 |
| **Tags** | Array, Greedy |
| **Link** | [View Problem](https://leetcode.com/problems/gas-station/) |
| **Runtime** | 4 ms |
| **Memory** | 112.6 MB |

## Problem Description

<p>There are <code>n</code> gas stations along a circular route, where the amount of gas at the <code>i<sup>th</sup></code> station is <code>gas[i]</code>.</p>

<p>You have a car with an unlimited gas tank and it costs <code>cost[i]</code> of gas to travel from the <code>i<sup>th</sup></code> station to its next <code>(i + 1)<sup>th</sup></code> station. You begin the journey with an empty tank at one of the gas stations.</p>

<p>Given two integer arrays <code>gas</code> and <code>cost</code>, return <em>the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return</em> <code>-1</code>. If there exists a solution, it is <strong>guaranteed</strong> to be <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> gas = [1,2,3,4,5], cost = [3,4,5,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> gas = [2,3,4], cost = [3,4,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == gas.length == cost.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= gas[i], cost[i] &lt;= 10<sup>4</sup></code></li>
	<li>The input is generated such that the answer is unique.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ [C++]Easy solution with explaination in O(n) time complexity (BEATS 97%) ✅
**Author**: [@vishnoi29](https://leetcode.com/vishnoi29/)
**Upvotes**: 490 👍
**Link**: [View Original Post](https://leetcode.com/problems/gas-station/solutions/3011141/)

---

\uD83C\uDFA5\uD83D\uDD25 Exciting News! Join my Coding Journey! Subscribe Now! \uD83D\uDD25\uD83C\uDFA5

\uD83D\uDD17 Link in the leetcode profile 

New coding channel alert! \uD83D\uDE80\uD83D\uDCBB Subscribe to unlock amazing coding content and tutorials. Help me reach 1K subs to start posting more videos! Join now! \uD83C\uDF1F\uD83D\uDCAA

Thanks for your support! \uD83D\uDE4F
# Intuition
Here we will apply greedy approach

# Approach
In the question given that
**If there exists a solution, it is guaranteed to be unique**
-This lines clearly tells us that we have unique or no solution exists

*Here two cases are possible*
1. if our **total_gas is less than our total cost** in that case we can\'t complete our journey ,so will return -1
2. Now we have a unique solution that means single **starting_point** exists
3. To find that point we will **keep track of my current_gas+=gas[i]-cost[i]**
  - lets suppose at any index our current gas became negative so we can clearly say that till that index all the gas station between ith and starting point are bad,  starting point as well.
So, this means we can start trying at next gas_station on the i+1 station

# Complexity
- Time complexity:O(N)
- Space complexity:O(1)

# Code(C++)
```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            //for checking the total present gas at index i
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                starting_point=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};
```
If you really found my solution helpful **please upvote it**, as it motivates me to post such kind of codes.
Lets connect on [Linkdin](https://www.linkedin.com/in/mahesh-vishnoi-a4a47a193/) Or [Telegram](https://t.me/mahesh_vishnoi29)


</details>
