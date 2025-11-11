#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Design n-Queens matrix having first Queen placed. Use backtracking to place remaining Queens to generate the final n-queen


void printBoard(vector<vector<int>>board, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    //1. check same columns
    for(int i=0;i<row;i++)
    {
        if(board[i][col] == 1) return false;
    }

    //2. check upper left diagonal
    for(int i=row-1, j=col-1; i>=0 &&j>=0; i--, j--)
    {
        if(board[i][j] == 1) return false;
    }

    //3. check upper right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--,j++)
    {
        if(board[i][j] == 1) return false;
    }

    return true;
}


bool solveNQueens(vector<vector<int>>&board, int row, int n)
{
    if(row == n)
    {
        return true;
    }

    // if queen already present in same row -> Skip, move to next row
    if(find(board[row].begin(),board[row].end(),1) != board[row].end())
    {
        return solveNQueens(board,row+1,n);
    }

    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col] = 1;
            if(solveNQueens(board,row+1,n)) return true;

            board[row][col] = 0; //backtrack
        }
    }

    return false;
}


int main()
{
    int n;
    cout<<"\nEnter board size: ";
    cin>>n;

    vector<vector<int>>board(n,vector<int>(n,0));

    cout<<"\nInitial Board: "<<endl;
    printBoard(board,n);

    int firstRow, firstCol;
    cout<<"\nEnter row of placed queen: ";
    cin>>firstRow;
    cout<<"\nEnter column of placed queen: ";
    cin>>firstCol;

    if(firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n)
    {
        cout<<"\nEnter valid position on board"<<endl;
        return 0;
    }

    board[firstRow][firstCol] = 1;
    cout<<"\nFirst Queen Placed: "<<endl;
    printBoard(board, n);

    if(solveNQueens(board, 0, n))
    {
        cout<<"\nAll queens are placed !!"<<endl;
        printBoard(board,n);
    }
    else
    {
        cout<<"\nNo solution exists with the first queen at the given position."<<endl;
    }

    return 0;
}