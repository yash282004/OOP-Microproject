#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;


// Define a structure to represent a medicine
struct Medicine {
    string name;
    double price;
    int quantity;
};

// Define a function to display the inventory
void displayInventory(const map<string, Medicine>& inventory) {
    cout << "Current Inventory:\n";
    cout << "-----------------------------------\n";
    cout << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    cout << "-----------------------------------\n";
    
    for (const auto& item : inventory) {
    cout << setw(20) << item.first << setw(10) << item.second.price << setw(10) << item.second.quantity << endl;
    }
    
    cout << "-----------------------------------\n";
}

// Define a function to add a medicine to the inventory
void addMedicine(map<string, Medicine>& inventory, const string& name, double price, int quantity) {
    Medicine med;
    med.name = name;
    med.price = price;
    med.quantity = quantity;
    inventory[name] = med;
    cout << name << " added to the inventory.\n";
}

// Define a function to generate a receipt
void generateReceipt(const vector<Medicine>& cart) {
    double total = 0;
    
    cout << "Receipt:\n";
    cout << "-----------------------------------\n";
    cout << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Subtotal" << endl;
    cout << "-----------------------------------\n";
    
    for (const Medicine& item : cart) {
        double subtotal = item.price * item.quantity;
        cout << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << subtotal << endl;
        total += subtotal;
    }
    
    cout << "-----------------------------------\n";
    cout << "Total: " << total << endl;
}

int main() {
    map<string, Medicine> inventory;
    vector<Medicine> cart;
    
    // Initialize some sample inventory items
    addMedicine(inventory, "Aspirin", 5.99, 100);
    addMedicine(inventory, "Ibuprofen", 7.99, 75);
    addMedicine(inventory, "Paracetamol", 4.99, 120);
    
    while (true) {
        int choice;
        cout << "Options:\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add to Cart\n";
        cout << "3. Generate Receipt\n";
        cout << "4. Add Medicine to Inventory\n";  // Added option
        cout << "5. Exit\n";  // Updated to include the new option
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayInventory(inventory);
                break;
            case 2:
                {
                    string medName;
                    int quantity;
                    cout << "Enter Medicine Name and Quantity: ";
                    cin >> medName >> quantity;
                    if (inventory.find(medName) != inventory.end() && inventory[medName].quantity >= quantity) {
                        cart.push_back(inventory[medName]);
                        cart.back().quantity = quantity;
                        inventory[medName].quantity -= quantity;
                        cout << quantity << " " << medName << " added to the cart.\n";
                    } else {
                        cout << "Medicine not found in the inventory or insufficient quantity.\n";
                    }
                }
                break;
            case 3:
                generateReceipt(cart);
                cart.clear();
                break;
            case 4:
        // Add a new case to add more medicines to the inventory
        {
            string name;
            double price;
            int quantity;
            cout << "Enter Medicine Name, Price, and Quantity: ";
            cin >> name >> price >> quantity;
            addMedicine(inventory, name, price, quantity);
        }
        break;
    case 5:
        return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
