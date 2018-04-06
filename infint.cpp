#include "infint.hpp"

using namespace std;

Infint::Infint()
{
    this->value = "0";
}

Infint::Infint(int value)
{
    this->value = std::to_string(value);
}

Infint::Infint(string value)
{
    this->value = value;
}

Infint Infint::operator+(string number)
{
    Infint result;
    result.value.clear();
    vector<int> arr;
    arr.push_back(0);
    bool carryFlag = false;
    if (isNegtiva(number) && !isNegtiva(value))
    {
        myAbs(number);
        if (value == maximalArray(value, number))
        {
            return (*this - number);
        }
        else
        {
            Infint result_ = (*this - number);
            result.value += result_.value;
            return result;
        }
    }
    if (!isNegtiva(number) && isNegtiva(value))
    {
        myAbs(value);
        if (value == maximalArray(value, number))
        {
            Infint result_ = (*this - number);
            result.value += '-';
            result.value += result_.value;
            return result;
        }
        else
        {
            Infint result_ = (*this - number);
            myAbs(result_.value);
            result.value += result_.value;
            return result;
        }
    }
    if (isNegtiva(number) && isNegtiva(value))
    {
        myAbs(value);
        myAbs(number);
        Infint result_ = (*this + number);
        result.value += "-";
        result.value += result_.value;
        return result;
    }
    int carry = 0;
    string maxString = maximalArray(value, number);
    string minString = minimalArray(value, number);
    std::reverse(maxString.begin(), maxString.end());
    std::reverse(minString.begin(), minString.end());
    for (int i = 0; i < minString.length(); i++)
    {
        arr.back() = arr.back() + myAtoi(minString[i]) + myAtoi(maxString[i]) + carry;
        carry = arr.back() / 10;
        arr.back() %= 10;
        while (carry)
        {
            arr.push_back(carry % 10);
            carry /= 10;
            carryFlag = true;
        }
        if (!carryFlag)
            arr.push_back(0);
        else
            carryFlag = false;
    }
    for (int i = minString.length(); i < maxString.length(); i++)
    {
        arr.back() = arr.back() + myAtoi(maxString[i]) + carry;
        arr.push_back(0);
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
            arr.erase(arr.begin() + i);
        else
            break;
    }
    for (int i = arr.size() - 1; i >= 0; i--)
        result.value += std::to_string(arr[i]);
    if(result.value.empty())
        result.value += '0';
    return result;
}

Infint Infint::operator+(long long number)
{
    Infint result;
    string strNumber = to_string(number);
    result = *this + strNumber;
    return result;
}

Infint Infint::operator-(string number)
{
    Infint result;
    result.value.clear();
    vector<int> arr;
    arr.push_back(0);
    int displacement = 1;
    bool symbol = true;
    if (isNegtiva(number) && !isNegtiva(value))
    {
        myAbs(number);
        return (*this + number);
    }
    if (!isNegtiva(number) && isNegtiva(value))
    {
        myAbs(value);
        myAbs(number);
        Infint result_ = (*this + number);
        result.value += "-";
        result.value += result_.value;
        return result;
    }
    if (isNegtiva(number) && isNegtiva(value))
    {
        myAbs(value);
        myAbs(number);
        if (value == maximalArray(value, number))
        {
            Infint result_ = (*this - number);
            result.value += "-";
            result.value += result_.value;
            return result;
        }
        else
        {
            Infint result_ = (*this - number);
            myAbs(result_.value);
            result.value += result_.value;
            return result;
        }
    }
    string maxString = maximalArray(value, number);
    string minString = minimalArray(value, number);
    if (value == maximalArray(value, number))
        symbol = true;
    else
        symbol = false;
    reverse(maxString.begin(), maxString.end());
    reverse(minString.begin(), minString.end());
    for (int i = 0; i < minString.length(); i++)
    {
        if (maxString[i] < minString[i])
        {
            arr.back() = myAtoi(maxString[i]) + 10 - myAtoi(minString[i]);
            while (maxString[i + displacement] == '0')
            {
                maxString[i + displacement] = '9';
                displacement++;
            }
            maxString[i + displacement]--;
        }
        else
            arr.back() = myAtoi(maxString[i]) - myAtoi(minString[i]);
        arr.push_back(0);
    }
    for (int i = minString.length(); i < maxString.length(); i++)
    {
        arr.back() = arr.back() + myAtoi(maxString[i]);
        arr.push_back(0);
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
            arr.erase(arr.begin() + i);
        else
            break;
    }
    if (!symbol)
        result.value += '-';
    for (int i = arr.size() - 1; i >= 0; i--)
        result.value += std::to_string(arr[i]);
    if (result.value.empty())
        result.value += '0';
    return result;
}

