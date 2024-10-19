class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        if(str.back() > '5'){
            for(int i = str.size()-2;i>=0;i--){
                if(++str[i] <='9'){
                    return str.substr(0,i+1)+'0'+string(str.size()-i-2,'0');
                }
                str[i]='0';
            }
            return '1' +string(str.size(),'0');
        }
        str.back() = '0';
        return str;
    }
};
