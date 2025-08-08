class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
        }

        for (int i = 0; i < m; i++) {
            mp2[nums2[i]]++;
        }

        unordered_map<int, int> res;

      
        for (auto const& [key, val] : mp1) {
            if (mp2.count(key)) {//Returns the number of elements matching specific key
                res[key] = min(val, mp2[key]);
            }
        }

        vector<int> result;
        for (auto const& [key, val] : res) {
            int count = val;
            while (count > 0) {
                result.push_back(key);
                count--;
            }
        }

        return result;
    }
};