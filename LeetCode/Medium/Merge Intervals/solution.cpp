class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>>ans;
        int n=v.size(), i=0;

        while(i<n){
            int first=v[i][0];
            int second=v[i][1];
            i++;
            while(i<n && v[i][0]<=second){
                second=max(second, v[i][1]);
                i++;
            }
            ans.push_back({first, second});
        }
        return ans;
    }
};