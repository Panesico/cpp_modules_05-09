#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>

struct Date {
	int year;
	int month;
	int day;
};

class BitcoinExchange {
private:
	std::multimap<long, std::string> myMultiMap;
public:
	BitcoinExchange();

	BitcoinExchange(BitcoinExchange &copy);

	BitcoinExchange &operator=(BitcoinExchange &copy);

	~BitcoinExchange();

	std::multimap<long, std::string> &getMap();
	void getDatabase(std::string &line);
	void getExchange(std::string &line);
	void getDate(std::string &line);
	bool isLeapYear(int year);
	bool isValidDate(const Date& date);
	bool parseDate(const std::string& input, Date& result);
	std::string formatDate(long date);
	long convertDateToInt(const std::string& dateStr);
};
