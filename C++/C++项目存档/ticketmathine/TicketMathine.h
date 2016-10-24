#ifndef TICKETMATHINE_H
#define TICKETMATHINE_H

class TicketMathine
{
	public:
		TicketMathine();
		~TicketMathine();
		void showPrompt();
		void insertMoney(int money);
		void showBalance();
		void printTicket();
		void showTotal();
	protected:
		const int PRICE;
		int balance=0;
		int total=0;
};

#endif
