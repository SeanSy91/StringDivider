#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "Arduino.h"
#include "vector"

class StringDivider {
private:

    std::vector<char> delimiters;
    std::vector<std::vector<char>> fields;
public:
    StringDivider(char firstdiv);
    StringDivider(char firstdiv, char seconddiv);
    StringDivider(char firstdiv, char seconddiv, char thirddiv);

    void divide(const char* srcStr, int sizeStr);

    void printFields() const;

    std::vector<std::string> getFields() const;

private:
    bool isDelimiter(char ch) const;
    

};

#endif  //_DIVIDE_H_
