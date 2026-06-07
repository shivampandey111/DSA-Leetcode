class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> nigga;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else nigga.push_back(nums[i]);
        }
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i<pos.size() && j<nigga.size()){
            res.push_back(pos[i]);
            i++;
            res.push_back(nigga[j]);
            j++;
        }
        return res;
    }
};