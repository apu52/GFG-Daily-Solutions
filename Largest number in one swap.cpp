class Solution {
  public:
    string largestSwap(string &s) {
        
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            int maxi=INT_MIN;
            int index=-1;
            for(int j=n-1;j>=i;j--){
                
                
                if(s[i]-'0'<s[j]-'0' && maxi<s[j]-'0'){
                    
                   
                   maxi=s[j]-'0';
                   
                   index=j;
                }
                
                
            }
            if(maxi!=INT_MIN){
               swap(s[i],s[index]);
            
            return s;  
            }
            
           
        }
        
        return s;
       
        
    }
};
