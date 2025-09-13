class Solution {
public:
    string multiply(string num1, string num2) {

        int m=num1.size();
        int n=num2.size();

        vector<int>result(m+n,0);

        for(int i=m-1;i>=0;i--)
        {   //we do multiplication for backside..123*456..therefore first we multiply 3*6=18 ..we store 8 and carry the 1 on the other number.
        int d1=num1[i]-'0';
            for(int j=n-1;j>=0;j--)
            {
                int d2=num2[j]-'0';
                int mul=d1*d2;
                int p1=i+j;//to hold the carry ad add it to the very next multiplication.
                int p2=i+j+1;//to hold the last dgigit of the multiplication of d1 and d2.

                int sum=mul+result[p2];
                result[p2]=sum%10;
                result[p1]+=sum/10;
            }
        }

        string ans;
        for(int num:result)
        {
            if(!(ans.empty() && num==0)) ans.push_back(num+'0');//to avoid leading zeroes.
        }

        return ans.empty()?"0":ans;  
    }
};