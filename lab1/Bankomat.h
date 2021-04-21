#pragma once
/* Реализовать класс Bankomat, моделирующий работу банкомата. 
В классе должны содержаться поля для хранения идентификационного номера банкомата,
информации о текущей сумме денег, оставшейся в банкомате,
минимальной и максимальной суммах, которые позволяется снять клиенту за раз. 
Сумма денег представляется полями-номиналами 10, 50, 100, 500, 1000. 
Реализовать метод инициализации банкомата, 
метод загрузки купюр в банкомат и метод снятия определенной суммы денег. 
Метод снятия денег должен выполнять проверку на корректность снимаемой суммы: 
она не должна быть меньше минимального значения и не должна превышать максимальное значение. 
Метод toString() должен преобразовать в строку сумму денег, оставшуюся в банкомате.*/

#include <sstream>
/**
 * \brief Класс Bankomat , моделирующий работу банкомата
 */
class Bankomat
{
public:
	Bankomat() = default;
	Bankomat(unsigned int id, const unsigned long maxCash=250000, 
		const unsigned long minCash=100, unsigned short ten = 0, 
		unsigned short fifty = 0, unsigned short oneHundred = 0, 
		unsigned short fiveHundred = 0, unsigned short oneThousand = 0);
	~Bankomat() = default;

	unsigned long putMoneyIn(unsigned short oneThousand=0, unsigned short fiveHundred=0, unsigned short oneHundred=0, unsigned short fifty=0, unsigned short ten=0);
	std::string withdrawMoney(unsigned long cash);
	std::string toString() const;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Bankomat& b);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Bankomat& b);


private:

	unsigned int id;
	unsigned short ten;
	unsigned short fifty;
	unsigned short oneHundred;
	unsigned short fiveHundred;
	unsigned short oneThousand;

	unsigned long maxCash;
	unsigned long minCash;


	const unsigned short TEN = 10;
	const unsigned short FIFTY = 50;
	const unsigned short HUNDRED = 100;
	const unsigned short FHUNDRED = 500;
	const unsigned short THOUSAND = 1000;

	unsigned int getId() const;
	unsigned long getMaxCash() const;
	unsigned long getMinCash() const;

	unsigned short getTens() const;
	unsigned short getFiftys() const;
	unsigned short getHundreds() const;
	unsigned short getFiveHundreds() const;
	unsigned short getThousands() const;

	unsigned long getDeposit() const;


	void setTens(unsigned short n);
	void setFiftys(unsigned short n);
	void setHundreds(unsigned short n);
	void setFiveHundreds(unsigned short n);
	void setThousands(unsigned short n);
	
};
