#include <iostream>
#include <cmath>
using namespace std;

const double TOLERANCE= 0.0001;

double f(double x){
	return (pow(x,4)+2*pow(x,3)-31*pow(x,2)-32*x+60);
}

double fprime(double x){
	return (4*pow(x,3)+6*pow(x,2)-62*x-32);
}

double newtonRoot(double x){
	double deltax;
	do{
			deltax= f(x)/fprime(x);
			x=x-deltax;
	}while(fabs(deltax)>TOLERANCE);
	return int(x);
}

int main(){
	double x;  char c;
	do{
		cout<<"Enter Guess: "<<endl;
		cin>>x;
		cout<<"Root: "<<newtonRoot(x)<<endl;
		cout<<"Enter Another Guess: y/n? "<<endl;
		cin>>c;
	}while(c=='y');
}