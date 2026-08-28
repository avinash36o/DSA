// if swr root of a num is prime then num is special

class Solution {
public:
    bool isPrime(int n){
        if(n<2)return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0)return false;
        }
        return true;
    }

    int nonSpecialCount(int l, int r) {
        int specialCount=0;
        int num=sqrt(r);

        while(num*num>=l && num*num<=r){
            if(isPrime(num)){
                specialCount++;
            }
            num--;
        }
        return (r-l+1)-specialCount;
    }
};