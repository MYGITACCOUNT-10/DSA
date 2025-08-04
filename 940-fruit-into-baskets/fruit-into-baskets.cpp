class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int>mp;//fruit:->number of times they appear
        int total_fruit=0;//maximum number 2 diff fruits

        int left=0;
        int right=0;

        for(int right=0;right<fruits.size();right++)
        {   
            mp[fruits[right]]++;
            
            while(mp.size()>2){
                mp[fruits[left]]--;

                if(mp[fruits[left]]==0) mp.erase(fruits[left]);

                left++;
            }

         
            total_fruit=max(total_fruit,right-left+1);
           
        }

        return total_fruit;
        
    }
};