# Q1. Count Consistent Subarrays I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | November 16, 2026 |
| **Link** | [View Problem](https://leetcode.com/problems/count-consistent-subarrays-i/) |
| **Runtime** | 4 ms |
| **Memory** | 29.9 MB |

## Problem Description

<p>You are given an integer array <code>nums</code>.</p>

<p>A <span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_e_" data-state="closed" class="">subarray</button></span> is called <strong>consistent</strong> if the <strong>bitwise AND</strong> of all its elements is equal to the <strong>minimum</strong> value of the subarray.</p>

<p>Return the number of <strong>consistent subarrays</strong> in <code>nums</code>.</p>

<p>&nbsp;</p>
<p><span class="float-right -my-0.5 ml-2 inline-flex select-none items-center" data-example-lang-controls=""><span role="group" class="inline-flex h-6 items-center rounded-sd-md bg-sd-muted p-0.5" data-example-lang-toggle=""><button type="button" aria-pressed="true" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-sd-border bg-sd-background text-sd-foreground">Original</button><button type="button" aria-pressed="false" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-transparent text-sd-muted-foreground hover:text-sd-foreground">C++</button></span></span><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,3,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>The following subarrays are consistent:</p>

<table style="border: 1px solid black; text-align: center;"><tbody><tr><th style="border: 1px solid black;">Subarray</th><th style="border: 1px solid black;">Values</th><th style="border: 1px solid black;">Bitwise AND</th><th style="border: 1px solid black;">Minimum Value</th></tr><tr><td style="border: 1px solid black;">nums[0..0]</td><td style="border: 1px solid black;">[5]</td><td style="border: 1px solid black;">5</td><td style="border: 1px solid black;">5</td></tr><tr><td style="border: 1px solid black;">nums[1..1]</td><td style="border: 1px solid black;">[3]</td><td style="border: 1px solid black;">3</td><td style="border: 1px solid black;">3</td></tr><tr><td style="border: 1px solid black;">nums[2..2]</td><td style="border: 1px solid black;">[1]</td><td style="border: 1px solid black;">1</td><td style="border: 1px solid black;">1</td></tr><tr><td style="border: 1px solid black;">nums[3..3]</td><td style="border: 1px solid black;">[2]</td><td style="border: 1px solid black;">2</td><td style="border: 1px solid black;">2</td></tr><tr><td style="border: 1px solid black;">nums[1..2]</td><td style="border: 1px solid black;">[3, 1]</td><td style="border: 1px solid black;">3 AND 1 = 1</td><td style="border: 1px solid black;">1</td></tr><tr><td style="border: 1px solid black;">nums[0..2]</td><td style="border: 1px solid black;">[5, 3, 1]</td><td style="border: 1px solid black;">5 AND 3 AND 1 = 1</td><td style="border: 1px solid black;">1</td></tr></tbody></table>

<p>Therefore, the number of consistent subarrays is 6.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>For every subarray, both the bitwise AND and the minimum value are equal to 1. Therefore, the answer is 6.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only subarray is <code>[0]</code>, whose bitwise AND and minimum value are both 0. Therefore, the answer is 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

