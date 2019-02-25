#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

int randNum(int randMax){
    return (rand()%(randMax+1));
}

vector<int> freqVector(int numSample, int randMax){
    vector<int> freqCount(randMax+1);
    for(int i=0; i<numSample; i++){
        int randSample = randNum(randMax);
        freqCount[randSample]+=1;
    }
    return freqCount;
}

int maxVec(vector<int>& freqCount){
    int max=freqCount[0];
    for(unsigned int i=0; i<freqCount.size();i++){
        if(freqCount[i]>=max){
            max=freqCount[i];
        }
    }
    return max;
}

int minVec(vector<int>& freqCount){
    int min=freqCount[0];
    for(unsigned int i=0; i<freqCount.size();i++){
        if(freqCount[i]<=min){
            min=freqCount[i];
        }
    }
    return min;
}

int sumVec(vector<int>& freqCount){
    int sum=0;
    for(unsigned int i=0; i<freqCount.size();i++){
        sum+=freqCount[i];
    }
    return sum;
}

double mean(vector<int>& freqCount){
    return sumVec(freqCount)/double(freqCount.size());
}

void barPrint(int value, int scale){
    int N=value/scale;
    for (int i=0; i<N; i++){
        cout<<"*";
    }
}
int main()
{
    int randMax, numSample;

    cout<<"Enter End Range: ";
    cin>>randMax;
    cout<<endl;

    cout<<"Enter number of Samples: ";
    cin>>numSample;
    cout<<endl;

    vector<int> freqCount=freqVector(numSample,randMax);

    int scale= maxVec(freqCount)/50;
    if(scale==0)
        scale=1;

    cout<<setw(5)<<"Index"<<"\t";
    cout<<setw(5)<<"Value"<<"\t";
    cout<<"Bar";
    cout<<endl;

    for(unsigned int i=0; i<freqCount.size(); i++){
        cout<<setw(5)<<i<<"\t";
        cout<<setw(5)<<freqCount[i]<<"\t";
        barPrint(freqCount[i],scale);
        cout<<endl;
    }

    cout<<"Scale: "<<scale<<" per *"<<endl;
    cout<<endl;

    cout<<"Range: 0 to "<<randMax<<endl;
    cout<<"Sample Count: "<<numSample<<endl;
    cout<<"Min Value: "<<minVec(freqCount)<<endl;
    cout<<"Max Value: "<<maxVec(freqCount)<<endl;
    cout<<"Sum Value: "<<sumVec(freqCount)<<endl;
    cout<<"Mean Value: "<<mean(freqCount)<<endl;

    return 0;
}
