class Solution {
public:
    // dimar's solution
    string fillFront(string& a, int n, char c) {
        string res = "";
        for (int x = 0; x < n; x++) {
            res += c;
        }

        return res + a;
    }

    void equalize(string& a, string& b) {
        int nA = a.length();
        int nB = b.length();
        if (nA < nB) {
            a = fillFront(a, nB - nA, '0');
        } else {
            b = fillFront(b, nA - nB, '0');
        }
    }

    string addBinary(string a, string b) {
        equalize(a, b);
        int n = a.length();
        int c = 0;
        for (int x = n - 1; x >= 0; x--) {
            int ax = a[x] - '0';
            int bx = b[x] - '0';
            int dx = c ^ ax ^ bx;
            char d = dx + '0';
            c = (ax & bx) | (ax & c) | (bx & c);
            b[x] = d;
        }

        if (c == 1) {
            b = fillFront(b, 1, '1');
        }

        return b;
    }
};