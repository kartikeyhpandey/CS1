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

class Quad {
    // implement cout for Quad classes objects
    friend ostream & operator<<( ostream &output, Quad &Q ){
        output << "Point 1: " << Q.P1 <<"\t"<< "Point 2: " << Q.P2<<"\t"<< "Point 3: "<< Q.P3 << "\t" << "Point 4: " << Q.P4 << endl;
        output << "Is Quad?: " <<Q.isQuadilateral(Q) << endl; 
        output << "Area: " << Q.getArea(Q) << endl;
        return output;
    }

    // implement cin for Quad classes objects
    friend istream & operator>>( istream &input, Quad &Q ){
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }

public:
    // Add your functions/methods here //
    Quad(){
        Point P;
        setPoints(P,P,P,P);
    }

    Quad(Point in_P1, Point in_P2, Point in_P3, Point in_P4){
        setPoints(in_P1, in_P2, in_P3, in_P4);
    }

    void setPoints(Point P1_in, Point P2_in, Point P3_in, Point P4_in){
        P1=P1_in;
        P2=P2_in;
        P3=P3_in;
        P4=P4_in;
    }

    bool isQuadilateral(Quad Q){
        Point p1=Q.getP1();
        Point p2=Q.getP2();
        Point p3=Q.getP3();
        Point p4=Q.getP4();

        bool b1= (p1.getx()*(p2.gety()-p3.gety())+p2.getx()*(p3.gety()-p1.gety())+p3.getx()*(p1.gety()-p2.gety()) == 0);
        bool b2= (p2.getx()*(p3.gety()-p4.gety())+p3.getx()*(p4.gety()-p2.gety())+p4.getx()*(p2.gety()-p3.gety()) == 0);
        bool b3= (p1.getx()*(p3.gety()-p4.gety())+p3.getx()*(p4.gety()-p1.gety())+p4.getx()*(p3.gety()-p1.gety()) == 0);
        bool b4= (p1.getx()*(p2.gety()-p4.gety())+p2.getx()*(p4.gety()-p1.gety())+p4.getx()*(p1.gety()-p2.gety()) == 0);

        return !(b1==1||b2==1||b3==1||b4==1);
    }

    double getArea(Quad Q){
        Point p1=Q.getP1();
        Point p2=Q.getP2();
        Point p3=Q.getP3();
        Point p4=Q.getP4();
        return abs((p1.getx()*p2.gety()+p2.getx()*p3.gety()+p3.getx()*p4.gety()+p4.getx()*p1.gety()-p2.getx()*p1.gety()-p3.getx()*p2.gety()-p3.getx()*p2.gety()-p4.getx()*p3.gety()-p1.getx()*p4.gety())/2);
    }

    double getLength(Point p1, Point p2){
        return sqrt(pow((p1.gety()-p2.gety()),2)+pow((p1.getx()-p2.getx()),2));
    }



    bool operator==(Quad &rhs) {
        if(isQuadilateral(rhs))
            return (rhs.P1 == P1 && rhs.P2 == P2 && rhs.P3 == P3 && rhs.P4 == P4);
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
    Point getP4(){
        return P4;
    }
    Point P1, P2, P3, P4;
};

int main(){
    Quad Q1;
    cout << "Q1: should have all zeros for values" << endl;
    cout << Q1 << endl;

    cout << "Enter points on the Quad for Q1: ";
    cin >> Q1;
    cout << Q1 << endl;

    Quad Q2;
    cout << "Enter points on the Quad for Q2: ";
    cin >> Q2;
    cout << Q2 << endl;
    bool b= Q1==Q2;
    cout<<"Are the quadilaterals equal?: "<<b<<endl;
    return 0;
}
