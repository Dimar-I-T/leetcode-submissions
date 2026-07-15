class Solution {
public:
    // dimar's solution
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        string sDP = "";
        map<string, bool> DP;
        DP[""] = true;
        for (int x = 0; x < s.length(); x++){
            sDP += s[x];
            for (int y = 0; y < n; y++){
                if (sDP.length() >= wordDict[y].length()){
                    string sek = wordDict[y];
                    bool bisaUjung = false;
                    if (sDP.substr(sDP.length() - sek.length(), sek.length()) == sek){
                        bisaUjung = true;
                    }

                    if (DP[sDP.substr(0, sDP.length() - sek.length())] && bisaUjung){
                        DP[sDP] = true;
                    }
                }
            }
        }

        return DP[s];
    }
};