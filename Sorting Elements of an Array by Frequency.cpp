class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
    unordered_map<int, int> mp;
    for(int num : arr) 
        mp[num]++;
    
    vector<pair<int, int>> freqVec;
    for(auto& it : mp) {
        freqVec.push_back({it.second, it.first});
    }
    
    // Sort by frequency descending, and by value ascending
    sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) 
            return a.second < b.second; // If frequencies are the same, sort by value ascending
        return a.first > b.first; // Sort by frequency descending
    });
    
    vector<int> result;
    for(auto& p : freqVec) {
        result.insert(result.end(), p.first, p.second);
    }
    
    return result;
}
};
