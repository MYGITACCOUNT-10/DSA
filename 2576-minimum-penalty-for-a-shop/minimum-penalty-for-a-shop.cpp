class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> prefix_N(n + 1, 0);
        
        prefix_N[0] = 0; // If we close at 0, zero 'N' have happened
        for(int i = 1; i <= n; i++)
        {
            prefix_N[i] = prefix_N[i-1] + (customers[i-1] == 'N' ? 1 : 0);
        }

        vector<int> suffix_Y(n + 1, 0);
        
        suffix_Y[n] = 0; // If we close at n, there are no customers left
        for(int i = n - 1; i >= 0; i--) 
        {
            suffix_Y[i] = suffix_Y[i+1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int min_penalty = INT_MAX;
        int best_hr = -1;

        for(int i = 0; i <= n; i++) {
            int penalty = prefix_N[i] + suffix_Y[i];
            if(penalty < min_penalty) {
                min_penalty = penalty;
                best_hr = i;
            }
        }

        return best_hr;
    }
};

        
