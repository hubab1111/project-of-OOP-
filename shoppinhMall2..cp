#include <iostream>
using namespace std;
class User {
protected:
    string username;
    string password;
public:
    User(string u, string p) {
        username = u;
        password = p;
    }
    string getUsername() { return username; }
    bool checkPassword(string p) { return password == p; }

    virtual string getRole() = 0; 
};
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p) {}
    string getRole() { return "Admin"; } 
};

class Customer : public User {
public:
    Customer(string u, string p) : User(u, p) {}
    string getRole() { return "Customer"; }
};

class Staff : public User {
public:
    Staff(string u, string p) : User(u, p) {}
    string getRole() { return "Staff"; }
};

class AuthSystem {
    User* users[10];   
    int count;
public:
    AuthSystem() { count = 0; }

    void registerUser(User* u) {
        users[count++] = u;
    }

    void login(string u, string p) {
    for (int i = 0; i < count; i++) {
    if (users[i]->getUsername() == u) {
    if (users[i]->checkPassword(p)) {
    cout << "Welcome " << users[i]->getRole()
    << " : " << users[i]->getUsername() << endl;
    } else {
    cout << "Wrong password!" << endl;
    }
    return;}}
    cout << "User not found!" << endl;
    }
};
int main() {
    AuthSystem system;

    system.registerUser(new Admin("admin1", "1234"));
    system.registerUser(new Customer("ali", "abcd"));
    system.registerUser(new Staff("staff1", "pass"));
    
    system.login("ali", "abcd");    
    system.login("staff1", "wrong"); 
    system.login("ghost", "1234");   
}
