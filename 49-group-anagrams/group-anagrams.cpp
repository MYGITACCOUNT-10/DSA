class Solution {
bool isanagram(string s1,string s2)
{
    if(s1.size()!=s2.size()) return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>result;

        unordered_map<string,vector<string>>anagrams;

        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            anagrams[temp].push_back(strs[i]);
        }

        for(auto it:anagrams)
        {
            result.push_back(it.second);
        }

        return result;
        
    }
};