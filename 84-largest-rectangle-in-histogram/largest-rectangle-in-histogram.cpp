class Solution {
public:
    struct NumIdx {
        int num;
        int idx;
    };

    int solveLeftRightDist(vector<int>& leftDist, vector<int>& rightDist, vector<int>& v) {
        int n = v.size();
        stack<NumIdx> st;
        st.push({-INT_MAX, -1});
        int res = 0;
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
                        if (leftDist[currLeftIdx] == 0) {
                            leftDist[currLeftIdx] = 1;
                        }

                        if (currLeftNum >= currNum) {
                            rightDist[currLeftIdx] = currIdx - currLeftIdx;
                        }
                    }

                    if (currLeftNum < currNum) {
                        leftDist[currIdx] = currIdx - currLeftIdx;
                        break;
                    }

                    st.pop();
                }
            }

            st.push({currNum, currIdx});
        }

        for (int x = 0; x < n - 1; x++) {
            int left = leftDist[x];
            int right = rightDist[x];
            int val = v[x];
            int area = val * (left + right - 1);
            res = max(res, area);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-INT_MAX);
        int n = heights.size();
        vector<int> leftDist(n), rightDist(n);  
        int res = solveLeftRightDist(leftDist, rightDist, heights);
        return res;
    }
};