class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>s;
        for(int x: nums)s.insert(x);

        for(int num: s){
            if(!s.count(num-1)){
                int curr=num;
                int length=1;
                while(s.count(curr+1)){
                    length++;
                    curr++;
                }
                longest=max(longest, length);
            }
        }
        return longest;
    }
};