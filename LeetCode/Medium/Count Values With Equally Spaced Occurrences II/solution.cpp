class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, vector<int>> map;
        unordered_map<int, int> isValid;
        for (int i = 0; i < nums.size(); i++) {
            int x=nums[i];
            if((map[x]).size()==0 || (map[x]).size()==1){
                map[x].push_back(i);
            }
            else{
                int n=map[x].size();
                if(isValid[x]==0 && ((map[x])[n-1] - (map[x])[n-2] == i - (map[x])[n-1])){
                    map[x].push_back(i);
                }else{
                    isValid[x]=1;
                }
            }
        }
        for(auto x: map){
            int num=x.first;
            if(map[num].size()>=3 && isValid[num]==0)ans++;
        }
        return ans;
    }
};