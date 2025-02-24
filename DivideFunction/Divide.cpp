#include "Divide.h"

StringDivider::StringDivider(char firstdiv){
    delimiters = { firstdiv };
}

StringDivider::StringDivider(char firstdiv, char seconddiv){
    delimiters = { firstdiv, seconddiv };
}

StringDivider::StringDivider(char firstdiv, char seconddiv, char thirddiv){
    delimiters = { firstdiv, seconddiv, thirddiv };
}

void StringDivider::divide(const char* srcStr, int sizeStr){
    fields.clear();
    std::vector<char> currentField;

    for(int i = 0; i < sizeStr; i++){
        if(isDelimiter(srcStr[i])){
            if(!currentField.empty()){
                currentField.push_back('\0');
                fields.push_back(currentField);
                currentField.clear();
            }
        } else {
            currentField.push_back(srcStr[i]);
        }
    }

    if(!currentField.empty()){
        currentField.push_back('\0');
        fields.push_back(currentField);
    }
}

void StringDivider::printFields() const {
    for (const auto& field : fields){
        Serial.println(field.data());
    }
}

std::vector<std::string> StringDivider::getFields() const{
    std::vector<std::string> result;
    for(const auto& field : fields) {
        result.push_back(std::string(field.data()));
    }
    return result;
}

bool StringDivider::isDelimiter(char ch) const {
    return std::find(delimiters.begin(), delimiters.end(), ch) != delimiters.end();
}
