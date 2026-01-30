class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        
        queue<int> temp;
        
        int n=q.size()/2;
        int m=n;
        while(n){
            temp.push(q.front());
            q.pop();
            n--;
        }
        while(m){
            int temp1=q.front();
            q.pop();
            int temp2=temp.front();
            temp.pop();
            
            q.push(temp2);
            q.push(temp1);
            m--;
        }
        
    }
};
