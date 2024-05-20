//Valid sudoko checking and Sudoko solving using recursion & backtracking

// ANAND KUMAR PADAKALA
#include <bits/stdc++.h>
using namespace std;

class solution
{
      bool isvalids(int row,int col,char check,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==check || board[i][col]==check) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==check)  return false;
        }
        return true;
        
    }

    bool isvalid(int row,int col,char check,vector<vector<char>>& board)
    {
        int count1=0,count2=0,count3=0;
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==check) count1++;
            if(board[i][col]==check) count2++;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==check) count3++;
            if((count1==2 || count2==2) || count3==2) return false;
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                if(board[row][col]!='.')
                {
                    if(!isvalid(row,col,board[row][col],board)) return false;
                } 
            }
        }
        return true;
        
    }

    bool sudokosolve(vector<vector<char>>& board)
    {
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]=='.')
                {
                    for(char check='1';check<='9';check++)
                    {
                        if(isvalids(row,col,check,board))
                        {
                            board[row][col]=check;
                            if(sudokosolve(board))
                            {
                                return true;
                            }
                            else board[row][col]='.';                           
                        }
                    }
                    return false;
                }
            }           
        }
        return true;
    }   



};

int main()
{
  vector<vector<char>> board(9,vector<char>(9,'.'));
  cout<<"The Sudoko board initially:"<<endl;
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"\n\n";
  cout<<"enter the inputs of the sudoko board as shown above:"<<endl;
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      cin>>board[i][j];
    }
  }

  solution obj;

  if(!obj.isValidSudoku(board))
  {
    cout<<"ENTERED SUDOKO IS NOT VALID!!!!!. enter correctly";
    exit(-1);
  }

  obj.sudokosolve(board);

  cout<<"\n\nTHE SOLUTION IS:"<<endl;

    for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;


  


  
}