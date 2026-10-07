class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos=haystack.find(needle);
        return (pos !=string::npos) ? pos : -1;



        // int n=haystack.size(), n2=needle.size();
        // for(int i=0; i<n; i++){
        //     if(haystack.substr(i,n2)==needle)return i;
        // }
        // return -1;


        // int st=0, end2=0;
        // for(int end=0; end<n; end++){
        //     if(haystack[end]==needle[end2] && end2==n2-1){
        //         return st;
        //     }
        //     else if(haystack[end]==needle[end2] && end2!=n2-1){
        //         end2++;
        //     }else{
        //         st=end;end2=0;
        //         if(haystack[st]==needle[end2]){
        //             end2++;
        //         }else{
        //             st++;
        //         }
        //         if(st>=n)return -1;
            // }
        //}
    }
};