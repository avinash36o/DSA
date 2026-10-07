class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size(), n2=t.size();
        int arr1[200]={};
        int arr2[200]={};

        for(int i=0; i<n1; i++){
            if(arr1[s[i]]!=arr2[t[i]])return false;
            arr1[s[i]]=i+1;
            arr2[t[i]]=i+1;
        }
        return true;
    }
};