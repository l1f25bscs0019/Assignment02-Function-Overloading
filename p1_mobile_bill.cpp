//answer 1: 
// we have to write sms 0 because to give last value you have to write 
// all previous values otherwise it will be error.
//answer 2:
//the call will give compilation error beacause you can't leave center
// value like mobileBill(60, , 1.5) 

#include <iostream>
using namespace std;

double mobileBill(int minutes,int sms=0, double gb=0.0);   // (a)
void printLine(char ch='-',int n=30);                   // (b)

int main() {
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);
    cout << "Bill 4: " << mobileBill(60,0,1.5) << endl;   // (c)
    printLine('=');
    return 0;
}

double mobileBill(int minutes,int sms,double gb) { 
    minutes *= 2;
    sms *= 1;
    gb *= 150;
    double bill = minutes + sms + gb;
    return bill;                                      // (e)
}

void printLine(char ch,int n) {//(f)
    for (int i = 0; i < n;i++) 
        cout << ch;                            // (g)
    cout << endl;
}
