class Solution {
public:
    void func(vector<char>& arr, int idx, vector<char>& temp){
        if(idx<0) return;
        if(idx==0){
            temp.push_back(arr[idx]);
            return;
        }
        temp.push_back(arr[idx]);
        func(arr, idx-1, temp);
    }

    void reverseString(vector<char>& s) {
        if(s.size()<=0) return;
        int idx = s.size()-1;
        vector<char> temp;
        func(s, idx, temp);
        s = temp;

        // stack<char> rev;

        // for(int i =0; i<s.size(); i++){
        //     rev.push(s[i]);
        // }
        // int i=0;
        //     while((!rev.empty()) && i<s.size()){
        //         s[i] = rev.top();
        //         rev.pop();
        //         i++;
        //     }
        
    }
};