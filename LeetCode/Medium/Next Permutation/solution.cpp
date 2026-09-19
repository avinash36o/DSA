class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), pivotIdx;
        bool notPossible=false;
        if(n==1)return;

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                pivotIdx=i; break;
            }else if(i==0){
                notPossible=true;
            }
        }

        if(notPossible){
            int st=0, end=n-1;
            while(st<=end){
                swap(nums[st], nums[end]);
                st++; end--;
            }
            return;
        }
        int rightMostIdx;
        for(int i=n-1; i>=0; i--){
            if(nums[i]>nums[pivotIdx]){
                rightMostIdx=i; break;
            }
        }

        swap(nums[pivotIdx], nums[rightMostIdx]);
        int st=pivotIdx+1, end=n-1;

        while(st<=end){
            swap(nums[st], nums[end]);
            st++; end--;
        }
    }
};