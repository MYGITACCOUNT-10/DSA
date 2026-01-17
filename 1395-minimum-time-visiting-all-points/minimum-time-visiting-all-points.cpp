class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int min_time = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            int dx = abs(points[i][0] - points[i + 1][0]);
            int dy = abs(points[i][1] - points[i + 1][1]);

            min_time += max(dx, dy);
            //This already accounts for diagonal + straight moves optimally.
        }

        return min_time;
    }
};
