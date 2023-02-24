#include<iostream>
using namespace std;

//Function prototypes
double calc_volume_cylinder(double radius,double height);
double calc_area_circle(double radius);
void area_circle();
void volume_cylinder();

const double pi{3.14159};

int main(){
    area_circle();
    volume_cylinder();
}

void area_circle(){
    double radius{};
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "The area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

double calc_area_circle(double radius){
    return pi*radius*radius;
}

double calc_volume_cylinder(double radius,double height){
    return calc_area_circle(radius)*height;
}

void volume_cylinder(){
    double radius{};
    double height{};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "Enter the height of the circle: ";
    cin >> height;

    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius,height) << endl;

}