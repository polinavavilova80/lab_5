//Программа для подсчета количества появлений заданного слова в текстовом файле
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("text.txt"); // открываем файл для чтения
    if (!file.is_open()) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::string wordToFind = "apple";
    std::string word;
    int count = 0;

    while (file >> word) { // читаем слово из файла
        if (word == wordToFind) {
            count++;
        }
    }

    file.close();
    std::cout << "Word '" << wordToFind << "' appears " << count << " times in the file.\n";

    return 0;
}
