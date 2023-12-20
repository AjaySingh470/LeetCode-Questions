class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int n = prices.size();
        int mn = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mn = min(mn , prices[i]  + prices[j]);
            }
        }
        if(mn > money) return money;
        return money - mn;
        
            
    }
};