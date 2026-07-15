class Solution {
public:
    // dimar's solution
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> hasil;
        for (int x = left; x <= right; x++){
            string s = to_string(x);
            bool bisa = true;
            for (int y = 0; y < s.length(); y++){
                if (s[y] == '0'){
                    bisa = false;
                    break;
                }

                if (x % (s[y] - '0') != 0){
                    bisa = false;
                    break;
                }
            }

            if (bisa){
                hasil.push_back(x);
            }
        }

        return hasil;
    }
};