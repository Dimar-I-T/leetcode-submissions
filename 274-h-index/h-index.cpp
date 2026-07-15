class Solution {
public:
    // dimar's solution
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        if (citations[0] > n){
            return n;
        }

        int hasil = 0, kem = 0;
        for (int x = 0; x < n; x++){
            if (citations[x] > (n - x)){
                kem = n - x;
                break;
            }

            hasil = citations[x]; 
        }

        hasil = max(hasil, kem);
        return hasil;
    }
};