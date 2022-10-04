#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool validchar(char c){
    // VALID CHARACTERS 0,1,2,3,4,5,6,7,8,9,+,-,*,/,(,)
    static char validchars[16] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/','(',')'}; //Static so we don't keep remaking this
    for(int i = 0; i < 16; i++){
        if(c==validchars[i]) return false;
    }
    return true;
}

string infixtopostfix(string startSTR){
    for(int i = 0; i < startSTR.length(); i++){
        if(validchar(startSTR[i] != true)) {
            cout << "Invalid characters in infix statement" << endl;
            return startSTR;
        }
    } // Checking if the string has all valid characters.
    string postSTR;
    Stack<char> operator_stack;
    return postSTR;
}
int main() {
    string s1 = "First Try";
    Stack<char> stack;
    for(int i = 0; i < s1.length(); i++){
        stack.push(s1[i]);
    }
    stack.display();
}