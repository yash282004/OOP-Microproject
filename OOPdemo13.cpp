#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ANSI color codes1
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";


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

    
    void addMedicine(const string& name, double price, int quantity) {
        if (inventorySize < maxInventorySize) {
                        inventory[inventorySize].name = name;
                        inventory[inventorySize].price = price;
                        inventory[inventorySize].quantity = quantity;

          
            inventorySize++;
            cout<< GREEN <<setw(20)<< name << BLUE << " added to the inventory."<<endl;
        } else {
            cout << RED <<"Inventory is full. Cannot add more items."<<endl;
        }
    }

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

   
    void addToCart(const string mname,float price, int quantity) {
        
            cart[cartSize].name = mname;
            cart[cartSize].quantity = quantity;
            cart[cartSize].price=price;
           
            cartSize++;
       
        }
    

   
    
};

class ReceiptGenerator : public Inventory {
public:
    void generateReceipt(const Medicine* cart, int cartSize) {
        float total = 0;

        cout << MAGENTA << "Receipt:"<<endl;
        cout << "----------------------------------------------------------------------"<<endl;
        cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Subtotal" << endl;
        cout << "----------------------------------------------------------------------"<<endl;

        for (int i = 0; i < cartSize; i++) {
            float subtotal = cart[i].price * cart[i].quantity;
            cout << setw(5) << (i + 1) << setw(20) << cart[i].name << setw(10) << cart[i].price << setw(10) << cart[i].quantity << setw(10) << subtotal << endl;
            total = total +subtotal;
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

    Inventory inventory; 
    ReceiptGenerator receiptGenerator; 
    ShoppingCart shoppingCart; 

  
    inventory.addMedicine("Acetaminophen", 8, 100);
    inventory.addMedicine("Adderall", 12, 75);
    inventory.addMedicine("Albuterol", 6, 120);
    inventory.addMedicine("Ambien", 9, 50);
    inventory.addMedicine("Amoxicillin", 4, 90);
    inventory.addMedicine("Antibiotics", 15, 60);
    inventory.addMedicine("Antacid", 7, 100);
    inventory.addMedicine("Antihistamine", 3, 70);
    inventory.addMedicine("Aspirin", 5, 80);
    inventory.addMedicine("Ativan", 10, 55);
    inventory.addMedicine("Atorvastatin", 11, 75);
    inventory.addMedicine("Benadryl", 6, 110);
    inventory.addMedicine("Carvedilol", 8, 65);
    inventory.addMedicine("Cephalexin", 5, 95);
    inventory.addMedicine("Ciprofloxacin", 7, 50);
    inventory.addMedicine("Citalopram", 12, 70);
    inventory.addMedicine("Claritin", 4, 60);
    inventory.addMedicine("Codeine", 14, 105);
    inventory.addMedicine("Cough Syrup", 7, 80);
    inventory.addMedicine("Escitalopram", 9, 95);
    inventory.addMedicine("Furosemide", 5, 40);
    inventory.addMedicine("Gabapentin", 8, 85);
    inventory.addMedicine("Hydrochlorothiazide", 10, 70);
    inventory.addMedicine("Ibuprofen", 6, 80);
    inventory.addMedicine("Insulin", 13, 110);
    inventory.addMedicine("Levothyroxine", 5, 120);
    inventory.addMedicine("Lisinopril", 9, 60);
    inventory.addMedicine("Loratadine", 8, 50);
    inventory.addMedicine("Losartan", 10, 45);
    inventory.addMedicine("Metformin", 9, 70);
    inventory.addMedicine("Metoprolol", 6, 40);
    inventory.addMedicine("Morphine", 12, 30);
    inventory.addMedicine("Naproxen", 8, 60);
    inventory.addMedicine("Omeprazole", 9, 85);
    inventory.addMedicine("Paracetamol", 6, 65);
    inventory.addMedicine("Penicillin", 11, 120);
    inventory.addMedicine("Prednisolone", 5, 40);
    inventory.addMedicine("Prednisone", 8, 90);
    inventory.addMedicine("Prozac", 10, 50);
   
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
                        shoppingCart.addToCart(inventory.inventory[index].name,inventory.inventory[index].price, quantity);
                        inventory.inventory[index].quantity =  inventory.inventory[index].quantity - quantity;
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
                shoppingCart.cartSize = 0; 
                break;
            case 4: {
                string name;
                double price;
                int quantity;
                cout <<YELLOW<< "Enter Medicine Name, Price, and Quantity: "<<RESET;
                cin >> name;
                for (int i = 0; i < inventory.inventorySize; i++) {
        if (inventory.inventory[i].name == name) {
            int addquantity;
            cout<<"Enter Quantity:"<<endl;
            cin>>addquantity;
            inventory.inventory[i].quantity = inventory.inventory[i].quantity+ addquantity; 
            cout << GREEN << setw(20) << name << BLUE << " quantity updated in the inventory." << endl;
            goto end;
        }
                }
                
                cin >> price >> quantity;
                inventory.addMedicine(name, price, quantity);
                end:
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
 