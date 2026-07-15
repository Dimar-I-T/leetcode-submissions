class Solution {
public:
    // dimar's solution
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> kiriKanan(n + 2), kananKiri(n + 2), jawaban(n);

        // kiri kanan
        kiriKanan[0] = 1; 
        kiriKanan[n + 1] = 1;
        for (int x = 1; x <= n; x++){
            kiriKanan[x] = kiriKanan[x - 1]*nums[x - 1];
        }

        // kanan kiri
        kananKiri[n + 1] = 1;
        kananKiri[0] = 1;
        int a = n - 1;
        for (int x = n; x >= 1; x--){
            kananKiri[x] = kananKiri[x + 1]*nums[a]; 
            a--;
        }

        for (int x = 1; x <= n; x++){
            jawaban[x - 1] = kiriKanan[x - 1]*kananKiri[x + 1];
        }

        return jawaban;
    }
};