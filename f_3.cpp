//Программа манипуляции с каталогом книг в текстовом файле
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct Book {
    std::string id;
    std::string author;
    std::string title;
    int pages;

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::setw(4) << book.id << " " << std::setw(12) << book.author << " " << std::setw(20) << book.title << " " << std::setw(5) << book.pages << std::endl;
        return os;
    }
};

void printAllBooks(const std::vector<Book>& books) {
    for (const Book& book : books) {
        std::cout << book;
    }
}

int main() {
    std::vector<Book> books;

    std::ifstream catalogFile("catalog.txt");
    if (!catalogFile.is_open()) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    while (!catalogFile.eof()) {
        Book book;
        catalogFile >> book.id >> book.author >> book.title >> book.pages;
        books.push_back(book);
    }

    catalogFile.close();

    // Пример добавления новой записи
    Book newBook = {"0003", "J.R.R. Tolkien", "The Lord of the Rings", 1178};
    books.push_back(newBook);

    // Пример просмотра всех записей
    printAllBooks(books);

    // Пример удаления записи
    books.erase(books.begin() + 1); // удаляем вторую книгу

    // Пример поиска записи
    for (const Book& book : books) {
        if (book.author == "A.S.Pushkin") {
            std::cout << "Book found: " << book;
        }
    }

    // Пример редактирования записи
    for (Book& book : books) {
        if (book.id == "0002") {
            book.pages = 400;
        }
    }

    // Запись всех изменений обратно в файл
    std::ofstream updatedCatalogFile("catalog.txt");
    for (const Book& book : books) {
        updatedCatalogFile << book;
    }
    updatedCatalogFile.close();

    return 0;
}