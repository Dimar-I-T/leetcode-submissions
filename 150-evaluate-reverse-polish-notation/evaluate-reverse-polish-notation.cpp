class Solution {
public:
    // dimar's solution
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        unordered_map<string, bool> operatorr;
        operatorr["+"] = 1;
        operatorr["-"] = 1;
        operatorr["*"] = 1;
        operatorr["/"] = 1;
        int A[10001] = {0}, i = 0;
        for (int x = 0; x < n; x++){
            if (!operatorr[tokens[x]]){
                A[i] = stoi(tokens[x]);
                i++;
            }else{
                //cout << tokens[x] << "\n";
                if (tokens[x] == "+"){
                    A[i - 2] += A[i - 1]; 
                    //cout << A[i - 2] << "\n";
                }else if (tokens[x] == "-"){
                    A[i - 2] -= A[i - 1];
                }else if (tokens[x] == "*"){
                    A[i - 2] *= A[i - 1];
                }else if (tokens[x] == "/"){
                    A[i - 2] /= A[i - 1];
                }

                A[i - 1] = 0;
                i--;
            }
        }   

        return A[0];
    }
};