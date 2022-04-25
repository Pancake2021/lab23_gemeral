//Панкеев группа 6112-100503d Вариант 9 
//
// Реализовать класс шахматная фигура и ее 3 наследника - пешка, ладья, слон
//
// У каждой клетки есть значение клетки на которой она стоит и цвет клетки
//Должны быть методы проверки может ли фигура переместиться на заданную клетку,
// Может ли атаковать заданную клетку
// Метод - вывода списка фигур с указанием типа
// Y: | X: 1A 2B 3C 4D 5E 6F 7G 8H
// 8
// 7 Black figures
// 6
// 5
// 4
// 3
// 2 White figures
// 1




#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <ctime>
#include "ChessFigure.h"

void ChessDesk()
{
    printf(" A B C D E F G H\n8\n7 Black Figures\n6\n5\n4\n3\n2 White Figures\n1");
}

bool CheckX(const int& x)
{
    if (x != 1 && x != 2 && x != 3 && x != 4 && x != 5 && x != 6 && x != 7 && x != 8) return false;
    return true;
}
bool CheckColor(const int& x)
{
    if (x != 1 && x != 2) return false;
    return true;
}
bool CheckIndex(const int& i, const int& value)
{
    if (value == 1 && i == 0) return true;
    for (int j = 1; j <= i; j++)
    {
        if (value == j) return true;
    }
    return false;
}

int get_key3()
{
    while (true)
    {
        int key;
        key = getchar();
        if ((key == 54) || (key == 49) || (key == 50)|| (key==51)) return key;
// 6(Escape) 1 2
    }
}

bool StrToInt(const char* str, int& value)
{
    setlocale(LC_ALL, "Russian");
    char* endptr = NULL;
    value = strtof(str, &endptr);
    if (endptr == str)return false; //к примеру при вводе "привет"
    if ((value == LONG_MIN || value == LONG_MAX) && errno == ERANGE) return false; //при вводе большого числа
    if (*endptr != str[strlen(str)]) return false; //при вводе 23привет
    return true;
}

bool CheckSymbol(const char* text, int &x)
{
    char temp[] = "ABCDEFGH";
    for (int i = 0; i < strlen(temp); ++i)
    {
        if (text[0] == temp[i])
        {
            switch (i)
            {
                case 0: {x = 1; return true; }
                case 1: {x = 2; return true; }
                case 2: {x = 3; return true; }
                case 3: {x = 4; return true; }
                case 4: {x = 5; return true; }
                case 5: {x = 6; return true; }
                case 6: {x = 7; return true; }
                case 7: {x = 8; return true; }
            }
        }
    }
    return false;
}

int TakeSymbol()
{
    char text[100];
    int x;
    printf("\nВведите букву столбца - \n");
    while (true)
    {
    
       
        std :: cin >> text;
        text[0] = toupper(text[0]);
        if (CheckSymbol(text, x) == false)
        {
            printf("\nВы ввели букву несуществующего столбца, повтортие ввод\n");
        }
        else
        {
            //if (CheckX(x) == true) break;
            //else printf("\nВы ввели букву несуществующего столбца, повтортие ввод\n");
       
            if (CheckX(x) == false)printf("\nВы ввели букву несуществующего столбца, повтортие ввод\n");
            else break;
          //  break;
        //
        }
        
    }
    return x;
}

int DeleteFigure(const int size)
{
    char text[100];
    int value;
    printf("\nВведите номер фигуры, которую вы хотите удалить - ");
    while (true)
    {
        std :: cin >> text;
        if (StrToInt(text, value) == false)
        {
            printf("\nВы ввели номер несуществующей фигуры, повторите ввод\n");
        }
        else
        {
            if (CheckIndex(size, value) == false) printf("\nВы ввели номер несуществующей фигуры, повторите ввод\n");
            else break;
        }
    }
    return value;
}

void Move(ChessFigure* figure)
{
    char text[100];
    int x, y;
    x=TakeSymbol();
    printf("\nВведите номер строки - \n");
    std :: cin >> text;
    StrToInt(text, y);
    if (figure->MoveTo(x, y) == true) printf("Да, туда можно сходить");
    else printf("Нет, туда нельзя сходить");
}

void Attack(ChessFigure* figure)
{
    char text[100];
    int x, y;
    x=TakeSymbol();
    printf("\nВведите номер строки - \n");
    std :: cin >> text;
    StrToInt(text, y);
    if (figure->AttackTo(x, y) == true) printf("Да, туда можно атаковать");
    else printf("Нет, туда нельзя атаковать");
}

