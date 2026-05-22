class Solution {
public:
    int exists(vector<vector<int>>& matrix, int mid){
        int row = matrix.size()-1;
        int col = 0;
        int count = 0;
        while(row>=0 && col<matrix.size()){
            int curr = matrix[row][col];
            if(curr>mid){
                row--;
            }
            else{
                count = count + row + 1;
                col++;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int last = matrix.size()-1;
        int high = matrix[last][last];
        int res= 0;
        while(low<=high){
            int mid = (low + high)/2;
            int count = exists(matrix, mid);
            if(count<k){
                low = mid + 1;
            }
            else{
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};