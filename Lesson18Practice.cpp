// Lesson18Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;



class Student {
private:
    string name;
    int age;
    int averageMark;
    const string filename = "example.bin";
public:
    Student() {
        name = "Alexey";
        age = 16;
        averageMark = 11.3;
    }

    void WriteInFileInfo() {

        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "Error while openning file.\n";
            
        }

        
        size_t stringSize3 = name.size();
        outFile.write(reinterpret_cast<const char*>(&age), sizeof(age));
        outFile.write(reinterpret_cast<const char*>(&averageMark), sizeof(averageMark));
        outFile.write(reinterpret_cast<const char*>(&stringSize3), sizeof(stringSize3));
        outFile.write(name.c_str(), stringSize3);

        outFile.close();
        cout << "Info successfully.\n";
    }

    void ReadFileInfo() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Error while readding.\n";
            
        }

        inFile.read(reinterpret_cast<char*>(&age), sizeof(age));
        inFile.read(reinterpret_cast<char*>(&averageMark), sizeof(averageMark));

        size_t readMessageSize;
        string readMessage;
        inFile.read(reinterpret_cast<char*>(&readMessageSize), sizeof(readMessageSize));
        readMessage.resize(readMessageSize);
        inFile.read(&readMessage[0], readMessageSize);

        inFile.close();

        cout << "Info from file:\n";
        cout << "Number: " << age << "\n";
        cout << "Number Pi: " << averageMark << "\n";
        cout << "Message: " << readMessage << "\n";
    }
};

int main()
{
    Student obj;
    obj.WriteInFileInfo();
    obj.ReadFileInfo();
    std::cout << "Hello World!\n";
}
