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
    void addProduct(int id, string name, int stock, float price)
    {
        products.push_back(Product(id, name, stock, price));
        cout << "\nProduct Added successfully";
    }

    void displayProducts()
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
            cout << "\n------------------------------";
        }
    }

    void addToCart(string name, int quantity)
    {
        bool found = false;

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

                // FIXED boundary condition
                if (p.stock >= quantity)
                {
                    cart.push_back(CartItem(p.name, p.price, quantity));
                    p.stock -= quantity;
                }
                else
                {
                    int available = p.stock; 
                    if (available == 0)
                    {
                        cout << "\nOut of stock!";
                        return;
                    }

                    cart.push_back(CartItem(p.name, p.price, available));
                    cout << "\nWe have only " << available << " in stock.";
                    p.stock = 0;
                }
                break; 
            }
        }

        if (!found)
        {
            cout << "\nSorry, this product is not available.";
        }
    }

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
            cout << "\n | " << num << " | " << c.name << " | " << c.price << " | " << c.quantity << " | ";
        }
    }

    void calculateBill()
    {
        if (cart.empty())
        {
            cout << "\nYour cart is empty.";
            return;
        }

        double total = 0;
        for (CartItem &c : cart)
        {
            total += (c.quantity * c.price);
        }

        cout << "\nTotal Bill : " << total;
    }

    void newCart()
    {
        cart.clear();
        cout << "\nNew cart started!";
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
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Product Name : ";
            cin.ignore();
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            cout << "\nEnter product Quantity : ";
            cin >> stock;

            cout << "\nEnter product Price : ";
            cin >> price;

            id++;
            bill.addProduct(id, name, stock, price);
            break;

        case 2:
            bill.displayProducts();
            break;

        case 3:
        {
            int quantity;

            cout << "\nEnter Product Name : ";
            cin.ignore();
            getline(cin, name);
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            cout << "\nEnter quantity : ";
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
            cout << "\nExited!";
            return 0;

        default:
            cout << "\nInvalid Choice!";
        }
    }
}