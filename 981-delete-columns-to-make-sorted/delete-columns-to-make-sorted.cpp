class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int count=0;
        int string_len=strs[0].size();
        int arr_len=strs.size();

        for(int i=0;i<string_len;i++)
        {   string s="";
            for(int j=0;j<arr_len;j++)
            {
                s+=strs[j][i];
            }
            string s_sorted=s;
            sort(s_sorted.begin(),s_sorted.end());
            if(s!=s_sorted) count++; 
        }
        
        return count;
    }
};