class Solution {
public:
    // dimar's solution
    int minPartitions(string n) {
        int hasil = 0;
        for (int x = 0; x < n.length(); x++){
            hasil = max(hasil, n[x] - '0');
        }

        return hasil;
    }
};