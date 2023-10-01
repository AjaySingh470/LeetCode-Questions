//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
        vector<string> ans;
    int dr[4] = {0,0,-1,+1};
    int dc[4] = {-1,+1,0,0};
    char pt[4] = {'L','R','U','D'};
    void solve(int i ,int j, string path , vector<vector<int>> &m)
    {
        if(i == m.size()-1 && j == m[0].size()-1)
        {
            ans.push_back(path);
            return;
        }
        m[i][j] = 0;
        for(int k=0;k<4;k++)
        {
            int nx = i+dr[k] , ny=j+dc[k];
            if(nx < m.size() && ny < m[0].size() && nx >= 0 && ny>=0 && m[nx][ny] == 1)
            { 
                path += pt[k];
                m[nx][ny] = 0;
                solve(nx,ny,path , m);
                path.pop_back();
                m[nx][ny] = 1;
            }
        }
    }
        
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return {"-1"};
        solve(0,0,"",m);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends