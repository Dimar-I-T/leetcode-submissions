class Solution {
public:
    struct Maks {
        char c;
        int freq;
    };

    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        freq.reserve(n);
        int l = 0, r = 1;
        freq[s[l]]++;
        Maks maks = {s[l], freq[s[l]]};
        int res = 1;
        while (r < n) {
            //cout << "l: " << l << "\n";
            //cout << "r: " << r << "\n";
            //cout << "sr: " << s[r] << "\n";
            freq[s[r]]++;
            //cout << "freq sr sekarang: " << freq[s[r]] << "\n";
            //cout << "maks.c = " << maks.c << "\n";
            //cout << "maks.freq = " << maks.freq << "\n";
            if (freq[s[r]] > maks.freq) {
                //cout << "KANAN LEBIH BESAR FREQ, GANTI\n";
                maks = {s[r], freq[s[r]]};
                //cout << "maks.c sekarang: " << s[r] << "\n";
                //cout << "maks.freq sekarang: " << maks.freq << "\n";
            }

            //cout << "minRep = " << r - l + 1 - maks.freq << "\n";
            //cout << "k: " << k << "\n";
            if (r - l + 1 - maks.freq > k) {
                //cout << "MIN REP LEBIH BESAR, GESER L\n\n";
                if (s[l] == maks.c) {
                    //cout << "SL itu sama dengan maks, kurangi freq\n\n";
                    maks.freq--;
                }

                freq[s[l]]--;
                l++;
            } else {
                //cout << "MINREP AMAN, SIMPAN RES: res atau " << r - l + 1 << "\n\n";
                res = max(res, r - l + 1);
            }

            r++;
        }

        return res;
    }
};