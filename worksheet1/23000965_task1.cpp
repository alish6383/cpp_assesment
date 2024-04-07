#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

void mainMenu() {
    cout << "      Main Menu " << endl;
    cout << "1. Temperature Conversion" << endl;
    cout << "2. Number Guessing Game" << endl;
    cout << "3. Find Minimum and Maximum in an Array" << endl;
    cout << "4. Password Strength Checker" << endl;
    cout << "5. Exit" << endl;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

char getScaleChoice() {
    char scale;
    cout << "Choose the scale for conversion (C for Celsius, F for Fahrenheit): ";
    cin >> scale;
    return toupper(scale);
}

double getTemperature() {
    double temperature;
    cout << "Enter the temperature value: ";
    cin >> temperature;
    return temperature;
}

void convertAndDisplayTemperature(double temperature, char scale) {
    if (scale == 'C') {
        double fahrenheit = celsiusToFahrenheit(temperature);
        cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    }
    else if (scale == 'F') {
        double celsius = fahrenheitToCelsius(temperature);
        cout << "Temperature in Celsius: " << celsius << endl;
    }
    else {
        cout << "Invalid scale entered. Please enter either C or F." << endl;
    }
}

void temperatureConversionMenu() {
    char scale = getScaleChoice();
    double temperature = getTemperature();
    convertAndDisplayTemperature(temperature, scale);
}

void displayInstructions() {
    cout << "Choose difficulty level (E for Easy, M for Medium, H for Hard): ";
}

int getUpperBound(char difficulty) {
    switch (difficulty) {
    case 'E':
        return 8;
    case 'M':
        return 30;
    case 'H':
        return 50;
    default:
        return -1;
    }
}

int generateRandomNumber(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

int getUserGuess(int lower, int upper) {
    int guess;
    cout << "Guess the number between " << lower << " and " << upper << ": ";
    cin >> guess;
    return guess;
}

void playGame() {
    char difficulty;
    int upper, number, guess, attempts = 0;

    displayInstructions();
    cin >> difficulty;
    difficulty = toupper(difficulty);

    upper = getUpperBound(difficulty);
    if (upper == -1) {
        cout << "Invalid difficulty level entered." << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    number = generateRandomNumber(1, upper);

    do {
        guess = getUserGuess(1, upper);
        attempts++;

        if (guess < number)
            cout << "Too low! Try again: ";
        else if (guess > number)
            cout << "Too high! Try again: ";

    } while (guess != number);

    cout << "Congratulations! You guessed it in " << attempts << " attempts." << endl;
}

void numberGuessingGameMenu() {
    playGame();
}

int* getInputArray(int n) {
    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

pair<int, int> findMinMax(const int* arr, int n) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    return { min, max };
}

void minMaxArrayMenu() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int* arr = getInputArray(n);
    pair<int, int> minMax = findMinMax(arr, n);
    cout << "Minimum value: " << minMax.first << endl;
    cout << "Maximum value: " << minMax.second << endl;
    delete[] arr;
}


int calculateStrength(const string& password) {
    int strength = 0;

    if (password.length() >= 8)
        strength += 2;

    bool hasUppercase = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUppercase = true;
            break;
        }
    }
    if (hasUppercase)
        strength += 2;

    bool hasLowercase = false;
    for (char c : password) {
        if (islower(c)) {
            hasLowercase = true;
            break;
        }
    }
    if (hasLowercase)
        strength += 2;


    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (hasDigit)
        strength += 2;

    bool hasSpecialChar = false;
    for (char c : password) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
            break;
        }
    }
    if (hasSpecialChar)
        strength += 2;

    return strength;
}

string determineStrengthLevel(int strength) {
    if (strength <= 4)
        return "Weak";
    else if (strength <= 8)
        return "Moderate";
    else
        return "Strong";
}

void passwordStrengthMenu() {
    string password;
    cout << "Enter a password: ";
    cin >> password;
    int strength = calculateStrength(password);
    string strengthLevel = determineStrengthLevel(strength);
    cout << "Password strength: " << strengthLevel << " (" << strength << " points)" << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;
    do {
        mainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            temperatureConversionMenu();
            break;
        case 2:
            numberGuessingGameMenu();
            break;
        case 3:
            minMaxArrayMenu();
            break;
        case 4:
            passwordStrengthMenu();
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
