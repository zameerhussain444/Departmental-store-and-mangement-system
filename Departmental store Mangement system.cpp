#include <iostream>
#include <string>
using namespace std;


class Product {
public:
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    
    void display() {
        cout << name << " - $" << price << " (Stock: " << quantity << ")\n";
    }

    
    void updateQuantity(int q) {
        quantity -= q;
    }
};


int main() {
    
    Product product1("Shampoo", 5.50, 50);
    Product product2("Soap", 2.30, 100);
    Product product3("Toothpaste", 3.75, 80);

    int choice;

    while (true) {
        cout << "\n----- Department Store Menu -----\n";
        cout << "1. Display Products\n";
        cout << "2. Purchase Product\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            
            product1.display();
            product2.display();
            product3.display();
        }
        else if (choice == 2) {
            string name;
            int quantity;
            bool found = false;

            cout << "Enter product name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;

            
            if (name == "Shampoo") {
                if (product1.quantity >= quantity) {
                    product1.updateQuantity(quantity);
                    double totalPrice = product1.price * quantity;
                    cout << "Purchase successful! Total Price: $" << totalPrice << endl;
                } else {
                    cout << "Not enough stock for Shampoo!" << endl;
                }
                found = true;
            }
            else if (name == "Soap") {
                if (product2.quantity >= quantity) {
                    product2.updateQuantity(quantity);
                    double totalPrice = product2.price * quantity;
                    cout << "Purchase successful! Total Price: $" << totalPrice << endl;
                } else {
                    cout << "Not enough stock for Soap!" << endl;
                }
                found = true;
            }
            else if (name == "Toothpaste") {
                if (product3.quantity >= quantity) {
                    product3.updateQuantity(quantity);
                    double totalPrice = product3.price * quantity;
                    cout << "Purchase successful! Total Price: $" << totalPrice << endl;
                } else {
                    cout << "Not enough stock for Toothpaste!" << endl;
                }
                found = true;
            }

            if (!found) {
                cout << "Product not found!" << endl;
            }
        }
        else if (choice == 3) {
            cout << "Thank you for visiting the store!\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    
}
}





