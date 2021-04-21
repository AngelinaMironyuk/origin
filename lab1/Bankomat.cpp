#include "bankomat.h"

Bankomat::Bankomat(unsigned int id, const unsigned long maxCash, const unsigned long minCash, unsigned short ten, unsigned short fifty, unsigned short oneHundred, unsigned short fiveHundred, unsigned short oneThousand)
{
	this->id = id;
	this->maxCash = maxCash;
	this->minCash = minCash;

	setTens(ten);
	setFiftys(fifty);
	setHundreds(oneHundred);
	setFiveHundreds(fiveHundred);
	setThousands(oneThousand);
}

unsigned long Bankomat::putMoneyIn(unsigned short oneThousand, unsigned short fiveHundred, unsigned short oneHundred, unsigned short fifty, unsigned short ten)
{
	setTens(getTens()+ ten);
	setFiftys(getFiftys()+ fifty);
	setHundreds(getHundreds()+ oneHundred);
	setFiveHundreds(getFiveHundreds()+ fiveHundred);
	setThousands(getThousands()+ oneThousand);
	unsigned long sumInCash = oneThousand * THOUSAND + fiveHundred * FHUNDRED + oneHundred * HUNDRED + fifty * FIFTY + ten * TEN;
	return sumInCash;
}

std::string Bankomat::withdrawMoney(unsigned long cash)
{
	if (cash % long(10) != 0) {
		return std::string("Cant withdraw this sum of cash. it must be miltiple 10");
	}
	unsigned long tmp = cash;
	if (cash >= getMinCash() && cash <= getMaxCash() && cash <= getDeposit()){

		if (cash / THOUSAND < getThousands()) {
			unsigned int thousands= cash / THOUSAND;
			cash -= thousands * THOUSAND;
			setThousands(getThousands() - thousands);
		}
		else {
			unsigned int thousands = getThousands();
			cash -= thousands * THOUSAND;
			setThousands(getThousands() - thousands);
		}

		if (cash / FHUNDRED < getFiveHundreds()) {
			unsigned int fhundreds = cash / FHUNDRED;
			cash -= fhundreds * FHUNDRED;
			setFiveHundreds(getFiveHundreds() - fhundreds);
		}
		else {
			unsigned int fhundreds = getFiveHundreds();
			cash -= fhundreds * FHUNDRED;
			setFiveHundreds(getFiveHundreds() - fhundreds);
		}

		if (cash / HUNDRED < getHundreds()) {
			unsigned int hundreds = cash / HUNDRED;
			cash -= hundreds * HUNDRED;
			setHundreds(getHundreds() - hundreds);
		}
		else {
			unsigned int hundreds = getHundreds();
			cash -= hundreds * HUNDRED;
			setHundreds(getHundreds() - hundreds);
		}

		if (cash / FIFTY < getFiftys()) {
			unsigned int fiftys = cash / FIFTY;
			cash -= fiftys * FIFTY;
			setFiftys(getFiftys() - fiftys);
		}
		else {
			unsigned int fiftys = getFiftys();
			cash -= fiftys * FIFTY;
			setFiftys(getFiftys() - fiftys);
		}

		if (cash / TEN < getTens()) {
			unsigned int tens = cash / TEN;
			cash -= tens * TEN;
			setTens(getTens() - tens);
		}
		else {
			unsigned int tens = getTens();
			cash -= tens * TEN;
			setTens(getTens() - tens);
		}
	}
	else {
		return std::string("Cant withdraw this sum of cash");
	}
	return std::to_string(tmp);
}

std::string Bankomat::toString() const
{
	
	return std::to_string(getDeposit());
}

unsigned int Bankomat::getId() const
{
	return this->id;
}

unsigned long Bankomat::getMaxCash() const
{
	return this->maxCash;
}

unsigned long Bankomat::getMinCash() const
{
	return this->minCash;
}

unsigned short Bankomat::getTens() const
{
	return this->ten;
}

unsigned short Bankomat::getFiftys() const
{
	return this->fifty;
}

unsigned short Bankomat::getHundreds() const
{
	return this->oneHundred;
}

unsigned short Bankomat::getFiveHundreds() const
{
	return this->fiveHundred;
}

unsigned short Bankomat::getThousands() const
{
	return this->oneThousand;
}

unsigned long Bankomat::getDeposit() const
{
	return getThousands()*THOUSAND+getFiveHundreds()*FHUNDRED+getHundreds()*HUNDRED+getFiftys()*FIFTY+getTens()*TEN;
}

void Bankomat::setTens(unsigned short n)
{
	this->ten = n;
}

void Bankomat::setFiftys(unsigned short n)
{
	this->fifty = n;
}

void Bankomat::setHundreds(unsigned short n)
{
	this->oneHundred = n;
}

void Bankomat::setFiveHundreds(unsigned short n)
{
	this->fiveHundred = n;
}

void Bankomat::setThousands(unsigned short n)
{
	this->oneThousand = n;
}


std::istream& operator>>(std::istream& in, Bankomat& b)
{
	unsigned int id;
	unsigned long maxCash, minCash;
	unsigned short ten, fifty, oneHundred,  fiveHundred,  oneThousand;
	in >> id;
	in >> maxCash;
	in >> minCash;
	in >> ten;
	in >>fifty;
	in >> oneHundred;
	in >> fiveHundred;
	in >> oneThousand;

	b.id = id;
	b.maxCash = maxCash;
	b.minCash = minCash;
	b.ten = ten;
	b.fifty = fifty;
	b.oneHundred = oneHundred;
	b.fiveHundred = fiveHundred;
	b.oneThousand = oneThousand;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Bankomat& b)
{
	out << "id " << b.getId() << " max min " << b.getMinCash() << "-" << b.getMaxCash() << " deposit " << b.getDeposit() << std::endl << " Banknotes: 1000 " << b.getThousands() << ", 500 " << b.getFiveHundreds() <<
		", 100 " << b.getHundreds() << ", 50 " << b.getFiftys() << ", 10 " << b.getTens() << std::endl;

	return out;
}
