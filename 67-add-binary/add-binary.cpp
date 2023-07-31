class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string result;
        while (carry || i >= 0 || j >= 0) {
            carry += (i >= 0) ? a[i--] - '0' : 0;
            carry += (j >= 0) ? b[j--] - '0' : 0;
            result = to_string(carry % 2) + result;
            carry /= 2;
        }
        return result;
    }
};
