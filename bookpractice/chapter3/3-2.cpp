// Calculate BMI
#include <iostream>
const int inch_per_feet = 12;
const double inch_per_meter = 0.0254,pound_per_kilogram = 2.2;
int main()
{
    using namespace std;
    //cout.setf(ios_base::fixed,ios_base::floatfield); // fixed-point
    double feet_of_height,inches_of_height,pounds_of_weight,meters_of_height,kilograms_of_weight,BMI;
    cout << "Please enter your height by feet and inches:" << endl;
    cout << "feet: ";
    cin >> feet_of_height;
    cout << "inches: ";
    cin >> inches_of_height;
    inches_of_height += inch_per_feet * feet_of_height; // used inches_of_height again
    cout << "Your height by inches is: " << inches_of_height << endl;
    meters_of_height = inches_of_height * inch_per_meter;
    cout << "Your height converted into meters: " << inches_of_height << " * " << inch_per_meter << " = " << meters_of_height << endl;
    cout << "Enter your weight by pounds: ";
    cin >> pounds_of_weight;
    kilograms_of_weight = pounds_of_weight / pound_per_kilogram;
    cout << "Your weight converted into kilograms: " << pounds_of_weight << " / " << pound_per_kilogram << " = " << kilograms_of_weight << endl;
    BMI = kilograms_of_weight / (meters_of_height * meters_of_height);
    cout << "Your BMI is: " << BMI << endl;
    return 0;
}