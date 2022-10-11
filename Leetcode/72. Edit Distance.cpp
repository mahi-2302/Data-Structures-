class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector> dp(word1.length(),vector(word2.length(),-1));
    return minDis(0,0,word1,word2,dp);
  }
  int minDis(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){
      if(i1==s1.length()&&i2<s2.length()){
          return s2.length()-i2;
      }
      if(i2==s2.length()){
          return s1.length()-i1;
      }
      if(dp[i1][i2]!=-1){return dp[i1][i2];}

      if(s1[i1]==s2[i2]){
          return dp[i1][i2]=0+minDis(i1+1,i2+1,s1,s2,dp);
      }
      else{
         int inst=1+minDis(i1,i2+1,s1,s2,dp); 
         int del=1+minDis(i1+1,i2,s1,s2,dp);
         int rep=1+minDis(i1+1,i2+1,s1,s2,dp);
          return dp[i1][i2]=min({inst,del,rep});
      }

  }
};
