#include <iostream>
using namespace std;
class Review {
    string user;
    string comment;
    int rating;
public:
    Review(string u, string c, int r) {
        user = u;
        comment = c;
        if (r >= 1 && r <= 5)
            rating = r;
        else
            rating = 1;
    }

    int getRating() { return rating; }

    void show() {
        cout << user << " (" << rating << "/5): " << comment << endl;
    }
};

class Product {
    string name;
    Review* reviews[10];   
    int count;             
public:
    Product(string n = "") {
        name = n;
        count = 0;
    }

    void setName(string n) {
        name = n;
    }

    void addReview(string user, string comment, int rating) {
        if (count < 10) {
            reviews[count] = new Review(user, comment, rating);
            count++;
        }
    }

    float averageRating() {
        if (count == 0) return 0;
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += reviews[i]->getRating();
        }
        return (float)sum / count;
    }

    void showProduct() {
        cout << "\nProduct: " << name << endl;
        cout << "Average Rating: " << averageRating() << "/5" << endl;
        cout << "Reviews:" << endl;
        for (int i = 0; i < count; i++) {
            reviews[i]->show();
        }
    }
};
int main() {
    Product products[5];
    int productCount = 0;
    products[productCount].setName("Smart Watch");
    products[productCount].addReview("Ali", "Excellent features!", 5);
    products[productCount].addReview("Sara", "Battery drains fast.", 3);
    products[productCount].addReview("Usman", "Worth the price.", 4);
    productCount++;

    products[productCount].setName("Laptop");
    products[productCount].addReview("Ahmed", "Very fast and reliable.", 5);
    products[productCount].addReview("Kiran", "Gets heated quickly.", 3);
    productCount++;


    products[productCount].setName("Mobile Phone");
    products[productCount].addReview("Nida", "Camera is amazing!", 4);
    products[productCount].addReview("Hassan", "Good performance.", 5);
    products[productCount].addReview("Aliya", "Battery life could be better.", 3);
    productCount++;


    cout << "\n--- Product List ---" << endl;
    for (int i = 0; i < productCount; i++) {
        products[i].showProduct();
    }

    return 0;
}
