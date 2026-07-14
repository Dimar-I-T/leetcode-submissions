class Solution {
public:
// dimar's solution
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), hasil = 1;
        int l = 0, banyak = 1;
        int lok[128] = {0};
        memset(lok, -1, sizeof(lok));
        lok[int(s[0])] = 0; 
        for (int x = 1; x < n; x++){
            if (lok[s[x]] >= l){
                hasil = max(hasil, banyak);
                banyak -= lok[int(s[x])] - l + 1;
                l = lok[int(s[x])] + 1;
                lok[int(s[x])] = -1;
            }

            lok[s[x]] = x;
            banyak++;
        }

        hasil = max(hasil, banyak);
        if (n == 0){
            hasil = 0;
        }

        return hasil;
    }
};