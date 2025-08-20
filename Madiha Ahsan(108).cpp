#include <iostream>
#include<vector>
#include<string>
using namespace std;
class product{
	public:
		string name;
		int quantity;
		double price;
		product(string n,int q,double p){
			name=n;
			quantity=q;
			price=p;
		}
		double getTotalPrice(){
			return quantity*price;
		}
};
class OrderConfirmation{
	private:
		vector<product>cart;
		double total;
		public:
			OrderConfirmation(vector<product>items){
				cart=items;
				total=0.0;
			}
			void displayConfirmation(){
				if(cart.empty()){
					cout<<"your cart is empty.No order to confrim!\n";
					return;
				}
				cout<<"\n=============Order Confirmation ============\n";
				for (int i = 0; i < cart.size(); i++) {
            cout << i + 1 << ". " << cart[i].name
                 << " (x" << cart[i].quantity << ") - Rs. "
                 << cart[i].getTotalPrice() << endl;
            total += cart[i].getTotalPrice();
        }
				cout<<"********************************\n";
				cout<<"Total Amount: Rs."<<total<<endl;
				cout<<"================================\n";
				char choice;
				cout<<"/n Do you want to confirm the order?(y/n):";
				cin>>choice;
				if(choice=='y'||choice=='y'){
					cout<<"\n order confrimed! thanks you for Shopping.\n";
				}
				else{
					cout<<"\n Order Cancelled.\n";
				}
			}
};
int main(){
	vector<product>cart;
	int n;
	cout<<"Enter number of products in your order";
	cin>>n;
	for(int i=0;i<n;i++){
		string name;
		int quantity;
		double price;
		cout<<"Enter product name\n";
		cin>>name;
		cout<<"Enter quantity\n";
		cin>>quantity;
		cout<<"Enter price per items\n";
		cin>>price;
		cart.push_back(product(name,quantity,price));
	}
	OrderConfirmation order(cart);
	order.displayConfirmation();
	return 0;
}
	

