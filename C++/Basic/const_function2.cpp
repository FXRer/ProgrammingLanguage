/* 
 * When a function is declared as const, it can be called on any type of 
 * object. Non-const functions can only be called by non-const objects.
 */

#include<iostream>
using namespace std;
 
class Test {
    int value;
public:
    Test(int v = 0) {value = v;}
    int getValue() {return value;}
};
 
int main() {
    const Test t;
    cout << t.getValue();
    return 0;
}
