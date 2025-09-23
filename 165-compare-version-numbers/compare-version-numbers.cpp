class Solution {
public:
    int compareVersion(string version1, string version2) {
        // FIX 1: Initialize both i and j
        int i = 0, j = 0;
        int n = version1.length();
        int m = version2.length();

        while (i < n || j < m) {
            long long version_1 = 0;
            while (i < n && version1[i] != '.') {
                version_1 = version_1 * 10 + (version1[i] - '0');
                i++;
            }

            long long version_2 = 0;
            while (j < m && version2[j] != '.') {
                version_2 = version_2 * 10 + (version2[j] - '0');
                j++;
            }

            if (version_1 < version_2) return -1;
            if (version_1 > version_2) return 1;

            //  skip the dots by checking bounds first
            if (i < n && version1[i] == '.') i++;
            if (j < m && version2[j] == '.') j++;
        }

        return 0; 
    }
};