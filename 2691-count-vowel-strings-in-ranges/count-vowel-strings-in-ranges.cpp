class Solution {
public:
    #define ll long long
    const int MAXN = 1e5;
    vector<ll> arr;
    vector<ll> segTree;
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

    void build(ll l, ll r, ll i) {
        // i representasi index untuk range [l, r] di segTree
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }

        ll m = (l + r) / 2;
        ll kiri = 2 * i + 1;
        ll kanan = 2 * i + 2;
        build(l, m, kiri);
        build(m + 1, r, kanan);
        segTree[i] = segTree[kiri] + segTree[kanan]; 
    }

    ll query(ll l1, ll r1, ll l, ll r, ll i) {
        // kasus [l1, r1] di dalam [l, r]
        if (l1 == l && r1 == r) {
            return segTree[i];
        }

        ll m = (l + r) / 2;
        ll kiri = 2 * i + 1;
        ll kanan = 2 * i + 2;
        ll nilaiKiri = 0, nilaiKanan = 0;
        if (l1 <= m) {
            if (r1 > m) {
                nilaiKiri = query(l1, m, l, m, kiri);
            } else {
                nilaiKiri = query(l1, r1, l, m, kiri);
            }
        } 

        if (r1 > m) {
            if (l1 > m) {
                nilaiKanan = query(l1, r1, m + 1, r, kanan);
            } else {
                nilaiKanan = query(m + 1, r1, m + 1, r, kanan);
            }
        }

        return nilaiKiri + nilaiKanan;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ll n = words.size();
        arr.clear(); arr.resize(n, 0);
        segTree.clear(); segTree.resize(4 * MAXN, 0);
        isiVowel();
        isiArr(words);
        build(0, n - 1, 0);
        vector<int> res(queries.size());
        ll i = 0;
        for (vector<int> q : queries) {
            ll l = q[0], r = q[1];
            res[i] = query(l, r, 0, n - 1, 0);
            i++;
        }

        return res;
    }
};