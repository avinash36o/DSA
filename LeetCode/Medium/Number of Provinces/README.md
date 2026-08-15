# Number of Provinces

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 15, 2026 |
| **Tags** | Depth-First Search, Breadth-First Search, Union-Find, Graph Theory |
| **Link** | [View Problem](https://leetcode.com/problems/number-of-provinces/) |
| **Runtime** | 3 ms |
| **Memory** | 20.8 MB |

## Approach

each time you call another dfs(since you couldnt traverse all node in one dfs call), you increase the count by one.

## Problem Description

<p>There are <code>n</code> cities. Some of them are connected, while some are not. If city <code>a</code> is connected directly with city <code>b</code>, and city <code>b</code> is connected directly with city <code>c</code>, then city <code>a</code> is connected indirectly with city <code>c</code>.</p>

<p>A <strong>province</strong> is a group of directly or indirectly connected cities and no other cities outside of the group.</p>

<p>You are given an <code>n x n</code> matrix <code>isConnected</code> where <code>isConnected[i][j] = 1</code> if the <code>i<sup>th</sup></code> city and the <code>j<sup>th</sup></code> city are directly connected, and <code>isConnected[i][j] = 0</code> otherwise.</p>

<p>Return <em>the total number of <strong>provinces</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;">
<pre><strong>Input:</strong> isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;">
<pre><strong>Input:</strong> isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> is <code>1</code> or <code>0</code>.</li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Simple C++ Solution || Fully Explained at begineers level || Easy Understanding of UNION concept
**Author**: [@ajaykumar0](https://leetcode.com/ajaykumar0/)
**Upvotes**: 109 👍
**Link**: [View Original Post](https://leetcode.com/problems/number-of-provinces/solutions/873741/)

---

**TOPIC: UNION FIND
   NOT A BIG TASK :), JUST GO LINE BY LINE** 

       In union we just make any element leader of any group and make other elements as a group member.

**Let\'s say 1 and 2 are friend , and 2 and 3 are also friend 
Then indirectly 1 and 3 are also friends. We can say that 1,2,3 are in same group.**

How we will deal with it in UNION:

WE have given **n * n matrix** , then **maximum number of group will be n**, if nobody is friend of none.

Lets Say n=5
Now we mark all of them initially with -1, because at starting all are alone, all are self leader.
**At the end we will find -1 for those index which will be leader of any group**

 _INDEX :     **[ 1 ,  2 ,3 ,4 ,   5]**
VALUES: **[-1,-1,-1,-1,-1]**

Now **1 is friend of 2**, mark **2** as a leader , how can we do this, simple ,**point index 2 from 1**
 _INDEX :     **[ 1 ,  2 ,3 ,4 ,   5]**
VALUES: **[  2,-1,-1,-1, -1]**
Here how we will find leader ,start from index 1

**1 is pointing 2 , 1->2
2 is pointing -1, 2 is leader of group**


Now **2 is friend of 3**, Now **point 2 at index 3**
 _INDEX :     **[ 1 ,  2 ,3 ,4 ,   5]**
VALUES: **[  2 , 3,-1,-1, -1]**

**1 is pointing 2 , 1->2
2 is pointing 3 , 2->3
3 is pointing -1 , 3 is leader of group**


Now if we start finding **leader of 1 and 2** , then **3** is the leader (**COMMON LEADER: SAME GROUP**)

Now **4 is friend of 5**, Now **point 4 at index 5**
 _INDEX :     **[ 1 ,  2 ,3 ,4 ,   5]**
VALUES: **[  2 , 3,-1, 5, -1]**

At the end just count total number of parent nodes whose value is -1.
Now we have **two** groups **{1,2,3}** and **{4,5}** , NOW go to solution line by line :)
 
```
class Solution {
public:
    
    //It will be use to store groups
    vector<int> v;
    
    //Find the leader of any group in which x lies
    //if not lie in any group then it is self leader
    int parent(int x)
    {
        //self leader
        if(v[x]==-1) return x; 
        //find the leader of self parent
        return v[x]=parent(v[x]);
    }
    
    //Adding 2 friends in a group
    void _union(int a,int b)
    {
        //find the leader of both a and b
        int p_a=parent(a),p_b=parent(b);
        
        //if already in same group, i.e leader of both of them are same then return
        if(p_a==p_b) return; 
        /*
         if both of them are from different group then add both the groups 
         and make a single common group
         We can do this by -> leader of 1st group is member of 2nd group 
         and now main leader of whole group is leader of 2nd member
        */ 
        v[p_a]=p_b; //v[p_a] will store the index of leader of whole group
    }
    
    int findCircleNum(vector<vector<int>>& M) { 
        int n=M.size();
        v=vector<int> (n,-1);//there will be maximum n group, mark all as a leader
        
        //making group
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])  //if i is friend of j, add them in a group
                { 
                    //if i is in any group then add j in that group
                    //or vice-versa
                    _union(i,j);  //Add them in a group
                }
            }
        }
        int c=0; 
        
        //counting group
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1) c++; //counting total number of parents
        }
        return c; 
    }
};
```

***Time Complexity: O(N * N * log(N))
Space Complexity: O(N)***  

**We are traversing N * N size matrix and finding parent each time in vector  of size N
Using a vector to store parent of size N**




</details>
