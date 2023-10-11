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

const int maxInventorySize = 50; // Define the maximum inventory size
Medicine inventory[maxInventorySize]; // Array to store the inventory
int inventorySize = 0; // Current size of the inventory

// Define a function to display the inventory
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

// Define a function to add a medicine to the inventory
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
    const int maxCartSize = 100; // Define a maximum cart size
    Medicine cart[maxCartSize]; // Use an array for the cart
    int cartSize = 0; // Initialize the cart size

    // Initialize some sample inventory items
    addMedicine("Acetaminophen", 8.99, 100);
    addMedicine("Adderall", 12.99, 75);
    addMedicine("Albuterol", 6.99, 120);
    addMedicine("Ambien", 9.99, 50);
    addMedicine("Amoxicillin", 4.49, 90);
    addMedicine("Antibiotics", 15.99, 60);
    addMedicine("Antacid", 7.99, 100);
    addMedicine("Antihistamine", 3.99, 70);
    addMedicine("Aspirin", 5.99, 80);
    addMedicine("Ativan", 10.49, 55);
    addMedicine("Atorvastatin", 11.49, 75);
    addMedicine("Benadryl", 6.49, 110);
    addMedicine("Carvedilol", 8.99, 65);
    addMedicine("Cephalexin", 5.49, 95);
    addMedicine("Ciprofloxacin", 7.99, 50);
    addMedicine("Citalopram", 12.99, 70);
    addMedicine("Claritin", 4.99, 60);
    addMedicine("Codeine", 14.99, 105);
    addMedicine("Cough Syrup", 7.49, 80);
    addMedicine("Escitalopram", 9.99, 95);
    addMedicine("Furosemide", 5.99, 40);
    addMedicine("Gabapentin", 8.49, 85);
    addMedicine("Hydrochlorothiazide", 10.99, 70);
    addMedicine("Ibuprofen", 6.99, 80);
    addMedicine("Insulin", 13.99, 110);
    addMedicine("Levothyroxine", 5.99, 120);
    addMedicine("Lisinopril", 9.99, 60);
    addMedicine("Loratadine", 8.99, 50);
    addMedicine("Losartan", 10.99, 45);
    addMedicine("Metformin", 7.99, 70);
    addMedicine("Metoprolol", 6.49, 40);
    addMedicine("Morphine", 12.99, 30);
    addMedicine("Naproxen", 7.99, 60);
    addMedicine("Omeprazole", 9.49, 85);
    addMedicine("Paracetamol", 6.99, 65);
    addMedicine("Penicillin", 11.99, 120);
    addMedicine("Prednisolone", 5.99, 40);
    addMedicine("Prednisone", 8.49, 90);
    addMedicine("Prozac", 10.49, 50);
    addMedicine("Ritalin", 7.49, 70);
    addMedicine("Sertraline", 9.99, 100);
    addMedicine("Simvastatin", 5.99, 60);
    addMedicine("Sudafed", 12.99, 40);
    addMedicine("Tamsulosin", 7.99, 70);
    addMedicine("Tramadol", 9.49, 35);
    addMedicine("Valium", 11.99, 40);
    addMedicine("Vitamin C", 6.49, 25);
    addMedicine("Warfarin", 7.99, 35);
    addMedicine("Xanax", 10.99, 65);

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
                displayInventory();
                break;
            case 2: {
                int medNo, quantity;
                cout << "Enter Medicine Number and Quantity: ";
                cin >> medNo >> quantity;
                if (medNo >= 1 && medNo <= inventorySize) {
                    int index = medNo - 1;
                    if (inventory[index].quantity >= quantity) {
                        cart[cartSize] = inventory[index];
                        cart[cartSize].quantity = quantity;
                        inventory[index].quantity -= quantity;
                        cartSize++;
                        cout << quantity << " " << inventory[index].name << " added to the cart.\n";
                    } else {
                        cout << "Insufficient quantity of " << inventory[index].name << " in the inventory.\n";
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
                addMedicine(name, price, quantity);
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
