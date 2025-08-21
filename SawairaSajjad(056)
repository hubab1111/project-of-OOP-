#include <iostream>
using namespace std;
class Customer {
private:
    string name;
    int id;
public:
    Customer() { 
        name = "Sawaira";
        id = 567;
    }

    Customer(string n, int i) {
        name = n;
        id = i;
    }

    void showProfile() {
        cout << "-- Customer Profile --"<<endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};
class Dashboard {
private:
    Customer customer;
    string cartItem;
    int cartPrice;
public:
    Dashboard(Customer c) {
        customer = c;   
        cartItem = "Empty";
        cartPrice = 0;
    }

    void showMenu() {
        int choice;
        do {
            cout << "-- Customer Dashboard-- "<<endl;
            cout << "1. View Profile"<<endl;
            cout << "2. Add Item to Cart"<<endl;
            cout << "3. View Cart"<<endl;
            cout << "4. Exit"<<endl;
            cout << "Enter choice: ";
            cin >> choice;

            if(choice == 1) {
                customer.showProfile();
            }
            else if(choice == 2) {
                cout << "Enter item name: ";
                cin >> cartItem;
                cout << "Enter item price: ";
                cin >> cartPrice;
                cout << cartItem<< "Added to cart"<<endl;
            }
            else if(choice == 3) {
                cout << " Your Cart "<<endl;
                cout << "Item: " << cartItem << endl;
                cout << "Price: Rs." << cartPrice << endl;
            }
        } while(choice != 4);
    }
};
int main() {
    Customer c1("Sawaira", 101);  
    Dashboard d(c1);             
    d.showMenu();                 
    return 0;
}


