class Solution {
public:
bool search(vector<vector<char>> &b, string w,int r,int c){
    
    if(w.empty()){
        return true;
    }
    
    char val=b[r][c];
    b[r][c]='*';
    char ch=w[0];
    bool dis=false;
    if(r>0){
        if(b[r-1][c]==ch){
           
            dis=dis||search(b,w.substr(1),r-1,c);
    
          
        }
    }
    if(c>0){
        if(b[r][c-1]==ch){
            
            dis=dis||search(b,w.substr(1),r,c-1);
           
        }
    }
    if(r<b.size()-1){
        if(b[r+1][c]==ch){
            dis=dis||search(b,w.substr(1),r+1,c);
            
        }
    }
    if(c<b[0].size()-1){
        if(b[r][c+1]==ch){
            dis=dis||search(b,w.substr(1),r,c+1);
          
        }
    }
   b[r][c]=val;
    return dis;
}
    bool exist(vector<vector<char>>& b, string w) {
        vector<vector<int>> start;
        
        vector<vector<int>> cord;
       
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                if(b[i][j]==w[0]){
                    cord.push_back({i,j});

                }
                
                
            }
        }
        
        for(auto v:cord){
            if(search(b,w.substr(1),v[0],v[1]))return true;
            
        }

        return false;}
};
