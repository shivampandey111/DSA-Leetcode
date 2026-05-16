class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size()-2;
        int res = -1;
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[arr.size()-1]>arr[high]){
            return arr.size()-1;
        }
        while(low<=high){
            int mid = (low+high)/2;

            if(arr[mid]<arr[mid-1]){
                res = mid;
                high = mid -1;
            }
            else if(arr[mid]<arr[mid+1]){
                low = mid +1;
                res = mid;
            }
            else{
                res = mid;
                break;
            }

        }
        return res;
    }
};