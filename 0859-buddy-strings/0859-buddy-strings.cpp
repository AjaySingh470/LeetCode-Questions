class Solution {
public:
    bool buddyStrings(string s, string goal) {
        map<char,int> mp,gl;
        if(s.size() != goal.size() || s.size() == 1 || goal.size() == 1) return false;
        for(auto i : s) mp[i]++;
        // // if(s == goal) return false;
        // for(auto i: goal)
        // {
        //     gl[i]++;
        //     if(mp[i] == 0) return false;
        // }
        // // cout<<2<<endl;
        // ///
        // // if(mp.size() == 1) return true;
        // if(s == goal)
        // {
        //     for(auto i : s) if(mp[i]>1) return true;
        //     return false;
        // }    
        // int cnt = 0;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i] != goal[i]) cnt++; 
        //     else if(mp[s[i]] != gl[goal[i]]) return false;
        // }
        // return cnt==2;
        if(s == goal)
        {
            for(auto i : s) if(mp[i]>1) return true;
            return false;
        }
        int i=-1,j=-1;
        for(int k=0;k<goal.size();k++)
        {
            if(s[k] != goal[k])
            {
                if(i == -1) i = k;
                else if(j == -1) j = k;
                else return false;
            }   
            
        }
        if(i == -1 || j == -1) return false;
        swap(s[i] , s[j]);
        return goal == s;
        
        
    }
};