class Solution {
public:
    struct NumIdx {
        int num;
        int idx;
    };

    void solveLeftDist(vector<int>& dist, vector<int>& v) {
        int n = v.size();
        stack<NumIdx> st;
        st.push({-INT_MAX, -1});
        for (int x = 0; x < n; x++) {
            NumIdx prev = st.top();
            int prevNum = prev.num;
            
            int currNum = v[x];
            int currIdx = x;
            if (prevNum >= currNum) {
                // ke kiri
                while (!st.empty()) {
                    prev = st.top();
                    int currLeftNum = prev.num;
                    int currLeftIdx = prev.idx;
                    if (currLeftIdx >= 0 && dist[currLeftIdx] == 0) {
                        dist[currLeftIdx] = 1;
                    }

                    if (currLeftNum < currNum) {
                        dist[currIdx] = currIdx - currLeftIdx;
                        break;
                    }

                    st.pop();
                }
            }

            st.push({currNum, currIdx});
        }
    }

    void solveRightDist(vector<int>& dist, vector<int>& v) {
        int n = v.size();
        stack<NumIdx> st;
        st.push({-INT_MAX, -1});
        for (int x = 0; x < n; x++) {
            NumIdx prev = st.top();
            int prevNum = prev.num;

            int currNum = v[x];
            int currIdx = x;
            if (prevNum >= currNum) {
                // KE KIRI
                while (!st.empty()) {
                    prev = st.top();
                    int currLeftNum = prev.num;
                    int currLeftIdx = prev.idx;
                    if (currLeftIdx >= 0) {
                        dist[currLeftIdx] = currIdx - currLeftIdx;
                    }

                    if (currLeftNum < currNum) {
                        break;
                    }

                    st.pop();
                }
            }

            st.push({currNum, currIdx});
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-INT_MAX);
        int n = heights.size();
        vector<int> leftDist(n), rightDist(n);

        // distKiri (prev smaller)
        solveLeftDist(leftDist, heights);

        // distKanan (next smaller)
        solveRightDist(rightDist, heights);

        int res = 0;
        for (int x = 0; x < n - 1; x++) {
            int left = leftDist[x];
            int right = rightDist[x];
            int val = heights[x];
            int area = val * (right + left - 1);
            res = max(res, area);
        }

        return res;
    }
};