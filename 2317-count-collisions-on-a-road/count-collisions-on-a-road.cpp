class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int collisions = 0;

        for (char cur : directions) {

            // CASE 1: Current car is 'R'
            if (cur == 'R') {
                st.push('R');
            }

            // CASE 2: Current car is 'S'
            else if (cur == 'S') {
                int poppedR = 0;

                // All R before S collide into it
                while (!st.empty() && st.top() == 'R') {
                    st.pop();
                    poppedR++;
                }

                collisions += poppedR;
                st.push('S');
            }

            // CASE 3: Current car is 'L'
            else { // cur == 'L'

                // L meets empty or L → no collision
                if (st.empty() || st.top() == 'L') {
                    st.push('L');
                }

                // L meets S → 1 collision
                else if (st.top() == 'S') {
                    collisions += 1;
                    st.push('S');
                }

                // L meets one or more R → many collisions
                else { 
                    // st.top() == 'R'
                    int poppedR = 0;

                    while (!st.empty() && st.top() == 'R') {
                        st.pop();
                        poppedR++;
                    }

                    // poppedR R's each contribute a collision
                    // plus L colliding with the last R (= +1)
                    collisions += poppedR + 1;
                    st.push('S');
                }
            }
        }

        return collisions;
    }
};
