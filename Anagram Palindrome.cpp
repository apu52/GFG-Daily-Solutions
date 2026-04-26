class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int count[256]={0};
        for(int i=0;s[i];i++){
            count[s[i]]++;
        }
        int odd=0;
        for(int i=0;i<256;i++){
            if(count[i]%2 !=0 )odd++;
            if(odd>1)return false;
        }
        return true;
    }
};
