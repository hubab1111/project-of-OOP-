#include <iostream>
#include <string>
using namespace std;

int main() {
    // Store registered username & password
    string regUser, regPass;

    // Simple console "Home Page"
    string title   = "shopping management";
    string tagline = "Welcome to MyApp — fast, simple, and reliable.";

    cout << "\n===============================================\n";
    cout << "                  " << title << "                  \n";
    cout << "===============================================\n";
    cout << tagline << "\n\n";

    cout << "[1] Register\n";
    cout << "[2] Login\n";
    cout << "[3] Home\n";
    cout << "[4] Features\n";
    cout << "[5] About\n";
    cout << "[6] Contact\n";
    cout << "[7] Exit\n";

    int choice;
    cout << "\nSelect an option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n--- Registration ---\n";
        cout << "Enter username: ";
        cin >> regUser;
        cout << "Enter password: ";
        cin >> regPass;
        cout << "Registration successful!\n";
    }
    else if (choice == 2) {
        cout << "\n--- Login ---\n";
        string user, pass;
        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        if (user == regUser && pass == regPass) {
            cout << "Login successful! Welcome, " << user << ".\n";
        } else {
            cout << "Invalid username or password.\n";
        }
    }
    else if (choice == 7) {
        cout << "Exiting program. Goodbye!\n";
    }
    else {
        cout << "You selected option " << choice << ". (Not implemented)\n";
    }

    return 0;
}
