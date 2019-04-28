/*
 * Project Title:
 * - The Conway's Game of Life
 * Description: 
 * This program implements Conway's Game of Life using object oriented programming in C++
 *
 * Developers:
 * - Kartikey Pandey - pandeykh@mail.uc.edu
 *
 * Help Received:
 * - Adedapo Alabi
 *
 * Developer comments: // Not optional
 * Developer 1:
 * Devloped the program's idea and implemented it
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Board{
public:
    int rows, columns;

    

/* Function Name: enterBoard
 *
 * Function Description:
 * This function inputs the board either by keyboard or from a file
 *
 * Parameters:
 * The firstBoard[][45] parameter is an empty board
 * The rows and columns parameters are the number of rows and columns
 *
 * return value:
 * void
 */

void enterBoard(char firstBoard[][45], int& rows, int& columns){
  int fileKeyboard;

  cout << "Would you like to load the data from a file(1) or keyboard(2)?" << endl;
  cin  >> fileKeyboard;

  do
  {
  if(fileKeyboard == 1)
    fileBoard(firstBoard, rows, columns);
  else if(fileKeyboard == 2)
    keyboardBoard(firstBoard, rows, columns);
  else
  {
    cout << "Please enter 1 for file or 2 for keyboard: ";
    cin  >> fileKeyboard;
  }
  }while(fileKeyboard < 1 || fileKeyboard > 2);
}

/* Function Name: fileBoard
 *
 * Function Description:
 * This function inputs the board from a file
 *
 * Parameters:
 * The firstBoard[][45] parameter is an empty board
 * The rows and columns parameters are the number of rows and columns
 *
 * return value:
 * void
 */
void fileBoard(char firstBoard[][45], int &rows, int &columns)
{
  char fileName[101];
  fstream infile;

  cout << "Please enter the location of the file: ";
  cin  >> fileName;
  infile.open(fileName, ios::in);
  infile >> rows;
  infile >> columns;

  for(int i =  1; i <= rows; i++)
  {
    for(int j = 1; j <= columns; j++)
    {
      infile >> firstBoard[i][j];
    }
  }
  infile.close();
}

/* Function Name: keyboardBoard
 *
 * Function Description:
 * This function inputs the board by keyboard
 *
 * Parameters:
 * The firstBoard[][45] parameter is an empty board
 * The rows and columns parameters are the number of rows and columns
 *
 * return value:
 * void
 */
void keyboardBoard(char firstBoard[][45], int &rows, int &columns){
  char again;
  int liveRow, liveCol;
 
  do{
  cout << "Please enter the number of rows between 5 and 20: ";
  cin  >> rows;
  }while(rows < 5 || rows > 20);

  do{
  cout << "Please enter the number of columns between 5 and 40: ";
  cin  >> columns;
  }while(columns < 5 || columns > 40);
   for(int i =  1; i <= rows; i++){
      for(int j = 1; j <= columns; j++)
      {
          firstBoard[i][j] = '-';
      }
  }
 
  cout << "Please enter the live cells" << endl;
 
  do{
      do{
          cout << "Please enter the row (between 1 and " << rows << "): ";
          cin  >> liveRow;
      }while(liveRow < 1 || liveRow > rows);
     
     do{
          cout << "Please enter the column (between 1 and " << columns << "): ";
          cin  >> liveCol;
      }while(liveCol < 1 || liveCol > columns);

      firstBoard[liveRow][liveCol] = '*';

      cout << "Would you like to add another live cell? (y/n): ";
      cin  >> again;
  }while(again == 'y' || again == 'Y');
 
}

/* Function Name: playGame
 *
 * Function Description:
 * This function intiated the game
 *
 * Parameters:
 * The currentBoard[][45] parameter is the current open board
 * The nextBoard[][45] parameter is the next board
 * The rows and columns parameters are the number of rows and columns
 * The rule parameter is to input the Rules
 *
 * return value:
 * void
 */
