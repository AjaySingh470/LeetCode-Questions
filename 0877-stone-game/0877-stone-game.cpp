class Solution {
public:
//     int dp[501][501];
//     int check(int i,int j,bool alice ,vector<int> &piles)
//     {
//         if(i>j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int left = 0 ;
//         if(alice)
//         {
//             left = max(piles[i] + check(i+1 , j , !alice , piles) , piles[j] + check(i , j-1 , !alice , piles));
//         }
//         else{
//             left = min(-piles[i] + check(i+1 , j , !alice , piles) , -piles[j] + check(i , j-1 , !alice , piles));
//         }
//         return dp[i][j] = left ;
//     }
    
    bool stoneGame(vector<int>& piles) {
                // memset(dp,0,sizeof(dp));
       return true;
    }
};