#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}


    Rectangle operator+(const Rectangle& other) {
        double combinedWidth = width + other.width;
        double combinedHeight = height + other.height;
        return Rectangle(combinedWidth, combinedHeight);
    }


    Rectangle operator*(int scale) {
        double scaledWidth = width * scale;
        double scaledHeight = height * scale;
        return Rectangle(scaledWidth, scaledHeight);
    }


    bool isSquare() {
        return width == height;
    }


    void checkSquare() {
        if (isSquare())
            cout << "This rectangle is a square." << endl;
        else
            cout << "This rectangle is not a square." << endl;
    }


    void show() {
        cout << "Width: " << width << ", Height: " << height << ", Area: " << (width * height) << endl;
    }
};

class Product {
protected:
    int product_code;

public:
    Product(int code) : product_code(code) {}

    virtual void show() {
        cout << "Product Code: " << product_code << endl;
    }
};

class Book : public Product {
private:
    string book_title;

public:
    Book(int code, const string& title) : Product(code), book_title(title) {}

    void show() override {
        cout << "Book Title: " << book_title << ", Product Code: " << product_code << endl;
    }
};

void f(Product* obj1, Product* obj2) {
    obj1->show();
    obj2->show();
}

int main() {
    cout << "Question no.1" << endl;
    Rectangle rect1(5, 5);
    Rectangle rect2(3, 4);
    cout << "First rectangle: ";
    rect1.show();
    cout << "Second rectangle: ";
    rect2.show();
    Rectangle rect3 = rect1 + rect2;
    cout << "Combined rectangle: ";
    rect3.show();

    int scale = 3;
    Rectangle rect4 = rect1 * scale;
    cout << "Scaled rect1 by " << scale << ": ";
    rect4.show();

    Rectangle rect5 = rect2 * scale;
    cout << "Scaled rect2 by " << scale << ": ";
    rect5.show();

    cout << "Is rect1 a square? ";
    rect1.checkSquare();

    cout << "Is rect2 a square? ";
    rect2.checkSquare();
    cout << "\n";
    cout << "Question no.2" << endl;
    Product prod1(101);
    Book book1(201, "Introduction to programming ");
    f(&prod1, &book1);

    return 0;
}
