class Solution {
public:
    int findClosest(int x, int y, int z) {

        int distance_from_x=abs(z-x);
        int distance_from_y=abs(z-y);

        if(distance_from_x>distance_from_y) return 2;
        else if(distance_from_x<distance_from_y) return 1;
        else return 0;
        
    }
};