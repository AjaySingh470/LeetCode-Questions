class Solution {
public:
    bool isPossible(int mid,vector<int> &house,vector<int> &heater)
    {
        int prevIdx=-1;
        for(int i=0;i<heater.size();i++)
        {
            int l = heater[i] - mid , r = heater[i] + mid;
            for(int j=prevIdx+1;j<house.size();j++)
            {
                if(house[j]>=l && house[j]<=r)
                {
                    prevIdx++;
                }
                else break;
            }
            if(prevIdx >= house.size()-1) return true;
        }
        return prevIdx >= house.size()-1;
        
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans = 0;
        for(int i=0;i<houses.size();i++)
        {
            auto nxt = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            int currRad = INT_MAX;
            if(nxt != heaters.end())
            {
                currRad = *nxt - houses[i];
            }
            if(nxt != heaters.begin())
            {
                nxt--;
                currRad = min(currRad ,  houses[i]-*nxt);
            }
            ans = max(ans , currRad);
        }
      return ans;
    }
};