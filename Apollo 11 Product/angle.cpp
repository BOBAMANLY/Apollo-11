#include <iostream>
using namespace std;


class Angle {
private:

    // Attributes
    double degrees;
    double radians;

    // Functions
    double convertToDegrees(double input) {
        double pi = 2 * acos(0.0); // Solve PI
        double degrees = (input * 360) / (2 * pi);
        return degrees;
    }
    double convertToRadians(double input) {
        double pi = 2 * acos(0.0); // Solve PI
        double radians = ((input * (2 * pi)) / 360);
        return radians;
    }
    double normalize(double input) {
        double pi = 2 * acos(0.0); // Solve PI
        double norm;
        if (fmod(input, pi) == 0)
            norm = pi;
        else
            norm = 360.0 - input;
        return norm;
    }

public:

    // Functions
    double getDegrees() {
        return degrees;
    }
    double getRadians() {
        return radians;
    }
    void setDegrees(double input) {
        degrees = input;
    }
    void setRadians(double input) {
        radians = input;
    }
    int display() {
        cout << "Degrees: " << degrees << endl;
        return 0;
    }
};

/***
int main()
{
    Angle object;

    // Test Degrees
    object.setDegrees(45.00);
    cout << "Degrees: " << object.getDegrees() << endl;

    // Test Radians
    object.setRadians(100.00);
    cout << "Radians: " << object.getRadians() << endl;

    // Test Display
    object.display();

    return 0;
}
***/