int GetIndexElement(const size_t& size)
{
    int value;
    while (true)
    {
        char text[100];
        printf("\nВведите номер фигуры - ");
        std :: cin >> text;
        if (StrToInt(text, value) == false)
        {
            printf("\nВы ввели номер несуществующей фигуры, повторите ввод\n");
        }
        else
        {
            if (CheckIndex(size, value) == false) printf("\n Вы ввели номер несуществующей фигуры, повторите ввод\n");
            else break;
        }
    }
    return value;
}

void EditFigure(ChessFigure* figure)
{
    char text[100];
    while (true)
    {
        int editor=0;
        
        printf("Изменяемая вами фигура : "); figure->print();
        printf("\nЧтобы изменить цвет введите - 1\nЧтобы изменить столбец нажмите - 2\nЧтобы изменить строку нажмите - 3\nДля отмены - 6\n");
        int key = get_key3();
        if (key == 54) break;// выход
        if (key == 49) // изменение цвета
        {
            figure->editcolor();
        }
        if (key == 50) // изменение столбца X
        {
           /* printf("\nВведите букву столбца, куда вы хотие поставить фигуру");
            while (true)
            {
              editor = TakeSymbol();
                
            }
            figure->editx(editor);
            */
            
            
            
            
            
            
            
       
            printf("\nВведите букву столбца - \n");
            while (true)
            {
            
               
                std :: cin >> text;
                text[0] = toupper(text[0]);
                if (CheckSymbol(text, editor) == false)
                {
                    printf("\nВы ввели букву несуществующего столбца, повтортие ввод\n");
                }
                else
                {
               
                    if (CheckX(editor) == false) printf("\nВы ввели букву несуществующего столбца, повтортие ввод\n");
                    else break;
                 
                }
                
            }
            figure->editx(editor);
        }
            
            
    
        if (key == 51) // изменение строки y
        {
            printf("\nВведите номер строки, куда вы хотите поставить фигуру");
            while (true)
            {
                std :: cin >> text;
                if (StrToInt(text, editor) == false)
                {
                    printf("\nВы ввели номер несуществующей строки, повторите ввод\n");
                }
                else
                {
                    if (CheckX(editor) == true) break;
                    else printf("\nВы ввели номер несуществующей строки, повторите ввод\n");
                }
            }
            figure->edity(editor);
        }
    }
}

ChessFigure* CreateFigure(const int& key)
{
    int color = 0;
    int x = 0;
    int y = 0;
    char test[100];
    while (true)
    {
        x = TakeSymbol();
        if (x != 0) break;
    }
    while (true)
    {
        printf("\nВведите номер строки(12345678) - \n");
        std :: cin >> test;
        if (StrToInt(test, y) == true)
        {
            if (CheckX(y) == true) break;
        }
        printf("Всего 8 строк, повторите ввод\n");
    }
    while (true)
    {
        printf("\nЕсли ваша фигура белая введите - 1\nЕсли ваша фигура черная введите - 2\n");
        std :: cin >> test;
        if (StrToInt(test, color) == true)
        {
            if (CheckColor(color) == true) break;
        }
        printf("Введите 1 или 2, повторите ввод\n");
    }
    switch (key)
        case 49:
        {
            if (color == 1)
            {
                return new Pawn(x, y, White);;
            }
            else
            {
                return new Pawn(x, y, Black);
            }
            case 50:
                if (color == 1)
                {
                    return new Rook(x, y, White);
                }
                else
                {
                    return new Rook(x, y, Black);
                }
            case 51:
                if (color == 1)
                {
                    return new Bishop(x, y, White);
                }
                else
                {
                    return new Bishop(x, y, Black);
                }
        }
    return 0;
}

int get_key()
{
    while (true)
    {
        int key;
        key = getchar();
        if ((key == 55)||(key==56) || (key==49) || (key==50) || (key ==51) || (key==52) || (key==53) ||(key==54)) return key;
// 7 8 1 2 3 4 5 6
    }
}

int get_key2()
{
    while (true)
    {
        int key;
        key = getchar();
        if ((key == 55) || (key == 49) || (key == 50) || (key==51) || (key==52) || (key ==53) ||  (key == 54)) return key;
//  1 2 3 4 5 6 7
    }
}


