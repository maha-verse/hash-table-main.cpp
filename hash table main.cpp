#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int x)
{
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == x)
        {
            cout << "Account already exists\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
        {
            cout << "Hash table is full\n";
            return;
        }
    }

    hashTable[index] = x;
    cout << "Account inserted successfully\n";
}

void search(int x)
{
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == x)
        {
            cout << "Account found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Account not found\n";
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            cout << i << " : Empty" << endl;
        else
            cout << i << " : " << hashTable[i] << endl;
    }
}

int main()
{
    int choice, x;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    do
    {
        cout << "\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> x;
                search(x);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
