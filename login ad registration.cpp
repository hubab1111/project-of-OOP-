#include <iostream>
using namespace std;
class User {
protected:
    string username, email, password;

public:
    void registerUser() {
        cout << "====== Registration Page =======\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password;
        cout << "User successfully registered!\n";
    }

    bool login() {
        cout << "\n====== Login Page =======\n";
        string u, e, p;
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

            if (choice == 'Y' || choice == 'N') {
                string newPass;
                cout << "Enter your new password: ";
                cin >> newPass;
                password = newPass;
                cout << "Password updated successfully!\n";
            }
            return true;
        } else {
            cout << "Invalid username, email or password!\n";
            return false;
        }
    }
};
class Admin : public User {
private:
    string adminName = "admin";
    string adminPass = "Mxn87*@";

public:
    void forgotPassword() {
        cout << "\n====== Admin Forgot Password =======\n";
        string au, ap;

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
    }
};
int main() {
    User user;
    Admin admin;

    user.registerUser();      
    user.login();             
    admin.forgotPassword();   

    return 0;
}
