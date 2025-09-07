class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        for (int i = 1; i <= n / 2; ++i) {//uska adhe use krenge taki double ho jayega
            ans.push_back(i);    // positive number
            ans.push_back(-i);   // negative number
        }

        if (n % 2 != 0) {
            ans.push_back(0);   
        }

        return ans;
    }
};