int main()
{
    ChessFigureCollection collection;
//ChessFigures* f =createfigure
// figures.insert(i,f)
    setlocale(LC_ALL, "");
//srand(time(0));
    bool check = false;
    int key=54;
    while (true)
    {
        while (check == false && key == 54)
        {

            printf("\nЗдравствуйте! Эта программа позволяет поставить Слона/Пешку/Ладью в определенную точку на щахматном столе\nИ узнать, можно ли атаковать или сходить в ту или иную точку.\nДля продолжения нажмите - 8\nДля выхода из программы - 6 \n");
            key = get_key();
            if (key == 56)
            {
                check = true;
                break;
            }
            if (key == 54) break;
            
            if (key != 54) // чтобы при нажатии на цифры, не выходил отсюбда
            {
                check = false;
                key = 54;
            }
             
        }
        if (key == 54) break;
        if (key == 54 && check ==true) break;

        printf("\n Чтобы сделать то или иное действие, нажмите на соответствующую кнопку\n 1 - Создать пешку со своими значениями\n 2 - Создать слона со своими значениями\n 3 - Создать ладью со своими значениями \n 4 - Создать рандомную фигуру , с рандомными значениями \n 5 - Вывести всю коллекцию на экран \n 6 - Вернуться ");
        key = get_key();
        if (key == 54) check = false; // возврат к условию
        if (key == 49 || key == 50 || key == 51) // Создание Пешки / Слона / Ферзя
        {

            ChessFigure* temp = CreateFigure(key);
            collection.Insert(collection.GetSize(),temp);
        }
        if (key == 52) // Создание случайной фигуры со случайными значениями
        {
            int temp1 = 1 + rand() % 8; // РАНДОМ ЧИСЛО ОТ 1 от 8
            int temp2 = 1 + rand() % 8;
            int temp3 = 1 + rand() % 2; // рандом число от 1 до 2
            ColourPoint temp4;
            if (temp3 == 1) temp4 = White;
            else temp4 = Black;
            int temp5 = 1+rand() % 3;// от 1 до 3
            switch (temp5)
            {
                case 1:
                {//key = 49;
                    ChessFigure* temp = new Pawn(temp1, temp2, temp4);
                    collection.Insert(collection.GetSize(), temp);
                    break; }
                case 2:
                { //key = 50;
                    ChessFigure* temp = new Rook(temp1, temp2, temp4);
                    collection.Insert(collection.GetSize(), temp);
                    break; }
                case 3:
                {//key = 51;
                    ChessFigure* temp = new Bishop(temp1, temp2, temp4);
                    collection.Insert(collection.GetSize(), temp);
                    break; }
            }
        }
        if (key == 53) // ВЫВОД ВСЕЙ КОЛЛЕКЦИИ НА ЭКРАН
        {
            while (true)
            {

                if (collection.GetSize() == 0) printf(" Нет фигур в коллекции\n");
                collection.PrintC();
                ChessDesk();
                printf("\nНажмите 1 - для изменения значений той или ной фигуры\nНажмите 2 - удаления фигуры\nНажмите 3 - чтобы спросить, можно ли ходить в вашу клетку\nНажмите 4 -чтобы спросить, можно ли атаковать в вашу клетку\nНажмите 5 - для удаления всех элементов\nНажмите 7 - чтобы вернуться ");
                int key2 = get_key2();
                if (key2 == 55) break; // выход из показа
                if (key2 == 49 && collection.GetSize()!=0) // изменение значения фигуры
                {
                    int temp = GetIndexElement(collection.GetSize());
                    ChessFigure* temp1 = collection.GetFigure(temp);
                    EditFigure(temp1);
                }
                if (key2 == 50 && collection.GetSize()!=0) //удаление фигуры
                {
                    int temp = DeleteFigure(collection.GetSize());
                    collection.Remove(temp);
                }
                if (key2 == 51 && collection.GetSize() != 0) // MoveTo
                {
                    int temp = GetIndexElement(collection.GetSize());
                    ChessFigure* temp1 = collection.GetFigure(temp);
                    Move(temp1);
                    printf("\nДля продолжения нажмите - 8\n");
                    while (true)
                    {
                        int enter = 0;
                        enter = getchar();
                        if (enter == 56) break;
                    }
                }
                if (key2 == 52 && collection.GetSize() != 0) // AttackTo
                {
                    int temp = GetIndexElement(collection.GetSize());
                    ChessFigure* temp1 = collection.GetFigure(temp);
                    Attack(temp1);
                    printf("\nДля продолжения нажмите - 8\n");
                    while (true)
                    {
                        int enter = 0;
                        enter = getchar();
                        if (enter == 56) break;
                    }
                }
                if (key2 == 53 && collection.GetSize() != 0) // DELETE ALL
                {
                    collection.~ChessFigureCollection();
                }
            }
        }
    }
    collection.~ChessFigureCollection(); // если пользователь забыл удалить
}
