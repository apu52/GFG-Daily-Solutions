class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0,  j = 0, dir = 0;
        
        while(i < n and j < m and i >= 0 and j >= 0) {
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                dir++;
            }
            
            dir %= 4;
            switch(dir) {
                case 0: j++; 
                        break;
                
                case 1: i++;
                        break;
                
                case 2: j--;
                        break;
                
                case 3: i--;
                        break;
            }
        }
        
        switch(dir) {
            case 1: return {i - 1, j};
            case 2: return {i, j + 1};
            case 3: return {i + 1, j};
        }
        
        return {i, j - 1};
    }
};
