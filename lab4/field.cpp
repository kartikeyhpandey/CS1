#include <iostream>
#include <iomanip>
using namespace std;

const double Q=1e-9;
const double Ke=9e+9;

double Efield(double r, double a){
	if(r>=a)
		return (Ke*Q/(r*r));
	else
		return (Ke*Q*r/(a*a*a));
}

int main(){
	double r, a;

	cout<<"Enter r: "<<endl;
	cin>>r;

	cout<<"Enter a: "<<endl;
	cin>>a;

	double field= Efield(r,a);

	cout<<"Efield: ";
	cout<<field<<endl;
}