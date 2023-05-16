class Solution {
public:
string reverseVowels(string str) {
char vow[10] = {'a','e','i','o','u','A','E','I','O','U'};
unordered_set <int>s;
for(auto ch: vow){
s.insert(ch);
}
int start = 0, end = str.size()-1;
while(start<end){
if(s.find(str[start])!=s.end() && s.find(str[end])!=s.end()){
swap(str[start], str[end]);
start++;
end--;
}
else if(s.find(str[start])!=s.end()){
end--;
}
else if(s.find(str[end])!=s.end()){
start++;
}
else {
start++;
end--;
}
}
return str;
}
};

