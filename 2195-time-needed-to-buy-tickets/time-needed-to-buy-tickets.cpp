class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int seconds = 0;
        while(true)
        {
            for(int i = 0; i < tickets.size(); i++)
            {
                if(tickets[i] == 0) continue;
                else
                {
                    tickets[i]--;
                    seconds ++;
                    if(i == k && tickets[i] == 0) break;
                }
            }
            if(!tickets[k]) break;
        }
        return seconds;
    }
};