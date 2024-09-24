class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // define string size; and used letters count
        int n = p.size();
        int countS[26] = {0};
        int countP[26] = {0};
        char chP, chS;
        
        // fill counts p with letters counts
        for(int i=0; i<n; i++)
        {
            char chP = p[i] - 'a';
            countP[chP]++;
        }
        
        // iMin, lenMin - starting point and length of minimum substring
        int iMin = -1;
        int lenMin = s.size() + 1;
        // i starting position of checked substring
        int i = 0;
        // count charachters in s and in p
        int count = 0;
        
        // loop throug s characters, increasing end point of the substring
        for(int j=0; j<s.size(); j++)
        {
            chS = s[j] - 'a';
            // when characters match; countP should be greater than countS
            if(countP[chS] > countS[chS])
            {
                count++;
            }
            countS[chS]++;
           
            // when count reaches length of p, start increase i
            if(count == n)
            {
                // increase i as much as possible
                char ch = s[i] - 'a';
                while(countS[ch] > countP[ch])
                {
                    countS[ch]--;
                    i++;
                    ch = s[i] - 'a';
                }
                // check substring position
                int len = j - i + 1;
                if(len < lenMin)
                {
                    iMin = i;
                    lenMin = len;
                }
            }
        }
        
        // update the results
        if(iMin > -1)
       {
            return s.substr(iMin, lenMin);
        }
        else
        {
            return "-1";
        }
    }
};