void playGame(char currentBoard[][45], char nextBoard[][45], int rows, int columns,vector<int>& rule){
  int numTurns;
  int neighbors;

  do{
      cout << "How many turns would you like to play? (Greater than 0): ";
      cin  >> numTurns;
  }while(numTurns < 1);
    
  displayBoard(currentBoard, rows, columns);

  for(int turns = 0; turns < numTurns; ++turns){
    
      for(int i = 1; i <= rows; i++){
     
          for(int j = 1; j <= columns; j++){
     
              neighbors = cellNeighbors(currentBoard, i, j);
              if (neighbors < rule[0])
                  nextBoard[i][j] = '-';
              else if (neighbors > rule[1])
                  nextBoard[i][j] = '-';
              else if (neighbors == rule[1])
                  nextBoard[i][j] = '*';
              else if (currentBoard[i][j] == '*' && neighbors == rule[0])
                  nextBoard[i][j] = '*';
              else
                  nextBoard[i][j] = '-';
          }

      }
      displayBoard(nextBoard, rows, columns);
      boardCopy(nextBoard, currentBoard);
  }
}

/* Function Name: restartGame
 *
 * Function Description:
 * This function retarts the game
 *
 * Parameters:
 * The currentBoard[][45] parameter is the current open board
 * The firstBoard[][45] parameter is the very first board
 * The rows and columns parameters are the number of rows and columns
 * The rule parameter is to input the Rules
 *
 * return value:
 * void
 */
void restartGame(char firstBoard[][45],char currentBoard[][45], int rows, int columns, vector<int> &rule){
  playGame(firstBoard, currentBoard, rows, columns, rule);
}

/* Function Name: displayBoard
 *
 * Function Description:
 * This function displays the board
 *
 * Parameters:
 * The board[][45] parameter is the board to display
 * The rows and columns parameters are the number of rows and columns
 *
 * return value:
 * void
 */
void displayBoard(char board[][45], int rows, int columns){
  char keepGoing;
  int i, j;
  float percent, live;

  live = 0;

  for(i = 1; i <= rows + 1; i++)
  {
      cout << "|";
      for(j = 1; j <= columns; j++)
      {
          if(board[i][j] != '*')
              board[i][j] = '.';

          cout << board[i][j];
        
      }

      cout << "|" << endl;
  }
  live = numLiveCells(board);
  percent = (live / (rows * columns)) * 100;

  cout << "Rows = " << rows << ", Columns = " << columns << ", Live = " << live << ", Pct = " << percent << endl;
  cout << "Press any letter or number to continue: ";
  cin  >> keepGoing;
}

/* Function Name: cellNeighbors
 *
 * Function Description:
 * This function returns the number of neighbors
 *
 * Parameters:
 * The board[][45] parameter is the open board
 * The rows and columns parameters are the number of rows and columns
 *
 * return value:
 * int:
 * returns the number of neisghbours
 */
int cellNeighbors(char board[][45], int row, int column){
  int neighbor;

  neighbor = 0;

  if(board[row-1][column-1] == '*')
      ++neighbor;
  if(board[row][column-1] == '*')
      ++neighbor;
  if(board[row-1][column] == '*')
      ++neighbor;
  if(board[row-1][column+1] == '*')
      ++neighbor;
  if(board[row+1][column-1] == '*')
      ++neighbor;
  if(board[row+1][column] == '*')
      ++neighbor;
  if(board[row][column+1] == '*')
      ++neighbor;
  if(board[row+1][column+1] == '*')
      ++neighbor;

return neighbor;
}

/* Function Name: boardCopy
 *
 * Function Description:
 * This function copies a board to another board
 *
 * Parameters:
 * The initBoard[][45] parameter is the board to copy
 * The newBoard[][45] parameter is the new copied board
 *
 * return value:
 * void
 *
 */
void boardCopy(char initBoard[][45], char newBoard[][45]){
  for(int i = 0; i < 25; i++)
  {
      for(int j = 0; j < 45; j++)
      {
          newBoard[i][j] = initBoard[i][j];
      }
  }
 }

