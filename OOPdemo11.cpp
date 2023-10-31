#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

// Define a structure to represent a medicine
struct Medicine {
    string name;
    double price;
    int quantity;
};

class Inventory {
public:
    const int maxInventorySize = 50;
    Medicine inventory[50];
    int inventorySize = 0;

    // Add a medicine to the inventory
    void addMedicine(const string& name, double price, int quantity) {
        if (inventorySize < maxInventorySize) {
            Medicine med;
            med.name = name;
            med.price = price;
            med.quantity = quantity;
            inventory[inventorySize] = med;
            inventorySize++;
            cout<< GREEN <<setw(20)<< name << BLUE << " added to the inventory."<<endl;
        } else {
            cout << RED <<"Inventory is full. Cannot add more items."<<endl;
        }
    }

    // Display the inventory
    void displayInventory() {
        cout << "Current Inventory:"<<endl;
        cout << "----------------------------------------------------------------------"<<endl;
        cout << setw(5) << "No" << setw(17) <<GREEN<< "Medicine Name" <<RESET<< setw(10) << "Price" << setw(10) << "Quantity" << endl;
        cout << "----------------------------------------------------------------------"<<endl;

        for (int i = 0; i < inventorySize; i++) {
            cout << setw(5) << (i + 1) << setw(25) << inventory[i].name << setw(10) << inventory[i].price << setw(10) << inventory[i].quantity << endl;
        }

        cout << "----------------------------------------------------------------------"<<endl;
    }
};

class ShoppingCart {
public:
    const int maxCartSize = 100;
    Medicine cart[100];
    int cartSize = 0;

    // Add a medicine to the shopping cart
    void addToCart(const Medicine& medicine, int quantity) {
        if (cartSize < maxCartSize) {
            Medicine cartItem = medicine;
            cartItem.quantity = quantity;
            cart[cartSize] = cartItem;
            cartSize++;
        } else {
            cout << RED<<"Cart is full. Cannot add more items."<<RESET<<endl;
        }
    }

    // Display the shopping cart
    void displayCart() {
        cout << "Shopping Cart:"<<endl;
        cout << "-----------------------------------"<<endl;
        cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        cout << "-----------------------------------"<<endl;

        for (int i = 0; i < cartSize; i++) {
            const Medicine& item = cart[i];
            cout << setw(5) << (i + 1) << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << endl;
        }

        cout << "-----------------------------------"<<endl;
    }
};

class ReceiptGenerator : public Inventory {
public:
    void generateReceipt(const Medicine* cart, int cartSize) {
        double total = 0;

        cout << MAGENTA << "Receipt:"<<endl;
        cout << "----------------------------------------------------------------------"<<endl;
        cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Subtotal" << endl;
        cout << "----------------------------------------------------------------------"<<endl;

        for (int i = 0; i < cartSize; i++) {
            const Medicine& item = cart[i];
            double subtotal = item.price * item.quantity;
            cout << setw(5) << (i + 1) << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << subtotal << endl;
            total += subtotal;
        }

        cout << "----------------------------------------------------------------------"<<endl;
        cout << "Total: " << total << RESET << endl;
    }
};

