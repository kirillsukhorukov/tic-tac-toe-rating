#include <iostream>

// Функция проверки строки по словарю
bool find_bad_char (std::string str, std::string dictionary)
{
    for (int i=0; i<str.length(); i++)
    {
        int goodChar = dictionary.find(str[i]);
        if (goodChar<0) return true;
    }
    return false;
}

//Функция нахождения количества символа в строках
int char_count (std::string str1, std::string str2, std::string str3, char symbol)
{
    int countChar = 0;
    for (int i=0; i<3; i++)
    {
        if (str1[i] == symbol) countChar++;
        if (str2[i] == symbol) countChar++;
        if (str3[i] == symbol) countChar++;
    }
    return countChar;
}

//Функция проверки корректности поля
bool incorrect (std::string str1, std::string str2, std::string str3)
{
   // Проверка строк на длину
   if (str1.length()!=3 || str2.length()!=3 || str3.length()!=3) return true;

   // Проверка на правильность ввода символов
   std::string dictionary = "O.X";
   if (find_bad_char(str1,dictionary) || find_bad_char(str2,dictionary) || find_bad_char(str3,dictionary)) return true;

   // Проверка на количество крестиков и ноликов (количество должно отличаться более чем на 1)
   if ((abs (char_count(str1,str2,str3,'X')-char_count(str1,str2,str3,'O'))) > 1) return true;

    return false;

}

int main()
{
    while (true)
    {
        // Ввод результатов игры
        std::string str1, str2, str3;
        std::cout << "Enter the result of the game of tic-tac-toe." << std::endl;
        std::cout << "The result is entered in three lines containing 3 characters each." << std::endl;
        std::cout << "The characters 'X', 'O' or '.' must be used for input." << std::endl;
        std::cin >> str1 >> str2 >> str3;

        // Выход из программы
        if (str1 == "exit" || str2 == "exit" || str3 == "exit")
        {
            std::cout << "Program stopped!" << std::endl;
            break;
        }

        // Проверка на корректность ввода результата игры
        if (incorrect(str1,str2,str3)) std::cout << "Incorrect" << std::endl;
        else
        {
            std::cout << "Correct" << std::endl;
        }

    }

    return 0;
}