#include <iostream>
using namespace std;

class IntException {
private:
    int code;
public:
    IntException(int c) : code(c) {}
    int getCode() const { return code; }
};

class Circle {
private:
    float rad;
public:
    Circle(float r) {
        if (r < 0)
            throw IntException(10);
        rad = r;
    }
    float getRadius() const { return rad; }
    void setRadius(float r) { rad = r; }
    Circle& operator-(int n) {
        float newRad = rad - n;
        if (newRad < 0)
            throw IntException(10);
        rad = newRad;
        return *this;
    }
};

class Ellipse : public Circle {
private:
    float axis;
public:
    Ellipse(float r, float a) : Circle(r), axis(a) {}
    float getAxis() const { return axis; }
    void setAxis(float a) { axis = a; }
    Ellipse& operator-(int n) {
        Circle::operator-(n);
        axis -= n;
        if (axis < 0)
            throw IntException(20);
        return *this;
    }
};

Circle createCircle() {
    float radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    return Circle(radius);
}

Ellipse createEllipse() {
    float radius, axis;
    cout << "Enter the radius of the ellipse: ";
    cin >> radius;
    cout << "Enter the axis of the ellipse: ";
    cin >> axis;
    return Ellipse(radius, axis);
}

void f(Circle& c, int n) {
    try {
        c = c - n;
        cout << "Result: Radius = " << c.getRadius() << endl;
    } catch (IntException& e) {
        cout << "Exception caught with code: " << e.getCode() << endl;
    }
}

void f(Ellipse& e, int n) {
    try {
        e = e - n;
        cout << "Result: Radius = " << e.getRadius() << ", Axis = " << e.getAxis() << endl;
    } catch (IntException& e) {
        cout << "Exception caught with code: " << e.getCode() << endl;
    }
}

int main() {
    try {
        Circle cir = createCircle();
        Ellipse ell = createEllipse();

        Circle &r1 = cir;
        Circle &r2 = ell;

        f(r1, 3);
        f(r2, 1);
        f(r2, 10);
    } catch (IntException& e) {
        cout << "Exception caught with code: " << e.getCode() << endl;
    } catch (...) {
        cout << "An unknown exception occurred" << endl;
    }

    return 0;
}
