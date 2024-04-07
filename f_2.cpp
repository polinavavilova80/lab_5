//Программа для записи и чтения объектов Matrix из текстового файла
#include <iostream>
#include <fstream>
#include <vector>

class Matrix {
public:
    int data;

    Matrix(int d) : data(d) {}

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << matrix.data << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        is >> matrix.data;
        return is;
    }
};

int main() {
    std::ofstream textFile("matrix.txt");
    textFile << Matrix(1) << Matrix(2) << Matrix(3); // записываем объекты в текстовый файл
    textFile.close();

    std::ifstream textFileInput("matrix.txt");
    std::vector<Matrix> matrices;
    Matrix m(0);
    while (textFileInput >> m) {
        matrices.push_back(m); // считываем объекты из текстового файла
    }

    for (const Matrix& matrix : matrices) {
        std::cout << matrix.data << " ";
    }

    textFileInput.close();

    return 0;
}