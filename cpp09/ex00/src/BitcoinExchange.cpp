#include "../include/BitcoinExchange.hpp"

std::multimap<long, std::string> &BitcoinExchange::getMap() {
	return myMultiMap;
}

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Calling BitcoinExchange constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy)
{
	std::cout << "Calling BitcoinExchange copy constructor" << std::endl;
	myMultiMap.insert(copy.getMap().begin(), copy.getMap().end());
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &copy)
{
	std::cout << "Calling BitcoinExchange equal operator" << std::endl;
	if (this != &copy)
		myMultiMap.insert(copy.getMap().begin(), copy.getMap().end());
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Calling BitcoinExchange destructor" << std::endl;
}

void BitcoinExchange::getDatabase(std::string &line) {
	size_t separatorPos;
	size_t separatorPos2;
	static std::string before;
	bool myBool = 1;
	long dateNum = 0;
	Date parsedDate;
	std::string *myDate;

	if (line.empty())
		return ;
	separatorPos = line.find(',');
	if (separatorPos >= line.length())
	{
		std::cerr << "CSV syntax error!" << std::endl;
		std::exit(-1);
	}
	if (!separatorPos)
	{
		myBool = 0;
		myDate = &before;
	}
	else
		myDate = &line;

	if (parseDate(*myDate, parsedDate)) {
		if (!isValidDate(parsedDate)) {
			std::cerr << "Invalid date." << std::endl;
			std::exit(-1);
		}
	} else {
		std::cerr << "Error parsing date." << std::endl;
		std::exit(-1);
	}
	separatorPos2 = line.find('.');
	if (separatorPos2 >= line.length())
		separatorPos2 = line.length();
	if (myBool) {
		dateNum = convertDateToInt(line.substr(0, line.find(',')));
		try{
			myMultiMap.insert(std::make_pair(dateNum, line.substr(separatorPos + 1, separatorPos2)));
		}
		catch (std::exception &e)
		{
			std::cout << myBool << std::endl;
			std::cout << "\033[31merror:\033[0m " << e.what() << std::endl;
			std::cout << "exiting..." << std::endl;
			std::exit(-1);
		}
	}
	else {
		dateNum = convertDateToInt(before.substr(0, before.find(',')));
		try {
			myMultiMap.insert(std::make_pair(dateNum, line.substr(separatorPos + 1, separatorPos2)));
		}
		catch (std::exception &e) {
			std::cout << myBool << std::endl;
			std::cout << "\033[31merror:\033[0m " << e.what() << std::endl;
			std::cout << "exiting..." << std::endl;
			std::exit(-1);
		}
	}
	before = line;
}

void BitcoinExchange::getDate(std::string &line) {
	long dateNum = 0;

	Date parsedDate;

	if (parseDate(line, parsedDate)) {
		if (!isValidDate(parsedDate)) {
			std::cerr << "Invalid date." << std::endl;
			std::exit(-1);
		}
	} else {
		std::cerr << "Error parsing date." << std::endl;
		std::exit(-1);
	}
	dateNum = convertDateToInt(line);
	std::multimap<long, std::string>::iterator it = myMultiMap.find(dateNum);
	for (; it != myMultiMap.end() && it->first == dateNum; ++it) {
		std::cout << formatDate(it->first) << " | " << it->second << std::endl;
	}
	if (myMultiMap.empty()){
		std::cerr << "No dates provided in database" << std::endl;
		std::exit(-1);
	}
	if (it == myMultiMap.end())
	{
		long closestDate = 9223372036854775807;
		for (std::multimap<long, std::string>::iterator it = myMultiMap.begin(); it != myMultiMap.end(); ++it){
			if (it->first > dateNum)
				break ;
			else
				closestDate = it->first;
		}
		if (closestDate != 9223372036854775807)
		{
			for (std::multimap<long, std::string>::iterator it = myMultiMap.find(closestDate); it != myMultiMap.end() && it->first == closestDate; ++it) {
				std::cout << formatDate(closestDate) << " | " << it->second << std::endl;
			}
		}
		else {
			std::multimap<long, std::string>::iterator it = myMultiMap.begin();
				std::cout << formatDate(it->first) << " | " << it->second << std::endl;
		}
	}
}

void BitcoinExchange::getExchange(std::string &line){
	
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const Date& date) {
	if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1) {
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.month == 2 && isLeapYear(date.year)) {
		daysInMonth[2] = 29;
	}

	return date.day <= daysInMonth[date.month];
}

bool BitcoinExchange::parseDate(const std::string& input, Date& result) {
	std::istringstream ss(input);
	char dash1, dash2;

	if (!(ss >> result.year >> dash1 >> result.month >> dash2 >> result.day) ||
		dash1 != '-' || dash2 != '-') {
		return false;
	}

	return isValidDate(result);
}

std::string BitcoinExchange::formatDate(long date) {
	int year = date / 10000;
	int month = (date % 10000) / 100;
	int day = date % 100;

	std::ostringstream ss;
	ss << std::setw(4) << std::setfill('0') << year << "-"
	   << std::setw(2) << std::setfill('0') << month << "-"
	   << std::setw(2) << std::setfill('0') << day;

	return ss.str();
}

long BitcoinExchange::convertDateToInt(const std::string& dateStr) {
	std::istringstream ss(dateStr);
	int year, month, day;
	char dash1, dash2;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day) ||
		dash1 != '-' || dash2 != '-') {
		return -1;
	}

	long result = static_cast<long>(year) * 10000 + month * 100 + day;
	return result;
}
