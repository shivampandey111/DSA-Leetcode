class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int r = k%n;
        reverse(nums.begin(), nums.begin()+n-r);
        reverse(nums.begin()+n-r, nums.end());
        reverse(nums.begin(), nums.end());
    }
};