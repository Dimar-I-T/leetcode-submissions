// dimar's solution
bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }

    char sx[11];
    sprintf(sx, "%d", x);
    int len = strlen(sx);
    for (int i = 0; i < len/2; i++){
        if (sx[i] != sx[len - i - 1]){
            return false;
        }
    }

    return true;
}