class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size() ; 
        int res = 0;
        int i = 0 ;
        while(i<n) {
            if(arr[i]>0 && arr[i]<=n) {
                int idx = arr[i] - 1;
                if(arr[i]!=arr[idx]) {
                    swap(arr[i], arr[idx]) ;
                }
                else i++;
            }
            else i++;
        }
        for(int i = 0; i<n; i++){
            if(arr[i] != i+1) {
                return i+1 ;
            };
        }
        return n+1;
    }
};