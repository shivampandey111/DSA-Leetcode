class Solution {
public:
    bool check(vector<char> permut, vector<char> current){
        unordered_map<int, int> freq;
        for(int val:permut){
            freq[val]++;
        }

        for(int val:current){
            if(freq[val]==0) return false;
            freq[val]--;
        }
        return true;

    }

    bool checkInclusion(string s1, string s2) {
        int low = 0;
        int high = s1.size()-1;
        bool result = false;
        vector<char> current;
        vector<char> permut;

        if(s1.size()>s2.size()) return false;
        
        for(int i =0; i<s1.size(); i++){
            permut.push_back(s1[i]);
        }
        for(int i =0; i<=high; i++){
            current.push_back(s2[i]);
        }
        while(high<s2.size()){
            if(check(permut, current)){
                result = true;
                return result;
            }
            low++;
            high++;
            if(high<s2.size()){
                current.push_back(s2[high]);
            }
            current.erase(current.begin());
        }
        return result;
    }
};