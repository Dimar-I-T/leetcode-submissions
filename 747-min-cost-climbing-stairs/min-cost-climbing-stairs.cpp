class Solution {
public:
    // dimar's solution
    int memo[10001] = {0};
    int H[10001] = {0};
    void F(int n){
        if (n == 1 || n == 2){
            memo[n] = 0;
            return;
        }

        if (memo[n] == -1){
            F(n - 1);
            F(n - 2);
            memo[n] = min(memo[n - 2] + H[n - 2], memo[n - 1] + H[n - 1]);
        }
    }

    int minCostClimbingStairs(vector<int>& cost) {
        fill(memo, memo + 10001, -1);
        int l = cost.size();
        for (int x = 1; x <= l; x++){
            H[x] = cost[x - 1];
        }

        F(l + 1);
        return memo[l + 1];
    }
};