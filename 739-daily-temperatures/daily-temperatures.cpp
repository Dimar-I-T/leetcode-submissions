class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> answers(n);
        int prev = temperatures[0];
        st.push({prev, 0});
        for (int x = 1; x < n; x++) {
            int curr = temperatures[x];
            if (curr > prev) {
                while (!st.empty()) {
                    pair<int, int> currLeft = st.top();
                    int currLeftVal = currLeft.first;
                    int currLeftInd = currLeft.second;
                    if (currLeftVal >= curr) {
                        break;
                    }

                    answers[currLeftInd] = x - currLeftInd; 
                    st.pop();
                }
            }

            prev = curr;
            st.push({curr, x});
        }

        return answers;
    }
};