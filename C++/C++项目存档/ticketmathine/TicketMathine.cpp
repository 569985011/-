#include "TicketMathine.h"
#include <iostream>
using namespace std;
TicketMathine::TicketMathine():PRICE(0) {
//const int PRICE;
}

TicketMathine::~TicketMathine() {

}

void TicketMathine::showPrompt(){
	cout<<"somethine"<<endl;
}

void TicketMathine::insertMoney(int Money){
	balance+=Money;
}

void TicketMathine::showBalance(){
	cout<<balance;
}
