#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> test;
    test.push('a');
    test.push('b');
    cout << test.size() << endl;
    char out = test.top();
    cout << out << endl;
    return 0;
}