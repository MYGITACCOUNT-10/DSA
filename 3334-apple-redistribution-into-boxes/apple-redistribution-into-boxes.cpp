class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int total_apples = accumulate(apple.begin(), apple.end(), 0); 

        sort(capacity.rbegin(), capacity.rend()); //descending
        int count = 0; 
        while (total_apples > 0 && count < capacity.size()) 
        {
            total_apples -= capacity[count];
            count++; 
        }
        
        return count;
    }
};