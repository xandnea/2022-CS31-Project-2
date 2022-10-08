#include <iostream>
#include <string>
using namespace std;

int main()
{
    // initialize varaibles
    string name;
    double income;
    string occupation;
    int children;
    double due = 0;

    // read varaibles & fault checking
    cout << "Name: ";
    getline(cin, name);
    while (name == "") {
        cout << "You must enter a name" << endl;
        cout << "Name: ";
        getline(cin, name);
    }

    cout << "Taxable income: ";
    cin >> income;
    while (income < 0) {
        cout << "The taxable income must not be negative" << endl;
        cout << "Taxable income: ";
        cin >> income;
    }
    cin.ignore(10000, '\n');

    cout << "Occupation: ";
    getline(cin, occupation);
    while (occupation == "") {
        cout << "You must enter an occupation" << endl;
        cout << "Occupation: ";
        getline(cin, occupation);
    }

    cout << "Number of children: ";
    cin >> children;
    while (children < 0) {
        cout << "The number of children must not be negative" << endl;
        cout << "Number of children: ";
        cin >> children;
    }

    // create three hyphens for formatting
    cout << "---" << endl;

    // tax bracket check & math
    if (income <= 55000) {
        due = (income * .04);
    }
    else if (income <= 125000) {
        if ((occupation == "nurse") || (occupation == "teacher")) { // if nurse or teacher, second bracket is taxed @ 5% instead of 7%
            due += (2200 + ((income - 55000) * .05));
        }
        else {
            due += (2200 + ((income - 55000) * .07)); // if not nurse or teacher, normal tax bracket
        }
    }
    else if (income > 125000) {
        if ((occupation == "nurse") || (occupation == "teacher")) { // if nurse or teacher, second bracket is taxed @ 5% instead of 7%
            due += (5700 + ((income - 125000) * .093));
        }
        else {
            due += (7100 + ((income - 125000) * .093)); // if not nurse or teacher, normal tax bracket
        }
    }

    // check # of children and lower tax by $200 per child until $0
    if ((children != 0) && (income < 125000)) {
        due -= (children * 200);
        if (due < 0) {
            due = 0;
        }
    }

    // set format of floats and final output
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << name << " would pay $" << due << endl;
}