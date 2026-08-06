class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // cari min max
        int minn = 1;
        int maks = 0;
        for (int x : piles) {
            maks = max(maks, x);
        }

        //cout << "min: " << minn << "\n";
        //cout << "maks: " << maks << "\n";
        int l = minn, r = maks;
        int res = 0;
        bool more = 0;
        //cout << "l awal = " << l << "\n";
        //cout << "r awal = " << r << "\n";
        while (l <= r) {
                    //cout << "l: " << l << "\n";
                    //cout << "r: " << r << "\n";
            int mid = (l + r) / 2;
            long long hTotal = 0;
                    //cout << "mid: " << mid << "\n";
            for (int x : piles) {
                hTotal += (x + mid - 1) / mid;
            }
            
                    //cout << "hTotal: " << hTotal << "\n";
                    //cout << "hTotal vs h = " << hTotal << " vs " << h << "\n"; 
            if (hTotal > h) {
                        //cout << "MELEBIHI!\n\n";
                l = mid + 1;
            } else {
                res = mid;
                        //cout << "KURANG\n\n";
                r = mid - 1;
            }
        }

        return res;
    }
};