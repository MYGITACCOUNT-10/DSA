class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0) {
            return "0";
        }
       
        if (denominator == 0) {
            return "";
        }
        string result;

        if((numerator>0)^(denominator>0))  result+="-";

        long long dividend=abs(static_cast<long long>(numerator));
        long long divisor=abs(static_cast<long long>(denominator));

        long long quotient=dividend/divisor;
        result+=to_string(quotient);

        long long remainder = dividend % divisor;

        if (remainder == 0) {
            return result;
        }
        //Handle the frcational part
        result += ".";

        unordered_map<long long, int> remainderMap;

        while (remainder != 0) 
        {

            if (remainderMap.find(remainder) != remainderMap.end()) 
            {
                //Finding the repitition of remainder at particular position
                int startPos = remainderMap[remainder];
                result.insert(startPos, "(");
                result += ")";
                break; 
            }
    

            // If no repetition, store the remainder and its CURRENT position
            // The position is the current length of the result string.
            remainderMap[remainder] = result.length();

            
            remainder *= 10;
            result += to_string(remainder / divisor); // Append the digit!
            remainder %= divisor; // Update the remainder for the next loop


        }

        return result;

        
        
    }
};