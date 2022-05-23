#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Recorder{
private:
    std::vector<int> link;
    std::vector<int>::iterator iter;
public:
    Recorder();
    void pushNumber(int n);
    //void pullNumber(int n); 
};

Recorder::Recorder()
{
    iter = link.begin();
}

void pushNumber(int n){
    link.push_back(n);
    iter++;
}