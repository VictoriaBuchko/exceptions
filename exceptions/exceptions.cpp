#include <iostream>
using namespace std;

bool isHappyNumber(int number) {

    int digitCount = 0;
    if (number == 0) {
        digitCount = 0;
    }
    else {
        int tempNumber = number; 
        while (tempNumber != 0) {
            digitCount++;
            tempNumber /= 10;
        }
    }
    cout << "Size: " << digitCount<< endl;
    if (digitCount< 6)
        throw "Number has 5 or fewer digits";
    else if (digitCount > 6)
        throw exception("Number has 7 or more digits");


    int firstHalf = 0;
    int secondHalf = 0;

    for (int i = 0; i < 6; ++i) {
        int digit = number % 10;
        number /= 10;

        if (i < 3)
            firstHalf += digit;
        else
            secondHalf += digit;
    }

    return firstHalf == secondHalf;
}

int main() {
    try {
        int number;
        cout << "Enter six digit number: ";
        cin >> number;


        if (isHappyNumber(number)) {
            cout << "Number " << number << " is lucky!" << endl;
        }
        else {
            cout << "Number " << number << " is not lucky(" << endl;
        }
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }
    catch (const exception& e) {
       cout << "Error: " << e.what() << endl;
    }

    return 0;
}
