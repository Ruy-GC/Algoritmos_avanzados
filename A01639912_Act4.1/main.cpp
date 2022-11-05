/*
Actividad 4.1 Implementación Intersección y proximidad aplicando geometría computacional.
Ruy Guzmán Camacho A01639912
Luis David lópez Magaña A00344656
04/11/2022
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;

    Point(int x, int y): x(x), y(y){}
};

struct Segment {
    Point p1;
    Point p2;

    Segment(Point p1, Point p2): p1(p1), p2(p2){}
};

int crossProd(Point p0, Point p1, Point p2){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

//Functiosn that finds the orientation of the triplet
//O(1)
string orientation(Point p0, Point p1, Point p2){
    // p1, p2 and p3 are points: [x, y]
    int crossProductResult = crossProd(p0, p1, p2);
    
    if(crossProductResult < 0)
        return "clock";

    if(crossProductResult > 0)
        return "counter";
    
    return "collinear";
}

//Function that  checks if point1 lies in the segment made from p0 and p2
//O(1)
bool onProjection(Point p0, Point p1, Point p2){
    //p1, p2 and p3 are points: [x, y]
    return (p1.x <= max(p0.x, p2.x) ) 
        && (p1.x >= min(p0.x, p2.x) )
        && (p1.y <= max(p0.y, p2.y) ) 
        && (p1.y >= min(p0.y, p2.y) );
}

//Function that returns true if segments a & b intersect
//O(n log n): n representing the points in the segments a & b
bool areIntersecting(Segment a,Segment b){
    //a and b are segments: [[x1,y1],[x2,y2]]
    string oa1 = orientation(a.p1, a.p2, b.p1);
    string oa2 = orientation(a.p1, a.p2, b.p2);
    string ob1 = orientation(b.p1, b.p2, a.p1);
    string ob2 = orientation(b.p1, b.p2, a.p2);
    
    //General case
    if (oa1 != oa2 && ob1 != ob2)
        return true;
        
    //Special case
    if ((oa1 == "collinear") && onProjection(a.p1, b.p1, a.p2))
        return true;
    if ((oa2 == "collinear") && onProjection(a.p1, b.p2, a.p2))
        return true;
    if ((ob1 == "collinear") && onProjection(b.p1, a.p1, b.p2))
        return true;
    if ((ob2 == "collinear") && onProjection(b.p1, a.p2, b.p2))
        return true;

    return false;
}

int main(){
    int nPoints = 0;
    cin >> nPoints;

    while (nPoints % 4 != 0) {
        cin >> nPoints;
    }

    int x, y;
    
    vector<Point> points;
    vector<Segment> segments;
    vector<bool> results;
    for(int i = 0; i < nPoints; i++){
        cin >> x;
        cin >> y;
        Point newPoint(x, y);
        points.push_back(newPoint);
    }

    int i = 0;
    while (i < points.size()){
        Point a = points[i];
        Point b = points[i+1];
        Segment newSegment(a, b);
        segments.push_back(newSegment);
        i += 2;
    }

    int j = 0;
    while(j < segments.size()){
        results.push_back(areIntersecting(segments[j], segments[j+1]));
        j += 2;
    }
    cout<<"\n---------------"<<endl;
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}