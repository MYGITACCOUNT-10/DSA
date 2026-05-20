class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
     //we are using sets beacuse this vector contains unique element
     //so do set contains
        set<int>seenA;
        set<int>seenB;
        vector<int> C(A.size());
        for(int i=0;i<A.size();i++)
        {
            seenA.insert(A[i]);
            seenB.insert(B[i]);
                

            // Temporary set to store the intersection
            set<int> result;
            set_intersection(seenA.begin(), seenA.end(),
                                  seenB.begin(), seenB.end(),
                                  inserter(result, result.begin()));

            // Store the size of the intersection
            C[i] = result.size();
        }

        return C;
        
    }
};
//OPTIMISED SOLUTION
// int n = A.size();
//         vector<int> freq(n+1, 0), res(n);
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
            
//             freq[A[i]]++;
//             if (freq[A[i]] == 2) cnt++;

//             freq[B[i]]++;
//             if (freq[B[i]] == 2) cnt++;

//             res[i] = cnt;
//         }

//         return res;