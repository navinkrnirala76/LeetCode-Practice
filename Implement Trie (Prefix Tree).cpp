class Trie {
public:
    unordered_map<char,vector<string>>mp;
    unordered_map<string,int>src;
    Trie() {
        unordered_map<char,vector<string>>ip;
        mp=ip;
    }
    
    void insert(string word) {
        mp[word[0]].push_back(word);
        src[word]++;
        
    }
    
    bool search(string word) {
        if(src[word]>0) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto x:mp[prefix[0]]){
            if(x.find(prefix)==0) return true;
        }
        return false;
    }
};
