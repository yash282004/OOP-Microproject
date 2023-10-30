#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define a structure to represent a medicine
struct Medicine {
    string name;
    double price;
    int quantity;
};

class MedicineInventory {
public:
    const int maxInventorySize = 50;
    Medicine inventory[50];
    int inventorySize = 0;

public:
    // Add a medicine to the inventory
    void addMedicine(const string& name, double price, int quantity) {
        if (inventorySize < maxInventorySize) {
            Medicine med;
            med.name = name;
            med.price = price;
            med.quantity = quantity;
            inventory[inventorySize] = med;
            inventorySize++;
            cout << name << " added to the inventory.\n";
        } else {
            cout << "Inventory is full. Cannot add more items.\n";
        }
    }

    // Display the inventory
    void displayInventory() {
        cout << "Current Inventory:\n";
        cout << "-----------------------------------\n";
        cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        cout << "-----------------------------------\n";

        for (int i = 0; i < inventorySize; i++) {
            cout << setw(5) << (i + 1) << setw(20) << inventory[i].name << setw(10) << inventory[i].price << setw(10) << inventory[i].quantity << endl;
        }

        cout << "-----------------------------------\n";
    }
};
void generateReceipt(const Medicine* cart, int cartSize) {
    double total = 0;

    cout << "Receipt:\n";
    cout << "-----------------------------------\n";
    cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Subtotal" << endl;
    cout << "-----------------------------------\n";

    for (int i = 0; i < cartSize; i++) {
        const Medicine& item = cart[i];
        double subtotal = item.price * item.quantity;
        cout << setw(5) << (i + 1) << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << subtotal << endl;
        total += subtotal;
    }

    cout << "-----------------------------------\n";
    cout << "Total: " << total << endl;
}

int main() {
    const int maxCartSize = 100;
    Medicine cart[maxCartSize];
    int cartSize = 0;
    int choice;

    MedicineInventory inventory; // Create an instance of the MedicineInventory class

    // Initialize some sample inventory items
    inventory.addMedicine("Acetaminophen", 8.99, 100);
    inventory.addMedicine("Adderall", 12.99, 75);
    // ... (other sample inventory items)

    do
    {
        cout << "Options:\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add to Cart\n";
        cout << "3. Generate Receipt\n";
        cout << "4. Add Medicine to Inventory\n";
        cout << "5. Exit\n";
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
                        cart[cartSize] = inventory.inventory[index];
                        cart[cartSize].quantity = quantity;
                        inventory.inventory[index].quantity -= quantity;
                        cartSize++;
                        cout << quantity << " " << inventory.inventory[index].name << " added to the cart.\n";
                    } else {
                        cout << "Insufficient quantity of " << inventory.inventory[index].name << " in the inventory.\n";
                    }
                } else {
                    cout << "Invalid medicine number.\n";
                }
                break;
            }
            case 3:
                generateReceipt(cart, cartSize);
                cartSize = 0; // Clear the cart
                break;
            case 4: {
                string name;
                double price;
                int quantity;
                cout << "Enter Medicine Name, Price, and Quantity: ";
                cin >> name >> price >> quantity;
                inventory.addMedicine(name, price, quantity);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }while(choice!=5);

    return 0;
}
