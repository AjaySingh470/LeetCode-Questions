class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        map<vector<int>,int> mp;
        for(int i=0;i<times.size();i++)
        {
            mp[times[i]] = i;
        }
        // first make chair empty and then allocate to new ones
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //
        // vector<int> chair(1e5 , false);
        set<int> st;
        int chair_count = 0;
        for(int i=0;i<times.size();i++)
        {
            int seat_alloc_no = -1;
            // first empty seats
            int enter_time = times[i][0];
            while( !pq.empty() and pq.top().first<=enter_time)
            {
                st.insert(pq.top().second);
                pq.pop();
            }
            // second allocate seats
            
            if(!st.empty())
            {
                seat_alloc_no = *st.begin();
                st.erase(st.begin());
            }
            else{
                seat_alloc_no = chair_count++;
            }
            
            
            int exit_time = times[i][1];
            if(mp[times[i]] == targetFriend)
            {
                return seat_alloc_no;
            }
            pq.push({exit_time, seat_alloc_no});
        }
        return 0;
        
        
        
    }
};