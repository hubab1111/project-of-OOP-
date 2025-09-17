#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;

class User {
public:
    string username, password, role, email;

    void registerUser() {
        cout << "\n=== Registration ===\n";
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
        cout << "Enter email: "; cin >> email;
        cout << "Select Role (admin/vendor/customer): "; cin >> role;
    }

    bool loginUser() {
        string u, p;
        cout << "\n=== Login ===\nUsername: "; cin >> u;
        cout << "Password: "; cin >> p;
        if (u == username && p == password) {
            cout << "Login Successful as " << role << "!\n";
            return true;
        }
        cout << "Invalid Credentials!\n";
        return false;
    }

    void forgotPassword() {
        string u;
        cout << "\n=== Forgot Password ===\nEnter your username: "; cin >> u;
        if (u == username) {
            string newpass;
            cout << "Enter new password: "; cin >> newpass;
            password = newpass;
            cout << "Password updated successfully!\n";
        } else cout << "Username not found!\n";
    }

    void manageProfile() {
        int c;
        cout << "\n=== User Profile Management ===\n";
        cout << "1. View Profile\n2. Update Email\n3. Update Password\nChoice: ";
        cin >> c;
        if (c == 1) {
            cout << "Username: " << username << "\nRole: " << role << "\nEmail: " << email << endl;
        } else if (c == 2) {
            cout << "Enter new email: "; cin >> email;
            cout << "Email updated!\n";
        } else if (c == 3) {
            cout << "Enter new password: "; cin >> password;
            cout << "Password updated!\n";
        }
    }
};


class Product {
public:
    int id;
    string name, category;
    float price;
    Product(int i, string n, string c, float p) { id = i; name = n; category = c; price = p; }
};


class Cart {
public:
    vector<Product> items;
    float total = 0;

    void addItem(Product p) {
        items.push_back(p);
        total += p.price;
        cout << p.name << " added to cart.\n";
    }

    void showCart() {
        cout << "\n=== Cart ===\n";
        for (auto& p : items) cout << p.name << " - Rs." << p.price << endl;
        cout << "Total Bill: Rs." << total << endl;
    }
};


class Payment {
protected: double amount;
public:
    Payment(double amt) { amount = amt; }
    virtual void pay() = 0;
};
class CreditCard : public Payment {
public: CreditCard(double amt) : Payment(amt) {}
void pay() override { cout << "Paid Rs." << amount << " using Credit Card.\n"; } };
class Cash : public Payment {
public: Cash(double amt) : Payment(amt) {}
void pay() override { cout << "Cash on Delivery selected Rs." << amount << endl; } };
class PaymentGateway : public Payment {
public: PaymentGateway(double amt) : Payment(amt) {}
void pay() override { cout << "Paid Rs." << amount << " via Payment Gateway (JazzCash/EasyPaisa).\n"; } };


