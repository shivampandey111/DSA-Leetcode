class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int low = 0;
        int mid = 1;
        if(arr.size()==1) return; 
        while(mid<arr.size()){
            if(arr[low]==0 & arr[mid]!=0){
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else{
                if(arr[low]==0 & arr[mid]==0){
                    mid++;
                }
                else{
                    low++;
                    mid++;
                }
            }
        }
    }
};