#pragma once
/* Реализовать класс ATM, моделирующий работу банкомата.
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
 * \brief Класс ATM , моделирующий работу банкомата
 */
class ATM
{	
public:
	/**
	* \brief Конструктор по умолчанию
	*/
    ATM() = default;   
	/**
	* \brief Конструктор параметризованный
	*/
	ATM(unsigned int id, const unsigned long maxCash,
		const unsigned long minBill, unsigned short ten = 0,
		unsigned short fifty = 0, unsigned short oneHundred = 0,
		unsigned short fiveHundred = 0, unsigned short oneThousand = 0);
	/**
	* \brief Деструктор
	*/
	~ATM() = default;

	/**
	* \brief Метод ввода купюр в АТМ
	*/
	unsigned long putMoneyIn(unsigned short oneThousand=0, unsigned short fiveHundred=0, unsigned short oneHundred=0, unsigned short fifty=0, unsigned short ten=0);
	/**
	* \brief Метод снятия суммы из АТМ
	*/
	std::string withdrawMoney(unsigned long cash);
	/**
	* \brief Метод преобразовывает строку сумму денег, оставшуюся в АТМ
	*/
	std::string toString() const;

	/**
	* \brief Перегруженный оператор ввода
	*/
	friend std::istream& operator>> (std::istream& in, ATM& b);

	/**
	* \brief Перегруженный оператор вывода
	*/
	friend std::ostream& operator<< (std::ostream& out, const ATM& b);
	
private:
	/**
	* \brief enum с номиналами банкнот
	*/
	enum Bill
	{
		TEN = 10,
		FIFTY = 50,
		HUNDRED = 100,
		FIVE_HUNDRED = 500,
		THOUSAND = 1000
	};
	/**
	* \brief структура с количеством банкнот в депозитории
	*/
	struct{
		unsigned short ten = 0;
		unsigned short fifty = 0;
		unsigned short oneHundred = 0;
		unsigned short fiveHundred = 0;
		unsigned short oneThousand = 0;
	}repository;

	unsigned int id = 1;
	unsigned long maxCash = 250000;
	unsigned long minBill = 50;
	
	//геттеры
	unsigned int getId() const;
	unsigned long getMaxCash() const;
	unsigned long getminBill() const;
	
	unsigned short getTens() const;
	unsigned short getFiftys() const;
	unsigned short getHundreds() const;
	unsigned short getFiveHundreds() const;
	unsigned short getThousands() const;
	
	unsigned long getDeposit() const;

	//сеттеры
	void setTens(unsigned short n);
	void setFiftys(unsigned short n);
	void setHundreds(unsigned short n);
	void setFiveHundreds(unsigned short n);
	void setThousands(unsigned short n);

};
