class Solution {
public:
	void dfs(int x, int y, vector<vector<int>>& v, vector<vector<char>>& board){
		v[x][y]=1;
		if(x>0 && board[x-1][y]=='O' && !v[x-1][y]){
			dfs(x-1, y, v, board);
		}
		if(y>0 && board[x][y-1]=='O' && !v[x][y-1]){
			dfs(x, y-1, v, board);
		}
		if(x<board.size()-1 && board[x+1][y]=='O' && !v[x+1][y]){
			dfs(x+1, y, v, board);
		}
		if(y<board[0].size()-1 && board[x][y+1]=='O' && !v[x][y+1]){
			dfs(x, y+1, v, board);
		}
	}
	void dfs1(int x, int y, vector<vector<int>>& v, vector<vector<char>>& board){
		v[x][y]=1;
		board[x][y]='X';
		if(x>0 && board[x-1][y]=='O' && !v[x-1][y]){
			dfs1(x-1, y, v, board);
		}
		if(y>0 && board[x][y-1]=='O' && !v[x][y-1]){
			dfs1(x, y-1, v, board);
		}
		if(x<board.size()-1 && board[x+1][y]=='O' && !v[x+1][y]){
			dfs1(x+1, y, v, board);
		}
		if(y<board[0].size()-1 && board[x][y+1]=='O' && !v[x][y+1]){
			dfs1(x, y+1, v, board);
		}
	}
	void solve(vector<vector<char>>& board) {
		vector<vector<int>>v(board.size(), vector<int>(board[0].size(), 0));
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[0].size(); j++){
				if(!v[i][j] && (i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='O'){
					dfs(i, j, v, board);
				}
			}
		}
		// for(int i=0; i<board.size(); i++){
		//     for(int j=0; j<board[0].size(); j++){
		//         cout<<v[i][j]<<" ";
		//     }cout<<endl;
		// }cout<<endl;
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[0].size(); j++){
				if(!v[i][j] && i && j && board[i][j]=='O'){
					dfs1(i, j, v, board);
				}
			}
		}
	}
};
