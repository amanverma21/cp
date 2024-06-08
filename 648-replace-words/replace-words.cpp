struct TrieNode
{
    bool wordend;
    TrieNode* child[26];
    TrieNode ()
    {
        wordend = false;
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
    }
};
class Solution 
{
private:
    TrieNode* root = new TrieNode();
public:
    void insert(string word)
    {
        TrieNode* temp = root;
        for (char c:word)
        {
            int index = c - 'a';
            if (!(temp->child[index]))
            {
                temp->child[index] = new TrieNode();
            }
            temp = temp->child[index];
        }
        temp->wordend = true;
    }
    string modify(string word)
    {
        TrieNode* temp = root;
        string res = "";
        for(char c:word)
        {
            int index = c-'a';
            if(!temp->child[index])
            {
                return word;
            }
            res += c;
            temp = temp->child[index];
            if(temp->wordend == true)
            {
                return res;
            }
            
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        for(string word:dictionary)
        {
            insert(word);
        }
        string result = "";
        vector<string> words;
        string str = "";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]!=' ')
            {
                str += sentence[i];
            }
            else
            {
                words.push_back(str);
                str = "";
            }
        }
        words.push_back(str);
        for (string word:words)
        {
            result += modify(word);
            result += " ";
        }
        return result.substr(0,result.length()-1);
    }
};