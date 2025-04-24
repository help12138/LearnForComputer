#include "count.h"

void hello(){
    cout << "hello thread";
}

int main(){
    thread t(hello);
    t.join(); // 确定从哪个位置汇入子线程
    std::cout<< "this is thread" << endl;
    
    return 0;
}