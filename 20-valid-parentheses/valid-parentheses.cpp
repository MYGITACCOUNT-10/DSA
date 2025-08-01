class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (char ch : s) {
            // If it's an opening bracket, push it to the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            // If it's a closing bracket, check for a match
            else {
                if (stack.empty()) {
                    return false; 
                }
                char top = stack.top();
                stack.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false; // Mismatch
                }
            }
        }

        // The stack should be empty if all brackets are matched
        return stack.empty();
    }
};