class OrderTracking {
    vector<string> stages = { "Processing","Packed","Shipped","Out for Delivery","Delivered" };
public:
    void track() {
        cout << "\n=== Order Tracking ===\n";
        for (auto& s : stages) {
            cout << "Status: " << s << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << "Your order has been delivered!\n";
    }
};


void saveOrderHistory(const User& u, const Cart& cart) {
    ofstream file("order_history.txt", ios::app);
    file << u.username << " (" << u.role << ") ordered:\n";
    for (auto& p : cart.items) file << p.name << " - Rs." << p.price << "\n";
    file << "Total: Rs." << cart.total << "\n----------------------\n";
    file.close();
}
void savePaymentHistory(const User& u, double amt, string method) {
    ofstream file("payment_history.txt", ios::app);
    file << u.username << " paid Rs." << amt << " via " << method << "\n";
    file.close();
}


void searchProducts(vector<vector<Product>>& allCategories) {
    cout << "\n=== Search & Filter ===\nEnter keyword: ";
    string key; cin >> key;
    transform(key.begin(), key.end(), key.begin(), ::tolower);

    bool found = false;
    for (auto& cat : allCategories) {
        for (auto& p : cat) {
            string n = p.name;
            transform(n.begin(), n.end(), n.begin(), ::tolower);
            if (n.find(key) != string::npos) {
                cout << p.id << ". " << p.name << " (" << p.category << ") - Rs." << p.price << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "No products found matching '" << key << "'.\n";
}


int main() {
    srand(time(0));
    User u;
    bool running = true;

   
    while (running) {
        cout << "\n=== Welcome to BS SE Section Grey Shopping Mall ===\n";
        cout << "1. Register\n2. Login\n3. Forgot Password\n0. Exit\nChoice: ";
        int choice; cin >> choice;
        if (choice == 1) { u.registerUser(); }
        else if (choice == 2) { if (u.loginUser()) break; }
        else if (choice == 3) { u.forgotPassword(); }
        else if (choice == 0) { return 0; }
    }

   
    if (u.role == "admin") {
        cout << "\n=== Admin Dashboard ===\n(View Reports, Manage Users, etc.)\n";
    }
    else if (u.role == "vendor") {
        cout << "\n=== Vendor Dashboard ===\n(Add Products, Manage Inventory)\n";
    }
    else {
        cout << "\n=== Customer Dashboard ===\n";
    }

    // Products
    vector<Product> grocery = { {1,"Basmati Rice","Grocery",1200},{2,"Cooking Oil","Grocery",950},{3,"Sugar","Grocery",360},
        {4,"Flour","Grocery",1800},{5,"Tea Pack","Grocery",450} };
    vector<Product> clothing = { {11,"Men T-Shirt","Clothing",1200},{12,"Women Kurti","Clothing",1800},
        {13,"Jeans","Clothing",2500},{14,"Kids Jacket","Clothing",3000},{15,"Formal Shirt","Clothing",2200} };
    vector<Product> fruits = { {21,"Apple","Fruits",300},{22,"Banana","Fruits",180},
        {23,"Potato","Fruits",350},{24,"Tomato","Fruits",180},{25,"Carrot","Fruits",150} };
    vector<Product> electronics = { {31,"LED TV 32 inch","Electronics",28000},{32,"Smartphone","Electronics",32000},
        {33,"Laptop","Electronics",85000},{34,"Headphones","Electronics",4500},{35,"Microwave","Electronics",18000} };
    vector<Product> toys = { {41,"Remote Car","Toys",2200},{42,"Doll House","Toys",3500},
        {43,"Puzzle Set","Toys",800},{44,"Cricket Bat","Toys",1200},{45,"Football","Toys",900} };
    vector<Product> homeAcc = { {51,"Curtains","Home Accessories",2000},{52,"Cushion Set","Home Accessories",1500},
        {53,"Table Lamp","Home Accessories",2500},{54,"Wall Clock","Home Accessories",1800},{55,"Dinner Set","Home Accessories",3500} };
    vector<Product> medicines = { {61,"Paracetamol","Medicines",120},{62,"Vitamin C","Medicines",350},
        {63,"Cough Syrup","Medicines",150},{64,"Pain Relief Spray","Medicines",450},{65,"Antibiotic Cream","Medicines",250} };
    vector<Product> makeup = { {71,"Lipstick","Makeup",600},{72,"Foundation","Makeup",1200},
        {73,"Mascara","Makeup",800},{74,"Blush","Makeup",950},{75,"Compact Powder","Makeup",700} };

    vector<vector<Product>> allCategories = { grocery, clothing, fruits, electronics, toys, homeAcc, medicines, makeup };

    Cart cart;
    bool shopping = true;
    while (shopping) {
        cout << "\n=== Categories ===\n";
        cout << "1. Grocery\n2. Clothing\n3. Fruits & Vegetables\n4. Electronics\n5. Toys\n6. Home Accessories\n7. Medicines\n8. Makeup\n9. Search & Filter\n10. Profile Management\n0. Checkout\nChoice: ";
        int cat; cin >> cat;
        if (cat == 0) break;
        else if (cat == 9) { searchProducts(allCategories); continue; }
        else if (cat == 10) { u.manageProfile(); continue; }

        vector<Product>* selected = nullptr;
        if (cat == 1) selected = &grocery;
        else if (cat == 2) selected = &clothing;
        else if (cat == 3) selected = &fruits;
        else if (cat == 4) selected = &electronics;
        else if (cat == 5) selected = &toys;
        else if (cat == 6) selected = &homeAcc;
        else if (cat == 7) selected = &medicines;
        else if (cat == 8) selected = &makeup;

        if (selected) {
            cout << "\n=== Products ===\n";
            for (auto& p : *selected) cout << p.id << ". " << p.name << " - Rs." << p.price << endl;
            cout << "Enter product id to add to cart (0 to back): ";
            int pid; cin >> pid;
            while (pid != 0) {
                for (auto& p : *selected) { if (p.id == pid) { cart.addItem(p); break; } }
                cout << "Enter product id (0 to back): "; cin >> pid;
            }
        }
    }

   
    cout << "\nEnter Coupon Code (or 'none'): ";
    string code; cin >> code;
    if (code == "SAVE10") { cart.total *= 0.9; cout << "10% Discount Applied!\n"; }

    
    cart.showCart();

   
    cout << "\nPayment Method (1 Credit Card / 2 Cash / 3 Payment Gateway): ";
    int pay; cin >> pay;
    Payment* payment = nullptr;
    if (pay == 1) { payment = new CreditCard(cart.total); savePaymentHistory(u, cart.total, "Credit Card"); }
    else if (pay == 2) { payment = new Cash(cart.total); savePaymentHistory(u, cart.total, "Cash on Delivery"); }
    else if (pay == 3) { payment = new PaymentGateway(cart.total); savePaymentHistory(u, cart.total, "Payment Gateway"); }
    payment->pay(); delete payment;

    
    saveOrderHistory(u, cart);

 
    OrderTracking ot; ot.track();

  
    cout << "\nEnter Product Review/Rating (1-5): ";
    int rating; cin >> rating;
    cout << "Thanks for rating " << rating << "/5!\n";

    cout << "\n=== Thank You ===\nThank you for shopping from BS SE Section Grey Shopping Mall!\n";
    return 0;
}
