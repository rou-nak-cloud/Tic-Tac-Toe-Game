#include<iostream>
#include<ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char winner);
bool checkTie(char *spaces);

int main(){

    char player = 'X';
    char computer = 'O';
    bool running = true;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    drawBoard(spaces);
    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
        

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, computer, player))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    std::cout <<"**Thanks for playing**"<<std::endl;

    return 0;
}
void drawBoard(char *spaces){
    std::cout<<'\n';
    std::cout <<"     |     |     " << std::endl;
    std::cout <<"  "<<spaces[0]<< "  |  "<<spaces[1]<< "  |  "<<spaces[2]<< "  " << std::endl;
    std::cout <<"_____|_____|_____" << std::endl;
    std::cout <<"     |     |     " << std::endl;
    std::cout <<"  "<<spaces[3]<< "  |  "<<spaces[4]<< "  |  "<<spaces[5]<< "  " << std::endl;
    std::cout <<"_____|_____|_____" << std::endl;
    std::cout <<"     |     |     " << std::endl;
    std::cout <<"  "<<spaces[6]<< "  |  "<<spaces[7]<< "  |  "<<spaces[8]<< "  " << std::endl;
    std::cout <<"     |     |     " << std::endl;
    std::cout<<'\n';
}
void playerMove(char *spaces, char player){
     int number;
     do
     {
        std::cout << "Enter your position (1-9): " <<std::endl;
        std::cin>>number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
      //  else{
      //    std::cout << "That position is taken. Try again." << std::endl};
     } while (!number > 0 || !number < 8);
     
}
void computerMove(char *spaces, char computer){
     int number; 
     srand(time(NULL));

     while (true)
     {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
        
     }
     
}
bool checkWinner(char *spaces, char player, char winner){
    //ROWS 
     if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
     {
        spaces[0] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
     {
        spaces[3] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
     {
        spaces[6] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
    //COLUMNS
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
     {
        spaces[0] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
     {
        spaces[1] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
     {
        spaces[2] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     } 
     //DIAGONALS
     else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
     {
        spaces[0] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
     {
        spaces[2] == player ? std::cout << "You Win\n" :  std::cout << "You Loose\n";
     }
     else{
        return false;
     }
    return true;
}
bool checkTie(char *spaces){
    
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }    
    std::cout << "It's a TIE!!!"<<std::endl;

    return true;
}