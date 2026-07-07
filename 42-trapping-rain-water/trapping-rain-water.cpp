class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        int lmax = 0;
        int rmax = 0;
        int area = 0;
        while(low<high){
            lmax = max(lmax, height[low]);
            rmax = max(rmax, height[high]);

            if(lmax<rmax){
                area += lmax - height[low];
                low++;
            }
            else{
                area += rmax - height[high];
                high--;
            }
        }
        return area;
    }
};