Infint Infint::operator-(long long number)
{
    Infint result;
    string strNumber = to_string(number);
    result = *this - strNumber;
    return result;
}

Infint Infint::operator*(string number)
{
    Infint result;
    result.value.clear();
    vector<int> arr;
    arr.push_back(0);
    bool symbol = true;
    int carry = 0;
    int displacement = 0;
    if ((isNegtiva(value) && isNegtiva(number)) || (!isNegtiva(value) && !isNegtiva(number)))
        symbol = true;
    else
        symbol = false;
    myAbs(value);
    myAbs(number);
    string maxString = maximalArray(value, number);
    string minString = minimalArray(value, number);
    std::reverse(maxString.begin(), maxString.end());
    std::reverse(minString.begin(), minString.end());
    for (int i = 0; i < minString.length(); i++)
    {
        displacement = i;
        for (int j = 0; j < maxString.length(); j++)
        {
            arr[displacement] = arr[displacement] + myAtoi(minString[i]) * myAtoi(maxString[j]) + carry;
            carry = arr[displacement] / 10;
            arr[displacement] %= 10;
            arr.push_back(0);
            displacement++;
        }
        while (carry)
        {
            arr[displacement] = carry % 10;
            carry /= 10;
        }
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
            arr.erase(arr.begin() + i);
        else
            break;
    }
    if (!symbol)
        result.value += '-';
    for (int i = arr.size() - 1; i >= 0; i--)
        result.value += std::to_string(arr[i]);
    if (result.value.empty())
        result.value += '0';
    return result;
}

Infint Infint::operator*(long long number)
{
    Infint result;
    string strNumber = to_string(number);
    result = *this * strNumber;
    return result;
}

Infint &Infint::operator++()
{
    *this = *this + "1";
}

Infint &Infint::operator--()
{
    *this = *this - "1";
}

Infint &Infint::operator+=(string number)
{
    *this = *this + number;
}

Infint &Infint::operator+=(long long number)
{
    *this = *this + number;
}

Infint &Infint::operator-=(string number)
{
    *this = *this - number;
}

Infint &Infint::operator-=(long long number)
{
    *this = *this - number;
}

Infint &Infint::operator*=(string number)
{
    *this = *this * number;
}

Infint &Infint::operator*=(long long number)
{
    *this = *this * number;
}

Infint &Infint::operator=(string number)
{
    this->value = number;
}

Infint &Infint::operator=(long long number)
{
    this->value = std::to_string(number);
}

ostream &operator<<(std::ostream &os, const Infint &result)
{
    os << result.value << endl;
    return os;
}

string Infint::minimalArray(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length() ? a : b;
    else
        return a < b ? a : b;
}

string Infint::maximalArray(string a, string b)
{
    if (a.length() != b.length())
        return a.length() > b.length() ? a : b;
    else
        return a >= b ? a : b;
}

bool Infint::isNegtiva(string number)
{
    return (number.find('-') != std::string::npos);
}

int Infint::myAtoi(char ch)
{
    return (int)ch - '0';
}

void Infint::myAbs(string &number)
{
    string::iterator it;
    for (it = number.begin(); it != number.end(); ++it)
    {
        if (*it == '-')
        {
            number.erase(it);
        }
    }
}
