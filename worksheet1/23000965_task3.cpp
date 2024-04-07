#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;
const int MAX_NAME_LENGTH = 50;

struct tbcItem {
    int productId;
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
};

void addItem(tbcItem inventory[], int& numItems) {
    if (numItems < MAX_ITEMS) {
        tbcItem newItem;
        cout << "Enter product ID: ";
        cin >> newItem.productId;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(newItem.name, MAX_NAME_LENGTH);
        cout << "Enter quantity: ";
        cin >> newItem.quantity;
        cout << "Enter price: ";
        cin >> newItem.price;
        inventory[numItems] = newItem;
        numItems++;
        cout << "Item added successfully." << endl;
    }
    else {
        cout << "Inventory is full. Cannot add more items." << endl;
    }
}

void removeItem(tbcItem inventory[], int& numItems, int productId) {
    int indexToRemove = -1;
    for (int i = 0; i < numItems; ++i) {
        if (inventory[i].productId == productId) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < numItems - 1; ++i) {
            inventory[i] = inventory[i + 1];
        }
        numItems--;
        cout << "Item removed successfully." << endl;
    }
    else {
        cout << "Item with product ID " << productId << " not found." << endl;
    }
}


void updateItem(tbcItem inventory[], int numItems, int productId) {
    for (int i = 0; i < numItems; ++i) {
        if (inventory[i].productId == productId) {
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new price: ";
            cin >> inventory[i].price;
            cout << "Item updated successfully." << endl;
            return;
        }
    }
    cout << "Item with product ID " << productId << " not found." << endl;
}

void displayItems(const tbcItem inventory[], int numItems) {
    cout << "Inventory:" << endl;
    for (int i = 0; i < numItems; ++i) {
        cout << "Product ID: " << inventory[i].productId << ", Name: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << ", Price:" << inventory[i].price << endl;
    }
}

int main() {
    tbcItem inventory[MAX_ITEMS];
    int numItems = 0;
    int choice;

    do {
        cout << "\n      Menu " << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Display Items" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addItem(inventory, numItems);
            break;
        case 2:
            int removeId;
            cout << "Enter the product ID of the item to remove: ";
            cin >> removeId;
            removeItem(inventory, numItems, removeId);
            break;
        case 3:
            int updateId;
            cout << "Enter the product ID of the item to update: ";
            cin >> updateId;
            updateItem(inventory, numItems, updateId);
            break;
        case 4:
            displayItems(inventory, numItems);
            break;
        case 5:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

