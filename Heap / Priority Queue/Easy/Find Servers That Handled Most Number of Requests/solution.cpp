class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> freq(k, 0); // to store the freq of req resolved
        set<int> availableServers;//storing the avavilable servers
        for (int i = 0; i < k; i++) {
            availableServers.insert(i);
        }
        //storing the busy servers. time,idx
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        for(int i=0; i<arrival.size(); i++){
            int currTime=arrival[i];
            while(!pq.empty() && pq.top().first<=currTime){
                availableServers.insert(pq.top().second);
                pq.pop();
            }
            if (availableServers.empty()) {
                continue;
            }
            auto validServer=availableServers.lower_bound(i%k);
            if (validServer == availableServers.end()) {
                validServer = availableServers.begin();
            }
            freq[*validServer]++;
            pq.push({currTime+load[i], *validServer});
            availableServers.erase(validServer);
        }

        int maxFreq=0;

        for(int x: freq){
            maxFreq=max(maxFreq, x);
        }
        vector<int>ans;

        for(int i=0; i<k; i++){
            if(freq[i]==maxFreq){
                ans.push_back(i);
            }
        }
        return ans;
    }
};