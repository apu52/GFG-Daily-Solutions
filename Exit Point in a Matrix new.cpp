class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        
        
    int n=mat.size();
    int m=mat[0].size();
    
    int dir=0;
    
//dir==0  means right;
//dir==1 means dowm
//dir==2 means  left
//dir==3 means up

   int i=0;
   int j=0;

while(i>=0 && j>=0 && i<n && j<m){
    
    if(mat[i][j]==1){
        
        mat[i][j]=0;
        
dir=(dir+1)%4;  //main thing matter as only moving right

    }
    
    if(dir==0){
        
        j++;
    
    }
    
    else if(dir==1){
        
        i++;
    }
    
    
    else if(dir==2){
        
        j--;
    }
    
    
    else if(dir==3){
        
        i--;
    }
}

if(i<0){
    
    i++;
}

if(j<0){
    
    j++;
}


if(i>=n){
    
    i--;
}


if(j>=m){
    
    j--;
}
   
   
   return {i,j};     
    }
};
