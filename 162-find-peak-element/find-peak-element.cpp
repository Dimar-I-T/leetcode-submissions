class Solution {
public:
    // dimar's solution
    int findPeakElement(vector<int>& nums) {
        long long A[1002] = {0};
        int n = nums.size();
        A[0] = -2147483648 - 2;
        A[n + 1] = -2147483648 - 2;
        for (int x = 1; x <= n; x++){
            A[x] = nums[x - 1];
        }

        int l = 0, r = n + 1, hasil = 0;
        while (l < r){
            int tengah = (l + r)/2;
            if (A[tengah] > A[tengah - 1] && A[tengah] > A[tengah + 1]){
                hasil = tengah;
                break;
            }else{
                int maks = max(A[tengah - 1], A[tengah + 1]);
                if (maks == A[tengah - 1]){
                    r = tengah;
                }else{
                    l = tengah;
                }
            }
        }

        cout << -INT_MAX;
        return hasil - 1;
    }
};