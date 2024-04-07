#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;


void reverseList(list<int>& lst) {
    lst.reverse();
}

stack<int> decimalToBinary(int decimalNumber) {
    stack<int> binaryStack;
    while (decimalNumber > 0) {
        binaryStack.push(decimalNumber % 2);
        decimalNumber /= 2;
    }
    return binaryStack;
}

int main() {
    cout << "(a) To reverse a list \n";
    list<int> myList = {1, 2, 3, 4, 5};
    cout << "Original list: ";
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    reverseList(myList);

    cout << "Reversed list: ";
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl<<"\n";

    cout << "(b) To convert a decimal to binary form using stack "<<"\n";
    int decimalNumber = 10;
    cout << "Decimal number: " << decimalNumber << endl;

    stack<int> binaryStack = decimalToBinary(decimalNumber);

    cout << "Binary representation: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout << endl;

   cout << "\n(c) Queue operations "<<"\n";
    queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    cout << "Queue elements: ";
    queue<int> tempQueue = myQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
    cout << "Adding more elements to the queue..." << endl;
    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);

    cout << "Queue elements after adding more: ";
    tempQueue = myQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
    myQueue.push(70);
    myQueue.push(80);

    cout << "Queue elements after adding more: ";
    tempQueue = myQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
    cout << "Removing elements from the queue" << endl;
    myQueue.pop();
    myQueue.pop();

    cout << "Queue elements after removal: ";
    tempQueue = myQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
    cout << "Checking if the queue is empty: ";
    cout << (myQueue.empty() ? "Yes" : "No") << endl;

    return 0;

}
