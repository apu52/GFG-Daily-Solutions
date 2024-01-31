class Solution
{
    public:
        void insert(struct TrieNode *root, string key)
        {
            for(auto i : key){
                if(root -> children[i - 'a']){
                    root = root -> children[i - 'a'];
                }
                else{
                    TrieNode * new_node = getNode();
                    root -> children[i - 'a'] = new_node;
                    root = new_node;
                }
            }
            
            root -> isLeaf = 1;
        }
        
        bool search(struct TrieNode *root, string key) 
        {
            for(auto i : key){
                if(root -> children[i - 'a']){
                    root = root -> children[i - 'a'];
                }
                else{
                    return 0;
                }
            }
            
            return root -> isLeaf;
        }
};
