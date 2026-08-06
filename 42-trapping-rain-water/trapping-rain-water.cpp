class Solution {
public:
    // dimar's solution
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int x = n - 2; x >= 0; x--) {
            rightMax[x] = max(height[x], rightMax[x + 1]);
        }   

        //cout << "rightMax:\n";
        // for (int x : rightMax) {
        //     //cout << x << " ";
        // }

        //cout << "\n";
        int l = 0;
        int left = height[l];
        if (n > 1) {
            left = min(left, rightMax[l + 1]);
        }

        int sum = 0;
        for (int x = 1; x < n - 1; x++) {
            int curr = height[x];
            if (curr >= left) {
                left = min(curr, rightMax[x + 1]);
                continue;
            }

            //cout << "left: " << left << "\n";
            //cout << "curr: " << curr << "\n";
            sum += left - curr;
            //cout << "+" << left - curr << "\n\n";
        }

        return sum;
    }
};