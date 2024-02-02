class Solution{ 
  public:  
    int atoi(string s) { 
         
        int ans = 0; 
        int isNegative = (s[0]=='-'); 
        for(int i=isNegative;i<s.length();i++){ 
            if(s[i]-'0'>=0 and s[i]-'0'<=9){ 
                ans = ans*10 + s[i]-'0'; 
            } 
            else{ 
                return -1; 
            } 
        } 
        return (isNegative)?-1*ans:ans; 
    } 
};
