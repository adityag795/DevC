#include "Shape.h" 
#include "Rectangle.h" 
#include "Circle.h" 
#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main() 
{ 
    double width = 2, length = 3; 
    
    Shape *rectangle = new Rectangle(width, length); 
    cout << "Rectangle width: " << width << " and length: " 
    << length << " Area: " << rectangle->area() << " Perimeter: " 
    << rectangle->perimeter() << endl;
    
    double radius = 10; 
    
    Shape *circle = new Circle(radius); 
    
    cout << "Circle radius: " << radius << " Area: " << 
    circle-> area() << " Perimeter: " << circle-> perimeter() << endl; 

    return 0; 
}