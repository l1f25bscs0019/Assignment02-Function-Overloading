// Answer 1:
// vesion 2 void printInfo(string name, int rollNo) runs smoothly because there is no 
//exactly matching verion so promotion occur and char b is promote to int which is 66
//Answer 2:
// adding  int printInfo(char grade) would give compile error beacuse there already 
// exist a function with this parameter the only difference will be return type and
// different return type don't create ovorloaded function
//Answer 3:
//version 2 (void printInfo(string name, int rollNo) ) and 3 (void printInfo(int rollNo, string name))
//are overloaded by order of argument 

#include<iostream>
using namespace std;
void printInfo(string name) {
    cout << "Name: " << name << endl;
}
void printInfo(string name, int rollNo) {
    cout << "Name: " << name << " | Roll No: " << rollNo << endl;
}
void printInfo(int rollNo, string name) {
    cout << "Roll No : " << rollNo << " | Name : " << name << endl;
}
void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;
}
void printInfo(char grade) {
    cout << "Grade: " << grade<< endl;
}
int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}
