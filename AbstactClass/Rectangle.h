class Rectangle : public Shape 
{ 
    private: 
    double width = 0, length = 0; 
    public: 
    Rectangle(); 
    Rectangle(double w, double l); 
    virtual void setWidth(double w);
    virtual void setLength(double l); 
    virtual double area() override; 
    virtual double perimeter() override; 
}; 

Rectangle:: Rectangle():Rectangle( 1, 1) 
{ } 

Rectangle:: Rectangle(double w,double l) 
{ 
    width = w; 
    length = l; 
} 

void Rectangle::setWidth(double w) 
{ 
    width = w; 
} 

void Rectangle::setLength(double l) 
{ 
    length = l; 
} 

double Rectangle::area() 
{ 
    return width * length; // Area = width * length 
}

double Rectangle::perimeter() 
{ 
    return 2 * (width + length);  // Perimeter = 2( width + length) 
}
