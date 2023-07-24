class Solution {
public:
    double pw(long double x,long int n)
    {
        if(n==0) return 1.0000;
        if(n==1) return x;
        if(n>0){
            return x * pw(x,n/2);
        }
        else{
            n = abs(n);
            return x*pw(1/x,n/2);
        }
    }
    double myPow(double x, int n) {
        return pow(x,n);
    }
};