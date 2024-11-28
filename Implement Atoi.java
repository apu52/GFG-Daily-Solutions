class Solution {
    public int myAtoi(String s) {
        // Your code here
        int sign = 1, res=0, i = 0;
        s=s.trim();
        if(i<s.length()&& (s.charAt(i)=='-'||s.charAt(i)=='+')){
            if(s.charAt(i)=='-')
                sign=-1;
            i++;
        }
        while(i<s.length()&&s.charAt(i)>='0'&& s.charAt(i)<='9'){
            int newNum = s.charAt(i)-'0';
            if(res>Integer.MAX_VALUE/10 || (res == Integer.MAX_VALUE/10 && newNum > 7))
                return sign==-1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            res=res*10+newNum;
            i++;
        }
        return res*sign;
    }
}
