#include <iostream>
using namespace std;
class Product {
public:
    string name;
    double price;
    Product(string n, double p) {
        name = n;
        price = p;
    }
};
class Discount {
public:
    double percentage;
    Discount(double per) {
        percentage = per;
    }
    double apply(double total) {
        return total - (total * percentage / 100.0);
    }
};
class Customer {
public:
    string name;
    double bill;
    Customer(string n) {
        name = n;
        bill = 0;
    }
    void buy(Product p) {
        bill += p.price;
        cout << name << " bought " << p.name << " for $" << p.price << endl;
    }
    void checkout(Discount d) {
        cout << "\nTotal Bill: $" << bill << endl;
        double finalPrice = d.apply(bill);
        cout << "Final Price after " << d.percentage << "% discount: $" << finalPrice << endl;
    }
};
int main() {
    Product shirt("Shirt", 200);
    Product shoes("Shoes", 500);
    Product cap("Cap", 100);
    Customer c1("Ali");
    c1.buy(shirt);
    c1.buy(shoes);
    c1.buy(cap);
    Discount d(10);
    c1.checkout(d);
    return 0;
}
