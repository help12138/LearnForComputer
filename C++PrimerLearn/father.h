#ifndef HEAD_
#define HEAD_
/* 头文件放置函数的声明，在源文件引用，可以解决声明排布问题 */
#include <iostream>
#include <string>

using namespace std;

//基类
class Quote
{
protected:
    double price = 0.0;
private:
    string bookNo;
public:
    // 取消默认构造函数的定义
    Quote(/* args */) = default;
    // 构造函数定义
    Quote(const string &book, double sales_price):bookNo(book), price(sales_price){};
    // 非虚函数， 子类不需要重构的函数
    string isbn() const {return bookNo;}
    // 虚函数，主要用于子类重构
    virtual double net_price(size_t n) const {
        return n * price;
    }
    ~Quote();
};


#endif