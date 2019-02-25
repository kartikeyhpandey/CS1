#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

const int ROW_SIZE = 15;
const int COL_SIZE = 15;
char board[ROW_SIZE][COL_SIZE];

vector<int> userLoc;
vector<int> MuskLoc;
vector<int> YugoLoc;
vector<int> FordLoc;
vector<int> RoadsterLoc;

int randNUM(){
	return (rand()%(16));
}

void initBoard(char fill_char) {
    for(int r = 0; r < ROW_SIZE; r++) {
         for(int c  = 0; c < COL_SIZE; c++) {
              board[r][c] = fill_char;
         }
    }
}

void randLocation(){
	char emptySpace= '*';

	initBoard(emptySpace);
	int randX, randY;

	do{
			randX = randNUM();
			randY = randNUM();
	}while(board[randX][randY]!='*');
	board[randX][randY]='M';
	MuskLoc.push_back(randX);
	MuskLoc.push_back(randY);

	do{
			randX = randNUM();
			randY = randNUM();
	}while(board[randX][randY]!='*');
	board[randX][randY]='Y';
	YugoLoc.push_back(randX);
	YugoLoc.push_back(randY);

	do{
			randX = randNUM();
			randY = randNUM();
	}while(board[randX][randY]!='*');
	board[randX][randY]='F';
	FordLoc.push_back(randX);
	FordLoc.push_back(randY);

	do{
			randX = randNUM();
			randY = randNUM();
	}while(board[randX][randY]!='*');
	board[randX][randY]='R';
	RoadsterLoc.push_back(randX);
	RoadsterLoc.push_back(randY);

	do{
			randX = randNUM();
			randY = randNUM();
	}while(board[randX][randY]!='*');
	board[randX][randY]='U';
	userLoc.push_back(randX);
	userLoc.push_back(randY);

}

void display(){
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			char loc=board[i][j];
			if(loc=='*'||loc=='U')
				cout<<loc<<" ";
			else
			{
				if(board[i-1][j-1]=='U'||board[i][j-1]=='U'||board[i+1][j-1]=='U'||board[i-1][j]=='U'||board[i+1][j]=='U'||board[i-1][j+1]=='U'||board[i][j+1]=='U'||board[i+1][j+1]=='U')
					cout<<loc<<" ";
				else
					cout<<'*'<<" ";
			}
		}
		cout<<endl;
	}
}

void move(char m){
	board[userLoc[0]][userLoc[1]]='*';
	switch(m){
		case 'w':
			userLoc[0]=userLoc[0]-1;
			board[userLoc[0]][userLoc[1]]='U';
			break;
		case 'a':
			userLoc[1]=userLoc[1]-1;
			board[userLoc[0]][userLoc[1]]='U';
			break;
		case 's':
			userLoc[0]=userLoc[0]+1;
			board[userLoc[0]][userLoc[1]]='U';
			break;
		case 'd':
			userLoc[1]=userLoc[1]+1;
			board[userLoc[0]][userLoc[1]]='U';
			break;
		default:
			board[userLoc[0]][userLoc[1]]='U';
			cout<<"Invalid Move"<<endl;
	}
}

void musk(){
	char moves[]={'w','a','s','d'};
	int rn= rand()%4;
	board[MuskLoc[0]][MuskLoc[1]]='*';
	switch(moves[rn]){
		case 'w':
			MuskLoc[0]=MuskLoc[0]-1;
			board[MuskLoc[0]][MuskLoc[1]]='M';
			break;
		case 'a':
			MuskLoc[1]=MuskLoc[1]-1;
			board[MuskLoc[0]][MuskLoc[1]]='M';
			break;
		case 's':
			MuskLoc[0]=MuskLoc[0]+1;
			board[MuskLoc[0]][MuskLoc[1]]='M';
			break;
		case 'd':
			MuskLoc[1]=MuskLoc[1]+1;
			board[MuskLoc[0]][userLoc[1]]='M';
			break;
		default:
			cout<<"Invalid Move"<<endl;
	}
}
double winPercentage(int wc, int c){
	return (wc*100.0)/c;
}
void hint(){
	if(userLoc[0]==RoadsterLoc[0])
		cout<<"\nYou are in the right row!!\n"<<endl;
	else if(userLoc[1]==RoadsterLoc[1])
		cout<<"\nYou are in the right column!!\n"<<endl;
}
void game(){
	int c=0;
	int wc=0;
	char userInput;
	int muskCount=0;
	randLocation();
	int muskMove=0;
	int input;
	do{
		c++;
		do{
			display();
			cout<<"\nEnter w/a/s/d to move: (Enter 0 to quit) ";
			cin>>userInput;
			if(userInput!='0')
				move(userInput);
			else
				break;
			
			if(board[userLoc[0]][userLoc[1]-1]=='M'||board[userLoc[0]-1][userLoc[1]]=='M'||board[userLoc[0]+1][userLoc[1]]=='M'||board[userLoc[0]][userLoc[1]+1]=='M'){
				if(muskCount==1){
					userInput=0;
					muskMove=0;
					cout<<"Elon Musk caught you!";
				}
				else{
					cout<<"Beware! Elon Musk is awake!";
					muskCount++;
					muskMove=1;
				}
			}

			if(muskMove==1)
					musk();

			if(userLoc==RoadsterLoc){
				cout<<"\nCongratulations! You found the Roadster!"<<endl;
				wc++;
				userInput=0;
				break;
			}
			else if(userLoc==YugoLoc){
				cout<<"\nYou are the Starman now, you got into Yugo"<<endl;
				userInput=0;
			}
			else if(userLoc==FordLoc){
				cout<<"\nYou are the Starman now, you got into Ford"<<endl;
				userInput=0;
			}
			else if(userLoc==MuskLoc){
				cout<<"\nYou are the Starman now, you woke up Elon Musk"<<endl;
				userInput=0;
			}
			hint();
		}while(userInput!=0);

		cout<<"\nGame Over!"<<endl;
		cout<<"Enter 1 if you want to play again, enter 0 to exit."<<endl;
		cin>>input;
	}while(input!=0);

	cout<<"You won "<<wc<<" time out of "<<c<<" for a winning percentage of "<<winPercentage(wc,c)<<"%"<<endl;
	cout<<"Good Bye!"<<endl;
}

int main(){
	srand(time(NULL));
	cout<<"Hello, welcome to SAVE THE ROADSTER!!\n"<<endl;
	cout<<"Story:\nYou find your way to SpaceX the night before the Roadster is mounted atop the rocket which is to send it into space.\nThe building is dark and the roadster is hidden somewhere in large open dark room (15x15).\nIn addition to the roadster, two other cars (a Yugo and ford pinto) are being stored in this facility as well.\n\nBTW: Elon Musk is sleeping somewhere in the same room and you have to avoid waking him to find your way to the roadster.\nOnce awoken he will randomly move through the building looking for you.\nIf he lands next to you, you can get away from him only once.\nThe second time you will be the “Starman” and blasted into space with his roadster.\nOnce he is a awake your only chance to avoid being “Starman” is to make your escape in his roadster.\nIf you get into either of the other two cars you will be caught and become the “Starman”."<<endl;
	cout<<"\nRules:"<<endl;
	cout<<"1) You can use w/a/s/d keys:\nw (forward/north),\na (left/west),\ns (backward/south),\nd (right/east)."<<endl;
	cout<<"2) You can quit anytime."<<endl;
	cout<<"\nIcons Used:"<<endl;
	cout<<"U - You\nM - Elon Musk\nR - Roadster\nY - Yugo\nF - Ford Pinto\n* - Empty Space\n"<<endl;
	 
	game();
}