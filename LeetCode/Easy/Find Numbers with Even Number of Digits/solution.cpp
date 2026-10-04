class Solution {
public:
    bool isEven(int n){
        string s=to_string(n);
        return s.size()%2==0;
    }

    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int x: nums){
            if(isEven(x)){
                ans++;
            }
        }
        return ans;
    }
};