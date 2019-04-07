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

class Triangle {
    // implement cout for Triangle classes objects
    friend ostream & operator<<( ostream &output, Triangle &T ){
        output << "Point 1: " << T.P1 <<"\t"<< "Point 2: " << T.P2<<"\t"<< "Point 3: "<<T.P3<<endl;
        output << "Is Triangle?: " <<T.isTriangle(T) << endl; 
        output << "Area: " << T.getArea(T) << endl;
        output << "Perimeter: " << T.getPerimeter(T) << endl;
        output << "Is Equilateral Triangle?: " << T.isEquilateral(T) << endl;
        return output;
    }

    // implement cin for Triangle classes objects
    friend istream & operator>>( istream &input, Triangle &T ){
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }

public:
    // Add your functions/methods here //
    Triangle(){
        Point P;
        setPoints(P,P,P);
    }

    Triangle(Point in_P1, Point in_P2, Point in_P3){
        setPoints(in_P1, in_P2, in_P3);
    }

    void setPoints(Point P1_in, Point P2_in, Point P3_in){
        P1=P1_in;
        P2=P2_in;
        P3=P3_in;
    }

    bool isTriangle(Triangle T){
        Point p1=T.getP1();
        Point p2=T.getP2();
        Point p3=T.getP3();
        return !(p1.getx()*(p2.gety()-p3.gety())+p2.getx()*(p3.gety()-p1.gety())+p3.getx()*(p1.gety()-p2.gety()) == 0);
    }

    double getArea(Triangle T){
        Point p1=T.getP1();
        Point p2=T.getP2();
        Point p3=T.getP3();
        return abs((p1.getx()*(p2.gety()-p3.gety())+p2.getx()*(p3.gety()-p1.gety())+p3.getx()*(p1.gety()-p2.gety()))/2);
    }

    double getLength(Point p1, Point p2){
        return sqrt(pow((p1.gety()-p2.gety()),2)+pow((p1.getx()-p2.getx()),2));
    }

    double getPerimeter(Triangle T){
        if(isTriangle(T)==0)
          return 0;
        Point p1=T.getP1();
        Point p2=T.getP2();
        Point p3=T.getP3();
        return (T.getLength(p1,p2)+T.getLength(p2,p3)+T.getLength(p3,p1));
    }

    bool isEquilateral(Triangle T){
        if(isTriangle(T)==0)
          return false;
        Point p1=T.getP1();
        Point p2=T.getP2();
        Point p3=T.getP3();
        double l1=T.getLength(p1,p2);
        double l2=T.getLength(p2,p3);
        double l3=T.getLength(p3,p1);
        return (l1 == l2 && l2 == l3 && l3 == l1);
    }

    bool operator==(Triangle &rhs) {
        if(isTriangle(rhs))
            return (rhs.P1 == P1 && rhs.P2 == P2 && rhs.P3 == P3);
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
    Point getP3(){
        return P3;
    }
    Point P1, P2, P3;
};

int main(){
    Triangle T1;
    cout << "T1: should have all zeros for values" << endl;
    cout << T1 << endl;

    cout << "Enter points on the Triangle for T1: ";
    cin >> T1;
    cout << T1 << endl;

    Triangle T2;
    cout << "Enter points on the Triangle for T2: ";
    cin >> T2;
    cout << T2 << endl;
    bool b= T1==T2;
    cout<<"Are the triangles equal?: "<<b<<endl;
    return 0;
}
