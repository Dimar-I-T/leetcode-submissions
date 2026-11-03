class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        if (n == 1) {
            return {0};
        }

        vector<int> indexesOnesFromLeft;
        vector<int> indexesOnesFromRight;
        for (int x = 0; x < n; x++) {
            if (boxes[x] == '1') {
                indexesOnesFromLeft.push_back(x);
            }
        }
        
        vector<int> ans(n);
        int n1 = indexesOnesFromLeft.size();
        if (n1 == 0) {
            return ans;
        }
        
        for (int x = n - 1; x >= 0; x--) {
            if (boxes[x] == '1') {
                indexesOnesFromRight.push_back(n - x - 1);
            }
        }

        reverse(indexesOnesFromRight.begin(), indexesOnesFromRight.end());
        vector<int> prefFromLeft(n1);
        prefFromLeft[0] = indexesOnesFromLeft[0];
        for (int x = 1; x < n1; x++) {
            prefFromLeft[x] = prefFromLeft[x - 1] + indexesOnesFromLeft[x];
        }

        vector<int> prefFromRight(n1);
        prefFromRight[n1 - 1] = indexesOnesFromRight[n1 - 1];
        for (int x = n1 - 2; x >= 0; x--) {
            prefFromRight[x] = prefFromRight[x + 1] + indexesOnesFromRight[x];
        }

        cout << "from left: ";
        for (int x : indexesOnesFromLeft) {
            cout << x << " ";
        }

        cout << "\nfrom right: ";
        for (int x : indexesOnesFromRight) {
            cout << x << " ";
        }

        cout << "\n";

        int res = 0;
        for (int x = 0; x < n; x++) {
            auto itrLeftB = binary_search(indexesOnesFromLeft.begin(), indexesOnesFromLeft.end(), x);
            auto itrLeft = upper_bound(indexesOnesFromLeft.begin(), indexesOnesFromLeft.end(), x);
            int il = (itrLeft - indexesOnesFromLeft.begin()), iL = 0;
            int kiri = 0;
            // kalau il = 0, artinya x < yang pertama, kiri = 0
            if (il > 0) {
                kiri = prefFromLeft[min(il - 1, n1 - 1)];
            }

            cout << "x = " << x << "\n";
            cout << "iL = " << iL << "\n";
            cout << "il = " << il << "\n";
            
            int banyakElemenKiri = x * (n1 - il);

            int lSum = (prefFromLeft[n1 - 1] - kiri) - banyakElemenKiri;
            cout << "prefFromLeft[n1 - 1] = " << prefFromLeft[n1 - 1] << "\n";
            cout << "- kiri = " << kiri << "\n";
            cout << "- banyakElemenKiri = " << banyakElemenKiri << "\n";
            cout << "lSum = " << lSum << "\n";
            int xr = (n - x - 1);
            auto itrRight = lower_bound(indexesOnesFromLeft.begin(), indexesOnesFromLeft.end(), x);
            int ir = itrRight - indexesOnesFromLeft.begin();
            cout << "ir = " << ir << "\n\n";
            int kanan = prefFromRight[min(ir, n1 - 1)];
            // kalau ir di ujung tetapi bukan satu, gak dikurangi
            if (ir == n1 && !itrLeftB) {
                kanan = 0;
            }

            int banyakElemenKanan = xr * (ir);
            int rSum = (prefFromRight[0] - kanan) - banyakElemenKanan;
            cout << "prefFromRight[n1 - 1] = " << prefFromRight[0] << "\n";
            cout << "- kanan = " << kanan << "\n";
            cout << "- banyakElemenKanan = " << banyakElemenKanan << "\n";
            cout << "rSum = " << rSum << "\n";
            res = (lSum + rSum);
            cout << "res = " << res << "\n\n";
            ans[x] = res;
        }

        return ans;
    }
};