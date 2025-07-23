class Solution {
int score(string &s,string pattern,int points)
{
    stack<char>st;
    int count=0;

    for(int i=0;i<s.size();i++)
    {
        if(!st.empty() && st.top()==pattern[0] && s[i]==pattern[1])
        {
            st.pop();
            count++;
        }
        else 
        {
            st.push(s[i]);
        }
    }

   string temp = "";
    while (!st.empty()) {
    temp += st.top();  // Append normally
    st.pop();
    }   
    reverse(temp.begin(), temp.end());  // Reverse the result
    s = temp;

    return count*points;
}
public:
    int maximumGain(string s, int x, int y) {
        
        int max_score=0;
        if(y>=x)
        {   
            max_score+=score(s,"ba",y);
            max_score+=score(s,"ab",x);
        }
        else
        {
            max_score+=score(s,"ab",x);
            max_score+=score(s,"ba",y);
        }

        return max_score;
        
    }
};