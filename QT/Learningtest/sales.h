#ifndef SALES_H
#define SALES_H
#include <iostream>
#include<string>
class Sales
{
    friend std::istream& operator >>(std::istream&,Sales&);
    friend std::ostream& operator <<(std::ostream&,Sales&);
    friend bool operator< (const Sales&, const Sales&);
    friend bool operator== (const Sales&, const Sales&);
public:
    Sales& operator+=(const Sales&);
    Sales(const std::string &book): ISBN(book) { }
    Sales(std::istream &is) { is >> *this; }
    Sales()=default;
    double Avg_price()const{if(Number)return Price/Number;else return 0;}
    std::string isbn() const { return ISBN; }
private:
    std::string ISBN;
    int Number=0;
    double Price=0.0;
};
inline bool compareIsbn (const Sales& a,const Sales& b){
    return a.isbn() == b.isbn();
}

inline bool operator< (const Sales& a, const Sales& b){
    return (a.Price < b.Price);
}

inline bool operator==(const Sales& a, const Sales& b){
    return compareIsbn(a,b);
}
inline bool operator!=(const Sales& a, const Sales& b){
    return !(a==b);
}
#endif // SALES_H
