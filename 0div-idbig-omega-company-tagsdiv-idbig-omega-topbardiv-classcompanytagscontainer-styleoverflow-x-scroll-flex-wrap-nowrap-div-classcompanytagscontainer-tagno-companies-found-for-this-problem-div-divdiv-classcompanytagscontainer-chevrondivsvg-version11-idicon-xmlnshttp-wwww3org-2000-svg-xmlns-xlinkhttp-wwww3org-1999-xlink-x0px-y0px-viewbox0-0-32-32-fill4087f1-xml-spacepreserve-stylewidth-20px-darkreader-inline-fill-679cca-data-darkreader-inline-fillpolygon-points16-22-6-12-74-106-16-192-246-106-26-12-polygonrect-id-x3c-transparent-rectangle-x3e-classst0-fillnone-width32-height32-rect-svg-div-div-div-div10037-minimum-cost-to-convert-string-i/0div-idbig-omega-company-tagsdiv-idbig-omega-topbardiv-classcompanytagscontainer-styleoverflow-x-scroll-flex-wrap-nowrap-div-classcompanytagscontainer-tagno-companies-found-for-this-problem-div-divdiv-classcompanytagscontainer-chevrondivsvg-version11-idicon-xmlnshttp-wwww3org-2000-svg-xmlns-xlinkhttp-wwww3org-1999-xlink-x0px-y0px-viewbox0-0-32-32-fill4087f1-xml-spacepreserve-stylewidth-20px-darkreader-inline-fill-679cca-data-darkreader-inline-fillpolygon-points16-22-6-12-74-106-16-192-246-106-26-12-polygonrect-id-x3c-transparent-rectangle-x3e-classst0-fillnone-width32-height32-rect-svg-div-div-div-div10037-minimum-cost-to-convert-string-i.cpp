class Solution {
public:
    #define INF 1e16
    
    const int mod = 1e9 + 7;
  vector<vector<long long>> floydWarshall(vector<vector<long long>>& graph, int numNodes) {
        vector<vector<long long>> distance = graph;

       

        for (int k = 0; k < numNodes; ++k) {
            for (int i = 0; i < numNodes; ++i) {
                for (int j = 0; j < numNodes; ++j) {
                    if (distance[i][k] != INF && distance[k][j] != INF &&
                        distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = (long long)(distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<numNodes;i++)
        {
            for(int j=0;j<numNodes;j++)
                if(distance[i][j] == INF)
                distance[i][j] = -1;
        }
        return distance;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<long long>> adj(26,vector<long long>(26,1e16));
        for(int i=0;i<n;i++){
            adj[original[i]-'a'][changed[i] - 'a'] = min(adj[original[i]-'a'][changed[i] - 'a'],(long long)cost[i]);
        }
        vector<vector<long long>> costs = floydWarshall(adj,26);
        long long costp = 0;
        for(int i=0;i<source.size();i++)
        {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(a != b) {
                if(costs[a][b] == -1) return -1;
                costp += costs[a][b];
            }
        }
        return costp;
    }
};