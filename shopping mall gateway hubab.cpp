#include <iostream>
#include <string>
using namespace std;

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
    void pay() override {
        cout << "Paid $" << amount << " using Credit Card\n";
    }
};

class Cash : public Payment {
public:
    Cash(double amt) : Payment(amt) {}
    void pay() override {
        cout << "Paid $" << amount << " using Cash\n";
    }
};

class Wallet : public Payment {
public:
    Wallet(double amt) : Payment(amt) {}
    void pay() override {
        cout << "Paid $" << amount << " using Wallet\n";
    }
};

int main() {
    int n;
    double price, total = 0;

    cout << "=== Shopping Mall System ===\n";
    cout << "Enter number of items: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter price of item " << i << ": ";
        cin >> price;
        total += price;
    }

    cout << "\nTotal Bill = $" << total << endl;

    int choice;
    cout << "\nSelect Payment Method:\n";
    cout << "1. Credit Card\n2. Cash\n3. Wallet\n";
    cin >> choice;

    Payment* p = nullptr;
    if(choice == 1)
        p = new CreditCard(total);
    else if(choice == 2)
        p = new Cash(total);
    else
        p = new Wallet(total);

    p->pay();

    delete p;
    return 0;
}
