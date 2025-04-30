#include <iostream>
#include <vector>

#include "func.h"

/*函数的源代码功能定义， 括号里的为形参， 形参的生命周期只到函数大括号结束
* 参数传递时， 如果形参不是引用类型， 都是拷贝一个副本，引用类型传递的则是
* 本值， C语言里也可以传递指针类型形参， 修改本值，但传递指针类型也是拷贝了
* 有个指针副本， 只不过指向的同一块内存
*/
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

/*数组参数传递的是指针*/
int pointFunc (const int* num){
    if(num){
        while (*num)
        {
            cout << *num++ << " ";
        }
    }else{
        cout << "question";
    }

    return 0;
}

int mai(){
    // 函数调用
    

    // /*此处的val为实参，顾名思义，实际的参数*/ 
    // result = func(val);
    // for (int i = 0; i < 3; i++)
    // {
    //     //验证静态参数的生命周期
    //     func(1);
    // }
    
    int list[] = {1,2,34,5,6,7,8,9,0};
    pointFunc(list);

    return 0;
}