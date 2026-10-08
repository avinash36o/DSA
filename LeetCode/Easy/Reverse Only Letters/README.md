# Reverse Only Letters

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 8, 2026 |
| **Tags** | Two Pointers, String |
| **Link** | [View Problem](https://leetcode.com/problems/reverse-only-letters/) |
| **Runtime** | 0 ms |
| **Memory** | 8.1 MB |

## Problem Description

<p>Given a string <code>s</code>, reverse the string according to the following rules:</p>

<ul>
	<li>All the characters that are not English letters remain in the same position.</li>
	<li>All the English letters (lowercase or uppercase) should be reversed.</li>
</ul>

<p>Return <code>s</code><em> after reversing it</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "ab-cd"
<strong>Output:</strong> "dc-ba"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a-bC-dEf-ghIj"
<strong>Output:</strong> "j-Ih-gfE-dCba"
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "Test1ng-Leet=code-Q!"
<strong>Output:</strong> "Qedo1ct-eeLg=ntse-T!"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of characters with ASCII values in the range <code>[33, 122]</code>.</li>
	<li><code>s</code> does not contain <code>'\"'</code> or <code>'\\'</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [3 approaches][faster than 100%][easy understanding][c++]
**Author**: [@rajat_gupta_](https://leetcode.com/rajat_gupta_/)
**Upvotes**: 22 👍
**Link**: [View Original Post](https://leetcode.com/problems/reverse-only-letters/solutions/842716/)

---

```
//1.[faster than 100.00%][stack][Runtime: 0 ms]
class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char>letters;
        for (char c: s)
            if (isalpha(c))  letters.push(c);

        string ans;
        for (char c: s) {
            if (isalpha(c)){
                ans+=(letters.top());
                letters.pop();
            }else
                ans+=c;
        }
        return ans;
    }
};
//2.[faster than 100.00%][2 pointer][Runtime: 0 ms]
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left=0,right=s.length()-1;
        while(left<right){
            if(isalpha(s[left]) && isalpha(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }else if(!isalpha(s[left]) && !isalpha(s[right])){
                left++;
                right--;
            }else if(!isalpha(s[left])){
                left++;
            }else 
                right--;
        }
        return s;
    }
};
//3.[Runtime: 4 ms]
class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> res;
        map<int,char> m; 
        for(int i=0;i<s.size();i++){
            if(!isalpha(s[i])) m[i]=s[i];
            else res.push_back(s[i]);
        }
        reverse(res.begin(),res.end());
        for(auto i:m){
            res.insert(res.begin() +i.first, i.second);
        }
        string str(res.begin(), res.end());
        return str;
    }
};
```
**Feel free to ask any question in the comment section.**
I hope that you\'ve found the solution useful.
In that case, **please do upvote and encourage me** to on my quest to document all leetcode problems\uD83D\uDE03
Happy Coding :)


</details>
