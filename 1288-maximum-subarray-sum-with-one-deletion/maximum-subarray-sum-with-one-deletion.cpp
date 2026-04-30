class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDel = arr[0];
        int oneDel = 0;
        int result = arr[0];

        for(int i=1; i<arr.size(); i++){
            oneDel = max(oneDel+arr[i], noDel);
            noDel = max(noDel+arr[i], arr[i]);

            result = max(result, max(oneDel, noDel));
        }
        return result;
    }
};