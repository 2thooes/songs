#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
    string name;
    string author;
    string text;
    int year;
    
}Info;

void add(int *num) {
    Info song;
    int choice1;
    string song_text;
    cout << "Введите название" <<endl;
    cin >> song.name;
    cout << "Введите автора" << endl;
    cin >> song.author;
    cout << "Введите год" << endl;
    cin >> song.year;
    cout << "Где взять текст: \n1) текст из файла \n2) ввести вручную" << endl;
    cin >> choice1;
    if (choice1 == 1) {
        fstream file2("songfromfile.txt");
        if (file2.is_open()) {

        }
    }
    if (choice1 == 2) {
        cout << "Введите текст песни (Чтобы закончить нажмите enter)";
        cin.ignore();
        while (true) {
            getline(cin, song_text);
            if (song_text.empty()) {
                break;
            }
            song.text += song_text;
        }
        cout << "Идет сохранение в файл" << endl;
        fstream file("songtext.txt",ios::app);
        if (file.is_open()) {
            cout << "Добавляем";
            file << "Name: " << song.name << "\n";
            file << "Author: " << song.author << "\n";
            file << "Year:" << song.year << "\n";
            file << "Song text:\n" << song.text << "\n";
            file << "\n========================\n\n";
        }
        else {
            cout << "error";
        }
        num += 1;
    }

}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;
    int num_of_songs = 0;
    Info* katalog = nullptr;
    while (true) {
        cout << "1)Добавить песню\n2)Удалить песню\n3)\n4)\n5)\nEnter:";
        cin >> choice;
        switch (choice) {
        case(1):
            add(&num_of_songs);
            break;
        }
    }
}

