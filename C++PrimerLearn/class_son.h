#ifndef SON_HEAD
#define SON_HEAD
#include "class_father.h"

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string&, double, size_t, double);
    // 覆盖基类的函数版本以实现子类的功能， 声明应与基类一样
    double net_price(size_t) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};
#endif