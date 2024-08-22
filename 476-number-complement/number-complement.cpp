class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1; 
        unsigned int ans = ~0; 
        while (num & ans) {
            ans <<= 1;
        }
        return num ^ ~ans;
    }
};