
#include <iostream>
#include "sales.h"

Sales& Sales::operator +=(const Sales& s){
    Number+=s.Number;
    Price+=s.Price;
    return *this;
}
Sales operator +(const Sales&a,const Sales& b){
    Sales temp(a);
    temp+=b;
    return temp;
}

std::istream& operator >>(std::istream&in,Sales&s){
    double price;
    in>>s.ISBN>>s.Number>>price;
    if(in)s.Price=price*s.Number;
    else s=Sales();//reset object to default state
    return in;
}

std::ostream& operator <<(std::ostream&out,Sales&s){
    out<<"{"<<s.ISBN<<" "<<s.Number<<" "<<s.Price
      <<" "<<s.Avg_price()<<"}\n";
         return out;
}
