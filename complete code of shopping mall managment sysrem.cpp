#include <iostream>
#include <string>
using namespace std;

class Registration {
public:
    string name, gender;
    int age;

    void registerUser() {
        cout << "\n=== User Registration ===\n";
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }
};

class Product {
public:
    int id;
    string name;
    float price;

    Product(int pid, string pname, float pprice) {
        id = pid; name = pname; price = pprice;
    }
};

class Cart {
public:
    float totalPrice = 0;

    void addToCart(Product p) {
        totalPrice += p.price;
        cout << p.name << " added to cart, Price = " << p.price << endl;
    }

    void showBill() {
        cout << "\nTotal Bill = " << totalPrice << endl;
    }
};

class Payment {
protected:
    double amount;
public:
    Payment(double amt) { amount = amt; }
    virtual void pay() = 0;
};

class CreditCard : public Payment {
public:
    CreditCard(double amt) : Payment(amt) {}
    void pay() override { cout << "Paid " << amount << " using Credit Card\n"; }
};

class Cash : public Payment {
public:
    Cash(double amt) : Payment(amt) {}
    void pay() override { cout << "Paid " << amount << " using Cash\n"; }
};

class Wallet : public Payment {
public:
    Wallet(double amt) : Payment(amt) {}
    void pay() override { cout << "Paid " << amount << " using Wallet\n"; }
};

class Order {
public:
    void confirmOrder() {
        cout << "\nOrder has been placed successfully!\n";
    }
};

class Review {
public:
    void giveReview() {
        string feedback;
        cout << "\nEnter your review about shopping: ";
        cin.ignore();
        getline(cin, feedback);
        cout << "Thanks for your feedback: " << feedback << endl;
    }
};

class Admin {
public:
    void manageMall() {
        cout << "\nAdmin is managing the shopping mall system...\n";
    }
};

int main() {
    Registration user;
    user.registerUser();

    Product p1(1, "Pizza", 2500);
    Product p2(2, "Shirt", 3500);
    Product p3(3, "Watch", 27000);

    Cart cart;
    int choice;
    cout << "\n=== Product Menu ===\n";
    cout << "1. Pizza (2500)\n2. Shirt (3500)\n3. Watch (27000)\n";
    cout << "Select product id to add to cart (0 to finish): ";
    cin >> choice;

    while(choice != 0) {
        if(choice == 1) cart.addToCart(p1);
        else if(choice == 2) cart.addToCart(p2);
        else if(choice == 3) cart.addToCart(p3);
        else cout << "Invalid choice\n";

        cout << "Select next product id (0 to finish): ";
        cin >> choice;
    }

    cart.showBill();

    int payChoice;
    cout << "\nSelect Payment Method:\n1. Credit Card\n2. Cash\n3. Wallet\n";
    cin >> payChoice;

    Payment* payment = nullptr;
    if(payChoice == 1) payment = new CreditCard(cart.totalPrice);
    else if(payChoice == 2) payment = new Cash(cart.totalPrice);
    else payment = new Wallet(cart.totalPrice);

    payment->pay();
    delete payment;

    Order order;
    order.confirmOrder();

    Review r;
    r.giveReview();

    Admin admin;
    admin.manageMall();

    return 0;
}
