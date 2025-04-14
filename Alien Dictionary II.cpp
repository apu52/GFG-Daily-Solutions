class Solution {
public:
    // Function to find the order of characters in the alien language
    string findOrder(vector<string> &words) {
        // Edge case: if there's only one word, return all unique characters in any order
        if (words.size() == 1) {
            string uniqueChars = "";
            unordered_set<char> seen;
            for (char c : words[0]) {
                if (seen.find(c) == seen.end()) {
                    seen.insert(c);
                    uniqueChars += c;
                }
            }
            return uniqueChars;
        }
        
        // Build a set of all characters
        unordered_set<char> chars;
        for (const string &word : words) {
            for (char c : word) {
                chars.insert(c);
            }
        }
        
        // Create adjacency list representation of the graph
        unordered_map<char, vector<char>> graph;
        // Initialize in-degree for each character
        unordered_map<char, int> inDegree;
        
        // Initialize graph and in-degree count
        for (char c : chars) {
            graph[c] = vector<char>();
            inDegree[c] = 0;
        }
        
        // Build the graph based on word comparisons
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            
            // Compare adjacent words and find the first differing character
            int minLen = min(word1.length(), word2.length());
            
            // Find the first different character between the two words
            bool foundDiff = false;
            for (int j = 0; j < minLen; j++) {
                if (word1[j] != word2[j]) {
                    // Add an edge from word1[j] to word2[j]
                    graph[word1[j]].push_back(word2[j]);
                    inDegree[word2[j]]++;
                    foundDiff = true;
                    break;
                }
            }
            
            // Check if word2 is a prefix of word1, which would be invalid
            if (!foundDiff && word1.length() > word2.length()) {
                return ""; // Invalid ordering
            }
        }
        
        // Perform topological sort using Kahn's algorithm
        queue<char> q;
        
        // Add all nodes with in-degree 0 to the queue
        for (auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        
        string result = "";
        
        // Process nodes in topological order
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            result += current;
            
            // Reduce in-degree of neighbors
            for (char neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we couldn't include all characters, there's a cycle
        if (result.length() != chars.size()) {
            return ""; // Cycle detected, no valid ordering
        }
        
        return result;
    }
};
