class Solution {
public:
    void func(string& digits, int idx, int n, unordered_map<char, string>& freq, string& temp, vector<string>& res){
        if(idx==n){
            res.push_back(temp);
            return;
        }
        string curr = freq[digits[idx]];
        for(int i = 0; i<curr.size(); i++){
            temp.push_back(curr[i]);
            func(digits, idx+1, n, freq, temp, res);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        int idx = 0;
        string temp;
        vector<string> res;
        int n = digits.size();
        unordered_map<char, string> freq;
        freq['2'] = "abc";
        freq['3'] = "def";
        freq['4'] = "ghi";
        freq['5'] = "jkl";
        freq['6'] = "mno";
        freq['7'] = "pqrs";
        freq['8'] = "tuv";
        freq['9'] = "wxyz";
        func(digits, idx, n, freq, temp, res);
        return res;
    }
};