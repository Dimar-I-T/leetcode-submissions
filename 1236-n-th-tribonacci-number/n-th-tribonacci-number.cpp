class Solution {
public:
    // dimar's solution
    int memo[38] = {0};
    void T(int n){
        if (n == 0){
            memo[n] = 0;
            return;
        }

        if (n == 1 || n == 2){
            memo[n] = 1;
            return;
        }

        if (memo[n] == 0){
            T(n - 1);
            T(n - 2);
            T(n - 3);
            memo[n] = memo[n - 1] + memo[n - 2] + memo[n - 3];
        }
    }

    int tribonacci(int n) {
        T(n);
        return memo[n];
    }
};