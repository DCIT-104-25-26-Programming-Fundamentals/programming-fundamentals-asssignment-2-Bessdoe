#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

// Part A: Print multiplication table for one number
void singleTable(int number)
{
    cout << "\nMultiplication Table for " << number << ":\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

// Part B: Print multiplication tables from 1 to N
void allTables(int n)
{
    if (n <= 0)
    {
        cout << "Error: Number must be positive." << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        singleTable(i);
        cout << "---------------------------" << endl;
    }
}

int main()
{
    int number, n;

    // Part A
    cout << "Enter a number: ";
    cin >> number;

    singleTable(number);

    // Part B
    cout << "\nEnter N: ";
    cin >> n;

    allTables(n);

    return 0;
}
