class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

       //Decalration of min heap used for storing pair<int,int>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto const& [num, freq] : mp) {
            minHeap.push({freq, num}); //after inserting the frequnecy of particular element]

           
            if (minHeap.size() > k) {//popping the least frequnecy one
                minHeap.pop();
            }
        }

    
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};