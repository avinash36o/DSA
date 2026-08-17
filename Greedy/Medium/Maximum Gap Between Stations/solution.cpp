class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size(), m=station.size(), ans=0;
        if(n==1)return 0;
        vector<int>left(n), right(n);

        //left
        int j=0;
        for(int i=0; i<m && j<n; i++){
            while(skill[j] != station[i]){
                i++;
            }
            left[j]=i;
            j++;
        }
        
        //right
        j=n-1;
        for(int i=m-1; i>=0 && j>=0; i--){
            while(skill[j] != station[i]){
                i--;
            }
            right[j]=i;
            j--;
        }

        for(int i=0; i<n-1; i++){
            ans=max(ans, right[i+1]-left[i]);
        }
        return ans;
    }
};