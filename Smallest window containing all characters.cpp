class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.size();
        int m = p.size();
        
        vector<int> hash(26);
        for(int i=0;i<m;i++){
            hash[p[i]-'a']++;
        }
        
        int l=0,r=0,mini=INT_MAX,ind=-1;
        int cnt=0;
        
        for(;r<n;r++){
            if(hash[s[r]-'a']>0) cnt++;
            hash[s[r]-'a']--;
            
            while(cnt==m){
                if(r-l+1<mini){
                    mini=r-l+1;
                    ind=l;
                }
                
                hash[s[l]-'a']++;
                if(hash[s[l]-'a']>0) cnt--;
                l++;
            }
        }
        
        if(mini==INT_MAX || ind==-1) return "";
        
        return s.substr(ind,mini);
    }
};
