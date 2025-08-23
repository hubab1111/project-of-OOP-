#include <iostream>
#include <vector>
#include <string>   

using namespace std;

class Order {
protected:
    int orderID;
    string customerName;
    string status;

public:
    Order(int id, string name) {
        orderID = id;
        customerName = name;
        status = "Pending";
    }

    int getOrderID() { return orderID; }
    string getCustomerName() { return customerName; }
    string getStatus() { return status; }

    void setStatus(string newStatus) { status = newStatus; }

    virtual void displayOrder() {
        cout << "Order ID: " << orderID
             << "  Customer: " << customerName
             << "  Status: " << status << endl;
    }
};

class OnlineOrder : public Order {
    string deliveryAddress;
public:
    OnlineOrder(int id, string name, string address)
        : Order(id, name), deliveryAddress(address) {}

    void displayOrder() {   
        cout << "Online Order -> ";
        Order::displayOrder();
        cout << "Delivery Address: " << deliveryAddress << endl;
    }
};

class StorePickup : public Order {
    string storeLocation;
public:
    StorePickup(int id, string name, string store)
        : Order(id, name), storeLocation(store) {}

    void displayOrder() {   
        cout << "Store Pickup Order -> ";
        Order::displayOrder();
        cout << "Pickup Store: " << storeLocation << endl;
    }
};

class OrderTracking {
    vector<Order*> orders;

public:
    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void updateOrderStatus(int id, string newStatus) {
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i]->getOrderID() == id) {
                orders[i]->setStatus(newStatus);
                cout << "Order " << id << " updated to: " << newStatus << endl;
                return;
            }
        }
        cout << "Order not found!" << endl;
    }

    void showAllOrders() {
        for (int i = 0; i < orders.size(); i++) {
            orders[i]->displayOrder();
        }
    }
};

int main() {
    OrderTracking system;

    OnlineOrder* o1 = new OnlineOrder(101, "Muhammad Abdullah", "Lahore, Pakistan");
    StorePickup* o2 = new StorePickup(102, "Ali Ahmed", "Karachi Store");

    system.addOrder(o1);
    system.addOrder(o2);

    system.showAllOrders();

    system.updateOrderStatus(101, "Shipped");
    system.updateOrderStatus(102, "Ready for Pickup");

    system.showAllOrders();

    return 0;
}

