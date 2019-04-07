// Add your information here
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please replace this Point class with your version from Part B
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        setXY(0,0);
    }

    Point(double in_x, double in_y){
        setXY(in_x, in_y);
    }

    void setXY(double xin, double yin){
        x = xin;
        y = yin;
    }
    
    double getx(){
        return x;
    }

    double gety(){
        return y;
    }

    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }


    // Add your functions here
private:
    
    double x,y;
};

class Circle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, Circle &C ){
        output << "Center: " << C.P1 << endl << "Point on Circle: " << C.P2<<endl;
        output << "Is Circle?: " <<C.isCircle(C) << endl; 
        output << "Radius: " << C.getRadius(C) << endl;
        output << "Diameter: " << C.getDiameter(C) << endl;
        output << "Area: " << C.getArea(C) << endl;
        output << "Circumference: " << C.getCircum(C) << endl; 
        return output;
    }

    // implement cin for Circle classes objects
    friend istream & operator>>( istream &input, Circle &C ){
        input >> C.P1 >> C.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Circle(){
        Point P;
        setPoints(P,P);
    }

    Circle(Point in_P1, Point in_P2){
        setPoints(in_P1, in_P2);
    }

    void setPoints(Point P1_in, Point P2_in){
        P1=P1_in;
        P2=P2_in;
    }

    bool isCircle(Circle C){
        Point p1=C.getP1();
        Point p2=C.getP2();
        if(p1==p2)
            return false;
        else
            return true;
    }

    double getRadius(Circle C){
        Point p1=C.getP1();
        Point p2=C.getP2();

        return sqrt(pow((p1.gety()-p2.gety()),2)+pow((p1.getx()-p2.getx()),2));
    }

    double getDiameter(Circle C){
        return (2*C.getRadius(C));
    }

    double getArea(Circle C){
        return (M_PI*pow(C.getRadius(C),2));
    }

    double getCircum(Circle C){
        return (2*M_PI*C.getRadius(C));
    }

    bool operator==(Circle &rhs) {
        if(isCircle(rhs))
            return (rhs.P1 == P1 && rhs.P2 == P2);
        else
            return false;
    }


private:
    Point getP1(){
        return P1;
    }
    Point getP2(){
        return P2;
    }
    Point P1, P2;
};

int main(){
    Circle C1;
    // Circle C2(5,6,7,8);
    cout << "C1: should have all zeros for values" << endl;
    cout << C1 << endl;

    cout << "Enter Center followed by another point on the circle for C1: ";
    cin >> C1;
    cout << C1 << endl;

    Circle C2;
    cout << "Enter Center followed by another point on the circle for C2: ";
    cin >> C2;
    cout << C2 << endl;
    bool b= C1==C2;
    cout<<"Are the circles equal?: "<<b<<endl;
    return 0;
}
