class Solution {
public:
    vector<string> func(int n, int open, int close, vector<string>& res, string& temp){
        if(open==n&&close==n){
            res.push_back(temp);
            return res;
        }
        if(open<n){
            temp.push_back('(');
            func(n, open+1, close, res, temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            func(n, open, close+1, res, temp);
            temp.pop_back();
        }
        return res;
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> result;
        string temp;
        vector<string> ouput = func(n, open, close, result, temp);
        return ouput;
    }
};