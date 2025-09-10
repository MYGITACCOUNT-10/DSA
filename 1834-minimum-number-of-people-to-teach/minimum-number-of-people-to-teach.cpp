class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert languages to sets for fast lookup
        vector<unordered_set<int>> userLangs(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLangs[i].insert(lang);
            }
        }
        
        // Find users involved in non-communicating pairs + count language frequency
        vector<int> langCount(n + 1, 0);
        unordered_set<int> problematicUsers;
        
        for (const auto& friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;
            
            // Check if they share any language
            bool canCommunicate = false;
            for (int lang : userLangs[u]) {
                if (userLangs[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if (!canCommunicate) {
                if (problematicUsers.insert(u).second) {
                    // Count languages for user u (only if newly added)
                    for (int lang : userLangs[u]) {
                        langCount[lang]++;
                    }
                }
                if (problematicUsers.insert(v).second) {
                    // Count languages for user v (only if newly added)
                    for (int lang : userLangs[v]) {
                        langCount[lang]++;
                    }
                }
            }
        }
        
        // If no problematic pairs, return 0
        if (problematicUsers.empty()) return 0;
        
        // Find the language known by most problematic users
        int totalUsers = problematicUsers.size();
        int minTeachings = totalUsers; // Worst case: teach a language no one knows
        
        for (int lang = 1; lang <= n; lang++) {
            int usersWhoKnow = langCount[lang];
            int usersToTeach = totalUsers - usersWhoKnow;
            minTeachings = min(minTeachings, usersToTeach);
        }
        
        return minTeachings;
    }
};