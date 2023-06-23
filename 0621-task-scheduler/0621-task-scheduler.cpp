class Solution {
public:
    int leastInterval(vector<char>& tasks, int N) {
         map<char , int> mp;
        // int res = 0;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it : mp)
             pq.push(it.second);
        
        int res = 0;
        while(!pq.empty())
        {
            int time =0 ;
            vector<int> tmp;
            for(int i=0;i<N+1;i++)
            {
                if(!pq.empty())
                {
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t : tmp)
            {
                if(t) pq.push(t);
            }
            res += pq.empty() ? time : (N+1);
        }
        return res;

    }
};