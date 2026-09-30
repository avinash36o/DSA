# Merge k Sorted Lists

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | September 30, 2026 |
| **Tags** | Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort, Tournament Sort |
| **Link** | [View Problem](https://leetcode.com/problems/merge-k-sorted-lists/) |
| **Runtime** | 96 ms |
| **Memory** | 18.4 MB |

## Problem Description

<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted linked list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= lists[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> will not exceed <code>10<sup>4</sup></code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Sharing my straightforward C++ solution without data structure other than vector
**Author**: [@zxyperfect](https://leetcode.com/zxyperfect/)
**Upvotes**: 638 👍
**Link**: [View Original Post](https://leetcode.com/problems/merge-k-sorted-lists/solutions/10531/)

---

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

The second function is from Merge Two Sorted Lists. 

The basic idea is really simple. We can merge first two lists and then push it back. Keep doing this until there is only one list left in vector. Actually, we can regard this as an iterative divide-and-conquer solution.

</details>
