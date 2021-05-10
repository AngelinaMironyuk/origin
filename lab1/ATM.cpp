#include "ATM.h"

ATM::ATM(unsigned int id, const unsigned long maxCash, const unsigned long minBill, unsigned short ten, unsigned short fifty, unsigned short oneHundred, unsigned short fiveHundred, unsigned short oneThousand)
{
	this->id = id;
	this->maxCash = maxCash;
	this->minBill = minBill;

	setTens(ten);
	setFiftys(fifty);
	setHundreds(oneHundred);
	setFiveHundreds(fiveHundred);
	setThousands(oneThousand);
}

unsigned long ATM::putMoneyIn(unsigned short oneThousand, unsigned short fiveHundred, unsigned short oneHundred, unsigned short fifty, unsigned short ten)
{
	setTens(getTens()+ ten);
	setFiftys(getFiftys()+ fifty);
	setHundreds(getHundreds()+ oneHundred);
	setFiveHundreds(getFiveHundreds()+ fiveHundred);
	setThousands(getThousands()+ oneThousand);
	unsigned long suminBill = oneThousand * THOUSAND + fiveHundred * FIVE_HUNDRED + oneHundred * HUNDRED + fifty * FIFTY + ten * TEN;
	return suminBill;
}

std::string ATM::withdrawMoney(unsigned long cash)
{
	if (cash % long(10) != 0) {
		return std::string("Cant withdraw this sum of cash. it must be miltiple 10");
	}
	unsigned long tmp = cash;
	if (cash >= getminBill() && cash <= getMaxCash() && cash <= getDeposit()){

		unsigned int thousands = (cash / THOUSAND < getThousands()) ? (cash / THOUSAND) : getThousands();
		cash -= thousands * THOUSAND;
		setThousands(getThousands() - thousands);		

		unsigned int fiveHundreds = (cash / FIVE_HUNDRED < getFiveHundreds()) ? (cash / FIVE_HUNDRED) : getFiveHundreds();
		cash -= fiveHundreds * FIVE_HUNDRED;
		setFiveHundreds(getFiveHundreds() - fiveHundreds);
		
		unsigned int hundreds = (cash / HUNDRED < getHundreds()) ? (cash / HUNDRED) : getHundreds();
		cash -= hundreds * HUNDRED;
		setHundreds(getHundreds() - hundreds);

		unsigned int fiftys = (cash / FIFTY < getFiftys()) ? (cash / FIFTY) : getFiftys();
		cash -= fiftys * FIFTY;
		setFiftys(getFiftys() - fiftys);

		unsigned int tens = (cash / TEN < getTens()) ? (cash / TEN) : getTens();
		cash -= tens * TEN;
		setTens(getTens() - tens);
	}
	else {
		return std::string("Cant withdraw this sum of cash");
	}
	return std::to_string(tmp);
}

std::string ATM::toString() const
{
	return std::to_string(getDeposit());
}

unsigned int ATM::getId() const
{
	return this->id;
}

unsigned long ATM::getMaxCash() const
{
	return this->maxCash;
}

unsigned long ATM::getminBill() const
{
	return this->minBill;
}

unsigned short ATM::getTens() const
{
	return this->repository.ten;
}

unsigned short ATM::getFiftys() const
{
	return this->repository.fifty;
}

unsigned short ATM::getHundreds() const
{
	return this->repository.oneHundred;
}

unsigned short ATM::getFiveHundreds() const
{
	return this->repository.fiveHundred;
}

unsigned short ATM::getThousands() const
{
	return this->repository.oneThousand;
}

unsigned long ATM::getDeposit() const
{
	return getThousands()*THOUSAND+getFiveHundreds()*FIVE_HUNDRED+getHundreds()*HUNDRED+getFiftys()*FIFTY+getTens()*TEN;
}

void ATM::setTens(unsigned short n)
{
	this->repository.ten = n;
}

void ATM::setFiftys(unsigned short n)
{
	this->repository.fifty = n;
}

void ATM::setHundreds(unsigned short n)
{
	this->repository.oneHundred = n;
}

void ATM::setFiveHundreds(unsigned short n)
{
	this->repository.fiveHundred = n;
}

void ATM::setThousands(unsigned short n)
{
	this->repository.oneThousand = n;
}

std::istream& operator>>(std::istream& in, ATM& b)
{
	unsigned int id;
	unsigned long maxCash, minBill;
	unsigned short ten, fifty, oneHundred,  fiveHundred,  oneThousand;
	in >> id >> maxCash >> minBill >> ten >> fifty >> oneHundred >> fiveHundred >> oneThousand;
	b = ATM(id,maxCash, minBill, ten, fifty, oneHundred, fiveHundred, oneThousand);
	return in;
}

std::ostream& operator<<(std::ostream& out, const ATM& b)
{
	out << "ATM id: " << b.getId() <<std::endl
		<< "max withdraw: " << b.getMaxCash() << std::endl
		<< "min withdraw: " << b.getminBill() << std::endl 
		<< "deposit: " << b.getDeposit() << std::endl 
		<< "Banknotes:" << std::endl
		<< "1000p: " << b.getThousands() << std::endl 
		<< "500p: " << b.getFiveHundreds() << std::endl 
		<< "100p: " << b.getHundreds() << std::endl 
		<< "50p: " << b.getFiftys() << std::endl 
		<< "10p: " << b.getTens() << std::endl;
	return out;
}
