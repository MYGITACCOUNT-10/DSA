class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int s_1 = 1, s_2 = 2;
        for (int i = 3; i <= n; i++) {
            int c = s_1 + s_2;
            s_1 = s_2;
            s_2 = c;
        }
        return s_2;
    }
};
