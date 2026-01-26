class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>answer;
         sort(arr.begin(),arr.end());
         int min_dif=INT_MAX;
         //answer.push_back({arr[0],arr[1]});

         for(int i=0;i<arr.size()-1;i++)
         {
           int diff=arr[i+1]-arr[i];
           min_dif=min(min_dif,diff);
         }

         for(int i=0;i<arr.size()-1;i++)
         {
            if(arr[i+1]-arr[i]==min_dif) answer.push_back({arr[i],arr[i+1]});
         }

         return answer;

        
        
    }
};