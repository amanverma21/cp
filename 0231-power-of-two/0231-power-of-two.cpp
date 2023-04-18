class Solution {
public:
    bool isPowerOfTwo(int num) {
        while(num > 1) {
            if(num % 2)return false;
            num /= 2;
        }
        return num == 1;
    }
};