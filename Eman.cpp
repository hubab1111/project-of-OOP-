#include <iostream>
using namespace std;

class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
};

class Admin : public User {
    int products, users;
    double sales;
public:
    Admin(string n, int p, int u, double s) : User(n), products(p), users(u), sales(s) {}
    void show() {
        cout << "--- Admin Dashboard ---\n";
        cout << "Admin: " << name << "\nProducts: " << products << "\nUsers: " << users << "\nSales: $" << sales << endl;
    }
};

int main() {
    Admin a("Eman_Admin", 100, 50, 12000.5);
    a.show();
    return 0;
}

