class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> grev[n];

        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                grev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:grev[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};