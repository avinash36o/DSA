# Q1. Count Rotations With Exactly K Equal Adjacent Pairs

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 6, 2026 |
| **Link** | [View Problem](https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/) |
| **Runtime** | 18 ms |
| **Memory** | 21.3 MB |

## Approach

rotaed 1 element each time and check the score if score is equal to k then ans++

## Problem Description

<p>You are given a string <code>s</code> of length <code>n</code> and an integer <code>k</code>.</p>

<p>A <strong>cyclic rotation</strong> of <code>s</code> is obtained by choosing a <strong>prefix</strong> of <code>s</code> whose length is between 0 and <code>n - 1</code> (inclusive), and moving it to the end of the string while preserving the order of all characters.</p>

<p>For <strong>every</strong> cyclic rotation of <code>s</code>, let its <strong>score</strong> be the number of indices <code>i</code> such that <code>0 &lt;= i &lt; n - 1</code> and the characters at positions <code>i</code> and <code>i + 1</code> are equal.</p>

<p>Return the number of cyclic rotations of <code>s</code> whose score equals <code>k</code>.</p>

<p>A <strong>prefix</strong> of a string is a substring that starts from the beginning of the string and extends to any point within it.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string, which may be empty.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "aab", k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The cyclic rotations of <code>s</code> are:</p>

<ul>
	<li><code>"aab"</code>: The characters at positions 0 and 1 are equal, so <code>score = 1</code>.</li>
	<li><code>"aba"</code>: No two adjacent characters are equal, so <code>score = 0</code>.</li>
	<li><code>"baa"</code>: The characters at positions 1 and 2 are equal, so <code>score = 1</code>.</li>
</ul>

<p>Since <code>score</code> equals <code>k</code> for 2 cyclic rotations of <code>s</code>, the answer is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abca", k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The cyclic rotations of <code>s</code> are:</p>

<ul>
	<li><code>"abca"</code>: No two adjacent characters are equal, so <code>score = 0</code>.</li>
	<li><code>"bcaa"</code>: The characters at positions 2 and 3 are equal, so <code>score = 1</code>.</li>
	<li><code>"caab"</code>: The characters at positions 1 and 2 are equal, so <code>score = 1</code>.</li>
	<li><code>"aabc"</code>: The characters at positions 0 and 1 are equal, so <code>score = 1</code>.</li>
</ul>

<p>Since <code>score</code> equals <code>k</code> for only 1 cyclic rotation of <code>s</code>, the answer is 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == s.length &lt;= 100</code></li>
	<li><code>s</code> only consists of lowercase English letters.</li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
</ul>

