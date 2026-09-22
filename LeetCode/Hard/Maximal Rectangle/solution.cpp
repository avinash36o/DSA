class Solution {
public:
    int maxArea(vector<int> &arr) {
        int n=arr.size();
        vector<int> nse(n,n), pse(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                nse[st.top()]=i;
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++) ans=max(ans,(nse[i]-pse[i]-1)*arr[i]);
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        vector<int> rectangles(m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (matrix[i][j]=='1') {
                    rectangles[j]++;
                } else {
                    rectangles[j]=0;
                }
            }
            ans=max(ans,maxArea(rectangles));
        }
        return ans;
    }
};