#include <iostream>
#include <string>
using namespace std;

int countWords(string& text) {
    if (text.empty()) return 0;
    int count = 1;
    
    for (size_t i = 0; i < text.size(); i++) {
        char space = ' ';
        if (text[i] == space) count++;
    }
    
    return count;
}

void splitString(string& str, string* words, char delimiter = ' ') {
    string word = "";
    int index = 0;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            words[index] = word;
            word = "";
            index++;
            continue;
        }
        word += str[i];
    }
    
    words[index] = word;
}

int evaluate(int n1, int n2, char oper) {
    if (oper == '+') {
        return n1 + n2;
    }
    if (oper == '-') {
        return n1 - n2;
    }
    if (oper == '*') {
        return n1 * n2;
    } 
    if (oper == '/') {
        return n1 / n2;
    } 
    cout << "Wrong operator!" << endl;
    return 0;
}

int getResult(string expression, int callCount = 1) {
    char availableOpers[2][2] = {
        {'+', '-'},
        {'*', '/'}
    };
    char availOp1 = availableOpers[callCount - 1][0];
    char availOp2 = availableOpers[callCount - 1][1];
    int operCount = 0;
    
    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == availOp1 || expression[i] == availOp2) {
            operCount++;
        }
    }
    
    int integers[operCount + 1] = {};
    char opers[operCount];
    int integersIndex = 0, opersIndex = 0;
    string integerTemp;
    
    for (size_t i = 0; i < expression.size(); i++) {
        bool isOper = expression[i] == availOp1
        || expression[i] == availOp2,
        
        isOperNext = expression[i+1] == availOp1
        || expression[i+1] == availOp2;
        
        if (isOper) {
            opers[opersIndex] = expression[i];
            opersIndex++;
            continue;
        };
        
        integerTemp += expression[i];
        
        if (i == expression.size() - 1 || isOperNext) {
            if (callCount == 2) {
                integers[integersIndex] = stoi(integerTemp);
            } else {
                callCount = 2;
                integers[integersIndex] = getResult(integerTemp, callCount);
            }
            integerTemp = "";
            integersIndex++;
        }
   }
    
    int result = integers[0];
    
    for (int i = 1; i < operCount + 1; i++) {
        result = evaluate(result, integers[i], opers[i - 1]);
    }
    
    return result;
}

int main() {
    string answerInput;
    string expressionsInput;

    getline(cin, answerInput);
    getline(cin, expressionsInput);
    
    int answer = stoi(answerInput);
    int exLen = countWords(expressionsInput);
    string expressions[exLen];
    
    splitString(expressionsInput, expressions);
    
    bool indexFound = false;
    
    for (int i = 0; i < exLen; i++) {
        string e = expressions[i];
        string expression = e.substr(1, e.size() - 2);
        int result = getResult(expression);
        
        if (result == answer) {
            indexFound = true;
            cout << "index " << i << endl;
            break;
        }
    }
    
    if (!indexFound) {
        cout << "none" << endl;
    }
    
    return 0;
}
