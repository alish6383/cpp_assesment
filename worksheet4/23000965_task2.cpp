#include <iostream>

using namespace std;

class Circle {
private:
    float rad;

public:
    Circle(float radius) : rad(radius) {}

    Circle& operator-(int n) {
        rad -= n;
        if (rad < 0)
            throw 10;
        return *this;
    }

    void show() const {
        cout << "Radius: " << rad << endl;
    }
};

class Ellipse : public Circle {
private:
    float axis;

public:
    Ellipse(float radius, float ellipse_axis) : Circle(radius), axis(ellipse_axis) {}

    Ellipse& operator-(int n) {
        Circle::operator-(n);
        axis -= n;
        if (axis < 0)
            throw 20;
        return *this;
    }

    void show() const {
        Circle::show();
        cout << "Axis: " << axis << endl;
    }
};

void f(Circle &c, int n) {
    try {
        Circle tmp = c - n;
        tmp.show();
    } catch (int exception_code) {
        if (exception_code == 10)
            cout << "Exception: Circle radius cannot be negative." << endl;
        else if (exception_code == 20)
            cout << "Exception: Ellipse axis cannot be negative." << endl;
    }
}

int main() {
    try {
        Circle cir(5);
        Ellipse ell(10, 6);
        Circle &r1 = cir, &r2 = ell;
        f(r1, 3);
        f(r2, 1);
        f(r2, 10);
    } catch (...) {
        cout << "An unknown exception occurred." << endl;
    }

    return 0;
}
