class Solution {
private:
void invert(string &s) {
    for (char &c : s) {
        c = (c == '0') ? '1' : '0';
    }
}
string solve(string &s,int i,int n)
{
    if(i==n) return s;

    string temp_1,temp_2;
    temp_2=s+"1";

    //Flipping the bits
    invert(s);
    //Reverse
    reverse(s.begin(),s.end());

    temp_2+=s;

    i++;

    return solve(temp_2,i,n);

}
public:
    char findKthBit(int n, int k) {
        
        string s="0";
        string res=solve(s,0,n);

        char ch=res[k-1];

        return ch;
    }
};