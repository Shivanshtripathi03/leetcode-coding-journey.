class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m = matrix[0].size();
        vector<vector<int>> neww = matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (neww[i][j]==0){
                    for(int k=0;k<n;k++){
                        matrix[k][j] = 0;
                    }
                    for(int k=0;k<m;k++){
                        matrix[i][k] = 0;
                    }

                }

            }
        }
        
    }
};