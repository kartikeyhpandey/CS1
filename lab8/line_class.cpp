// Add your information here

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

    Point(int in_x, int in_y){
        setXY(in_x, in_y);
    }

    void setXY(int xin, int yin){
        x = xin;
        y = yin;
    }
    
    int getx(){
        return x;
    }

    int gety(){
        return y;
    }

    // Add your functions here
private:
    
    int x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){
        Point P;
        setPoints(P,P);
    }

    Line(Point in_P1, Point in_P2){
        setPoints(in_P1, in_P2);
    }

    void setPoints(Point P1_in, Point P2_in){
        P1=P1_in;
        P2=P2_in;
    }

    double getSlope(Line L){
        Point p1=L.getP1();
        Point p2=L.getP2();

        return (p1.gety()-p2.gety())/(p1.getx()-p2.getx());
    }

    double getLength(Line L){
        Point p1=L.getP1();
        Point p2=L.getP2();

        return sqrt(pow((p1.gety()-p2.gety()),2)+pow((p1.getx()-p2.getx()),2));
    }

    double getYintercept(Line L){
        Point p1=L.getP1();

        return (p1.gety()-(L.getSlope(L)*p1.getx()));
    }

    bool vertical(Line L){
        Point p1=L.getP1();
        Point p2=L.getP2();

        if(P1.getx()==P2.getx()){
            return true;
        }

        return false;
    }

    bool horizontal(Line L){
        Point p1=L.getP1();
        Point p2=L.getP2();

        if(P1.gety()==P2.gety()){
            return true;
        }

        return false;
    }

    bool isParallel(Line L1, Line L2){
        if(getSlope(L1)==getSlope(L2)){
            return true;
        }

        return false;
    }

    void display(Line L){
        cout << "Line Properties: " << endl;
        cout << "Slope: " << getSlope(L) << endl;
        cout << "Length: " << getLength(L) << endl;
        cout << "getYintercept: " << getYintercept(L) << endl;
        cout << "Vertical?: " << vertical(L) << endl;
        cout << "Horizontal?: " << horizontal(L) << endl << endl;
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
    Line L1;
    // Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;
    L1.display();

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;
    L1,.display();
    return 0;
}
