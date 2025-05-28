#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "This is the first line written to the file.\n";
        file << "File handling in C++ is easy.\n";
        file.close();
        cout << "Data written successfully!" << endl;
    } else {
        cout << "Can't open file for writing." << endl;
    }
}

void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "This line is appended to the file.\n";
        file.close();
        cout << "Data appended successfully!" << endl;
    } else {
        cout << "Can't open file for appending." << endl;
    }
}

void readFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        cout << "Reading data from file:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Can't open file for reading." << endl;
    }
}

int main() {
    string filename = "my_file.txt";
    int choice;

    do {
        cout << "\n===== SIMPLE FILE MANAGER =====\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting... Bye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
