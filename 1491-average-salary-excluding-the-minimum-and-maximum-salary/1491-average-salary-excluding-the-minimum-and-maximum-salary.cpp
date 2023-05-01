class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin() , salary.end());
        double is=0;
        for(int i=1;i<salary.size()-1;i++) is += salary[i];
        return is/(salary.size()-2);
    }
};