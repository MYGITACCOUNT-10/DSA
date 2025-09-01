class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        
        // Add all classes to priority queue with their improvement value
        for(int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, i});
        }
        
        // Add extra students one by one to the class with max improvement
        for(int i = 0; i < extraStudents; i++) {
            int idx = pq.top().second;
            pq.pop();
            
            classes[idx][0]++; // increase pass count
            classes[idx][1]++; // increase total count
            
            // Recalculate gain and add back to queue
            int pass = classes[idx][0];
            int total = classes[idx][1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, idx});
        }
        
        // Calculate final average
        double sum = 0;
        for(int i = 0; i < classes.size(); i++) {
            sum += (double)classes[i][0] / classes[i][1];
        }
        
        return sum / classes.size();
    }
};