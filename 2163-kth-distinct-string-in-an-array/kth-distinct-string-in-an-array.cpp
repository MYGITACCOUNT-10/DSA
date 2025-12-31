class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string, int> freq;
        set<string> repeated;

        for (auto &s : arr) {
            freq[s]++;
            if (freq[s] == 2) {
                repeated.insert(s);   
            }
        }

    
        for (auto &s : arr) {
            if (freq[s] == 1 && repeated.find(s) == repeated.end()) {
                k--;
                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};