int main() {
    const int maxCartSize = 100;
    Medicine cart[maxCartSize];
    int cartSize = 0;
    int choice;

    Inventory inventory; // Create an instance of the Inventory class
    ReceiptGenerator receiptGenerator; // Create an instance of the ReceiptGenerator class
    ShoppingCart shoppingCart; // Create an instance of the ShoppingCart class

    // Initialize some sample inventory items
    inventory.addMedicine("Acetaminophen", 8.99, 100);
    inventory.addMedicine("Adderall", 12.99, 75);
    inventory.addMedicine("Albuterol", 6.99, 120);
    inventory.addMedicine("Ambien", 9.99, 50);
    inventory.addMedicine("Amoxicillin", 4.49, 90);
    inventory.addMedicine("Antibiotics", 15.99, 60);
    inventory.addMedicine("Antacid", 7.99, 100);
    inventory.addMedicine("Antihistamine", 3.99, 70);
    inventory.addMedicine("Aspirin", 5.99, 80);
    inventory.addMedicine("Ativan", 10.49, 55);
    inventory.addMedicine("Atorvastatin", 11.49, 75);
    inventory.addMedicine("Benadryl", 6.49, 110);
    inventory.addMedicine("Carvedilol", 8.99, 65);
    inventory.addMedicine("Cephalexin", 5.49, 95);
    inventory.addMedicine("Ciprofloxacin", 7.99, 50);
    inventory.addMedicine("Citalopram", 12.99, 70);
    inventory.addMedicine("Claritin", 4.99, 60);
    inventory.addMedicine("Codeine", 14.99, 105);
    inventory.addMedicine("Cough Syrup", 7.49, 80);
    inventory.addMedicine("Escitalopram", 9.99, 95);
    inventory.addMedicine("Furosemide", 5.99, 40);
    inventory.addMedicine("Gabapentin", 8.49, 85);
    inventory.addMedicine("Hydrochlorothiazide", 10.99, 70);
    inventory.addMedicine("Ibuprofen", 6.99, 80);
    inventory.addMedicine("Insulin", 13.99, 110);
    inventory.addMedicine("Levothyroxine", 5.99, 120);
    inventory.addMedicine("Lisinopril", 9.99, 60);
    inventory.addMedicine("Loratadine", 8.99, 50);
    inventory.addMedicine("Losartan", 10.99, 45);
    inventory.addMedicine("Metformin", 7.99, 70);
    inventory.addMedicine("Metoprolol", 6.49, 40);
    inventory.addMedicine("Morphine", 12.99, 30);
    inventory.addMedicine("Naproxen", 7.99, 60);
    inventory.addMedicine("Omeprazole", 9.49, 85);
    inventory.addMedicine("Paracetamol", 6.99, 65);
    inventory.addMedicine("Penicillin", 11.99, 120);
    inventory.addMedicine("Prednisolone", 5.99, 40);
    inventory.addMedicine("Prednisone", 8.49, 90);
    inventory.addMedicine("Prozac", 10.49, 50);
    inventory.addMedicine("Ritalin", 7.49, 70);
    inventory.addMedicine("Sertraline", 9.99, 100);
    inventory.addMedicine("Simvastatin", 5.99, 60);
    inventory.addMedicine("Sudafed", 12.99, 40);
    inventory.addMedicine("Tamsulosin", 7.99, 70);
    inventory.addMedicine("Tramadol", 9.49, 35);
    inventory.addMedicine("Valium", 11.99, 40);
    inventory.addMedicine("Vitamin C", 6.49, 25);
    inventory.addMedicine("Warfarin", 7.99, 35);
    inventory.addMedicine("Xanax", 10.99, 65);
    do {
        cout << YELLOW;
        cout << "Options:"<<endl;
        cout << "1. Display Inventory"<<endl;
        cout << "2. Add to Cart"<<endl;
        cout << "3. Generate Receipt"<<endl;
        cout << "4. Add Medicine to Inventory"<<endl;
        cout << "5. Exit"<<endl;
        cout<< RESET<<"Enter your options:";
        cin >> choice;


        switch (choice) {
            case 1:
                inventory.displayInventory();
                break;
            case 2: {
                int medNo, quantity;
                cout << "Enter Medicine Number and Quantity: ";
                cin >> medNo >> quantity;
                if (medNo >= 1 && medNo <= inventory.inventorySize) {
                    int index = medNo - 1;
                    if (inventory.inventory[index].quantity >= quantity) {
                        shoppingCart.addToCart(inventory.inventory[index], quantity);
                        inventory.inventory[index].quantity -= quantity;
                        cout << quantity << " " << inventory.inventory[index].name << " added to the cart."<<endl;
                    } else {
                        cout << RED <<"Insufficient quantity of " << inventory.inventory[index].name << " in the inventory."<<RESET<<endl;
                    }
                } else {
                    cout <<RED<< "Invalid medicine number."<<RESET<<endl;
                }
                break;
            }
            case 3:
                receiptGenerator.generateReceipt(shoppingCart.cart, shoppingCart.cartSize);
                shoppingCart.cartSize = 0; // Clear the cart
                break;
            case 4: {
                string name;
                double price;
                int quantity;
                cout <<YELLOW<< "Enter Medicine Name, Price, and Quantity: "<<RESET;
                cin >> name >> price >> quantity;
                inventory.addMedicine(name, price, quantity);
                break;
            }
            case 5:
                return 0;
            default:
                cout << RED<<"Invalid choice. Try again."<<RESET<<endl;
        }
    }while(choice!=5);

    return 0;
}
 