class Solution 
{ 
  public: 
    //Function to check if a string is Pangram or not. 
    bool checkPangram (string s) { 
        int n=s.length(); 
        map<char,bool>m; 
         
        transform(s.begin(), s.end(), s.begin(), ::tolower);  
         
        for(int i=0;i<n;i++) 
       { 
          int d=s[i]-'a'; 
          if(d>=0 && d<=26) 
            m[s[i]]=1; 
       } 
         
        return m.size()==26; 
    } 
 
};
