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
    void generateReceipt( Medicine* cart, int cartSize) {
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

    Inventory i1; 
    ReceiptGenerator r1; 
    ShoppingCart s1; 

  
    i1.addMedicine("Acetaminophen", 8, 100);
    i1.addMedicine("Adderall", 12, 75);
    i1.addMedicine("Albuterol", 6, 120);
    i1.addMedicine("Ambien", 9, 50);
    i1.addMedicine("Amoxicillin", 4, 90);
    i1.addMedicine("Antibiotics", 15, 60);
    i1.addMedicine("Antacid", 7, 100);
    i1.addMedicine("Antihistamine", 3, 70);
    i1.addMedicine("Aspirin", 5, 80);
    i1.addMedicine("Ativan", 10, 55);
    i1.addMedicine("Atorvastatin", 11, 75);
    i1.addMedicine("Benadryl", 6, 110);
    i1.addMedicine("Carvedilol", 8, 65);
    i1.addMedicine("Cephalexin", 5, 95);
    i1.addMedicine("Ciprofloxacin", 7, 50);
    i1.addMedicine("Citalopram", 12, 70);
    i1.addMedicine("Claritin", 4, 60);
    i1.addMedicine("Codeine", 14, 105);
    i1.addMedicine("Cough Syrup", 7, 80);
    i1.addMedicine("Escitalopram", 9, 95);
    i1.addMedicine("Furosemide", 5, 40);
    i1.addMedicine("Gabapentin", 8, 85);
    i1.addMedicine("Hydrochlorothiazide", 10, 70);
    i1.addMedicine("Ibuprofen", 6, 80);
    i1.addMedicine("Insulin", 13, 110);
    i1.addMedicine("Levothyroxine", 5, 120);
    i1.addMedicine("Lisinopril", 9, 60);
    i1.addMedicine("Loratadine", 8, 50);
    i1.addMedicine("Losartan", 10, 45);
    i1.addMedicine("Metformin", 9, 70);
    i1.addMedicine("Metoprolol", 6, 40);
    i1.addMedicine("Morphine", 12, 30);
    i1.addMedicine("Naproxen", 8, 60);
    i1.addMedicine("Omeprazole", 9, 85);
    i1.addMedicine("Paracetamol", 6, 65);
    i1.addMedicine("Penicillin", 11, 120);
    i1.addMedicine("Prednisolone", 5, 40);
    i1.addMedicine("Prednisone", 8, 90);
    i1.addMedicine("Prozac", 10, 50);
   
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
                i1.displayInventory();
                break;
            case 2: {
                int medNo, quantity;
                cout << "Enter Medicine Number and Quantity: ";
                cin >> medNo >> quantity;
                if (medNo >= 1 && medNo <= i1.inventorySize) {
                    int index = medNo - 1;
                    if (i1.inventory[index].quantity >= quantity) {
                        s1.addToCart(i1.inventory[index].name,i1.inventory[index].price, quantity);
                        i1.inventory[index].quantity =  i1.inventory[index].quantity - quantity;
                        cout << quantity << " " << i1.inventory[index].name << " added to the cart."<<endl;
                    } else {
                        cout << RED <<"Insufficient quantity of " << i1.inventory[index].name << " in the inventory."<<RESET<<endl;
                    }
                } else {
                    cout <<RED<< "Invalid medicine number."<<RESET<<endl;
                }
                break;
            }
            case 3:
                r1.generateReceipt(s1.cart, s1.cartSize);
                s1.cartSize = 0; 
                break;
            case 4: {
                string name;
                double price;
                int quantity;
                cout <<YELLOW<< "Enter Medicine Name, Price, and Quantity: "<<RESET;
                cin >> name;
                for (int i = 0; i < i1.inventorySize; i++) {
        if (i1.inventory[i].name == name) {
            int addquantity;
            cout<<"Enter Quantity:"<<endl;
            cin>>addquantity;
            i1.inventory[i].quantity = i1.inventory[i].quantity+ addquantity; 
            cout << GREEN << setw(20) << name << BLUE << " quantity updated in the inventory." << endl;
            goto end;
        }
                }
                
                cin >> price >> quantity;
                i1.addMedicine(name, price, quantity);
                end:
                break;
            }
            case 5:
                cout<<CYAN<<"Thank you for using our software "<<endl;
                cout<<"Guided by S.V Jadhav"<<endl;
                cout<<"Micro-project on Medical Store Management"<<endl;
                cout<<"Under subject Object oriented programming ( OOP )"<<endl<<endl;
                cout<<"Submitted by :-  1255 Mayur Dhanaji Jagdale"<<endl;
                cout<<"                 1258 Yash Santosh Khandagale"<<endl;
                cout<<"                 1261 Om Ramdas Chavhan"<<endl;
                cout<<"                 1271 Sakshi Pradip Sagare"<<endl<<endl;
                cout<<"Academic Year 2023-24";
                return 0;
            default:
                cout << RED<<"Invalid choice. Try again."<<RESET<<endl;
        }
    }while(choice!=5);

    return 0;
}
 