class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;

        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                factors.push_back(p);

                // Remove all occurrences of p
                while (n % p == 0) {
                    n /= p;
                }
            }
        }

        // If n > 1, n itself is a prime factor
        if (n > 1) {
            factors.push_back(n);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> primes; // number and its prime
        unordered_map<int, int> primeFreq;      // prime number and freq
        int st = 0, ans=0;

        for(int i=0; i<nums.size(); i++){
            primes[nums[i]]=primeFactors(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int x : primes[nums[i]]) {
                primeFreq[x]++; // stored freq of each prime till now
            }
            while (primeFreq.size() > k) {
                for (int x : primes[nums[st]]) {
                    primeFreq[x]--; // remove the primes of st
                    if(primeFreq[x]==0){ //freq=0 means it shouldnt exist
                        primeFreq.erase(x);
                    }
                }
                st++;
            }
            if(st<=i){
                ans=max(ans,i-st+1);
            }
        }
        return ans;
    }
};