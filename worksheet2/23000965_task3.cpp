#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    const int numTitles = 10;
    char titles[numTitles][150];
    char filename[100];

    cout << "Enter the file name: ";
    cin.getline(filename, 100);

    cout << "Enter titles of 10 books:" << endl;
    for (int i = 0; i < numTitles; ++i) {
        cout << "Title " << i + 1 << ": ";
        cin.getline(titles[i], 150);
    }

    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numTitles; ++i) {
        file.write(titles[i], strlen(titles[i]));
        file.put('\0');
    }

    file.close();
    cout << "Book titles have been written to the file '" << filename << "'." << endl;

    char searchTitle[150];
    cout << "Enter a title to search in the file: ";
    cin.getline(searchTitle, 150);

    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    bool found = false;
    char buffer[150];
    while (inputFile.getline(buffer, 150, '\0')) {
        if (strcmp(buffer, searchTitle) == 0) {
            found = true;
            break;
        }
    }

    inputFile.close();

    if (found)
        cout << "The title is present in the file." << endl;
    else
        cout << "The title is not present in the file." << endl;

    return 0;
}
