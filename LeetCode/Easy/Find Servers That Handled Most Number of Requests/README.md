# Find Servers That Handled Most Number of Requests

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | November 9, 2026 |
| **Tags** | Array, Heap (Priority Queue), Simulation, Ordered Set |
| **Link** | [View Problem](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/) |
| **Runtime** | 148 ms |
| **Memory** | 122.7 MB |

## Approach

set will check the available servers and pq will store the busy servers

## Problem Description

<p>You have <code>k</code> servers numbered from <code>0</code> to <code>k-1</code> that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but <strong>cannot handle more than one request at a time</strong>. The requests are assigned to servers according to a specific algorithm:</p>

<ul>
	<li>The <code>i<sup>th</sup></code> (0-indexed) request arrives.</li>
	<li>If all servers are busy, the request is dropped (not handled at all).</li>
	<li>If the <code>(i % k)<sup>th</sup></code> server is available, assign the request to that server.</li>
	<li>Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the <code>i<sup>th</sup></code> server is busy, try to assign the request to the <code>(i+1)<sup>th</sup></code> server, then the <code>(i+2)<sup>th</sup></code> server, and so on.</li>
</ul>

<p>You are given a <strong>strictly increasing</strong> array <code>arrival</code> of positive integers, where <code>arrival[i]</code> represents the arrival time of the <code>i<sup>th</sup></code> request, and another array <code>load</code>, where <code>load[i]</code> represents the load of the <code>i<sup>th</sup></code> request (the time it takes to complete). Your goal is to find the <strong>busiest server(s)</strong>. A server is considered <strong>busiest</strong> if it handled the most number of requests successfully among all the servers.</p>

<p>Return <em>a list containing the IDs (0-indexed) of the <strong>busiest server(s)</strong></em>. You may return the IDs in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/08/load-1.png" style="width: 389px; height: 221px;">
<pre><strong>Input:</strong> k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
<strong>Output:</strong> [1] 
<strong>Explanation:</strong> 
All of the servers start out available.
The first 3 requests are handled by the first 3 servers in order.
Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> 
The first 3 requests are handled by first 3 servers.
Request 3 comes in. It is handled by server 0 since the server is available.
Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> k = 3, arrival = [1,2,3], load = [10,12,11]
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong> Each server handles a single request, so they are all considered the busiest.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrival.length, load.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arrival.length == load.length</code></li>
	<li><code>1 &lt;= arrival[i], load[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>arrival</code> is <strong>strictly increasing</strong>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Segment Tree Approach
**Author**: [@projjwalraj707](https://leetcode.com/projjwalraj707/)
**Upvotes**: 1 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/solutions/5236345/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
For any request which arrives at `arrival[i]`, we need to find the first server starting from $$server_{(i\\%k)}$$ till the last server which becomes free at or before time `arrival[i]`.

# Approach
<!-- Describe your approach to solving the problem. -->
Create a SegTree which stores the point of time when each of the server becomes free. For example, if a server was alloted task $$i$$, then it would become free at $$arrival[i]+load[i]$$. Initialize all nodes of the segment tree with all zeros. Also implement a function `findServer(int l, int r, int target)` which finds the first server starting from $$server_l$$ till $$server_r$$ which becomes free on or before the `target` time. 


# Code
```
class SegTree {
public:
    int s, e, mini;
    SegTree* lChild, *rChild;
    SegTree(int l, int r) {
        s = l;
        e = r;
        if (s == e) {
            lChild = rChild = NULL;
            mini = 0;
        }
        else {
            int mid = (s+e)/2;
            lChild = new SegTree(s, mid);
            rChild = new SegTree(mid+1, e);
        }
    }
    void update(int ind, int newVal) {
        if (s == e) {
            mini = newVal;
        }
        else {
            int mid = (s+e)/2;
            if (ind<=mid) lChild->update(ind, newVal);
            else rChild->update(ind, newVal);
            mini = min(lChild->mini, rChild->mini);
        }
    }
    int findServer(int l, int r, int target) {
        if (l>e || r<s) return -1;
        if (l<=s && r>=e) {
            if (mini > target) return -1;
            if (s == e) return s;
            if (lChild->mini <= target) return lChild->findServer(l, r, target);
            return rChild->findServer(l, r, target);
        }
        int temp = lChild->findServer(l, r, target);
        if (temp != -1) return temp;
        return rChild->findServer(l, r, target);
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        SegTree* st = new SegTree(0, k-1);
        unordered_map<int,int> endTime;
        vector<int> ans(k);
        for (int i=0; i<arrival.size(); i++) {
            int server = st->findServer(i%k, arrival.size()-1, arrival[i]);
            if (server == -1) server = st->findServer(0, i%k-1, arrival[i]);
            if (server != -1) {
                endTime[server] = arrival[i] + load[i];
                st->update(server, arrival[i]+load[i]);
                ans[server]++;
            }
        }
        int maxi = *max_element(ans.begin(), ans.end());
        vector<int> finalAns;
        for (int i=0; i<ans.size(); i++) if (ans[i] == maxi) finalAns.push_back(i);
        return finalAns;
    }
};
```

</details>
