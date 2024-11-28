#include <iostream>
using namespace std;

class MyString {
private:
    char* str;
    int size;

public:
    
    MyString() {
        size = 80; 
        str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            str[i] = '*'; 
        }
        str[size] = '\0';
    }

    MyString(int custom_size) {
        size = custom_size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            str[i] = '*'; 
        }
        str[size] = '\0';
    }

    
    MyString(True) {
        
        cout << "input str: ";
        char input[100];
        cin.getline(input, 100); 
        size = strlen(input); 
        str = new char[size + 1]; 

        for (size_t i = 0; i < size; i++) {
            str[i] = input[i];
        }
        str[size] = '\0';
        
    }
    MyString(const MyString& other) { // Конструктор копирования
        size = other.size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    char* getStr() {
        return str;
    }

    void setStr(const char* my_str) {
        delete[] str;
        if (my_str != nullptr) {
            size = strlen(my_str);
            str = new char[size + 1];
            for (int i = 0; i < size; i++) {
                str[i] = my_str[i];
            }
            str[size] = '\0';
        }
    }

    int getSize() {
        return size;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString defaultStr;
    cout << "default str: " << defaultStr.getStr() << endl;
    cout << "size: " << defaultStr.getSize() << endl;

    MyString customSizeStr(10);
    cout << "custom size str: " << customSizeStr.getStr() << endl;
    cout << "size: " << customSizeStr.getSize() << endl;

    MyString initializedStr(true);
    cout << "initialized str: " << initializedStr.getStr() << endl;
    cout << "size: " << initializedStr.getSize() << endl;

    MyString copiedStr = initializedStr; // Сам конструктор копирования
    cout << "copied str: " << copiedStr.getStr() << endl;
    cout << "size: " << copiedStr.getSize() << endl;

    return 0;
}
