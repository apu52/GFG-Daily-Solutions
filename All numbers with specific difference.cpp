class Solution {
  public:
    virtual int digSumService(int x){
      if(x==0) return 0;
      return x%10 + digSumService(x/10);
    }
    
    virtual bool isValid(int x, int d){
      int digSum=digSumService(x);
      return (x-digSum)>=d;
    }
    
    virtual void getCountService(int s, int e, int n, int d, int &miniAns){
      if(s>e) return;
      
      int m=s+(e-s)/2;
      if(isValid(m, d)){ 
          miniAns=m;
          getCountService(s, m-1, n, d, miniAns);
          return;
      }
      getCountService(m+1, e, n, d, miniAns);
      return;      
    }
    
    virtual int getCount(int n, int d){
      if(d>=n) return 0;
      
      int miniAns=INT_MAX;
      getCountService(0, n, n, d, miniAns);
      
      if(miniAns==INT_MAX) return 0;
      
      return n-miniAns+1;
    }
    virtual ~Solution(){}
};
