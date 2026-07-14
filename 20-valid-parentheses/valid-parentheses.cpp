class Solution {
public:
    // dimar's solution
    bool isValid(string s) {
        vector<char> v;
        unordered_map<char, char> cc;
        cc[')'] = '(';
        cc[']'] = '[';
        cc['}'] = '{';
        bool bisa = 1;
        for (int x = 0; x < s.length(); x++){
            if (s[x] == '(' || s[x] == '[' || s[x] == '{'){
                v.push_back(s[x]);
            }else {
                if (v.empty()){
                    bisa = 0;
                    break;
                }

                char c = v[v.size() - 1];
                if (cc[s[x]] != c){
                    bisa = 0;
                    break;
                }

                v.pop_back();
            }
        }

        if (!v.empty()){
            bisa = 0;
        }

        return bisa;
    }
};