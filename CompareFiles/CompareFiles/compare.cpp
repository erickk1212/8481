// This Code wasn't written by me.
// ChatGPT wrote this since I didn't know how to use ifstream.
#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::string name1, name2;
    std::cin >> name1 >> name2;
    std::ifstream file1("C:\\Users\\84lsj\\OneDrive\\���� ȭ��\\8481\\" + name1);
    std::ifstream file2("C:\\Users\\84lsj\\OneDrive\\���� ȭ��\\8481\\" + name2);

    if (!file1 || !file2) {
        std::cerr << "������ �� �� �����ϴ�.\n";
        return 1;
    }

    std::string line1, line2;
    int lineNum = 1;
    bool differenceFound = false;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "�ٸ�: �� " << lineNum << '\n';
            std::cout << "file1: " << line1 << '\n';
            std::cout << "file2: " << line2 << '\n';
            differenceFound = true;
        }
        ++lineNum;
    }

    // ���� ������ �� �� ���
    while (std::getline(file1, line1)) {
        std::cout << "file1 �߰� �� " << lineNum << ": " << line1 << '\n';
        differenceFound = true;
        ++lineNum;
    }

    while (std::getline(file2, line2)) {
        std::cout << "file2 �߰� �� " << lineNum << ": " << line2 << '\n';
        differenceFound = true;
        ++lineNum;
    }

    if (!differenceFound) {
        std::cout << "�� ������ �����մϴ�.\n";
    }
    
    std::cin.ignore();

    return 0;
}
