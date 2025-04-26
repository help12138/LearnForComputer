#include <iostream>

#include "func.h"

/*函数的源代码功能定义， 括号里的为形参， 形参的生命周期只到函数大括号结束*/
int func(int val){
    // 计算从0~val的阶乘
    //static定义的参数生命周期为全局
    static int staNum = 1;
    int resultNum = 1;
    while (val > 1)
    {
        resultNum *= val--;
    }
    staNum++;
    std::cout << "the staNum is " << staNum << std::endl;
    std::cout << "the resultNum is " << resultNum << std::endl;
    // 返回值
    return resultNum;
}

int main(){
    // 函数调用
    int val = 4;
    int result;
    /*此处的val为实参，顾名思义，实际的参数*/ 
    for (int i = 0; i < 3; i++)
    {
        func(1);
    }
    
    
    result = func(val);
    std::cout << "the func return is " << result << std::endl;
    
    return 0;
}