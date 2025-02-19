class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        if(k > 3*(1<<(n-1))) return result;
        h(n, k, -1, result); 
        return result;
    }
private:
    void h(int n, int k, int lastChar, string&result){
        if(n==0) return; 
        for(int i=0;i<3;i++){ 
            if(i==lastChar) continue; 
            else{
                if(1<<(n-1) < k) k-=(1<<(n-1));
                else{
                    result.push_back(char(i + 'a'));
                    h(n-1, k, i, result);
                    return;
                }
            }
        }
    }
};