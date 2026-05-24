class Solution {
public:

    vector<int> dp;
    int n;

    int dfs(int index, vector<int>& arr, int d) {

      
        if (dp[index] != -1) {
            return dp[index];
        }

        int best = 1;

        for (int next = index + 1;
             next <= min(n - 1, index + d);
             next++) {

           
            if (arr[next] >= arr[index]) {
                break;
            }

            best = max(
                best,
                1 + dfs(next, arr, d)
            );
        }

        // Move left
        for (int next = index - 1;
             next >= max(0, index - d);
             next--) {

            // Cannot jump further
            if (arr[next] >= arr[index]) {
                break;
            }

            best = max(
                best,
                1 + dfs(next, arr, d)
            );
        }

        return dp[index] = best;
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();

        dp.resize(n, -1);

        int answer = 1;

        for (int i = 0; i < n; i++) {

            answer = max(
                answer,
                dfs(i, arr, d)
            );
        }

        return answer;
    }
};