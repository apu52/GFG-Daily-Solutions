class Solution {
  public:
    virtual string profession(int level, int pos){
      int flips=0;
      pos--;
      for(int i=0; i<32; i++){
        if(pos & (1<<i)) flips++;  
      }
      
      return (flips % 2 == 0) ? "Engineer" : "Doctor";
    }
};
