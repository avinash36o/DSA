class Solution {
public:
    int binaryToNum(string s){
        int n=s.size(), factor=1, ans=0;
        for(int i=n-1; i>=0; i--){
            ans+=factor*(s[i]-'0');
            factor*=2;
        }
        cout<<ans<<" ";
        return ans;
    }

    int deciTobin(int n){
        int ans=0, power=1;
        while(n>0){
            int rem=n%2;
            n/=2;
            ans+=(rem*power);
            power*=10;
        }
        cout<<ans<<" ";
        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        int ans=0;
        string s1=to_string(deciTobin(nums[0])) + to_string(deciTobin(nums[1])) + to_string(deciTobin(nums[2]));
        string s2=to_string(deciTobin(nums[0])) + to_string(deciTobin(nums[2])) + to_string(deciTobin(nums[1]));
        string s3=to_string(deciTobin(nums[1])) + to_string(deciTobin(nums[0])) + to_string(deciTobin(nums[2]));
        string s4=to_string(deciTobin(nums[1])) + to_string(deciTobin(nums[2])) + to_string(deciTobin(nums[0]));
        string s5=to_string(deciTobin(nums[2])) + to_string(deciTobin(nums[0])) + to_string(deciTobin(nums[1]));
        string s6=to_string(deciTobin(nums[2])) + to_string(deciTobin(nums[1])) + to_string(deciTobin(nums[0]));

        ans=max({binaryToNum(s1), binaryToNum(s2), binaryToNum(s3), binaryToNum(s4), binaryToNum(s5),binaryToNum(s6)});
        return ans;
    }
};