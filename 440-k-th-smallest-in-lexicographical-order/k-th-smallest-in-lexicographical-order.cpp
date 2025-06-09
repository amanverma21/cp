class Solution {
public:
    int countSteps(int n, long node1, long node2){
        int steps = 0;

        while(node1 <= n){
            steps += min((long)(n+1), node2) - node1;
            node1 *= 10;
            node2 *= 10;
        }

        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while(k > 0){
            int step = countSteps(n, curr, curr+1);
            if(step <= k){
                curr++;
                k -= step;
            }else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};