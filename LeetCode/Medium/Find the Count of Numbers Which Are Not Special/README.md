# Find the Count of Numbers Which Are Not Special

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 28, 2026 |
| **Tags** | Array, Math, Number Theory |
| **Link** | [View Problem](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/) |
| **Runtime** | 48 ms |
| **Memory** | 8.5 MB |

## Approach

a num has only 1, root(num), nums as divisor if root(num) is a prime num

## Problem Description

<p>You are given 2 <strong>positive</strong> integers <code>l</code> and <code>r</code>. For any number <code>x</code>, all positive divisors of <code>x</code> <em>except</em> <code>x</code> are called the <strong>proper divisors</strong> of <code>x</code>.</p>

<p>A number is called <strong>special</strong> if it has exactly 2 <strong>proper divisors</strong>. For example:</p>

<ul>
	<li>The number 4 is <em>special</em> because it has proper divisors 1 and 2.</li>
	<li>The number 6 is <em>not special</em> because it has proper divisors 1, 2, and 3.</li>
</ul>

<p>Return the count of numbers in the range <code>[l, r]</code> that are <strong>not</strong> <strong>special</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">l = 5, r = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>There are no special numbers in the range <code>[5, 7]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">l = 4, r = 16</span></p>

<p><strong>Output:</strong> <span class="example-io">11</span></p>

<p><strong>Explanation:</strong></p>

<p>The special numbers in the range <code>[4, 16]</code> are 4 and 9.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= l &lt;= r &lt;= 10<sup>9</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Sieve of Eratosthenes
**Author**: [@fahad84](https://leetcode.com/fahad84/)
**Upvotes**: 55 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/solutions/5546339/)

---

# Intuition
- To determine which numbers in the range [l,r] are not special, we need to identify which numbers are special. A number is special if it has exactly two proper divisors. For a number to have exactly two proper divisors, it must be the square of a prime number. This is because the divisors of such a number p^2 (where p is a prime) are 1, p and p^2 with 1 and p being the proper divisors.
-  For example, 9 = 3^2 is special because it has proper divisors 1 and 3.

# Approach
1. **Find Upper Limit for Primes:** We only need to find primes up to sqrt(r) because we are interested in their squares, which should fall within the range [l, r].
2. **Generate Primes Using Sieve of Eratosthenes:** Create an array to mark non-prime numbers up to sqrt(r). The Sieve of Eratosthenes is used for this purpose.
3. **Identify Special Numbers:** Iterate through the primes generated. For each prime p, check if p^2 falls within the range [l, r]. If it does, it\'s a special number.
4. **Count Non-Special Numbers:** Calculate the total numbers in the range [l, r] and finally Subtract the count of special numbers from the total to get the count of non-special numbers.

# Complexity
- Let **n = sqrt(r)**
- Time complexity: $$O(nloglogn)$$

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```C++ []
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // Calculate the limit up to which we need to find prime numbers
        int lim = (int)(sqrt(r));

        // Create a boolean array to mark primes up to lim using Sieve of Eratosthenes
        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i <= lim; i++) {
            if (v[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    v[j] = false;
                }
            }
        }

        // Count special numbers in the range [l, r]
        int cnt = 0;
        for (int i = 2; i <= lim; i++) {
            if (v[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    cnt++;
                }
            }
        }

        // Total numbers in the range [l, r]
        int totalCount = r - l + 1;

        // Calculate non-special numbers
        return totalCount - cnt;
    }
};

```
```Java []
class Solution {
    public int nonSpecialCount(int l, int r) {
        // Calculate the limit up to which we need to find prime numbers
        int lim = (int) Math.sqrt(r);
        
        // Create an array to mark primes up to lim using Sieve of Eratosthenes
        boolean[] isPrime = new boolean[lim + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i <= lim; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count special numbers in the range [l, r]
        int specialCount = 0;
        for (int i = 2; i <= lim; i++) {
            if (isPrime[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    specialCount++;
                }
            }
        }

        // Total numbers in the range [l, r]
        int totalCount = r - l + 1;

        // Calculate non-special numbers
        return totalCount - specialCount;
    }
}
```
```Python3 []
class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        # Calculate the limit up to which we need to find prime numbers
        lim = int(math.sqrt(r))
        
        # Create a list to mark primes up to lim using Sieve of Eratosthenes
        is_prime = [True] * (lim + 1)
        is_prime[0] = is_prime[1] = False # 0 and 1 are not prime numbers

        # Sieve of Eratosthenes to mark non-prime numbers
        for i in range(2, int(math.sqrt(lim)) + 1):
            if is_prime[i]:
                for j in range(i * i, lim + 1, i):
                    is_prime[j] = False

        # Count special numbers in the range [l, r]
        special_count = 0
        for i in range(2, lim + 1):
            if is_prime[i]:
                square = i * i
                if l <= square <= r:
                    special_count += 1

        # Total numbers in the range [l, r]
        total_count = r - l + 1

        # Calculate non-special numbers
        return total_count - special_count
```

# Note
- Can also be solved in O(1) space by iterating till sqrt(r) and checking if the number is prime and it\'s square lies in the range [l, r].
- Time complexity of which would be O(sqrt(r)*sqrt(r)) = O(r)
*However, this is an upper bound, and the actual complexity will be somewhat less.*



</details>
