class Solution {
public:
    // dimar's solution
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            int left = height[l];
            int right = height[r];
            int sumCurr = min(left, right) * (r - l);
            res = max(res, sumCurr);
            if (left >= right) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};