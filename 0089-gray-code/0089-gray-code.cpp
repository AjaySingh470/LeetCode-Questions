class Solution {
public:
    void recur(int i,int n,vector<int> &resut , bitset<32> &bits )
    {
      if( i == n) 
      {
        resut.push_back(bits.to_ulong());
        return;
      }
      recur(i+1,n,resut,bits);
        bits.flip(i);
      recur(i+1,n,resut,bits);
    }
    vector<int> grayCode(int n) {
        vector<int> resut;
      bitset<32> bt;
      recur(0,n,resut,bt);
      return resut;
    }
};