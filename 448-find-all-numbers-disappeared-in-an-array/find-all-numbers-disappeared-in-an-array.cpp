class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        int i = 0;
        while(i<n) {
            int idx = arr[i] - 1;
            if(arr[i] != arr[idx]) {
                swap(arr[i], arr[idx]);
            }
            else i++;
        }
        for(int i = 0; i<n; i++){
            if(arr[i] != i+1) {
                res.push_back(i+1) ;
            }
        }
        return res;
    }
};