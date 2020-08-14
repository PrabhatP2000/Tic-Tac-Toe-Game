#include<iostream>
using namespace std;

class game
{
private:
	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int choice{0},row{0},column{0};

public:
	char turn='X';
	bool draw=false;

	
	void welcome()
	{
		cout<<"\tWelcome to the Tic Tak Toe Game\n"<<endl;

		cout<<"\tTik Tok Toe Game\t\n\n"<<endl;
	    cout<<"\tPlayer1 [X]\t Player2 [O]\t\n\n"<<endl;

	}

	void display_board()
	{
    system("cls");
	cout<<"\t\t                 |                 |             "<<endl;
	cout<<"\t\t\t"<<board[0][0]<<"\t |\t"<<board[0][1]<<"\t   |\t"<<board[0][2]<<endl;
	cout<<"\t\t                 |                 |             "<<endl;
	cout<<"\t\t ----------------|-----------------|-------------"<<endl;
	cout<<"\t\t                 |                 |             "<<endl;
	cout<<"\t\t\t"<<board[1][0]<<"\t |\t"<<board[1][1]<<"\t   |\t"<<board[1][2]<<endl;
	cout<<"\t\t                 |                 |             "<<endl;
	cout<<"\t\t ----------------|-----------------|-------------"<<endl;
	cout<<"\t\t                 |                 |             "<<endl;
	cout<<"\t\t\t"<<board[2][0]<<"\t |\t"<<board[2][1]<<"\t   |\t"<<board[2][2]<<endl;
	cout<<"\t\t                 |                 |             "<<endl;

	cout<<"\n\n";
    }


    void player_turn()
    {
    	if(turn=='X')
    		cout<<"\n\tPlayer1 [X] turn: ";

    	else if(turn=='O')
    		cout<<"\n\tPlayer2 [O] turn: ";
    	cin>>choice;

    	switch(choice)
    	{
    		case 1: row=0; column=0; break;
    		case 2: row=0; column=1; break;
    		case 3: row=0; column=2; break;
    		case 4: row=1; column=0; break;
    		case 5: row=1; column=1; break;
    		case 6: row=1; column=2; break;
    		case 7: row=2; column=0; break;
    		case 8: row=2; column=1; break;
    		case 9: row=2; column=2; break;
    		default:cout<<"\tInvalid Choice Entered";
    	}

    	if (turn=='X' && board[row][column]!='X' && board[row][column]!='O')
    	{
    		board[row][column]='X';
    		turn='O';
    	}
    	else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O')
    	{
    		board[row][column]='O';
    		turn='X';
    	}
    	else
    	{
    		
    		cout<<"\tEntry already Done\n";
    		cout<<"\tPlease Try again\n\n";
    	}
    }

    bool game_over()
    {
    	for (int i = 0; i < 3; i++)
    	{
    	  if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i] || board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0])
    	  {
    	     return false;
    	  }
    	}
    	
    

    	for (int i = 0; i < 3; i++)
    	{
    	 for (int j = 0; j < 3; j++)
    	 {
          if (board[i][j]!='X' && board[i][j]!='O')
          {
          	return true;
          }
         }
      }
       
       draw=true;
       return false;

   }
    

 
	
};


int main()
{
	game obj;
	obj.welcome();
	while(obj.game_over())
	{
    obj.display_board();
	obj.player_turn();
	obj.game_over();
	}

	if (obj.turn=='X' && obj.draw==false)
	{
		cout<<"\tPlayer2 [O] Wins!!  Congratulations\n";
	}
	else if(obj.turn=='O' && obj.draw==false)
	{
		cout<<"\tPlayer1 [X] Wins!!  Congratulations\n";
	}
	else
		cout<<"\tGame Draw!!\n";
	

	return 0;
}