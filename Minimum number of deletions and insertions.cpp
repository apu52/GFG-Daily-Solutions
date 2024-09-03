class Solution{
  

 public:
 
 int dp[1000][1000];
 int n,m;
 
 int rec(int i, int j,string &str1, string &str2){
     if(i==n) return m-j;
     if(j==m) return n-i;
     
     
     if(dp[i][j]!=-1) return dp[i][j];
     
     int ans;
     if(str1[i]==str2[j]){
         ans= rec(i+1,j+1,str1,str2);
     }
     else{
         ans= 1+min(rec(i,j+1,str1,str2),rec(i+1,j,str1,str2));
     }
     
     return dp[i][j]=ans;
 }
 int minOperations(string str1, string str2) 
 { 
     // Your code goes here
     n= str1.size();
     m= str2.size();
     
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             dp[i][j]=-1;
         }
     }
     
     rec(0,0,str1,str2);
     
 } 
};
