class Solution {
public:
    // dimar's solution
    vector<long long> sumOfThree(long long num) {
        vector<long long> hasil;
        if ((num - 3) % 3 == 0){
            long long a = (num - 3)/3;
            hasil = {a, a + 1, a + 2};
        }

        return hasil;
    }
};