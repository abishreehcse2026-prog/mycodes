#include <iostream>
using namespace std;
class shape
{
    public:
    virtual float area()=0; //pure virtual function

};
class Circle : public shape
{
private:
    float radius;
public:
    Circle(float r )
    {
        radius = r;
    }
    float area()
    {
        return 3.14*radius*radius;
    }  
};
class Rectangle : public shape
{
private:
    float length;
    float breadth;
public:
Rectangle(float l , float b)
{
    length = l;
    breadth = b;
}
float area()
{
    return length * breadth;
}
};
class triangle :public shape
{
    private:
    float base , height;
    public:
    triangle(float b, float h)
    {
        base = b;
        height = h;
    }
    float area()
    {
        return 0.5*base*height;
    }
};
int main()
{
    Circle c(5);
    Rectangle r(4, 6);
    triangle t(10, 8);
    shape * ptr ;
    ptr=&c;
    cout << "Area of Circle: " << ptr->area() << endl;
    ptr = &r;
    cout << "Area of Rectangle: " << ptr->area() << endl;
    ptr = &t;
    cout << "Area of Triangle: " << ptr->area() << endl;
    return 0;
}