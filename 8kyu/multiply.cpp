#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    int result = (a * b);
    return result;
}

int main() 
{
    int num1, num2;

    // User input for multiplication
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Call the multiply function and display the result
    int result = multiply(num1, num2);
    cout << "The result of multiplying " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}