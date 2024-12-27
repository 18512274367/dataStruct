#ifndef _String_H_
#define _String_H_

#include <iostream>

class String
{
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	String &operator=(const String &el);
	String &operator=(const char *el);

	String &operator+=(const String &el);
	String &operator+=(const char *el);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);

	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);

	friend std::ostream &operator<<(std::ostream &os, const String &el);
	friend std::istream &operator>>(std::istream &is, String &el);

private:
	char * _pstr;
};

String operator+(const String &lhs, const String &rhs);
String operator+(const String &lhs, const char *rhs);
String operator+(const char *lhs, const String &rhs);

#endif

