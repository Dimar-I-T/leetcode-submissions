class Solution {
public:
    // dimar's solution
    string mergeAlternately(string word1, string word2) {
        int minn = 0;
        string sisa = "";
        if (word1.length() < word2.length()){
            minn = word1.length();
            sisa = word2;
        }else{
            minn = word2.length();
            sisa = word1;
        }

        string hasil = "";
        int w1 = 0, w2 = 0;
        for (int x = 0; x < minn*2; x++){
            if (x % 2 == 0){
                hasil += word1[w1];
                w1++;
            }else{
                hasil += word2[w2];
                w2++;
            }
        }
        
        if (w1 <= sisa.length() - 1){
            hasil += sisa.substr(w1, sisa.length() - w1);
        }

        return hasil;
    }
};