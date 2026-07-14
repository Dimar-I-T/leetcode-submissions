// dimar's solution
int romanToInt(char* s) {
    int n = strlen(s);
    int des[20];
    for (int x = 0; x < n; x++){
        switch(s[x]){
            case 'I':
                des[x] = 1;
                break;
            
            case 'V':
                des[x] = 5;
                break;
            
            case 'X':
                des[x] = 10;
                break;
            
            case 'L':
                des[x] = 50;
                break;
            
            case 'C':
                des[x] = 100;
                break;

            case 'D':
                des[x] = 500;
                break;
            
            case 'M':
                des[x] = 1000;
                break;
        }
    }

    int hasil = 0;
    for (int x = 0; x < n - 1; x++){
        hasil = (des[x] < des[x + 1]) ? hasil - des[x] : hasil + des[x];
    }

    return hasil + des[n - 1];
}