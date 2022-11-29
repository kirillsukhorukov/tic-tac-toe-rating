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

// Функция поиска символа по координатам
char find_char (std::string str1, std::string str2, std::string str3, int x, int y)
{
    if (y == 0) return str3[x];
    else if (y == 1) return str2[x];
    else if (y == 2) return str1[x];
    else return '-';
}
// Функция получения столбца
std::string column (std::string str1, std::string str2, std::string str3, int y)
{
    std::string col;
    col += str1[y];
    col += str2[y];
    col += str3[y];
    return col;
}

// Функция нахождения победителя в строке
bool  find_won (std::string str, char symbol)
{
    if (str[0] == symbol && str[1] == str[0] && str[2] == str[0]) return true;
    else return false;
}

int main()
{
    std::cout << "------------Tic-tac-toe------------\n" << std::endl;

    // Ввод результатов игры
    std::string str1, str2, str3;
    std::cout << "Enter the result of the game of tic-tac-toe." << std::endl;
    std::cout << "The result is entered in three lines containing 3 characters each." << std::endl;
    std::cout << "The characters 'X', 'O' or '.' must be used for input." << std::endl;
    std::cin >> str1 >> str2 >> str3;


    // Проверка на корректность ввода результата игры
    if (incorrect(str1,str2,str3)) std::cout << "Incorrect" << std::endl;
    else
    {

        // Находим количество Х и О
        int amountX = char_count(str1,str2,str3,'X');
        int amountO = char_count(str1,str2,str3,'O');

        // Выделяем строки-столбцы
        std::string col1 = column(str1,str2,str3,0);
        std::string col2 = column(str1,str2,str3,1);
        std::string col3 = column(str1,str2,str3,2);

        // Выделяем строки-диагонали
        std::string diag1, diag2;
        for (int i; i<3; i++)
        {
            diag1 += find_char (str1,str2,str3,i,i);
            diag2 += find_char (str1,str2,str3,i,2-i);
        }
        //    std::cout << "Strings:" << std::endl;
        //    std::cout << str1 << std::endl << str2 << std::endl << str3 << std::endl;
        //    std::cout << "Columns" << std::endl;
        //    std::cout << col1 << std::endl << col2 << std::endl << col3 << std::endl;
        //    std::cout << "Diagonals:" << std::endl;
        //    std::cout << diag1 << std::endl << diag2 << std::endl;
        //    std::cout << "X: " << amountX << " O: " << amountO << std::endl;

        // Проверка на выигрыш Пети
        if (find_won(str1, 'X') || find_won(str2, 'X') || find_won(str3, 'X') ||
                find_won(col1, 'X') ||find_won(col2, 'X') ||find_won(col3, 'X') ||
                find_won(diag1, 'X') ||find_won(diag2, 'X'))
        {
            if (amountX-amountO == 1) std::cout << "Petya won" << std::endl;
            else std::cout << "Incorrect" << std::endl;
        }
        else if (find_won(str1, 'O') || find_won(str2, 'O') || find_won(str3, 'O') ||
                 find_won(col1, 'O') ||find_won(col2, 'O') ||find_won(col3, 'O') ||
                 find_won(diag1, 'O') ||find_won(diag2, 'O'))
        {
            if (amountO-amountX == 1) std::cout << "Vasya won" << std::endl;
            else std::cout << "Incorrect" << std::endl;
        }
        else std::cout << "Nobody" << std::endl;
    }

    return 0;
}