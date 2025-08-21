
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    string email;
public:
    User(string u, string p, string e) : username(u), password(p), email(e) {}
    void resetPassword() {
        cout << "Enter new password: ";
        cin >> password;
        cout << "Password reset successfully!\n";
    }
};
class Admin : public User {
	protected:
    string securityQuestion;
    string securityAnswer;
public:
    Admin(string u, string p, string e, string q, string a) : User(u, p, e), securityQuestion(q), securityAnswer(a) {}
    void forgotPassword() {
        cout << "Security Question: " << securityQuestion << "\n";
        string ans;
        bool success = false;

        for (int attempt = 1; attempt <= 3; attempt++) {
            cout << "Enter answer ";
            cin >> ans;
            if (ans == securityAnswer) {
                resetPassword();
                success = true;
                break;
            } 
			else {
                cout << "Incorrect answer!\n";
                if (attempt == 2) {
                    cout << "Hint: last word of answer is mall" 
                         << securityAnswer[0] << "'\n";
                }
            }
        }

        if (!success) {
            cout << "Security answer failed! Trying Gmail verification...\n";
            if (verifyEmail()) {
                resetPassword();
            }
        }
    }

    bool verifyEmail() {
        string inputEmail;
        int attempts = 3;
        while (attempts--) {
            cout << "Enter registered Gmail: ";
            cin >> inputEmail;
            if (inputEmail == email) {
                cout << "Email verified successfully!\n";
                return true;
            } else {
                cout << "Invalid Gmail! Try again.\n";
            }
        }
        cout << "Too many failed attempts!\n";
        return false;
    }
};

class Customer : public User {
public:
    Customer(string u, string p, string e) : User(u, p, e) {}
    void forgotPassword() {
        if (verifyEmail()) {
            resetPassword();
        }
    }

    bool verifyEmail() {
        string inputEmail;
        int attempts = 3;
        while (attempts--) {
            cout << "Enter registered Gmail: ";
            cin >> inputEmail;
            if (inputEmail == email) {
                cout << "Email verified successfully!\n";
                return true;
            } else {
                cout << "Invalid Gmail! Try again.\n";
            }
        }
        cout << "Too many failed attempts!\n";
        return false;
    }
};

int main() {
    Admin* admin = new Admin("manager", "786786", "manager@gmail.com", "What is your mall name?", "shoppingmall");
    Customer* customer = new Customer("uskt", "1234321", "uskt@gmail.com");
    int choice;
    cout << "1. Admin Forgot Password\n2. Customer Forgot Password\nChoose: ";
    cin >> choice;
    if (choice == 1) {
        admin->forgotPassword();
    } else if (choice == 2) {
        customer->forgotPassword();
    }

    delete admin;
    delete customer;

    return 0;
}

