class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        long long max_sq_diag = 0; 
        int max_area = 0;
        
        for (const auto& dim : dimensions) {
            long long l = dim[0];
            long long b = dim[1];
            
            
            long long current_sq_diag = l*l + b*b;
            int current_area = l*b;
            
           
            if (current_sq_diag > max_sq_diag) {
                max_sq_diag = current_sq_diag;
                max_area = current_area; 
            } 
           
            else if (current_sq_diag == max_sq_diag) {
                max_area = max(max_area, current_area);
            }
        }
        
        return max_area;
    }
};