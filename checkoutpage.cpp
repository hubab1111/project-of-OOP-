#include <iostream>
using namespace std;

class Item {
public:
    string name;
    int price;
    Item(string n, int p) {
        name = n;
        price = p;
    }
    void display() {
        cout << "Item " << name << "Price" << price << endl;
    }
};

class Checkout {
    int total;
public:
    Checkout() {
        total = 0;
    }
    void additem(Item i){
    	total=total+i.price;
	}
    void showBill() {
        cout << "total Bill " << total << endl;
    }
};

int main() {
    Item i1("Shoes", 3000);
    Item i2("dress",5000);

    cout << " ------Purchased Items------"<<endl;
    i1.display();
    i2.display(); 
     Checkout bill;
    bill.additem(i1);
    bill.additem(i2);
    
    bill.showBill();

    return 0;
}