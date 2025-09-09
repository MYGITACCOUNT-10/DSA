class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        const int MOD = 1000000007;
        
        // dp[i] = number of people who discovered the secret on day i
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // One person discovers on day 1
        
        long long sharing = 0; // Number of people currently sharing
        long long total = 1;   // Total people who know the secret
        
        for (int day = 2; day <= n; day++) {
            // People who discovered the secret 'delay' days ago start sharing today
            if (day - delay >= 1) {
                sharing = (sharing + dp[day - delay]) % MOD;
            }
            
            // People who discovered the secret 'forget' days ago stop sharing today
            if (day - forget >= 1) {
                sharing = (sharing - dp[day - forget] + MOD) % MOD;
                // They also forget the secret, so remove from total
                total = (total - dp[day - forget] + MOD) % MOD;
            }
            
            // New people discover the secret today (equal to people sharing)
            dp[day] = sharing;
            total = (total + dp[day]) % MOD;
        }
        
        return (int)total;
    }
};
        