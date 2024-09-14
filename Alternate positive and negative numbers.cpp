class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos,neg;
        for(auto i:arr){
            if(i>=0) pos.push_back(i);
            else neg.push_back(i);
        }
        arr.clear();
        
        while(!pos.empty() && !neg.empty()){
            arr.push_back(*pos.begin());
            pos.erase(pos.begin());
            arr.push_back(*neg.begin());
            neg.erase(neg.begin());
        }
        
        while(!pos.empty()){
            arr.push_back(*pos.begin());
            pos.erase(pos.begin());
        }
        
        while(!neg.empty()){
            arr.push_back(*neg.begin());
            neg.erase(neg.begin());
        }
        
    }
};
