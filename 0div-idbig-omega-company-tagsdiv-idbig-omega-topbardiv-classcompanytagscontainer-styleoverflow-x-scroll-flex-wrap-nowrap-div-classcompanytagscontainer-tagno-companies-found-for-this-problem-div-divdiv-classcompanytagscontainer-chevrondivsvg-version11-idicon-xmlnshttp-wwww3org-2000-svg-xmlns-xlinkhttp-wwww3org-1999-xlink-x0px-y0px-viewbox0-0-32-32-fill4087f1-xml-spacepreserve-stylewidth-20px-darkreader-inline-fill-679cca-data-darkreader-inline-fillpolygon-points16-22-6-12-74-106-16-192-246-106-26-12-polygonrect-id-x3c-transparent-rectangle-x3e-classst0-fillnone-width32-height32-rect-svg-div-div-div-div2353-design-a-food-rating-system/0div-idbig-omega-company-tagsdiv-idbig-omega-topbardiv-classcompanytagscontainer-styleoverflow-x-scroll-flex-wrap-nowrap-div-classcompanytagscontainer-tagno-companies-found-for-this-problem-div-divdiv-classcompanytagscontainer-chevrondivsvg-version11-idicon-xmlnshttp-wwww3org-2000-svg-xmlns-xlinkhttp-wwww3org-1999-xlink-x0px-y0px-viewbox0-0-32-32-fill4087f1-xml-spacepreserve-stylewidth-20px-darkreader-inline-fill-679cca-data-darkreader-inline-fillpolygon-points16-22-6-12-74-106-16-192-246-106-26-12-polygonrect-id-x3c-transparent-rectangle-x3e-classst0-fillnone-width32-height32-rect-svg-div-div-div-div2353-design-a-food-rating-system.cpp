class Compare{
    public : 
        bool operator()(pair<int,string> &a , pair<int,string> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
};


class FoodRatings {   
    
public:
    unordered_map<string,string> cusi;
    unordered_map<string,int> foodRating;
    unordered_map<string,set<pair<int,string>>> cfm;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            foodRating[foods[i]] = ratings[i];
            // cusi[cuisines[i]].push_back(foods[i]);
            cusi[foods[i]] = cuisines[i];
            cfm[cuisines[i]].insert({-ratings[i] , foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cusine = cusi[food];
        auto prev_it = cfm[cusine].find({-foodRating[food] , food});
        cfm[cusine].erase(prev_it);
        foodRating[food] = newRating;
        cfm[cusine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto highRateFood = *cfm[cuisine].begin();
        return highRateFood.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */