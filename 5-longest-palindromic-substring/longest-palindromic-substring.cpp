class Solution {
public:
    // dimar's solution
    string longestPalindrome(string s) {
        string s1 = "=";
        int n = s.length();
        for (int x = 0; x < n; x++){
            s1 += s[x];
        }

        s1 += "+";
        vector<int> idxHasil;
        for (int x = 1; x <= n; x++){
            int l = x - 1, r = x + 1, r1 = x + 1, l1 = x - 1;
            vector<int> sem;
            vector<int> sem1;
            sem1.push_back(x);
            sem.push_back(x);
            if (s1[x] == s1[r]){
                sem1.push_back(x + 1);
                r1++;
            }

            while (s1[l] == s1[r]){
                sem.push_back(l);
                sem.push_back(r);
                l--;
                r++;
            }

            while (s1[l1] == s1[r1]){
                sem1.push_back(l1);
                sem1.push_back(r1);
                l1--;
                r1++;
            }

            if (sem.size() > idxHasil.size()){
                idxHasil = sem;
            }

            if (idxHasil.size() < sem1.size()){
                idxHasil = sem1;
            }
        }

        sort(idxHasil.begin(), idxHasil.end());
        string hasil = "";
        for (int x = 0; x < idxHasil.size(); x++){
            hasil += s1[idxHasil[x]];
        }

        return hasil;
    }
};