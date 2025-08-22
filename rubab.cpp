#include <iostream>
using namespace std;
class Product {
protected:
    int id;
    string name;
    double price;

public:
    Product(int pid, string pname, double pprice)
        : id(pid), name(pname), price(pprice) {}

    virtual void display() const {
        cout << setw(5) << id << " | "
             << setw(15) << name << " | "
             << "Rs. " << price << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual ~Product() {}
};
class Clothing : public Product {
public:
    Clothing(int id, string name, double price)
        : Product(id, name, price) {}
};

class Electronics : public Product {
public:
    Electronics(int id, string name, double price)
        : Product(id, name, price) {}
};

class Grocery : public Product {
public:
    Grocery(int id, string name, double price)
        : Product(id, name, price) {}
};
class Mall {
private:
    vector<Product*> products;

public:
    Mall() {
        products.push_back(new Clothing(1, "T-Shirt", 1200));
        products.push_back(new Clothing(2, "Jeans", 2500));
        products.push_back(new Electronics(3, "Mobile Phone", 25000));
        products.push_back(new Electronics(4, "Headphones", 3500));
        products.push_back(new Grocery(5, "Rice 5kg", 1200));
        products.push_back(new Grocery(6, "Milk 1L", 180));
    }

    void showProducts() {
        cout << "\n------ Available Products ------\n";
        cout << setw(5) << "ID" << " | "
             << setw(15) << "Name" << " | "
             << "Price" << endl;
        cout << "--------------------------------\n";
        for (auto p : products) {
            p->display();
        }
    }

    Product* getProductById(int id) {
        for (auto p : products) {
            if (p->getId() == id) return p;
        }
        return nullptr;
    }

    ~Mall() {
        for (auto p : products) delete p;
    }
};
int main() {
    Mall mall;
    mall.showProducts();

    int choice;
    cout << "\nEnter product ID to view details (0 to exit): ";
    cin >> choice;

    if (choice != 0) {
        Product* selected = mall.getProductById(choice);
        if (selected) {
            cout << "\nYou selected: " << selected->getName()
                 << " | Price: Rs." << selected->getPrice() << endl;
        } else {
            cout << "Invalid product ID!\n";
        }
    }

    return 0;
}
