class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        int n = numCourses;
        vector<vector<int>> adj(n);

        vector<int> indeg(n,0);
	   
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
	    queue<int> q;
       
	    for(int i=0;i<n;i++)
	    {
	        if(indeg[i] == 0)
	        {
	            q.push(i);
	           
	        }
	    }
	    ///////////////////////////
        int cnt = 0;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
            cnt++;
	        for(auto it : adj[node])
	        {
	            indeg[it]--;
	            if(indeg[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
        if(cnt == n)
            return true;
        return false;
    }
};