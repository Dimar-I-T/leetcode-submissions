class Solution {
public:
    // dimar's solution
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();

        int xh = 0;
        int xn = 0;
        int hasil = 0;
        bool bisa = 0;
        while (xh < h) {
            if (haystack[xh] == needle[xn]) {
                xn++;
                if (xn == n) {
                    bisa = 1;
                    break;
                }
            } else {
                xh = xh - xn;
                xn = 0;
            }
            
            xh++;
        }

        if (bisa) {
            hasil = xh - xn + 1;
        } else {
            hasil = -1;
        }
        
        return hasil;
    }
};