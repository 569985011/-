#ifndef CLOCK_H
#define CLOCK_H

class Clock {
	public:
		Clock(int ,int);
		bool start();
	    void print();
	protected:
		int value;
		int limit;

};

#endif
