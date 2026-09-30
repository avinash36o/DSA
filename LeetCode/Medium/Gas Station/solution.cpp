class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, currGas=0;
        int gasSum=0,costSum=0;
        
            for(int i=0; i<gas.size(); i++){
                gasSum+=gas[i];
            costSum+=cost[i];
            currGas=currGas+gas[i]-cost[i];
            if(currGas<0){
                currGas=0;
            start=i+1;
            }
        }
        return gasSum<costSum ? -1: start;
        
    }
};