class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            int len = s.length();
            if(len % 2 == 0) {
                int sum1 = 0, sum2 = 0;
                for(int j = 0; j < len / 2; j++) {
                    sum1 += s[j] - '0';
                    sum2 += s[j + len / 2] - '0';
                }
                if(sum1 == sum2)
                    count++;
            }
        }
        return count;
    }
};