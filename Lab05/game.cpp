#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDie(){
	return (rand()%6)+1;
}

bool playOneGame(int point){
	int rd;
	for(int i=0; i<3; i++){
		rd=rollDie();
		cout<<"Roll #"<<i+1<<" is "<<rd<<endl;
		if(rd==point){
			return true;
		}
	}
	return false;
}

bool isPointValid(int point){
	return (point>=1&&point<=6);
}

bool isWagValid(int wag, int accbal){
	return (wag>=0&&wag<=accbal);
}

double winPercentage(int wc, int c){
	return (wc*100.0)/c;
}

int main(){
	int accbal=100;
	int wag=1;
	int point;
	int c=0;
	int wc=0;
	double wp;
	srand(time(NULL));

	while(wag!=0&&accbal!=0){
		cout<<"Account balance $"<<accbal<<endl;
		cout<<"Enter wager (0 to exit): ";
		cin>>wag;
		cout<<endl;

		while(wag>accbal){
			cout<<"Error: You must wager less than your account balance (type 0 to exit): ";
			cin>>wag;
			cout<<endl;
		}

		while(isWagValid(wag, accbal)==false){
			cout<<"Error: You must wager between $1 and $"<<accbal<<" (type 0 to exit): ";
			cin>>wag;
			cout<<endl;
		}

		if(wag!=0){
			cout<<"Enter your point value (1 - 6): ";
			cin>>point;
			cout<<endl;

			while(isPointValid(point)==false){
				cout<<"Error: Enter your point value, must be between 1 and 6: ";
				cin>>point;
				cout<<endl;
			}

			if(playOneGame(point)==true){
				cout<<" ** You win! **"<<endl;
				accbal+=wag;
				wc++;
			}
			else{
				cout<<" ** You Lose **"<<endl;
				accbal-=wag;
			}
			c++;
		}

		if(wag==0){
			wp=winPercentage(wc,c);
			cout<<"Your final account balance is $"<<accbal<<endl;
			cout<<"You won "<<wc<<" time out of "<<c<<" for a winning percentage of "<<wp<<"%"<<endl;
		}

		if(accbal<=0){
			wp=winPercentage(wc,c);
			cout<<"Game over, you are out of money!"<<endl;
			cout<<"Your final account balance is $"<<accbal<<endl;
			cout<<"You won "<<wc<<" time out of "<<c<<" for a winning percentage of "<<wp<<"%"<<endl;
		}
	}

}