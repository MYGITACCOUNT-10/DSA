class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());

        if(nums==sorted) return 0;
    
        int count=0;
        vector<int>temp=nums;

        while(temp!=sorted)
        {   
            int min_sum=INT_MAX;
            int idx=-1;

            for(int i=0;i<temp.size()-1;i++)
            {
                int sum=temp[i]+temp[i+1];
                if(sum<min_sum)
                {
                    min_sum=sum;
                    idx=i;//storing the leftmost index corressponding to min_sum
                }
            }

            //REPLACING THE MIN_SUM WITH ELEMENTS WHICH GAVE MIN_SUM
            temp.insert(temp.begin()+idx,min_sum);//Inserts min_sum before index i
            temp.erase(temp.begin() + (idx + 1), temp.begin() + (idx + 3));
            count++;
            //safer approach..replace the ith index ele with sum and then remove the i+1th ele
            //temp[i] = min_sum;
            //temp.erase(temp.begin() + i + 1);
            vector<int>non_dec=temp;
            sort(non_dec.begin(),non_dec.end());
            sorted=non_dec;
        }

        return count;

        
    }
};