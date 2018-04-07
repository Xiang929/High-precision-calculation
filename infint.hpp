#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#ifndef _INFINT_HPP_
#define _INFINT_HPP_

using namespace std;

class Infint
{
public:
  Infint();
  Infint(int value);
  Infint(string value);
  Infint operator+(string number);
  Infint operator-(string number);
  Infint operator*(string number);
  Infint &operator+=(string number);
  Infint &operator-=(string number);
  Infint &operator*=(string number);
  Infint &operator=(string number);
  Infint operator+(long long number);
  Infint operator-(long long number);
  Infint operator*(long long number);
  Infint &operator+=(long long number);
  Infint &operator-=(long long number);
  Infint &operator*=(long long number);
  Infint &operator=(long long number);
  Infint &operator++();
  Infint &operator--();
  string minimalArray(string a, string b);
  string maximalArray(string a, string b);
  void myAbs(string &number);
  friend ostream &operator<<(std::ostream &os, const Infint &result);
  bool isNegtiva(string number);
  int myAtoi(char ch);

private:
  string value;
};
#endif#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#ifndef _INFINT_HPP_
#define _INFINT_HPP_

using namespace std;

class Infint
{
public:
  Infint();
  Infint(long long value);
  Infint(string value);
  Infint operator+(string number);
  Infint operator-(string number);
  Infint operator*(string number);
  Infint &operator+=(string number);
  Infint &operator-=(string number);
  Infint &operator*=(string number);
  Infint &operator=(string number);
  Infint operator+(long long number);
  Infint operator-(long long number);
  Infint operator*(long long number);
  Infint operator+(Infint number);
  Infint operator-(Infint number);
  Infint operator*(Infint number);
  Infint &operator+=(long long number);
  Infint &operator-=(long long number);
  Infint &operator*=(long long number);
  Infint &operator=(long long number);
  Infint &operator+=(Infint number);
  Infint &operator-=(Infint number);
  Infint &operator*=(Infint number);
  Infint &operator++(int);
  Infint &operator--(int);
  Infint &operator++();
  Infint &operator--();
  string minimalArray(string a, string b);
  string maximalArray(string a, string b);
  friend Infint operator+(long long number1, Infint number2);
  friend Infint operator+(string number1, Infint number2);
  friend Infint operator-(long long number1, Infint number2);
  friend Infint operator-(string number1, Infint number2);
  friend Infint operator*(long long number1, Infint number2);
  friend Infint operator*(string number1, Infint number2);
  friend ostream &operator<<(std::ostream &os, const Infint &cal_result);

private:
  string value;
};

void myAbs(string &number);
bool isNegtiva(string number);
int myAtoi(char ch);
#endif
