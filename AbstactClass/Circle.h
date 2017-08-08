#include<math.h>
#define M_PI 3.14
class Circle : public Shape 
{ 
    private:
        double radius = 0; 
    public: 
        Circle(); 
        Circle(double r); 
        virtual void setRadius(double r); 
        virtual double area() override; 
        virtual double perimeter() override; 
}; 

Circle:: Circle() : Circle(1) { } 

Circle:: Circle(double r) 
{
    radius = r; 
}

void Circle::setRadius(double r) 
{ 
    radius = r; 
} 

double Circle::area() 
{ 
    return M_PI * pow(radius, 2); 
} 

double Circle::perimeter() 
{
    return 2 * M_PI * radius; 
}
