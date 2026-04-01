#include <iostream>
#include <vector>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool isIssued;

    // Fixed constructor
    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false)
    {
    }
};

class Library
{
private:
    vector<Book> books;

public:
    void addBooks(int id, string title, string author)
    {
        books.push_back(Book(id, title, author));
        cout << "\nBook added successfully!";
    }

    void displayBooks()
    {
        for (Book &s : books)
        {
            cout << "\nID : " << s.id;
            cout << "\nBook title : " << s.title;
            cout << "\nAuthor's Name : " << s.author;

            if (s.isIssued)
            {
                cout << "\nBook is unavailable.";
            }
            else
            {
                cout << "\nBook is available.";
            }
            cout << "\n-----------";
        }
    }

    void issueBook(int id)
    {
        bool found = false;

        for (Book &s : books)
        {
            if (s.id == id)
            {
                found = true;

                if (!s.isIssued)
                {
                    s.isIssued = true;
                    cout << "\nBook Issued Successfully!";
                }
                else
                {
                    cout << "\nThis book is unavailable.";
                }
            }
        }

        if (!found)
        {
            cout << "\nBook id not found.";
        }
    }

    void returnBook(int id)
    {
        bool found = false;

        for (Book &s : books)
        {
            if (s.id == id)
            {
                found = true;

                if (s.isIssued)
                {
                    s.isIssued = false;
                    cout << "\nBook returned Successfully!";
                }
                else
                {
                    cout << "\nThis book was not issued.";
                }
            }
        }

        if (!found)
        {
            cout << "\nBook id not found.";
        }
    }
};

int main()
{
    Library lib;
    cout << "\n=== LIBRARY MANAGEMENT SYSTEM ===";

    while (true)
    {
        int choice;
        int id;
        string title, author;

        cout << "\n1. Add Book";
        cout << "\n2. Show Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter ID: ";
            cin >> id;

            cout << "Enter Title: ";
            cin.ignore(); // only once
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            lib.addBooks(id, title, author);
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            cout << "\nEnter Book ID: ";
            cin >> id;
            lib.issueBook(id);
            break;

        case 4:
            cout << "\nEnter Book ID: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 5:
            cout << "\nExiting the program. Goodbye!";
            return 0;

        default:
            cout << "\nInvalid choice!";
            break;
        }
    }
}