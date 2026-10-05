class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>freq(1001,0);
        vector<int>ans;
        for(int x: arr1){
            freq[x]++;
        }

        for(int i=0; i<arr2.size(); i++){
            int curr=arr2[i];
            while(freq[curr]>0){
                ans.push_back(curr);
                freq[curr]--;
            }
        }

        for(int i=0; i<freq.size(); i++){
            while(freq[i]>0){
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};