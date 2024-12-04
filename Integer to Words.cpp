class Solution {
public:
    // Arrays to store words for digits, tens, and powers of ten.
    vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                  "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                                  "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    // Function to convert a three-digit number to words.
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return belowTwenty[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return belowTwenty[num / 100] + " Hundred " + helper(num % 100);
    }
    
    string convertToWords(int n) {
        if (n == 0) return "Zero";
        
        string result = "";
        int i = 0;
        
        while (n > 0) {
            if (n % 1000 != 0) {
                result = helper(n % 1000) + thousands[i] + " " + result;
            }
            n /= 1000;
            i++;
        }
        
        // Remove any trailing spaces.
        while (result.back() == ' ') result.pop_back();
        
        return result;
    }
};
