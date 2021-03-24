#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(){}
    Point(int x, int y){
    this->x = x;
    this->y = y;
    }

    Point(const Point& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    int getx()
    {

        return this->x;
    }

    int gety()
    {

        return this->y;
    }

    float compute_distance(Point p)
    {
        return sqrt(pow((x-p.getx()),2)+pow((y-p.gety()),2));
    }
};

class Shape
{

protected:
    Point center;
public:
    Shape(){}
    void updateInfo(int x, int y)
    {
        Point mypoint(x,y);
        this->center = mypoint;
    }

    float compute_distance(Point p)
    {
        return center.compute_distance(p);
    }

    Point getcenter()
    {
    	return center;
    }

    virtual double computeArea() = 0;
    virtual double computeCir() =0;

};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(){}
    Circle(int x, int y, int radius)
    {

        this->radius = radius;
        updateInfo(x,y);
    }

    double computeArea()
    {
        return this->radius*this->radius*3.14;
    }

    double computeCir()
    {

        return this->radius*2.0*3.14;
    }

};

class Square : public Shape
{
private:
    int side;
public:
    Square(){};
    Square(int x, int y,int side)
    {
    	updateInfo(x,y);
        this->side = side;
    }
    double computeArea()
    {
        return this->side*this->side;
    }
    double computeCir()
    {

        return this->side*4.0;
    }


};

class Rectangle : public Shape
{
private:
    int height;
    int width;
public:
    Rectangle(){}
    Rectangle(int x, int y,int h, int w)
    {
    	updateInfo(x,y);
        this->height = h;
        this->width = w;
    }
    double computeArea()
    {
        return this->height*this->width;
    }
    double computeCir()
    {

        return (this->height + this->width)*2.0;
    }
};

int main()
{
    Shape* circle = new Circle(1,1,6);
    cout << "Circle Area: " << circle->computeArea() << endl;
    cout << "Circle Circumference: " << circle->computeCir() << endl;

    Shape* square = new Square(3,2,7);
    cout << "Square Area: " << square->computeArea() << endl;
    cout << "Square Circumference: " << square->computeCir() << endl;
    cout << "Distance to Circle: " << square->compute_distance(circle->getcenter()) << endl;

    Shape* rectangle = new Rectangle(7,8,4,5);
    cout << "Rectangle Area: " << rectangle->computeArea() << endl;
    cout << "Rectangle Circumference: " << rectangle->computeCir() << endl;
    cout << "Distance to Square: " << rectangle->compute_distance(square->getcenter()) << endl;
    return 0;
}
