class Solution {
public:
    string add_odd(string s, int a) {
        for(int i = 1; i < s.size(); i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string rotate(string s, int b) {
        int n = s.size();
        b = b % n;
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        set<string> visited;
        queue<string> q;
        visited.insert(s);
        q.push(s);

        while(!q.empty()) {
            string curr = q.front();
            q.pop();

            // add a to odd indices
            string added = add_odd(curr, a);
            if(!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            // rotate by b
            string rotated = rotate(curr, b);
            if(!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return *visited.begin(); 
    }
};
