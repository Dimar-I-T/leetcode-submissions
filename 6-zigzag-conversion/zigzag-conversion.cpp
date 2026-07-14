class Solution {
public:
    // dimar's solution
    string convert(string s, int numRows) {
        int k = 2*numRows - 2;
        string hasil = "";
        if (k == 0){
            hasil = s;
        }else{
            for (int x = 0; x < numRows; x++){
                for (int y = x; y < s.length(); y += k){
                    hasil += s[y];
                    if (x != 0 && x != numRows - 1 && y + k - 2*x < s.length()){
                        hasil += s[y + k - 2*x];
                    }
                }
            }
        }

        return hasil;
    }
};