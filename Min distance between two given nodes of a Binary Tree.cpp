class Solution{ 
    public: 
    /* Should return minimum distance between a and b 
    in a tree with given root*/ 
     
    int ans=0; 
    int solve(Node *root, int a, int b){ 
        if(!root) 
        return 0; 
        int left=solve(root->left,a,b); 
        int right=solve(root->right,a,b); 
         
        if(root->data==a || root->data==b){ 
            if(left|| right) 
            ans=max(left,right); 
            else 
            return 1; 
        } 
        else if(left&& right) 
        ans=left+right; 
         
         
        else if(left||right) 
        return max(left,right)+1; 
         
        return 0; 
         
    } 
    int findDist(Node* root, int a, int b) { 
        int a5s=solve(root,a,b); 
        return ans; 
    } 
};
