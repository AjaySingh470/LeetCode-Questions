class Solution {
public:
    vector<vector<int>> generate(int numr) {
       int len=0;
        vector<vector<int>> tri;
        cout<<"1";
        tri.push_back({{1}});
        
        for(int i=1;i<numr;i++)
        {
            vector<int> temp(i+1,0);
            temp[0] = 1;
            temp[i] = 1;
            cout<<"i="<<i<<" ";
            for(int j=1;j<i;j++)
            {
                 cout<<tri[i-1][j-1];
                temp[j] = tri[i-1][j-1] + tri[i-1][j];
               
            }
            cout<<endl;
            tri.push_back(temp);
            
            
        }
        
        return tri;
    }
};