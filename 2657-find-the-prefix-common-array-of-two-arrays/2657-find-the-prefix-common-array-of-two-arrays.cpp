class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0),visA(n+1,0) , visB(n+1,0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
               
            visA[A[i]] = 1;
            visB[B[i]] = 1;
            if(visA[A[i]] == 1 && visB[A[i]] == 1)
                cnt++;
            if((A[i]!=B[i]) && visA[B[i]] == 1 && visB[B[i]] == 1)
                cnt++;
            ans[i] = cnt;
            // cout<<cnt<<" ";
        }
        // cout<<endl;
        return ans;
    }
};