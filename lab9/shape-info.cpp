// Add your information here
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class Point {

    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

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

    void setXY(int xin, int yin){
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

private:
    
    double x,y;
};

class Circle {
    friend ostream & operator<<( ostream &output, Circle &C ){
        output << "Radius of the Circle: " << C.getRadius(C) << " units" << endl;
        output << "Diameter of the Circle: " << C.getDiameter(C) << " units" << endl;
        output << "Area of the Circle: " << C.getArea(C) <<  " sq. units" << endl;
        output << "Circumference of teh Circle: " << C.getCircum(C) << " units" << endl; 
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

class Triangle {
    // implement cout for Triangle classes objects
    friend ostream & operator<<( ostream &output, Triangle &T ){
        output << "Area of the Triangle: " << T.getArea(T) << " sq. units" << endl;
        output << "Perimeter of the Triangle: " << T.getPerimeter(T) << " units" << endl;
        if(T.isEquilateral(T))
            output << "The triangle is an equilateral triangle" << endl;
        else
            output << "The triangle is not an equilateral triangle" << endl;
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

class Quad {
    // implement cout for Quad classes objects
    friend ostream & operator<<( ostream &output, Quad &Q ){
        output << "Area of the Quadilateral: " << Q.getArea(Q) << " sq. units" << endl;
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

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;    
        numdata.push_back(temp);
    }

    return numdata;
}

int main(){
    ifstream infile;
    infile.open("shapes.txt");
    string str;
    ofstream outfile;
    outfile.open("shapes-info.txt");
    vector<double> vec;
    if (infile.is_open()){
        while ( getline (infile, str) ){
            vec=breakupstring(str);
            switch(vec.size()){
                case 4: {outfile<<"Sufficient coordinates input.\n";
                        Point P1(vec[0],vec[1]);
                        Point P2(vec[2],vec[3]);
                        Circle C(P1,P2);
                        if(C.isCircle(C)){
                            outfile<<"The object is a Circle.\n";
                            outfile<<C;
                        }
                        else
                            outfile<<"The object is not a Circle.\n";
                        break;
                        }
                case 6: {outfile<<"Sufficient coordinates input.\n";
                        Point p1(vec[0],vec[1]);
                        Point p2(vec[2],vec[3]);
                        Point p3(vec[4],vec[5]);
                        Triangle T(p1,p2,p3);
                        if(T.isTriangle(T)){
                            outfile<<"The object is a Triangle.\n";
                            outfile<<T;
                        }
                        else
                            outfile<<"The object is not a Triangle.\n";
                        break;
                        }
                case 8: {outfile<<"Sufficient coordinates input.\n";
                        Point Po1(vec[0],vec[1]);
                        Point Po2(vec[2],vec[3]);
                        Point Po3(vec[4],vec[5]);
                        Point Po4(vec[6],vec[7]);
                        Quad Q(Po1,Po2,Po3,Po4);
                        if(Q.isQuadilateral(Q)){
                            outfile<<"The object is a Quadilateral.\n";
                            outfile<<Q;
                        }
                        else
                            outfile<<"The object is not a Quadilateral.\n";
                        break;
                        }
                default:outfile<<"Sufficient coordinates NOT input.\n";
            }
            outfile<<"\n";
        }
    }

    outfile.close();
    infile.close();
