#include <iostream>

using namespace std;
void setup(char board[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]='_';
        }
    }
}
void display(char board[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
char check(char board[3][3], char playerChar)
{
    if(board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar)
    {
        return playerChar;
    }
    else if(board[0][3] == playerChar && board[1][2] == playerChar && board[3][1] == playerChar)
    {
        return playerChar;
    }
    else if(board[0][0] == playerChar && board[0][1] == playerChar && board[0][2] == playerChar)
    {
        return playerChar;
    }
    else if(board[1][0] == playerChar && board[1][1] == playerChar && board[1][2] == playerChar)
    {
        return playerChar;
    }
    else if(board[2][0] == playerChar && board[2][1] == playerChar && board[2][2] == playerChar)
    {
        return playerChar;
    }
    else if(board[0][0] == playerChar && board[1][0] == playerChar && board[2][0] == playerChar)
    {
        return playerChar;
    }
    else if(board[0][1] == playerChar && board[1][1] == playerChar && board[2][1] == playerChar)
    {
        return playerChar;
    }
    else if(board[0][3] == playerChar && board[1][3] == playerChar && board[2][3] == playerChar)
    {
        return playerChar;
    }
    else
    {
        return 'n';
    }
}
char player(char board[3][3], char playerChar)
{
    int a,b;
    char ret;
    bool chk = false;
    do
    {
        cout<<"Enter indices:";
        cin>>a>>b;
        if(board[a][b] == '_')
        {
            chk = true;
            board[a][b] = playerChar;
            ret = check(board, playerChar);
        }
        else
            cout<<"Invalid Index!";
    }while(!chk);
    return ret;
}
int main()
{
    char board[3][3];
    setup(board);
    int p=0;
    char wincheck;
    display(board);
    for(int i=0; i<9; i++)
    {

        if(p == 0)
        {
            cout<<"\nPlayer 1 place X\n";
            wincheck = player(board, 'X');
            if(wincheck == 'X')
            {
                cout<<"\nPlayer 1 wins!";
                display(board);
                break;
            }
        }
        if(p == 1)
        {
            cout<<"\nPlayer 2 place O\n";
            wincheck = player(board, 'O');
            if(wincheck == 'O')
            {
                cout<<"\nPlayer 2 wins!";
                display(board);
                break;
            }
        }
        display(board);
        p = !p;
    }
    if(wincheck == 'n')
    {
        cout<<"\nIts a tie!";
    }
    return 0;
}
