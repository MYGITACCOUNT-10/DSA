class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0;
        int j=height.size()-1;
        int max_area=INT_MIN;
        while(i<=j)
        {
            if(height[i]<height[j])
            {
                int area= height[i]*(j-i);
                if(area>max_area) max_area=area;
                i++;
            }
            else
            {
                int area= height[j]*(j-i);
                if(area>max_area) max_area=area;
                j--;


            }
        }
        return max_area;

        
    }
};