class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> suppliesmap;
        vector<string> result;

        for(string s : supplies) suppliesmap[s] = true;

        for(int i = 0; i < recipes.size(); i++) {
            bool check = true;
            for(string s : ingredients[i]) {
                if(!suppliesmap[s]) {
                    check = false;
                }
            }
            if(check) {
                suppliesmap[recipes[i]] = true;
                result.push_back(recipes[i]);
                recipes.erase(recipes.begin() + i);
                ingredients.erase(ingredients.begin() + i);
                i = -1;
            }
        }

        return result;
    }
};