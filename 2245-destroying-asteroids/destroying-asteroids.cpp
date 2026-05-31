class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();

        long long curr_mass = mass;
        int idx = -1; 

        for(int i = 0; i < asteroids.size(); i++) { 
        if(asteroids[i] <= curr_mass) 
        { 
            curr_mass += (long long)asteroids[i]; 
            idx = i; 
        }   
        else break;
        }
        


        if(idx==(n-1)) return true;
        else return false;
        
    }
};