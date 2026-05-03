class Solution {
public:
    bool rotateString(string s, string goal) {

    
    if (s.size() != goal.size()) return false; // First, check if lengths match
    string z = s + s;
    return z.find(goal) != string::npos; // Check if goal is found anywhere in z


    }
};