class Solution {
public:
    // dimar's solution
    int memo[46] = {0};
    void F(int n){
        if (n == 1){
            memo[n] = 1;
            return;
        }

        if (n == 2){
            memo[n] = 2;
            return;
        }

        if (memo[n] == 0){
            F(n - 1);
            F(n - 2);
            memo[n] = memo[n - 1] + memo[n - 2];
        }
    }
    
    int climbStairs(int n) {
        F(n);
        return memo[n];
    }
};