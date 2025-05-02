class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0, j = 0;

        while(i < n && j < n && i <= j){
            while(i < n && dominoes[i] == '.'){
                i++;
            }
            while(j < n && dominoes[j] == '.' || i == j){
                j++;
            }
            if(i >= n || j >= n) break;
            if(dominoes[i] == 'R' && dominoes[j] == 'L'){
                for(int k = 1; k <= (j-i-1)/2; k++){
                    dominoes[i+k] = 'R';
                    dominoes[j-k] = 'L';
                }
            }
            else if(dominoes[i] == 'L' && dominoes[j] == 'L'){
                for(int k = 0; k <= (j-i-1)/2 + 1; k++){
                    dominoes[i+k] = 'L';
                    dominoes[j-k] = 'L';
                }
            }
            else if(dominoes[i] == 'R' && dominoes[j] == 'R'){
                for(int k = 1; k <= (j-i-1)/2 + 1; k++){
                    dominoes[i+k] = 'R';
                    dominoes[j-k] = 'R';
                }
            }
            i = j;
        }   

        if(dominoes[0] == '.'){
            i = 0;
            while(i < n && dominoes[i] == '.'){
                i++;
            }
            if(i < n){
                if(dominoes[i] == 'L'){
                    while(i >= 0){
                        dominoes[i] = 'L';
                        i--;
                    }
                }
            }
        }
        if(dominoes[n-1] == '.'){
            i = n-1;
            while(i >= 0 && dominoes[i] == '.'){
                i--;
            }
            if(i >= 0){
                if(dominoes[i] == 'R'){
                    while(i < n){
                        dominoes[i] = 'R';
                        i++;
                    }
                }
            }
        }
        return dominoes;
    }
};