class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj = vector<vector<pair<int,int>>> (n);
        for(auto it:edges)
        {
          adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1] , edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>> , greater<pair<long long int,int>>> pq;
        pq.push({0,node1});
        vector<int> ans(100,INT_MAX);
      if(node1 == node2) return 0;
        while(!pq.empty())
        {
          int n = pq.size();
          for(int i=0;i<n;i++)
          {
            auto it = pq.top();
            pq.pop();
            for(auto iw : adj[it.second])
            {
              long long int dis = it.first + iw.second;
              if(dis < ans[iw.first])
              {
                ans[iw.first] = dis;
                pq.push({dis , iw.first});
              }
            }
          }
        }
      
      return (ans[node2] == INT_MAX) ? -1 : ans[node2];
      
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */