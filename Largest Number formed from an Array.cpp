class Solution{
public:
   static bool cmp(string a,string b){
       return a+b>b+a;
   }
    string printLargest(int n, vector<string> &arr) {
        sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }
        while(ans[0]=='0' && ans.length()>1) ans.erase(0,1);
        return ans;
    }
};
