#include <iostream>
#include <fstream>
using namespace std;
char gameboard[10] = {'0', '1', '2', '3', '4' ,'5' , '6' , '7' , '8'}; // game board chars. ABCDDEFG or 1234?
void board();
int AreUWinningComrade();
void deletefiles();

int main()
{
  int player = 1;
  int end = 1;
  char PlayerMark; //player mark. X and Os
  int choice; //choice of number
  int p1score = 0;
  int p2score = 0;
  char DeleteAns; //yes or no answers
  string line;
  // Creating .txt save files.
  ofstream savescorefilep1;
  savescorefilep1.open("scorep1.txt", fstream::app);
  ofstream savescorefilep2;
  savescorefilep2.open("scorep2.txt", fstream::app);
  // Creating .txt save files.
  do {
    board();
    player=(player%2)?1:2;
    
    cout << "Player " <<player << ", enter a number: "<<endl;
    
    cin >> choice;


    PlayerMark=(player == 1) ? 'X' : 'O'; //chooses to put an X or an O

    if (choice == 0 && gameboard[0] == '0')
      gameboard[0] = PlayerMark;

    else if (choice == 1 && gameboard[1] == '1')
      gameboard[1] = PlayerMark;

    else if (choice == 2 && gameboard[2] == '2')
      gameboard[2] = PlayerMark;

    else if (choice == 3 && gameboard[3] == '3')
      gameboard[3] = PlayerMark;

    else if (choice == 4 && gameboard[4] == '4')
      gameboard[4] = PlayerMark;

    else if (choice == 5 && gameboard[5] == '5')
      gameboard[5] = PlayerMark;

    else if (choice == 6 && gameboard[6] == '6')
      gameboard[6] = PlayerMark;

    else if (choice == 7 && gameboard[7] == '7')
      gameboard[7] = PlayerMark;

    else if (choice == 8 && gameboard[8] == '8')
      gameboard[8] = PlayerMark;

      else
      {
       cout << "Move is invalid.";

       player--;
       cin.ignore();
       cin.get(); 
       exit(0);
      }
      end = AreUWinningComrade();

  system("CLS");
  cout << gameboard;
      player++;
  } while(end == -1);
  player--;
  board();
  if(end==1)
  {
    cout << "Player" << player << " wins!" <<endl;

    if(player==1)
    {
      savescorefilep1 << "a" <<endl;
      savescorefilep1.close();
    }
    else if (player==2)
    {
      savescorefilep2 << "b" <<endl;
      savescorefilep1.close();
    }
  }
  else
  {
    cout << "Game draw." <<endl;
  }

  ifstream score1("scorep1.txt");
  ifstream score2("scorep2.txt");

  while (getline(score1, line))
  {
    ++p1score;
  }

  while (getline(score2, line))
  {
    ++p2score;
  }

  cout << "Player 1 score is: " << p1score<<endl;
  cout << "Player 2 score is: " << p2score<<endl;
  //new code by moi -N
  cout<<endl;
  cout << "Would you like to reset the scores? Y/N"<<endl;
  cin >> DeleteAns;
  
  if (DeleteAns=='Y')
  {
    deletefiles();
    exit(0);
  }
  else if (DeleteAns=='N')
  {
    exit(0);
  }  
  //new code ends here
  cin.ignore();
  cin.get();
  


	return 0;

  
}




int AreUWinningComrade() //Func. for winning russian style
{
  if(gameboard[0] == gameboard[1] && gameboard[1] == gameboard[2])
    return 1;

  else if(gameboard[3] == gameboard[4] && gameboard[4] == gameboard[5])
    return 1;

  else if(gameboard[6] == gameboard[7] && gameboard[7] == gameboard[8])
    return 1;
    
  else if(gameboard[0] == gameboard[3] && gameboard[3] == gameboard[6])
    return 1;

  else if(gameboard[1] == gameboard[4] && gameboard[4] == gameboard[7])
    return 1;

  else if(gameboard[2] == gameboard[5] && gameboard[5] == gameboard[8])
    return 1;

  else if(gameboard[0] == gameboard[4] && gameboard[4] == gameboard[8])
    return 1;

  else if(gameboard[2] == gameboard[4] && gameboard[4] == gameboard[6])
    return 1;

  else if(gameboard[0] != '0' && gameboard[1] !=  '1' && gameboard[2] != '2'
  && gameboard[3] != '3' && gameboard[4] != '4' && gameboard[5] != '5' && gameboard[6] != '6' && gameboard[7] != '7'
  && gameboard[8] != '8')
  
  	return 0;
  	
  else 
    return -1;

  
}

void deletefiles()//new insert if this fails uhhhh erase it -N
{
  ofstream score1;
  score1.open("scorep1.txt", ios::trunc);
  ofstream score2;
  score2.open("scorep2.txt", ios::trunc);

  score1.close();
  score2.close();
}

void board() //Func for drawing the board. use ____ ||| and box[1] vars.
{
  
cout << "Player X --- Player O" <<endl <<endl;

//cout << "   |   |   "<<endl;
cout << "  " <<gameboard[0] << " | " << gameboard[1] << " | "<< gameboard[2]<<endl;
cout << " " <<"___|___|___" <<endl;
cout << " " <<"   |   |   " <<endl;
cout << "  " <<gameboard[3] << " | " << gameboard[4] << " | " << gameboard[5]<<endl;
cout << " " <<"___|___|___" <<endl;
cout << " " <<"   |   |   " <<endl;
cout << "  " <<gameboard[6] << " | " << gameboard[7] << " | " << gameboard[8] <<endl;
}








