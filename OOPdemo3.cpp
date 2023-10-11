#include <iostream>
#include <map>
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
    cout << setw(5) << "No" << setw(20) << "Medicine Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    cout << "-----------------------------------\n";

    int no = 1;
    for (const auto& item : inventory) {
        cout << setw(5) << no << setw(20) << item.first << setw(10) << item.second.price << setw(10) << item.second.quantity << endl;
        no++;
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
    map<string, Medicine> inventory;

    // Initialize some sample inventory items
    addMedicine(inventory, "Acetaminophen", 8.99, 100);
    addMedicine(inventory, "Adderall", 12.99, 75);
    addMedicine(inventory, "Albuterol", 6.99, 120);
    addMedicine(inventory, "Ambien", 9.99, 50);
    addMedicine(inventory, "Amoxicillin", 4.49, 90);
    addMedicine(inventory, "Antibiotics", 15.99, 60);
    addMedicine(inventory, "Antacid", 7.99, 100);
    addMedicine(inventory, "Antihistamine", 3.99, 70);
    addMedicine(inventory, "Aspirin", 5.99, 80);
    addMedicine(inventory, "Ativan", 10.49, 55);
    addMedicine(inventory, "Atorvastatin", 11.49, 75);
    addMedicine(inventory, "Benadryl", 6.49, 110);
    addMedicine(inventory, "Carvedilol", 8.99, 65);
    addMedicine(inventory, "Cephalexin", 5.49, 95);
    addMedicine(inventory, "Ciprofloxacin", 7.99, 50);
    addMedicine(inventory, "Citalopram", 12.99, 70);
    addMedicine(inventory, "Claritin", 4.99, 60);
    addMedicine(inventory, "Codeine", 14.99, 105);
    addMedicine(inventory, "Cough Syrup", 7.49, 80);
    addMedicine(inventory, "Escitalopram", 9.99, 95);
    addMedicine(inventory, "Furosemide", 5.99, 40);
    addMedicine(inventory, "Gabapentin", 8.49, 85);
    addMedicine(inventory, "Hydrochlorothiazide", 10.99, 70);
    addMedicine(inventory, "Ibuprofen", 6.99, 80);
    addMedicine(inventory, "Insulin", 13.99, 110);
    addMedicine(inventory, "Levothyroxine", 5.99, 120);
    addMedicine(inventory, "Lisinopril", 9.99, 60);
    addMedicine(inventory, "Loratadine", 8.99, 50);
    addMedicine(inventory, "Losartan", 10.99, 45);
    addMedicine(inventory, "Metformin", 7.99, 70);
    addMedicine(inventory, "Metoprolol", 6.49, 40);
    addMedicine(inventory, "Morphine", 12.99, 30);
    addMedicine(inventory, "Naproxen", 7.99, 60);
    addMedicine(inventory, "Omeprazole", 9.49, 85);
    addMedicine(inventory, "Paracetamol", 6.99, 65);
    addMedicine(inventory, "Penicillin", 11.99, 120);
    addMedicine(inventory, "Prednisolone", 5.99, 40);
    addMedicine(inventory, "Prednisone", 8.49, 90);
    addMedicine(inventory, "Prozac", 10.49, 50);
    addMedicine(inventory, "Ritalin", 7.49, 70);
    addMedicine(inventory, "Sertraline", 9.99, 100);
    addMedicine(inventory, "Simvastatin", 5.99, 60);
    addMedicine(inventory, "Sudafed", 12.99, 40);
    addMedicine(inventory, "Tamsulosin", 7.99, 70);
    addMedicine(inventory, "Tramadol", 9.49, 35);
    addMedicine(inventory, "Valium", 11.99, 40);
    addMedicine(inventory, "Vitamin C", 6.49, 25);
    addMedicine(inventory, "Warfarin", 7.99, 35);
    addMedicine(inventory, "Xanax", 10.99, 65);

    const int maxCartSize = 100;  // Define a maximum cart size
    Medicine cart[maxCartSize];   // Use an array for the cart
    int cartSize = 0;             // Initialize the cart size

    while (true) {
        int choice;
        cout << "Options:\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add to Cart\n";
        cout << "3. Generate Receipt\n";
        cout << "4. Add Medicine to Inventory\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                displayInventory(inventory);
                break;
            case 2: {
                int medNo, quantity;
                cout << "Enter Medicine Number and Quantity: ";
                cin >> medNo >> quantity;
                if (medNo >= 1 && medNo <= inventory.size()) {
                    auto it = inventory.begin();
                    advance(it, medNo - 1);
                    const string& medName = it->first;
                    if (it->second.quantity >= quantity) {
                        cart[cartSize] = it->second;
                        cart[cartSize].quantity = quantity;
                        it->second.quantity -= quantity;
                        cartSize++;
                        cout << quantity << " " << medName << " added to the cart.\n";
                    } else {
                        cout << "Insufficient quantity of " << medName << " in the inventory.\n";
                    }
                } else {
                    cout << "Invalid medicine number.\n";
                }
                break;
            }
            case 3:
                generateReceipt(cart, cartSize);
                cartSize = 0;  // Clear the cart
                break;
            case 4: {
                string name;
                double price;
                int quantity;
                cout << "Enter Medicine Name, Price, and Quantity: ";
                cin >> name >> price >> quantity;
                addMedicine(inventory, name, price, quantity);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
