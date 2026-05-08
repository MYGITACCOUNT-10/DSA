class Solution {
public:

    bool isprime(int n)
    {
        if(n < 2) return false;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return false;
        }

        return true;
    }

    vector<int> primefactors(int n)
    {
        vector<int> factors;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                factors.push_back(i);

                while(n % i == 0)
                    n /= i;
            }
        }

        if(n > 1)
            factors.push_back(n);

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // Build:
        // prime factor -> indices divisible by it
        for(int i = 0; i < n; i++)
        {
            vector<int> factors = primefactors(nums[i]);

            for(auto p : factors)
            {
                mp[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int steps = 0;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                int idx = q.front();
                q.pop();

                if(idx == n - 1)
                    return steps;

                // left
                if(idx - 1 >= 0 && !visited[idx - 1])
                {
                    visited[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // right
                if(idx + 1 < n && !visited[idx + 1])
                {
                    visited[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // teleport
                if(isprime(nums[idx]))
                {
                    int p = nums[idx];

                    for(auto nextidx : mp[p])
                    {
                        if(!visited[nextidx])
                        {
                            visited[nextidx] = 1;
                            q.push(nextidx);
                        }
                    }

                    mp[p].clear();
                }
            }

            steps++;
        }

        return -1;
    }
};