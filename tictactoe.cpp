#include<bits/stdc++.h>
using namespace std;
char tic[3][3] ={{'1','2','3'}, {'4','5','6'} ,{'7','8','9'}};
int choice;
int row , column;
char turn ;
bool draw = false;
// function to display board
void display_board()
{
     cout<<"TIC TAC TOE !!!!"<<endl;
     cout<<"\t |  "<<"   "<<"  |  "<<endl;
     cout<<"\t"<<tic[0][0]<<"|  "<<"  "<<tic[0][1]<<"  |  "<<tic[0][2]<<endl;
     cout<<"\t |  "<<"   "<<"  |  "<<endl;
      cout<<"-------------------------"<<endl;
     cout<<"\t |  "<<"   "<<"  |  "<<endl;
 cout<<"\t"<<tic[1][0]<<"|  "<<"  "<<tic[1][1]<<"  |  "<<tic[1][2]<<endl;
      cout<<"\t |  "<<"   "<<"  |  "<<endl;
       cout<<"-------------------------"<<endl;
      cout<<"\t |  "<<"   "<<"  |  "<<endl;
    cout<<"\t"<<tic[2][0]<<"|  "<<"  "<<tic[2][1]<<"  |  "<<tic[2][2]<<endl;
      cout<<"\t |  "<<"   "<<"  |  "<<endl;

}
void func()
{   if(turn == 'x')
cout<<"\n player 1[X] turn"<<endl;
else if(turn == '0')
 {cout<<"\n player 2[0] turn "<<endl;}

    cout<<"enter your choice"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1 : row = 0 , column = 0;
        break;
         case 2 : row = 0 , column = 1;
        break;
         case 3 : row = 0 , column = 2;
        break;
         case 4 : row = 1 , column = 0;
        break;
         case 5 : row = 1 , column = 1;
        break;
         case 6 : row = 1 , column = 2;
        break;
         case 7 : row = 2, column = 0;
        break;
         case 8 :row = 2, column = 1;
        break;
         case 9 : row = 2, column = 2;
        break;
         default:
            cout<<"invalid input  "<<endl;
    }
    // check the block is empty or full and place x or 0 at correct place
    if(turn == 'x' && (tic[row][column]!= 'x' || tic[row][column]!= '0'))
    {
        tic[row][column] = 'x';
        turn = '0';
    }
    else if(turn == '0' && tic[row][column]!= 'x' || tic[row][column]!= '0')
    {
        tic[row][column] = '0';
        turn = 'x';
    }
    else
        { cout<<"the blocks are full"<<endl;
    func();
        }
        display_board();

}
//this function will calculate result
bool result()
{
    for( int i=0;i<3 ;i++)
    {
        if(tic[i][0]==tic[i][1]&& tic[i][0]==tic[i][2] || tic[0][i]==tic[1][i]&& tic[0][i]==tic[2][i]) //checking rows and column
        return false;
    }
         if(tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2] || tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0])  //checking diagonals
    return false;
    for(int i =0;i<3;i++)
        {for(int j = 0; j<3;j++)
         {if(tic[i][j]!='x'||tic[i][j]!='0')
          {
                return true;
          }
           }
          }
    draw = true;
    return false;

}
int main()
{string a , b;
    cout<<"player 1 --> X";
    cin>>a;
    cout<<"\nplayer 2--> 0";
cin >>b;
    cout<<"\n whoose turn "<<endl;
    cin>>turn;

cout<<"tttT I C K -- T A C -- T O E -- G A M Ettt";
    cout<<"nttttFOR 2 PLAYERSnttt";
    while(result()){
        display_board();
        func();
        result();
    }
    if(turn == 'x' && draw == false)
        cout<<"nnCongratulations!Player  " <<b<< "has won the game";

    else if(turn == '0' && draw == false)
        cout<<"nnCongratulations!Player "<<a<<"  has won the game";

    else if(draw == true)
    cout<<"nnGAME DRAW!!!nn";


cout<<" won!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

    return 0;
}
