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
#endif