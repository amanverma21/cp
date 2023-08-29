class Solution {
 public:
  int bestClosingTime(string s) {
    int ans = 0;
    int profit = 0;
    int maxProfit = 0;
    for (int i = 0; i < s.length(); i++) {
      profit += s[i] == 'Y' ? 1:-1;
      // if(profit=='Y')
      //   profit = 1;
      // else
      //   profit = -1;
      if(profit>maxProfit){
          profit=maxProfit;
          ans = i + 1;
      }
    }
    return ans;
  }
};