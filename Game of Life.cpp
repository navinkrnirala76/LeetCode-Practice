class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
int m=board[0].size();
vector<vector<int>> grid=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
               // int t=board[i][j];
                int live=0,dead=0;
               // if(t==1){
                    if(i-1>=0  && j-1>=0)
                    {
                        int t1=board[i-1][j-1];
                        if(t1==0)dead++;
                        else live++;
                    }
                     if(i-1>=0  )
                    {
                        int t1=board[i-1][j];
                        if(t1==0)dead++;
                        else live++;
                    }

                    if(i-1>=0  && j+1<m)
                    {
                        int t1=board[i-1][j+1];
                        if(t1==0)dead++;
                        else live++;
                    }
                    if(i>=0  && j-1>=0)
                    {
                        int t1=board[i][j-1];
                        if(t1==0)dead++;
                        else live++;
                    }
                    if( j+1<m)
                    {
                        int t1=board[i][j+1];
                        if(t1==0)dead++;
                        else live++;
                    }
                    if(i+1<n  && j-1>=0)
                    {
                        int t1=board[i+1][j-1];
                        if(t1==0)dead++;
                        else live++;
                    }
                     if(i+1<n  )
                    {
                        int t1=board[i+1][j];
                        if(t1==0)dead++;
                        else live++;
                    }
                     if(i+1<n  && j+1<m)
                    {
                        int t1=board[i+1][j+1];
                        if(t1==0)dead++;
                        else live++;
                    }
                 
if(board[i][j]==1)
{
    if(live<2)grid[i][j]=0;
    if(live==2 || live==3)grid[i][j]=1;
    if(live>3)grid[i][j]=0;
}
else if(board[i][j]==0)
{
    if(live==3)grid[i][j]=1;
}
    else
    grid[i][j]=board[i][j];            
            }
        }
        board=grid;
        
        
    }
};
