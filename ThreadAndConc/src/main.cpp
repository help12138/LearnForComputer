#include "count.h"

void hello(){
    cout << "hello thread" << endl;
}

int main(){
    vector<int> list = {1,2,5,6,7};
    for (auto &item : list)
    {
        cout << item << endl;
    }
    
    return 0;
}