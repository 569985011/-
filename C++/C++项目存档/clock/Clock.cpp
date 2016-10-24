#include "Clock.h"
#include<iostream>
using namespace std;
Clock::Clock(int Value,int Limit) {
	value=Value;
	limit=Limit;
}
bool Clock::start() {
	value++;
	if(value==limit)value=0;
	return true;
}
