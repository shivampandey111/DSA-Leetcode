class Solution {
public:
    struct node{
        int value;
        int row;
        int col;

        node(int v, int r, int c){
            value = v;
            row = r;
            col = c;
        }
    };
    struct cmp{
        bool operator()(const node& a, const node& b){
            return a.value>b.value;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node, vector<node>, cmp> pq;
        int currMax = -1e9;
        for(int i = 0; i<nums.size(); i++){
            int value = nums[i][0];
            pq.emplace(value, i, 0);
            currMax = max(currMax, value);
        }
        int rs = 0;
        int re = 1e9;
        
        while(true){
            node currMin = pq.top();
            pq.pop();
            int cr = currMax - currMin.value;
            int bR = re - rs;
            if(bR>cr){
                re = currMax;
                rs = currMin.value;
                bR = re - rs;
            }
            int currRow = currMin.row;
            int currCol = currMin.col;
            if(currCol+1>=nums[currRow].size()) break;
            int next = nums[currRow][currCol+1];
            pq.emplace(next, currRow, currCol+1);
            currMax = max(currMax, next);
        }
        vector<int> result = {rs, re};
        return result;
    }
};