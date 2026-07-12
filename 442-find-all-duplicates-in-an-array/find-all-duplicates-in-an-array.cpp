class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        int i = 0;
        while(i<n) {
            int idx = arr[i] - 1;
            if(arr[i] != arr[idx]) {
                swap(arr[i], arr[idx]) ;
            }
            else i++;
        }
        for(int i = 0; i<n; i++) {
            if(arr[i] != i+1) {
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};