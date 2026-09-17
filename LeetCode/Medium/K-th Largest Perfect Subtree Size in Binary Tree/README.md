# K-th Largest Perfect Subtree Size in Binary Tree

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 17, 2026 |
| **Tags** | Tree, Depth-First Search, Sorting, Binary Tree |
| **Link** | [View Problem](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/) |
| **Runtime** | 248 ms |
| **Memory** | 66.4 MB |

## Approach

get info from both side and if both side if balanced and have same size then it is a good node

## Problem Description

<p>You are given the <code>root</code> of a <strong>binary tree</strong> and an integer <code>k</code>.</p>

<p>Return an integer denoting the size of the <code>k<sup>th</sup></code> <strong>largest<em> </em>perfect binary</strong><em> </em><span data-keyword="subtree" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">subtree</button></span>, or <code>-1</code> if it doesn't exist.</p>

<p>A <strong>perfect binary tree</strong> is a tree where all leaves are on the same level, and every parent has two children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmpresl95rp-1.png" style="width: 400px; height: 173px;"></p>

<p>The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are <code>[3, 3, 1, 1, 1, 1, 1, 1]</code>.<br>
The <code>2<sup>nd</sup></code> largest size is 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,4,5,6,7], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmp_s508x9e-1.png" style="width: 300px; height: 189px;"></p>

<p>The sizes of the perfect binary subtrees in non-increasing order are <code>[7, 3, 3, 1, 1, 1, 1]</code>. The size of the largest perfect binary subtree is 7.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,null,4], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/10/14/tmp74xnmpj4-1.png" style="width: 250px; height: 225px;"></p>

<p>The sizes of the perfect binary subtrees in non-increasing order are <code>[1, 1]</code>. There are fewer than 3 perfect binary subtrees.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 2000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 2000</code></li>
	<li><code>1 &lt;= k &lt;= 1024</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy O(N) dfs traversal solution
**Author**: [@be_fighter](https://leetcode.com/be_fighter/)
**Upvotes**: 27 👍
**Link**: [View Original Post](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/solutions/5905494/)

---


# Approach
# Base Case:

1. If the root is NULL, it returns {true, 0}. This indicates that an empty subtree is considered perfect and its size is 0.
# Recursive Calls:

The function recursively checks the left and right subtrees by calling make_tree(root->left) and make_tree(root->right), storing the results in l and r.
# Check for Perfect Subtree:

If both left (l.first) and right (r.first) subtrees are perfect (true) and their sizes (l.second and r.second) are equal, it confirms that the current subtree rooted at root is also perfect.
# Calculate Subtree Size:

The size of this perfect subtree is calculated as l.second + r.second + 1 (1 for the root, and the sum of left and right subtree sizes).
# Store the Result:

The size s is added to the ans vector to track all perfect subtree sizes.
# Return:

The function returns {true, s}, indicating that this subtree is perfect and its size is s.
If the subtree is not perfect, it returns {false, 0}.

# Complexity
- Time complexity:
O(Nlogn)

- Space complexity:
O(N)

# Code
```cpp []
class Solution {
public:
    vector<int>ans;
    pair<bool,int>make_tree(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        pair<bool,int>l=make_tree(root->left);
        pair<bool,int>r=make_tree(root->right);

        if(l.first && r.first && l.second==r.second ){
            int s=l.second+r.second+1;
            ans.push_back(s);
            return {true,s};
        }

        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {

        if(root==NULL){
            return -1;
        }
        ans.clear();
        make_tree(root);

        sort(ans.begin(),ans.end(),greater<int>());

        if(ans.size()>=k){
            return ans[k-1];
        }
        return -1;
    }
};
```
```java []
import java.util.*;

class Solution {
    List<Integer> ans = new ArrayList<>();

    // Method to recursively check for perfect subtree and calculate its size
    public Pair<Boolean, Integer> makeTree(TreeNode root) {
        if (root == null) {
            return new Pair<>(true, 0);
        }

        Pair<Boolean, Integer> l = makeTree(root.left);
        Pair<Boolean, Integer> r = makeTree(root.right);

        if (l.getKey() && r.getKey() && l.getValue().equals(r.getValue())) {
            int s = l.getValue() + r.getValue() + 1;
            ans.add(s);
            return new Pair<>(true, s);
        }

        return new Pair<>(false, 0);
    }

    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }

        ans.clear();
        makeTree(root);

        Collections.sort(ans, Collections.reverseOrder());

        if (ans.size() >= k) {
            return ans.get(k - 1);
        }

        return -1;
    }

}

```
```python []
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.ans = []

    def make_tree(self, root):
        if root is None:
            return (True, 0)

        l = self.make_tree(root.left)
        r = self.make_tree(root.right)

        if l[0] and r[0] and l[1] == r[1]:
            s = l[1] + r[1] + 1
            self.ans.append(s)
            return (True, s)

        return (False, 0)

    def kthLargestPerfectSubtree(self, root, k):
        if root is None:
            return -1

        self.ans.clear()
        self.make_tree(root)

        self.ans.sort(reverse=True)

        if len(self.ans) >= k:
            return self.ans[k - 1]
        return -1

```
```javascript []
class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    constructor() {
        this.ans = [];
    }

    // Function to recursively check and calculate perfect subtree size
    makeTree(root) {
        if (root === null) {
            return [true, 0];
        }

        let l = this.makeTree(root.left);
        let r = this.makeTree(root.right);

        if (l[0] && r[0] && l[1] === r[1]) {
            let s = l[1] + r[1] + 1;
            this.ans.push(s);
            return [true, s];
        }

        return [false, 0];
    }

    kthLargestPerfectSubtree(root, k) {
        if (root === null) {
            return -1;
        }

        this.ans = [];
        this.makeTree(root);

        this.ans.sort((a, b) => b - a);

        if (this.ans.length >= k) {
            return this.ans[k - 1];
        }
        return -1;
    }
}

```
![c2d27b08-ffbe-4bc6-8b29-5fc4d8effd5f_1723775276.9029489.jpeg](https://assets.leetcode.com/users/images/67d4c577-4d03-4b9c-b295-b70a9c761a31_1728792685.7451727.jpeg)



</details>
