class Solution {
public:
    // dimar's solution
    bool isSubsequence(string s, string t) {
        int sl = s.length(), tl = t.length();
        bool bisa = false;
        if (sl <= tl){
            int k = 0;
            for (int x = 0; x < tl; x++){
                char l = s[k];
                if (t[x] == l){
                    k++;
                }
            }

            if (k == sl){
                bisa = true;
            }
        }

        return bisa;
    }
};