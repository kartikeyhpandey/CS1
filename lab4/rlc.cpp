#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi= 3.14159;

double Omega(double f){
	return 2*pi*f;
}
double TimePeriod(double f){
	return 1/f;
}

double appliedVoltage(double t, double E0, double omega){
	return (E0*sin(omega*t));
}

double CurrentAmplitude(double omega, double E0, double L, double R, double C){
	return ((omega*E0)/sqrt(pow(L*omega*omega-(1/C),2)+(R*R*omega*omega)));
}

double PhaseAngle(double omega, double L, double R, double C){
	return (atan((L*omega/R)-(1/(R*C*omega))));
}

double totalCurrent(double A, double phaseAng, double omega, double t){
	return (A*sin(omega*t - phaseAng));
}

double ResVoltDrop(double A, double R, double omega, double phaseAng, double t){
	return R*A*sin(omega*t-phaseAng);
}

double IndVoltDrop(double A, double L, double omega, double phaseAng, double t){
	return L*omega*A*cos(omega*t-phaseAng);
}

double CapVoltDrop(double A, double C, double omega, double phaseAng, double t){
	return ((-A/(C*omega))*cos(omega*t-phaseAng));
}

int main(){
	double E0, f, R, L, C, nstep;
	cout<<"Enter Applied voltage amplitude (Eo) - volts: "<<endl;
	cin>>E0;
	cout<<"Enter Line frequency (f) - hertz (= 1/sec): "<<endl;
	cin>>f;
	cout<<"Resistor value (R) - ohms (W): "<<endl;
	cin>>R;
	cout<<"Inductor value (L) - henrys: "<<endl;
	cin>>L;
	cout<<"Capacitor value (C) - F: "<<endl;
	cin>>C;
	cout<<"pts/AC period (nstep): "<<endl;
	cin>>nstep;

	cout<<endl;
	cout<<"RLC Circuit Summary:"<<endl;
	cout<<endl;
	cout<<"Voltage: "<<E0<<"-Volts @ "<<f<<"-Hz"<<endl;
    cout<<"Resistor Value: "<<R<<"-ohms"<<endl;
    cout<<"Inductor Value: "<<L<<"-H"<<endl;
    cout<<"Capacitor Value: "<<C<<"-F"<<endl;
    cout<<endl;
    
    double omega=Omega(f);
    double T=TimePeriod(f);
    double A=CurrentAmplitude(omega,E0,L,R,C);
    double phaseAng=PhaseAngle(omega, L, R, C);

    double AV, I, VR, VL, VC, VT;
    cout<<"Calculated Parameters:"<<endl;
    cout<<"Current Amplitude: "<<A<<endl;
    cout<<"Phase Angle: "<<phaseAng<<endl;
    cout<<endl;

    cout<<setw(5)<<"Iter.";
    cout<<setw(5)<<"Time";
    cout<<setw(5)<<"AV";
    cout<<setw(5)<<"I";
    cout<<setw(5)<<"VR";
    cout<<setw(5)<<"VL";
    cout<<setw(5)<<"VC";
    cout<<setw(5)<<"VT"<<endl;
    int c=0;
    for(double t=0; t<2*T; t+=nstep, c++){
		AV=appliedVoltage(t, E0, omega);
		I=totalCurrent(A, phaseAng, omega, t);
		VR=ResVoltDrop(A,R,omega,phaseAng,t);
		VL=IndVoltDrop(A,L,omega,phaseAng,t);
		VC=CapVoltDrop(A,C,omega, phaseAng, t);
		VT=VR+VC+VL;

		cout<<fixed;
		cout<<setw(5)<< setprecision(3)<<c;
   		cout<<setw(5)<< setprecision(3)<<t;
    	cout<<setw(5)<< setprecision(3)<<AV;
    	cout<<setw(5)<< setprecision(3)<<I;
    	cout<<setw(5)<< setprecision(3)<<VR;
    	cout<<setw(5)<< setprecision(3)<<VL;
    	cout<<setw(5)<< setprecision(3)<<VC;
	    cout<<setw(5)<< setprecision(3)<<VT<<endl;
	}
}
