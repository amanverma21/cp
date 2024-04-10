class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        vector<int> reveal(n);
        for (int i = 0; i < n; i++) {
            reveal[i] = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        vector<int> order(n);
        for (int i = 0; i < n; i++) {
            order[reveal[i]] = deck[i];
        }
        return order;
    }
};