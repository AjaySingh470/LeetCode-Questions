class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=  asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i] < 0)
            {
                bool f = false;
                while(!st.empty() && st.top() <= abs(asteroids[i]))
                {
                    if(st.top() == abs(asteroids[i]))
                    {
                        f = true;
                        st.pop();
                    ans.pop_back();
                        break;
                    }
                    st.pop();
                    ans.pop_back();
                }
                if(st.empty() && !f)
                {
                    //
                    ans.push_back(asteroids[i]);
                }
                
            }
            else{
                st.push(asteroids[i]);
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};