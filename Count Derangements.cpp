class Solution {
    public:
        int derangeCount(int n) {
            if(n<4)
                return n-1;
            int count=1, prevCount=0;
            for(int i=2; i<n; i++){
                const int nextCount=i*(count+prevCount);
                prevCount=count;
                count=nextCount;
            }
            return count;
        }
};
