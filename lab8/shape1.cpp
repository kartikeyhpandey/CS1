
#include <iostream>
using namespace std;

class Cuboid{
public:
    Cuboid(){
        setW(0);
        setL(0);
        setH(0);
    }

    Cuboid(double in_w, double in_l, double in_h){
        setW(in_w);
        setL(in_l);
        setH(in_h);
    }

    double getW(){
        return w;
    }

    double getL(){
        return l;
    }

    double getH(){
    	return h;
    }

    void setW(double in_w){
        w = in_w;
    }

    void setL(double in_l){
        l = in_l;
    }

    void setH(double in_h){
        h = in_h;
    }

    void display(){
        cout << "Cuboid Parameters: " << endl;
        cout << "Width: " << getW() << endl;
        cout << "Length: " << getL() << endl;
        cout << "Height: " << getH() << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }

private:
    double getArea(){
        return 2*l*h + 2*w*h + 2*l*w;
    }

    double getVolume(){
        return l*h*w;
    }

    double w;
    double l;
    double h;

};

int main(){

    Cuboid Cubo1;
    Cubo1.display();

    Cuboid Cubo2(2,4,3);
    Cubo2.display();
   
    Cubo2.setW(3);
    Cubo2.display();

    return 0;
}
