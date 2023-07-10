class Solution {
public:

    int m,n;
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    struct trie{
        trie* chil[26] = {NULL};
        int dn = -1;
    };

    void solve(vector<vector<char>>&board,vector<string>&ans,string &cur,int x,int y,trie* tt){

        //If next dfs character doesn't exist, returning..
        if(tt==NULL || tt->chil[board[x][y]-'a']==NULL)
            return;
        
        cur += board[x][y];
        
        tt = tt->chil[board[x][y]-'a'];

        char tmp = board[x][y];
        board[x][y] = '0';

        if(tt->dn==0){
            tt->dn = 1;
            ans.push_back(cur);
        }
            
        
        for(int i=0;i<4;i++){
            int a = x + dir[i][0],b = y + dir[i][1];
            if(a>=0 && a<m && b>=0 && b<n && board[a][b]!='0')
                solve(board,ans,cur,a,b,tt);
        }
        
        board[x][y] = tmp;
        cur.pop_back();
    }   


    vector<string> findWords(vector<vector<char>>& board, vector<string>& wds) {
        m = board.size();
        n = board[0].size();

        //building trie
        trie* tt = new trie();
        for(auto it:wds){
            trie* k = tt;
            for(int i=0;i<it.size();i++){
                if(k->chil[it[i]-'a']==NULL)
                    k->chil[it[i]-'a'] = new trie();
                k = k->chil[it[i]-'a'];
                if(i==(it.size()-1))
                    k->dn = 0;
            }
        }

        vector<string>ans;
        string cur = "";

        //checking all possible strings, starting from each character
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                solve(board,ans,cur,i,j,tt);
        
        return ans;
    }
};
