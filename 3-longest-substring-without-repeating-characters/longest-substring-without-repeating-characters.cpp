class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;  // Use a hash set instead of string search
            int j = i;
            
            while (j < n && seen.find(s[j]) == seen.end()) { 
                //seen.find(s[j]) looks for s[j] in the set
                //If it returns seen.end(), it means s[j] is not found in the set
                // meaning it's a unique character
                seen.insert(s[j]);  // Add to set
                j++;
            }
            
            max_size = max(max_size, j - i);  // Update max length
        }

        return max_size;
    }
};
