class Solution {
public:
    long long flowerGame(int n, int m) {

        //Since we want alice should win..therefor she should be last ione to take the alst flower..
        //Now as per question she should be the one to start first now..
        //If the sum of the flower on both the lane is odd->Aloice will win as she will be last to take the flower.

        //x+y=>odd
        //x is even  and y is odd
        //x is odd and y is even

        long long odd_x=0;//between 1 to n
        long long even_y=0;//between 1 to m

        for(int i=1;i<=n;i++){

            if(i%2==1) odd_x++;
        }

        for(int i=1;i<=m;i++){

            if(i%2==0) even_y++;
        }

        long long total_1=(long long)((odd_x)*(even_y));

        long long even_x=0;//between 1 to n
        long long odd_y=0;//between 1 to m

        for(int i=1;i<=n;i++){

            if(i%2==0) even_x++;
        }

        for(int i=1;i<=m;i++){

            if(i%2==1) odd_y++;
        }

        long long total_2=(long long)((odd_y)*(even_x));

        return total_1+total_2;

        
    }
};