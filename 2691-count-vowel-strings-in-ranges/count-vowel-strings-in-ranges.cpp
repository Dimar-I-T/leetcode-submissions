class Solution {
public:
#define ll long long
    vector<ll> arr;
    unordered_map<char, bool> isVowel;
    void isiVowel() {
        isVowel['a'] = 1;isVowel['i'] = 1;isVowel['u'] = 1;isVowel['e'] = 1;isVowel['o'] = 1;
    }

    bool startsEndsVowel(string s) {
        return isVowel[s[0]] && isVowel[s[s.length() - 1]];
    }

    void isiArr(vector<string>& words) {
        ll n = words.size();
        for (ll x = 0; x < n; x++) {
            string s = words[x];
            if (startsEndsVowel(s)) {
                arr[x] = 1;
            }
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ll n = words.size();
        arr.clear(); arr.resize(n, 0);
        isiVowel();
        isiArr(words);

        // jadiin prefSum
        for (int x = 1; x < n; x++) {
            arr[x] += arr[x - 1];
        }   

        int q = queries.size(); 
        vector<int> res(q);
        for (int x = 0; x < q; x++) {
            int l = queries[x][0], r = queries[x][1];
            int kiri = 0;
            if (l > 0) {
                kiri = arr[l - 1];
            }

            res[x] = arr[r] - kiri;
        } 

        return res;
    }
};