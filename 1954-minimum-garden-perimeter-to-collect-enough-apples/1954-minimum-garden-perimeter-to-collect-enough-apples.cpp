class Solution {
public:
    vector<long long int> total;
    long long minimumPerimeter(long long apples) {
        long long int it = 1;
        long long int tmp = 0;
        while(tmp <= apples)
        {
           apples -= (it * it)*12;
            if( 0 >= apples) break;
            it++;
        }
    
        return it*8;
    }
};