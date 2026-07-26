class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        for (int x = 1; x < n; x++) {
            char prev = path[x - 1];
            char& curr = path[x];
            if (prev == '/' && curr == '/') {
                curr = ' ';
            }
        }

        path.erase(remove(path.begin(), path.end(), ' '), path.end());
        stringstream ss(path);
        string token;
        vector<string> dirs;
        while (getline(ss, token, '/')) {
            dirs.push_back(token);
        }
        
        // for (string s : dirs) {
        //     cout << s << "\n";
        // }

        stack<string> st;
        for (string s : dirs) {
            if (s == "") {
                continue;
            }

            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s == ".") {
                continue;
            } else {
                st.push(s);
            }
        }

        string res = "/";
        vector<string> resV;
        resV.reserve(st.size());
        while (!st.empty()) {
            resV.emplace_back(st.top());
            st.pop();
        }

        reverse(resV.begin(), resV.end());
        for (string s : resV) {
            res += s;
            res += "/";
        }

        if (res.length() > 1) {
            res = res.substr(0, res.length() - 1);
        }

        return res;
    }
};