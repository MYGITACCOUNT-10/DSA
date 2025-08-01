class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int>pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        int l1=pq.top();
        pq.pop();
        int l2=pq.top();

        return (l1-1)*(l2-1);
        
    }
};