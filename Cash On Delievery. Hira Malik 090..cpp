#include <iostream>
using namespace std;

class Payment {
public:
    float amount;

    Payment(float a = 0) {
        amount = a;
    }

    virtual void makePayment() {
        cout << "Generic payment of Rs. " << amount << endl;
    }
};

class CashOnDelivery : public Payment {
public:
    string customerName;
    string address;

    CashOnDelivery(string name = "", string addr = "", float a = 0) : Payment(a) {
        customerName = name;
        address = addr;
    }

    void makePayment() override {
        cout << "\n--- Cash on Delivery ---" << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Address : " << address << endl;
        cout << "Amount  : Rs. " << amount << endl;
        cout << "Payment Status: Pending until delivery." << endl;
    }
};

int main() {
    CashOnDelivery codCustomers[100]; // simple array for up to 100 customers
    int count = 0;
    int choice;

    do {
        cout << "\n=== Cash on Delivery System ===" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Show All Customers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, addr;
            float amt;

            cout << "\nEnter Customer Name: ";
            getline(cin, name);

            cout << "Enter Address: ";
            getline(cin, addr);

            cout << "Enter Amount (Rs.): ";
            cin >> amt;
            cin.ignore();

            codCustomers[count] = CashOnDelivery(name, addr, amt);
            count++;

            cout << "\nCustomer added successfully!" << endl;
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo customers found." << endl;
            } else {
                cout << "\n==== All Cash on Delivery Customers ====\n";
                for (int i = 0; i < count; i++) {
                    codCustomers[i].makePayment();
                }
            }
        }

    } while (choice != 3);

    return 0;
}
