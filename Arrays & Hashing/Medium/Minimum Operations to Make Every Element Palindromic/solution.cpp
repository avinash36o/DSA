class Solution {
public:
    int nearest(int k, const vector<long long>& v) {
        int st = 0;
        int end = v.size() - 1;
        int ans = v.size(); 

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (v[mid] >= k) {
                ans = mid;     
                end = mid - 1; 
            } else {
                st = mid + 1;  
            }
        }
        return ans;
    }

    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        
        // Using 'static' so these persist across all test cases
        static vector<long long> evenPal, oddPal;
        static bool initialized = false;

        // Only run this heavy precomputation ONCE per execution
        if (!initialized) {
            for (int i = 0; i <= 100000; i++) {
                string s = to_string(i);
                
                // Odd length palindrome
                string left = s.substr(0, s.size() - 1);
                reverse(left.begin(), left.end());
                long long palindrome1 = stoll(s + left);

                // Even length palindrome
                string rev = s;
                reverse(rev.begin(), rev.end());
                long long palindrome2 = stoll(s + rev);

                // Separate by parity (even/odd values)
                (palindrome1 % 2 == 0) ? evenPal.push_back(palindrome1) : oddPal.push_back(palindrome1);
                (palindrome2 % 2 == 0) ? evenPal.push_back(palindrome2) : oddPal.push_back(palindrome2);
            }
            
            sort(evenPal.begin(), evenPal.end());
            sort(oddPal.begin(), oddPal.end());
            
            initialized = true; // Mark as done!
        }
        
        for (int i = 0; i < nums.size(); i++) {
            long long current_min = LLONG_MAX;
            
            if (nums[i] % 2 == 0) { // Search in evenPal
                int idx = nearest(nums[i], evenPal);
                
                if (idx < evenPal.size()) {
                    current_min = min(current_min, abs(nums[i] - evenPal[idx]) / 2);
                }
                if (idx > 0) {
                    current_min = min(current_min, abs(nums[i] - evenPal[idx - 1]) / 2);
                }
            } else { // Search in oddPal
                int idx = nearest(nums[i], oddPal);
                
                if (idx < oddPal.size()) {
                    current_min = min(current_min, abs(nums[i] - oddPal[idx]) / 2);
                }
                if (idx > 0) {
                    current_min = min(current_min, abs(nums[i] - oddPal[idx - 1]) / 2);
                }
            }
            ans += current_min;
        }
        return ans;
    }
};