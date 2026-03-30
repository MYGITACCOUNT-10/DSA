class Solution {
public:
    bool checkStrings(string s1, string s2) {

        if(s1.size()!=s2.size()) return false;

        map<char,vector<int>>position_1;
        map<char,vector<int>>position_2;

        for(int i=0;i<s1.size();i++)
        {
            char ch=s1[i];
            position_1[ch].push_back(i);
        }

        for(int i=0;i<s2.size();i++)
        {
            char ch=s2[i];
            position_2[ch].push_back(i);
        }

        // ✅ FIX 1: size check
        if(position_1.size() != position_2.size()) return false;

        // ✅ FIX 2: iterate only over position_1
        for(auto &itr1 : position_1)
        {
            char ch = itr1.first;

            // ✅ FIX 3: check if key exists in second map
            if(position_2.find(ch) == position_2.end()) return false;

            vector<int> v_1 = itr1.second;
            vector<int> v_2 = position_2[ch];

            int odd_occupied_1=0, even_occupied_1=0;

            for(int i=0;i<v_1.size();i++)
            {
                if(v_1[i]%2==0) even_occupied_1++;
                else odd_occupied_1++;
            }

            int odd_occupied_2=0, even_occupied_2=0;

            for(int i=0;i<v_2.size();i++)
            {
                if(v_2[i]%2==0) even_occupied_2++;
                else odd_occupied_2++;
            }

            if(odd_occupied_1!=odd_occupied_2 || even_occupied_1!=even_occupied_2)
                return false;
        }

        return true;
    }
};