/* Function Name: numLiveCells
 *
 * Function Description:
 * This function returns the number of neighbors
 *
 * Parameters:
 * The board[][45] parameter is the board to check
 * 
 *
 * return value:
 * float:
 * returns no. of live cells
 *
 */
float numLiveCells(char board[][45]){
  float live;
  live = 0.0f;
  for(int i = 1; i <= 20; i++)
  {
      for(int j = 1; j <= 40; j++)
      {
          if(board[i][j] == '*')
              ++live;
      }
  }
return live;
}

/* Function Name: boardCopy
 *
 * Function Description:
 * This function allows the user to change rules
 *
 * Parameters:
 * 
 *
 * return value:
 * vector<int>:
 * returns the new rules
 *
 */
vector<int> changeRules(){
  int choice=0;
  int overpopulation=4;
  int underpopulation=1;
  vector<int> rule;
  rule.push_back(underpopulation);
  rule.push_back(overpopulation);
  do{
    cout << "What rule do you wnat to change:" << endl;
    cout << "\t1) No. of neighbors for dying by solitude?" << endl;
    cout << "\t2) No. of neighbors for dying by population?" << endl;
    cin >> choice;
    if(choice==1){
      cout << "Enter the no. of neighbors on less than which a cell dies of solitude: ";
      cin >> underpopulation;
      rule[0]=underpopulation;
      return rule;
    }
    else if(choice==2){
      cout << "Enter the no. of neighbors on more than which a cell dies of overpopulation: ";
      cin >> overpopulation;
      rule[1]=overpopulation;
      return rule;
    }
    else{
      cout <<"Invalid Choice. Choose again" << endl;
    }
  }while(choice!=1||choice!=2);
}

/* Function Name: stop
 *
 * Function Description:
 * This function stops the game
 *
 * Parameters:
 * 
 *
 * return value:
 * void
 *
 */
void stop(){
  cout << "Goodbye" << endl;
}
};

/* Function Name: main
 *
 * Function Description:
 * This is the main function
 *
 * Parameters:
 * 
 *
 * return value:
 * int:
 * returns -1 or 0 depending on of the program runs successfully
 *
 */
int main(){
  char firstBoard[25][45], currentBoard[25][45], nextBoard[25][45];
  int choice, rows, columns;
  Board b1;

  cout << "Conway's Game of Life" << endl;
 
  cout<< "The Rules:-\nFor a space that is 'populated':\n\tEach cell with one or no neighbors dies, as if by solitude.\n\tEach cell with four or more neighbors dies, as if by overpopulation.\n\tEach cell with two or three neighbors survives.\nFor a space that is 'empty' or 'unpopulated':\n\tEach cell with three neighbors becomes populated."<<endl;
  vector<int> rule;
  rule.push_back(2);
  rule.push_back(3);
  b1.enterBoard(firstBoard, rows, columns);
  b1.boardCopy(firstBoard, currentBoard);
  b1.displayBoard(currentBoard, rows, columns);

  do
  {
      do
      {
          cout << "Menu" << endl
               << "(1) Play Game of Life" << endl
               << "(2) Restart the Game" << endl
               << "(3) Display the Current Board" << endl
               << "(4) Enter a New Board" << endl
               << "(5) Change Rules" << endl
               << "(6) Stop the Program" << endl;
          cout << "Please enter your choice between 1 and 6: ";
          cin  >> choice;
      }while(choice > 6 || choice < 1);
      if(choice == 1)
          b1.playGame(currentBoard, nextBoard, rows, columns, rule);
      else if(choice == 2)
          b1.restartGame(firstBoard, currentBoard, rows, columns, rule);
      else if(choice == 3)
          b1.displayBoard(currentBoard, rows, columns);
      else if(choice == 4)
          b1.enterBoard(firstBoard, rows, columns);
      else if(choice == 5)
          rule=b1.changeRules();
     else if(choice == 6)
      b1.stop();
  }while(choice !=6);
 return 0;
}
    