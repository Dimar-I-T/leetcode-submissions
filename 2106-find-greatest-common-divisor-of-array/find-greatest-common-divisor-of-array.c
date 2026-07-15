// dimar's solution
int gcd(int a, int b){
    if (a == 1 || b == 1){
        return 1;
    }else if (a == 0){
        return b;
    }else if (b == 0){
        return a;
    }    
    else{
        if (a > b){
            return gcd(a % b, b);
        }else{
            return gcd(a, b % a);
        }
    }
}

int findGCD(int* nums, int numsSize) {
    int minn = 1000;
    int maks = 0;
    for (int x = 0; x < numsSize; x++){
        if (minn > nums[x]){
            minn = nums[x];
        }

        if (maks < nums[x]){
            maks = nums[x];
        }
    }

    return gcd(minn, maks);
}