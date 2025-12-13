class Solution {
private:
    bool validCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!(isalnum(c) || c == '_'))
                return false;
        }
        return true;
    }

    bool validBusiness(const string& s) {
        return (s == "electronics" || s == "grocery" ||
                s == "pharmacy" || s == "restaurant");
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < code.size(); i++) {
            if (validCode(code[i]) &&
                validBusiness(businessLine[i]) &&
                isActive[i]) {

                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> result;
        vector<string> order = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (const string& b : order) {
            if (mp.count(b)) {
                sort(mp[b].begin(), mp[b].end());
                for (const string& c : mp[b])
                    result.push_back(c);
            }
        }

        return result;
    }
};
