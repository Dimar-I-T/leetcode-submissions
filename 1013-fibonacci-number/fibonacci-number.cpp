class Solution {
public:
    // dimar's solution
    int memo[31] = {0};
    void F(int n){
        if (n == 0){
            memo[0] = 0;
            return;
        }

        if (n == 1){
            memo[1] = 1;
            return;
        }

        if (memo[n] == 0){
            F(n - 1);
            F(n - 2);
            memo[n] = memo[n - 1] + memo[n - 2];
        }
    }

    int fib(int n) {
        F(n);
        return memo[n];
    }
};