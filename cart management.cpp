# include <iostream>
using namespace std;
float price = 0;
class cart{
	public:
		void display(){
			int a;
			cout << "Enter the number from (1 to 10) for order:" << endl;
			cin >> a;
			switch (a){
			case 1:
				price += 2500;
				cout << "Pizza = 2500" << endl;
				cout << "Add to cart" << endl;
				break;
					case 2:
				price += 1800;
				cout << "Fried Chicken = 1800" << endl;
				cout << "Add to cart" << endl;
				break;
					case 3:
				price += 200;
				cout << "Fanta = 200" << endl;
				cout << "Add to cart" << endl;
				break;
					case 4:
				price += 200;
				cout << "coke = 200" << endl;
				cout << "Add to cart" << endl;
				break;
					case 5:
				price += 3500;
				cout << "Shirts = 3500" << endl;
				cout << "Add to cart" << endl;
				break;
					case 6:
				price += 3000;
				cout << "Baggy Pants = 3000" << endl;
				cout << "Add to cart" << endl;
				break;
					case 7:
				price += 9000;
				cout << "Lofers = 9000" << endl;
				cout << "Add to cart" << endl;
				break;
					case 8:
				price += 5000;
				cout << "Joggers = 5000" << endl;
				cout << "Add to cart" << endl;
				break;
					case 9:
				price += 27000;
				cout << "Watch = 27000" << endl;
				cout << "Add to cart" << endl;
				break;
					case 10:
				price += 2000;
				cout << "Earings = 2000" << endl;
				cout << "Add to cart" << endl;
				break;
				default:
					cout << "Invalid choice" << endl;
			}
		}
};
class pay {
	private:
		int accountNumber;
		int pin;
		
		public:
			string name;
			int age;
			string gender;
			
			void getpay(){
				cout << "--------PAYMENT DETAILS ----------" << endl;
				cout << "Name :" << name << endl;
				cout << "Age :" << age << endl;
				cout << "Gender :" << gender << endl;
				cout << "Account Number :" << accountNumber << endl;
				cout << "Pin :" << pin << endl;
				cout << "Total Price Paid:" << price << endl;
			}
			void setpay(int acc, int p ){
				this->accountNumber =acc;
				this->pin = p;
			}
};
int main(){
	
	int n;
	do{
		cout << "1. See Menu" << endl;
		cout << "2. Exit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> n;
		
		switch (n){
			case 1:
				cout << "---------SEE MENU------------" << endl;
				cout << "1. Pizza" <<endl;
				cout << "2. Fried Chicken" << endl;
				cout << "3. Fanta" << endl;
				cout << "4. Coke" << endl;
				cout << "5. shirts" << endl;
				cout << "6. Baggy Pants" << endl;
				cout << "7. Lofers" << endl;
				cout << "8.Joggers" << endl;
				cout << "9. Watch" << endl;
				cout << "10. Earings" << endl;
				
				{
					
					cart c1;
					c1.display();
					
				}
				break;
				case 2:
					cout << "---------EXIT--------" << endl;
					cout << "Your Total price=" << price << endl;
					break;
					
					default:
						cout << "Invalid choice! Please Try again." << endl;
						break;
		}
	} while (n != 2);
	
	pay p1;
	cout << "Enter your Name:" << endl;
	cin >> p1.name;
	cout << "Enter your Age:" << endl;
	cin >> p1.age;
	cout << "Enter your Gender:" << endl;
    cin >> p1.gender;
	
	int acc,pin;
	cout << "Enter your Account Number:" << endl;
	cin >> acc;
	cout << "Enter your PIN:" << endl;
	cin >> pin;
	
	p1.setpay(acc,pin);
	p1.getpay(); 
	
	
	return 0;
}
