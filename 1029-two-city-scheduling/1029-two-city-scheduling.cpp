class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<int> diff;
      int mcost = 0;
      for(auto it:costs)
      {
        mcost += it[0];
        diff.push_back(it[1] - it[0]);
      }
      sort(diff.begin() , diff.end());
      for(int i=0;i<costs.size()/2;i++)
      {
        mcost += diff[i];
      }
      return mcost;
        
    }
};