class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        // map keeps keys sorted automatically
        map<int, vector<int>> mp;

        for(int i = 0; i < arr.size(); i++)
        {
            int ones = __builtin_popcount(arr[i]);
            mp[ones].push_back(arr[i]);
        }

        vector<int> result;

        // keys (bit counts) are already in ascending order
        for(auto &itr : mp)
        {
            vector<int> &v = itr.second;
            sort(v.begin(), v.end());  

            result.insert(result.end(), v.begin(), v.end());
        }

        return result;
    }
};