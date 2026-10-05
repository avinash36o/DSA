# Third Maximum Number

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Array, Sorting |
| **Link** | [View Problem](https://leetcode.com/problems/third-maximum-number/) |
| **Runtime** | 0 ms |
| **Memory** | 12.8 MB |

## Problem Description

<p>You are given an integer array <code>nums</code>.</p>

<p>Return the <strong>third distinct maximum</strong> number in this array. If the third <strong>maximum</strong> does not exist, return the <strong>maximum</strong> number.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,3,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you find an <code>O(n)</code> solution?

##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅C++ 4 Different Approach Solution || In-Place Algorithm || Max heap || Set || Sorting || ✅
**Author**: [@ayushkr01](https://leetcode.com/ayushkr01/)
**Upvotes**: 89 👍
**Link**: [View Original Post](https://leetcode.com/problems/third-maximum-number/solutions/3343654/)

---

//---------------> \uD83D\uDC7B Pls Upvote if it is helpful for You \uD83D\uDC7B <-----------------//  
 # Intuition
- We can solve this Question Using Multiple Approach(Here I have Explained **4** Appraoch)
1. Sorting 
2. Ordered Set
3. Max heap
4. In Place 
 
 - **Pls see All the method for Clarity and the Last method is the**   **Best Optimal Solution** 
 - Time complexity O(n) 
 - Space Complexity O(1)

 #   Using Sorting 
  **Time Complexity --> Nlog(N)**
   **Space Complexity --> O(1)**
# Code
``` 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int third_maximun=0;
        for(int i=nums.size()-1 ;i>0;i--){
            if(nums[i]!=nums[i-1]){
                count++;
                third_maximum=nums[i];
            }
           else if(i==1 && nums[i]==nums[i-1]){
                count++;
                third_maximum=nums[i];
            }
            if(count>2){
                 return third_maximum;
           }
        }
        if(count+1==3 && nums[0]!=nums[1]){
           return nums[0]; //if first and second index element not same [1,2,2,3]
        }
        return nums[nums.size()-1];  // if 3rd maximum not exist return maximum
    }
};
```
   #   Using set  
  **Time Complexity --> O(N)**
  **Space Complexity --> O(N)**
# Code
``` 
class Solution {
public:
 int thirdMax(vector<int>& nums) {
           set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()>=3){   // when set size >=3 means 3rd Maximum exist(because set does not contain duplicate element)
            int Third_index_from_last=s.size()-3;
            auto third_maximum=next(s.begin(),Third_index_from_last);
            return *third_maximum;
        }
            return *--s.end(); // return maximum if 3rd maximum not exist
    }
};
```


 #   Using maxheap 
# Code
``` 
class Solution {
public:
 // build max heap 
    void maxhipify(vector<int>&nums,int n ,int i){
    int left=2*i+1;
    int right=2*i+2;
    int maximum=i;
    if(left<n && nums[left]>nums[i]){
        maximum=left;
    }
    if(right<n && nums[right]>nums[maximum] ){
        maximum=right;
    }
    if(maximum!=i){
        swap(nums[i],nums[maximum]);
        maxhipify(nums,n,maximum);
    }
}
// extract root element each time ( root is maximum element in maxheap  )
    void deleteRoot(vector<int>&nums,set<int>&s,int &n){
        int lastElement=nums[n-1];
        s.insert(nums[0]);
        nums[0]=lastElement;
        n=n-1;
        maxhipify(nums,n,0);
    }

 int thirdMax(vector<int>& nums) {
        if(nums.size()==1){            // when array size is 1
         return nums[0];   
        }
        if(nums.size()==2){               // when array size is 2
            return max(nums[0],nums[1]);
        }
        int n=nums.size();

        for(int i=nums.size()/2;i>=0;i--){    // build max heap 
            maxhipify(nums,n,i);
        }
        set<int>s;
        for(int i=0;i<nums.size();i++){   // extract root( maximum element each time )
            deleteRoot(nums,s,n);
        }
        if(s.size()<3){         //  3rd largest element does not exist 
            return *--s.end();
        }else{                 // set s size >=3 3rd largest element exist
                int index=s.size()-3; // 3rd maximum index (index start with 0 )
                // using next() function
                auto it = next(s.begin(), index);   
                return   *it;
        }
    }
};
```

# Best Solution In Place Algorithm
**Time Complexity O(n)
Space Complexity O(1)**
# Code
``` 
class Solution {
public:
 int thirdMax(vector<int>& nums) {
        if(nums.size()==1){           // when size of Array is 1
         return nums[0];   
        }
        if(nums.size()==2){           // When size of array is 2
            return max(nums[0],nums[1]);
        }
 // find First maximum element using *max_element() function
        int First_max=*max_element(nums.begin(),nums.end());   
	    int Second_max=INT_MIN;
        int Third_max=INT_MIN;
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(Second_max<nums[i] && nums[i]!=First_max){
                Second_max=nums[i];
                count1++;
            }
        }
// if Second maximum element does not exist return First maximum element
        if(count1==0) return First_max; 
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if((Third_max<nums[i] || nums[i]==INT_MIN) && ( nums[i]!=First_max &&  nums[i]!=Second_max)){
                Third_max=nums[i];
                count2++;
            }
        }
        if(count2>0){
            return Third_max;
        }else{
            return First_max;
        }
    }
};
```
---

\uD83D\uDC7B IF YOU LIKE THE SOLUTION THEN PLEASE UPVOTE MY SOLUTION BECAUSE IT GIVES ME MOTIVATION TO REGULARLY POST THE SOLUTION\uD83D\uDC7B*
![image.png](https://assets.leetcode.com/users/images/14a3ceaa-fd34-46b0-a334-3b2395d99d77_1679831064.7105706.png)



</details>
