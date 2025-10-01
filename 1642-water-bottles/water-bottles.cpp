class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int ans=numBottles;
        int empty=0;
        int full=0;

        while(numBottles>=numExchange)
        {   
            empty=numBottles%numExchange;
            full=numBottles/numExchange;
            ans+=full;
            numBottles=full+empty;
        }

        return ans;
        
    }
};