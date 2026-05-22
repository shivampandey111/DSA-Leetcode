class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;

        while(row>=0 && col<(matrix[0].size())){
            int mid = matrix[row][col];
            if(mid==target) return true;
            if(mid<target){
                col++;
            }
            else{
                row--;
            }
        }
        return false;

    }
};