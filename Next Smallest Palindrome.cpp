class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
     if (n % 2 != 0) {
         bool ok = true;
         bool isPalindrom = true;
         int i = 0, j = n-1;
         while (i < j) {
             if (num[i] != num[j]) {
                 isPalindrom = false; break;
             }
             i++; j--;
         }
         if (isPalindrom) {
             ok = false;
         } else {
             int i = n/2-1, j = n/2+1;
             while (i >= 0) {
                 if (num[i] < num[j]) {
                     ok = false; break;
                 }
                 if (num[i] > num[j]) break;
                 i--; j++;
             }
         }
         if (ok) {
             vector <int> res;
             for (int i = 0; i <= n/2; i++) res.push_back(num[i]);
             for (int i = n/2-1; i >= 0; i--) res.push_back(num[i]);
             return res;
         }
         
         int perenos = 1;
         for (int i = n/2; i >= 0 && perenos == 1; i--) {
             int val = num[i] + perenos;
             num[i] = val % 10;
             perenos = val / 10;
         }
         if (perenos == 1) {
             vector <int> res;
             res.push_back(1);
             for (int i = 0; i < n-1; i++) {
                 res.push_back(0);
             }
             res.push_back(1);
             return res;
         } else {
             vector <int> res;
             for (int i = 0; i <= n/2; i++) res.push_back(num[i]);
             for (int i = n/2-1; i >= 0; i--) res.push_back(num[i]);
             return res;
         }
     } else {
         bool ok = true;
         bool isPalindrom = true;
         int i = 0, j = n-1;
         while (i < j) {
             if (num[i] != num[j]) {
                 isPalindrom = false; break;
             }
             i++; j--;
         }
         if (isPalindrom) {
             ok = false;
         } else {
             int i = n/2-1, j = n/2;
             while (i >= 0) {
                 if (num[i] < num[j]) {
                     ok = false; break;
                 }
                 if (num[i] > num[j]) break;
                 i--; j++;
             }
         }
         if (ok) {
             vector <int> res;
             for (int i = 0; i <= n/2-1; i++) res.push_back(num[i]);
             for (int i = n/2-1; i >= 0; i--) res.push_back(num[i]);
             return res;
         }         
         int perenos = 1;
         for (int i = n/2-1; i >= 0 && perenos == 1; i--) {
             int val = num[i] + perenos;
             num[i] = val % 10;
             perenos = val / 10;
         }
         if (perenos == 1) {
             vector <int> res;
             res.push_back(1);
             for (int i = 0; i < n-1; i++) {
                 res.push_back(0);
             }
             res.push_back(1);
             return res;
         } else {
             vector <int> res;
             for (int i = 0; i <= n/2-1; i++) res.push_back(num[i]);
             for (int i = n/2-1; i >= 0; i--) res.push_back(num[i]);
             return res;
         }
     }
     
     return {};        
    }
};
