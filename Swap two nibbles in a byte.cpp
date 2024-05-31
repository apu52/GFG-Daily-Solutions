class Solution {
  public:
    int swapNibbles(int n) {
        

        int a = n&15;
        int b = n&240;
        b=b>>4;
        a=a<<4;
        return a+b;
    }
};
