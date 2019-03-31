// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    setString("");
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
   setString(in_string);
}

// retrieve function
string stringManip::retrieve(){
    // finish me
    return tobeEdited;
}

void stringManip::setString(string a){
    tobeEdited=a;
}

// padString() function
void stringManip::padString(int length){
    string s=retrieve();
    int l=s.length();
    if(l<length){
        for(int i=1; i<=(length-l); i++){
            s=s+" ";
        }
    }
    setString(s);
}

void stringManip::chop(){

    string s= retrieve();
    int length= s.length();
    do{
        if(s[0]==' '){
        s=s.substr(1,length-2);
        }
        length--;
    }while(s[0]==' ');

    do{
        if(s[length-1]==' '){
            s=s.substr(0,length-1);
        }
        length--;
    }while(s[length-1]==' ');
    setString(s);
}

void stringManip::center(int length){
    stringManip S2(retrieve());
    S2.chop();
    int l=S2.retrieve().length();
    string s = S2.retrieve();
    int diff=length-l;
    if(length>l){
        if(!(diff%2==0)){
            for(int i=0; i<diff/2; i++){
                s=" "+s;
            }
            for(int i =0; i<=(diff/2); i++){
                s+=" ";
            }
        }
        else{
             for(int i=0; i<diff/2; i++){
                s=" "+s;
            }
            for(int i =0; i<(diff/2); i++){
                s+=" ";
            }
        }
        
    }
    setString(s);

}

void stringManip::truncate(int n){
    string s = retrieve();
    setString(s.substr(0,n));
}

void stringManip::removeNonAlpha(){
    string str= retrieve();
    int i = 0;
    int len = str.length();
    while(i < len){
    if (!isalnum(str[i]) || str[i] == ' '){
        str.erase(i,1);
        len--;
    }else
        i++;
    }

    setString(str);
}

void stringManip::convertToLowerCase(){
    string s = retrieve();
    string s2="";
    int l=s.length();
    for(int i=0; i<l; i++){
        s2+=tolower(s[i]);
    }
    setString(s2);
}

void stringManip::convertToUpperCase(){
    string s = retrieve();
    string s2="";
    int l=s.length();
    for(int i=0; i<l; i++){
        s2+=toupper(s[i]);
    }
    setString(s2);
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123");

    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;
    stringManip S3(" thing1  ");
    S3.center(10);

    cout<<"<"<<S3.retrieve()<<">"<<endl;
  
    return 0;
}