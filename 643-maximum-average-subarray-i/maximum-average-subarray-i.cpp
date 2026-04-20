class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int low = 0;
       int high = k-1;
       double avg = INT_MIN;
       double sum = 0;
       for(int i=0; i<k; i++){
        sum = sum + nums[i];
       }

       while(high<nums.size()){
        double presAvg = (double)sum/k;
        avg = max(avg, presAvg);
        high++;
        low++;
        if(high<nums.size()){
             sum = sum - nums[low-1] + nums[high];
        }

       } 
       return avg;
    }
};