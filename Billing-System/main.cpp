#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Product
{
public:
    int id;
    string name;
    int stock;
    float price;

    Product(int id, string name, int stock, float price)
        : id(id), name(name), stock(stock), price(price) {}
};

class CartItem
{
public:
    string name;
    float price;
    int quantity;

    CartItem(string name, float price, int quantity)
        : name(name), price(price), quantity(quantity) {}
};

class BillingSystem
{
private:
    vector<Product> products;
    vector<CartItem> cart;

public:
    // Add product to Cart
    bool addProduct(int id, string name, int stock, float price)
    {
        for (Product &p : products)
        {
            if (p.name == name)
            {
                cout << "\nThis product already exists in inventory.\n";
                return false;
            }
        }

        products.push_back(Product(id, name, stock, price));
        cout << "\nProduct Added successfully";
        return true;
    }
    // Show Inventory
    void inventory()
    {
        if (products.empty())
        {
            cout << "\nNo products available.";
            return;
        }

        for (Product &p : products)
        {
            cout << "\nID : " << p.id;
            cout << "\nName : " << p.name;
            cout << "\nStock : " << p.stock;
            cout << "\nPrice : " << p.price;
            cout << "\n------------------------------\n";
        }
    }
    // Add product to Cart
    void addToCart(string name, int quantity)
    {
        bool found = false;

        for (CartItem &c : cart)
        {
            if (c.name == name)
            {
                cout << "\nProduct already exists in cart.\n";
                return;
            }
        }

        for (Product &p : products)
        {
            if (p.name == name)
            {
                found = true;

                if (quantity <= 0)
                {
                    cout << "\nInvalid quantity!";
                    return;
                }

                if (p.stock >= quantity)
                {
                    cart.push_back(CartItem(p.name, p.price, quantity));
                    p.stock -= quantity;
                    cout << "\nProduct added to cart successfully!\n";
                }
                else
                {
                    int available = p.stock;

                    if (available == 0)
                    {
                        cout << "\nOut of stock!\n";
                        return;
                    }

                    cart.push_back(CartItem(p.name, p.price, available));
                    cout << "\nOnly " << available << " items available.\n";
                    p.stock = 0;
                }
                break;
            }
        }

        if (!found)
        {
            cout << "\nProduct not found.\n";
        }
    }
    // Show Cart items
    void showCart()
    {
        if (cart.empty())
        {
            cout << "\nYour cart is empty.";
            return;
        }

        int num = 0;
        cout << "\n | No | Name | Price | Qty |";
        for (CartItem &c : cart)
        {
            num++;
            cout << "\n | " << num << " | " << c.name << " | " << c.price << " | " << c.quantity << " |";
        }
    }
    // Calculate Bill
    void calculateBill()
    {
        if (cart.empty())
        {
            cout << "\nYour cart is empty.\n";
            return;
        }

        double total = 0;
        for (CartItem &c : cart)
        {
            total += (c.quantity * c.price);
        }

        cout << "\nTotal Bill : " << total;
    }
    // Create New Cart
    void newCart()
    {
        cart.clear();
        cout << "\nNew cart started!\n";
    }
    // Remove Individual item from Cart
    void removeItem(string name)
    {
        bool found = false;

        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i].name == name)
            {
                found = true;

                // Restore stock
                for (Product &p : products)
                {
                    if (p.name == name)
                    {
                        p.stock += cart[i].quantity;
                        break;
                    }
                }

                cart.erase(cart.begin() + i);
                cout << "\nItem removed successfully!\n";
                return;
            }
        }

        if (!found)
        {
            cout << "\nItem not found in cart.\n";
        }
    }
    // Print Bill
    void printBill()
    {
        if (cart.empty())
        {
            cout << "\nYour cart is empty.\n";
            return;
        }
    
        double total = 0;
        int num = 0;

        cout << "\n | No | Name | Price | Qty |";

        for (CartItem &c : cart)
        {
            num++;
            cout << "\n | " << num << " | " << c.name << " | " << c.price << " | " << c.quantity << " |";
            total += (c.quantity * c.price);
        }

        cout << "\n--------------------------------------";
        cout << "\nTotal Bill : " << total << endl;
    }
};

int main()
{
    BillingSystem bill;

    int id = 0, stock;
    string name;
    float price;

    while (true)
    {
        int choice;
        cout << "\n1. Add product in Stock";
        cout << "\n2. Display All Products";
        cout << "\n3. Add to Cart";
        cout << "\n4. Show Cart";
        cout << "\n5. Calculate Bill";
        cout << "\n6. New Cart";
        cout << "\n7. Delete Item from Cart";
        cout << "\n8. Print Bill";
        cout << "\n9. Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        cin.ignore(); 

        switch (choice)
        {
        case 1:
            cout << "\nEnter Product Name : ";
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            cout << "Enter product Quantity : ";
            cin >> stock;

            cout << "Enter product Price : ";
            cin >> price;

            id++;
            if (!bill.addProduct(id, name, stock, price)){
                id--;
            }
            break;

        case 2:
            bill.inventory();
            break;

        case 3:
        {
            int quantity;
            cout << "\nEnter Product Name : ";
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            cout << "Enter quantity : ";
            cin >> quantity;

            bill.addToCart(name, quantity);
            break;
        }

        case 4:
            bill.showCart();
            break;

        case 5:
            bill.calculateBill();
            break;

        case 6:
            bill.newCart();
            break;

        case 7:
            cout << "\nEnter Product Name : ";
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            bill.removeItem(name);
            break;

        case 8:
            bill.printBill();
            break;

        case 9:
            cout << "\nExited!";
            return 0;

        default:
            cout << "\nInvalid Choice!";
        }
    }
}