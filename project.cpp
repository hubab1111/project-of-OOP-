#include <iostream>
using namespace std;

int main() {
    string username, email, password;
    string u, p, e;

    cout << "Registration Page \n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    cout << "User successfully registered!\n";

    cout << "\nLogin Page \n";
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter email: ";
    cin >> e;
    cout << "Enter password: ";
    cin >> p;

    if (u == username && p == password && e == email) {
        cout << "Login successful! Welcome " << u << "\n";
        char choice;
        cout << "Do you want to change your password? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            string newPass;
            cout << "Enter your new password: ";
            cin >> newPass;
            password = newPass; 
            cout << "Password updated successfully!\n";
        }
    } else {
        cout << "Invalid username, email or password!\n";
    }
    const string adminName = "admin"; 
    string adminPass = "Mxn87*@"; 
    string au, ap;

    cout << "\n Admin Forgot Password \n";
    cout << "Enter admin username: ";
    cin >> au;

    if (au == adminName) {
        cout << "Enter current admin password: ";
        cin >> ap;

        if (ap == adminPass) {
            string newAdminPass;
            cout << "Enter new admin password: ";
            cin >> newAdminPass;
            adminPass = newAdminPass;
            cout << "Admin password updated successfully!\n";
        } else {
            cout << "Invalid admin password!\n";
        }
    } else {
        cout << "Only admin can access this section!\n";
    }

    return 0;
}
