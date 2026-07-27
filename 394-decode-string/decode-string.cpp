class Solution {
public:
    struct NumString {
        int rep;
        string strr;
    };

    string duplicate(int k, string s) {
        string res = "";
        while (k-- > 0) {
            res += s;
        }
        
        return res;
    }

    bool isNumber(char c) {
        return (c >= 48 && c <= 57);
    }

    int charToNum(char c) {
        return c - '0';
    }

    string decodeString(string s) {
        stack<NumString> st;
        st.push({1, ""});
        NumString currTop = st.top();
        string numS = "";
        for (char c : s) {
            bool isNum = isNumber(c);
            if (isNum) {
                numS += c;
            } else {
                // open bracket case
                if (c == '[') {
                    int rep = stoi(numS);
                    numS = "";
                    // cout << "Ketemu [" << "\n";
                    // cout << "currTop untuk dipush: " << currTop.rep << "&" << currTop.strr << "\n";
                    st.push(currTop);
                    currTop = {rep, ""};
                } else if (c == ']') {
                    // cout << "Ketemu ]\n";
                    // cout << "currTop rep untuk duplikat: " << currTop.rep << " strr: " << currTop.strr << "\n";
                    string repS = duplicate(currTop.rep, currTop.strr);
                    NumString topp = st.top();
                    st.pop();
                    currTop = {topp.rep, topp.strr + repS};
                    // cout << "currTop:\n" << "rep: " << currTop.rep << " str: " << currTop.strr << "\n\n";
                } else {
                    currTop.strr += c;
                }
            }
        }

        return currTop.strr;
    }
};