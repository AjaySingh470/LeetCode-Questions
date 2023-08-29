class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0 , n = 0;
        for(auto it : customers)
        {
            if(it == 'Y')
                y++;
        }
        // if(y == customers.size()) return customers.size();
        vector<int> mp(1e5+1,-1);
        int mn = INT_MAX,idx = -1;
        for(int i=0;i<customers.size();i++)
        {
            int score = y + n;
            if(customers[i] == 'N') n++;
            else y--;
            if(mp[score]==-1)
            { 
                mp[score] = i;
                mn = min(mn,score);
            }
        }
        int score = y + n;
        if(mp[score] == -1)
        {
            mp[score] = customers.size();
            mn = min(mn,score);

        }
        // auto it = upper_bound(mp.begin(),mp.end(),-1);
        return mp[mn];
        
    }
};