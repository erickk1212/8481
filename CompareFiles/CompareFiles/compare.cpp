// This Code wasn't written by me.
// ChatGPT wrote this since I didn't know how to use ifstream.
#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::string name1, name2;
    std::cin >> name1 >> name2;
    std::ifstream file1("C:\\Users\\84lsj\\OneDrive\\바탕 화면\\8481\\" + name1);
    std::ifstream file2("C:\\Users\\84lsj\\OneDrive\\바탕 화면\\8481\\" + name2);

    if (!file1 || !file2) {
        std::cerr << "파일을 열 수 없습니다.\n";
        return 1;
    }

    std::string line1, line2;
    int lineNum = 1;
    bool differenceFound = false;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "다름: 줄 " << lineNum << '\n';
            std::cout << "file1: " << line1 << '\n';
            std::cout << "file2: " << line2 << '\n';
            differenceFound = true;
        }
        ++lineNum;
    }

    // 한쪽 파일이 더 길 경우
    while (std::getline(file1, line1)) {
        std::cout << "file1 추가 줄 " << lineNum << ": " << line1 << '\n';
        differenceFound = true;
        ++lineNum;
    }

    while (std::getline(file2, line2)) {
        std::cout << "file2 추가 줄 " << lineNum << ": " << line2 << '\n';
        differenceFound = true;
        ++lineNum;
    }

    if (!differenceFound) {
        std::cout << "두 파일은 동일합니다.\n";
    }
    
    std::cin.ignore();

    return 0;
}
