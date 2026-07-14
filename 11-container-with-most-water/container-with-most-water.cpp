class Solution {
public:
    // dimar's solution
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int luas = 0;
        while (l < r) {
            if (luas < min(height[l], height[r]) * (r - l)){
                luas = min(height[l], height[r]) * (r - l);
            }

            if (height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }    

        return luas;
    }
};