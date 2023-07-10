class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode (char ch){
        data= ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal =false;
    }
};
class WordDictionary {
 TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode('\0');
    }
    void addWordUtil(TrieNode* root ,string word){
        if(word.size()==0){
            root->isTerminal =true;
            return ;
        }
        int index= word[0]-'a';
        TrieNode* child;
        if(root->children[index]==NULL){
            child= new TrieNode(word[0]);
          root->children[index]=child;
        }else{
            child=  root->children[index];
        }
      addWordUtil(child,word.substr(1));  
    }
    void addWord(string word) {
        return addWordUtil(root,word);
    }

     bool search(string word) {
        TrieNode *cur = root;
        return searchT(cur,0,word);
    }
    
      bool searchT(TrieNode* cur,int idx,string word){
       if(word.size()==idx){
          return  cur->isTerminal;
       }
       if(word[idx]=='.'){
           for(int i=0;i<26;i++){
             if(cur->children[i]&& searchT(cur->children[i],idx+1,word))
             return true; 
           }
       }else{
           int i=word[idx]-'a';
          if(cur->children[i]&& searchT(cur->children[i],idx+1,word))
             return true; 
       }
       return false;
    }
   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
