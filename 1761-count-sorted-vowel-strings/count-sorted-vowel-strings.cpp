class Solution {
public:
    // dimar's solution
    int G(int n){
      if (n == 1){
            return 1;
      }else{
            return G(n - 1) + n;
      }
    }

    int S(int n){
      if (n == 0){
            return 1;
      }else{
            return S(n - 1) + G(n + 1);
      }
    }

    int F(int n){
      if (n == 0){
            return 1;
      }else{
            return F(n - 1) + S(n);
      }
    }   

    int countVowelStrings(int n) {
          return F(n);
    }
};