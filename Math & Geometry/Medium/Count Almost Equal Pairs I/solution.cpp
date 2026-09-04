class Solution {
public:
    bool isEqual(int x, int y){
        string s1=to_string(x), s2=to_string(y);
        int n=s1.size(), m=s2.size();
        int maxLen=max(n,m);
        while(n !=maxLen){
            s1='0'+s1;
            n++;
        }
        while(m !=maxLen){
            s2='0'+s2;
            m++;
        }
        int diff=0;
        unordered_map<char,int>m1,m2;

        for(int i=0; i<maxLen; i++){
            diff+=(s1[i]!=s2[i]);
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        return diff<=2 && m1==m2;
    }

    int countPairs(vector<int>& nums) {
        int n=nums.size(), count=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                count+=isEqual(nums[i],nums[j]);
            }
        }
        return count;
    }
};