#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    //check in the row
    for(int i=0; i<n;i++)
    {
        if(board[row][i] == 'Q') return false;
    }

    //Check diagonal
    int i = row;
    int j = col;
    while(i>=0 && j>=0)
    {
        if(board[i][j] == 'Q') return false;
        i--;
        j--;
    }

     i = row;
     j = col;
    while(i<n && j>=0)
    {
        if(board[i][j] == 'Q') return false;
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<char>> &board, int n, int c, vector<vector<int>> &ans)
{
    if(c == n)
    {
        //Found valid config
        vector<int>temp;
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<n ;i++)
            {
                if(board[j][i] == 'Q')
                {
                    temp.push_back(i);
                }
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int r = 0; r<n ;r++)
    {
        if(board[r][c] != 'Q')
        {
            if(isSafe(r, c, board, n))
            {   cout<<"\nGoing for c: "<<c<<" r: "<<r<<endl;
                board[r][c] = 'Q';
                solve(board, n, c+1, ans);
                board[r][c] = '.';
            }
        }
    }
}

void nQueens(int n, vector<vector<int>> &ans)
{
    vector<vector<char>> board(n, vector<char>(n,'.'));
    
    int c = 0;
    cout<<"\nInside func";
    solve(board, n, c, ans);
}
int main()
{
    int n;
    cout<<"\n\n Enter N: ";
    cin>>n;
    vector<vector<int>> ans;
    nQueens(n, ans);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<"\n Configuration "<<i+1<<" : \n";
        for(int j=0; j<n; j++)
        {
            cout<<" "<<ans[i][j];
        }
    }
    return 0;
}