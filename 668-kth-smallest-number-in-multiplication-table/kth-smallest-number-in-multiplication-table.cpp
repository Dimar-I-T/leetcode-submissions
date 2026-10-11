class Solution {
public:
    #define ll long long
    const ll MAXN = 3 * 1e4 + 1;
    const ll MAXNM = MAXN * MAXN;
    int findKthNumber(int m, int n, int k) {
        ll minRow = min(n, m);
        ll maxCol = max(n, m);
        ll l = 1, r = MAXNM;
        ll res = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll val = 0;
            for (ll x = 1; (x <= mid && x <= minRow); x++) {
                ll y = mid / x;
                if (y <= maxCol) {
                    val = max(val, x * y);
                }
            }

            if (val == 0) {
                r = mid - 1;
                continue;
            }

            ll rank = 0;
            ll freq = 0;
            ll col = maxCol;
            for (ll row = 1; row <= minRow; row++) {
                while (col >= 0) {
                    ll ujung = row * col;
                    if (val < ujung) {
                        col--;
                    } else {
                        rank += col;
                        if (val == ujung) {
                            freq++;
                        }

                        break;
                    }
                }
            }

            ll minRank = rank - freq + 1;
            ll maxRank = rank;
            if (k >= minRank && k <= maxRank) {
                res = val;
                break;
            } else {
                if (k < minRank) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return res;
    }   
};