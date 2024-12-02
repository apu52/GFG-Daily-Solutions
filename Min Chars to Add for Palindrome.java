class Solution {
    public static int minChar(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String combined = s + "$" + rev; 
        int[] lps = computeLPSArray(combined); 
        return s.length() - lps[lps.length - 1]; 
    }

    
    private static int[] computeLPSArray(String str) {
        int n = str.length();
        int[] lps = new int[n];
        int length = 0; 
        int i = 1;

        while (i < n) {
            if (str.charAt(i) == str.charAt(length)) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
}
