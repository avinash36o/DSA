# Replace Elements with Greatest Element on Right Side

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 4, 2026 |
| **Tags** | Array |
| **Link** | [View Problem](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/) |
| **Runtime** | 5 ms |
| **Memory** | 72.7 MB |

## Approach

take the max till now backward

## Problem Description

<p>Given an array <code>arr</code>,&nbsp;replace every element in that array with the greatest element among the elements to its&nbsp;right, and replace the last element with <code>-1</code>.</p>

<p>After doing so, return the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [17,18,5,4,6,1]
<strong>Output:</strong> [18,6,6,6,1,-1]
<strong>Explanation:</strong> 
- index 0 --&gt; the greatest element to the right of index 0 is index 1 (18).
- index 1 --&gt; the greatest element to the right of index 1 is index 4 (6).
- index 2 --&gt; the greatest element to the right of index 2 is index 4 (6).
- index 3 --&gt; the greatest element to the right of index 3 is index 4 (6).
- index 4 --&gt; the greatest element to the right of index 4 is index 5 (1).
- index 5 --&gt; there are no elements to the right of index 5, so we put -1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [400]
<strong>Output:</strong> [-1]
<strong>Explanation:</strong> There are no elements to the right of index 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: With Explanation Comments: Time: 24 ms (63.84%), Space: 14.6 MB (69.38%)
**Author**: [@deleted_user](https://leetcode.com/deleted_user/)
**Upvotes**: 14 👍
**Link**: [View Original Post](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/solutions/2366624/)

---

**Like it? ->Upvote please!**

**Solution 1:**
\'\'\'
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        //base case: if there\'s only one element-> replace it with -1
        if(arr.size()==1){
            arr[0]=-1;
            return arr;
        }
        
        //loop over the whole array elements
        for(int i=0;i<arr.size();i++){
            //initialize the maximum variable with 0 in each step
            int max=0;
            //loop over the remainder array elements again
            for(int j=i+1;j<arr.size();j++)
                //get the largest value
                if(arr[j]>max)
                    max=arr[j];
            //replace the current value with the max one
            arr[i]=max;
        }
        
        //after that-> replace the last value with -1 & return the array
        arr[arr.size()-1]=-1;
        return arr;
    }
};
\'\'\'

**Solution 2:**

\'\'\'
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int maximum=-1;
        //loop over the whole array elements
        for(int i=arr.size()-1;i>=0;i--){
            //store the current value in a temp variable
            int temp=arr[i];
            //replace the current value with the maximum one & by default, the last element will be -1, as the initial value is it\'s
            arr[i]=maximum;
            //get the largest element by comparing
            maximum=max(maximum,temp);
        }

        //return the array elements
        return arr;
    }
};
\'\'\'


**Like it? ->Upvote please!**

</details>
