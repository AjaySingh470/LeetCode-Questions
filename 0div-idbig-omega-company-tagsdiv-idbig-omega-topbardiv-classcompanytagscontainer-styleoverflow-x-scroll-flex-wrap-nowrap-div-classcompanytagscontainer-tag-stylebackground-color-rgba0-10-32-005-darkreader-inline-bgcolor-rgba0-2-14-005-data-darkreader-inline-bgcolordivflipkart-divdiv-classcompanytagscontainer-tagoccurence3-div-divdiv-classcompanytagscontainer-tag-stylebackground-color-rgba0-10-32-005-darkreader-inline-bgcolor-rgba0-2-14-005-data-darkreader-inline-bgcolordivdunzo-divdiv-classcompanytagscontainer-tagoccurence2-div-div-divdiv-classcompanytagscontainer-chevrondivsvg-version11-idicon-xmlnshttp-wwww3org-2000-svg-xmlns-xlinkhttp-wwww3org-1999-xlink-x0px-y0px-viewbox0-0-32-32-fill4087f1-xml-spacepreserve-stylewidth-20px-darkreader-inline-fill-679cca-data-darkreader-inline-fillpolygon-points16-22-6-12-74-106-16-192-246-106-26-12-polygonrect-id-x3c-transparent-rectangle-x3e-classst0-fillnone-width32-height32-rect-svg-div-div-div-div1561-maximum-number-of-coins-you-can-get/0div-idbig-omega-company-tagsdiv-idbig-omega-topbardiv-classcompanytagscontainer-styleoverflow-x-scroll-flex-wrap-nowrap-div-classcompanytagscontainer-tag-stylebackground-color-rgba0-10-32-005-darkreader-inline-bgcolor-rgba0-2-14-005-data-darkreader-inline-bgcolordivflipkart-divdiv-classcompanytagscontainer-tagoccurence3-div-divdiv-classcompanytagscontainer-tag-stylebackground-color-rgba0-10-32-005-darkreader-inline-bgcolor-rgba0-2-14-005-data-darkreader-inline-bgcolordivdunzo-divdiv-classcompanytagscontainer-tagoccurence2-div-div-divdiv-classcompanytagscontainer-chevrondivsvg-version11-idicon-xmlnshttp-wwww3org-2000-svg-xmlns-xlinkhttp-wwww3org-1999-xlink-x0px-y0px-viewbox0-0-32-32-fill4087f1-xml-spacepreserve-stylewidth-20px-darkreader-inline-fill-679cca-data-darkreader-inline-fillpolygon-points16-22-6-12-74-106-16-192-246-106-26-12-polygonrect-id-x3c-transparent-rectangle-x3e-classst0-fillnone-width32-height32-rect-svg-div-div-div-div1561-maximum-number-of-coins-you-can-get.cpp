class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //  3 4 5 
        // 8 + 6 + 4
        int ans = 0;
        int n = piles.size();
        sort(piles.begin() , piles.end());
        int i=0,j=piles.size() - 2;
        while(i<j)
        {
            ans += piles[j];
            j -= 2;
            i++;
        }
        return ans;
    }
};