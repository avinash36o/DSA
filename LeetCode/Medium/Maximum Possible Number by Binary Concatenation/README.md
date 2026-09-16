# Maximum Possible Number by Binary Concatenation

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 16, 2026 |
| **Tags** | Array, Bit Manipulation, Enumeration |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/) |
| **Runtime** | 0 ms |
| **Memory** | 26.5 MB |

## Approach

convert all three num into binary sort them on the basis of a+b>b+a. then concate them and convert them into decimal

## Problem Description

<p>You are given an array of integers <code>nums</code> of size 3.</p>

<p>Return the <strong>maximum</strong> possible number whose <em>binary representation</em> can be formed by <strong>concatenating</strong> the <em>binary representation</em> of <strong>all</strong> elements in <code>nums</code> in some order.</p>

<p><strong>Note</strong> that the binary representation of any number <em>does not</em> contain leading zeros.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3]</span></p>

<p><strong>Output:</strong> 30</p>

<p><strong>Explanation:</strong></p>

<p>Concatenate the numbers in the order <code>[3, 1, 2]</code> to get the result <code>"11110"</code>, which is the binary representation of 30.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,8,16]</span></p>

<p><strong>Output:</strong> 1296</p>

<p><strong>Explanation:</strong></p>

<p>Concatenate the numbers in the order <code>[2, 8, 16]</code> to get the result <code>"10100010000"</code>, which is the binary representation of 1296.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == 3</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 127</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅C++ || Beats 100% || Simple Brute Force || With Explanation
**Author**: [@Mrigyank_Roy](https://leetcode.com/Mrigyank_Roy/)
**Upvotes**: 16 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/solutions/5875697/)

---


# Approach
1. Binary Conversion: Each integer in nums is converted to binary.
2. Concatenation: All permutations of the binary strings are generated.
3. Decimal Conversion: Each concatenated binary string is converted back to decimal.
4. Maximization: The maximum decimal value from all permutations is returned.


# Code
```cpp []
class Solution {
public:
    // Num -> Binary
    string convert(int num) {
        if (num == 0) return "0";
        string binary = "";
        while (num > 0) {
            binary = (num%2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }

    // Binary -> int
    int decimal(string s){
        int res =0;
        for(int i=0; i < s.length(); i++) {
            res = res*2 + (s[i]-\'0\');
        }
        return res;
    }

    int maxGoodNumber(vector<int>& nums) {
        string a = convert(nums[0]);
        string b = convert(nums[1]);
        string c = convert(nums[2]);
        // Returning Max from all Permutations
        return max({
            decimal(a+b+c),
            decimal(a+c+b),
            decimal(b+a+c),
            decimal(b+c+a),
            decimal(c+a+b),
            decimal(c+b+a)
        });
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

```

</details>
