// КТбо1-2 Колмогоров Владислав ИЗ 12 вариант
// Построить список клиентов, которые имеют заданную сумму кредита и задолженности и не пользуются указанными тремя видами услуг
// Три вида услуг, сумма кредита и долга

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Client //структура Клиента
{
    string FullName;    //ФИО
    string PhoneNumber; //номер телефона
    string StartData;   //дата заключения договора
    string FinishData;  //дата окончания договора
    string Debt;      //размер задолженности
    string Kredit;      //допустимый кредит
};

struct InfoAboutService //структура услуг
{
    string FullName; //наименование услуги
    string Kod;      //код услуги
    string Rate;     //тариф 
    string Time;     //временной интервал измерения
};

struct RenderedService //структура  
{
    string PhoneNumber; //номер телефона клиента
    string Kod;         //код услуги
    string Data;        //дата
    string Time;        //время использования в секундах
};

struct Param
{
    string Servise1; //название услуги #1
    string Servise2; //название услуги #2
    string Servise3; //название услуги #3
    string Kod_Servise1; //код услуги #1
    string Kod_Servise2; //код услуги #2
    string Kod_Servise3; //код услуги #3
    string Debt; //сумма долга
    string summ; //Кредит
};

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);

    Client client[10];
    ifstream ClientFile("InfoAboutClient.txt");//создаем объект потока istream  по имени file
    string str; int count = 0;
    while (getline(ClientFile, str))
    {
        int a = 0; //переменная-счетчик
        string current_data_str;//текущая строка
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '\t')
            {
                switch (a)
                {
                case 0:
                {
                    client[count].FullName = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 1:
                {
                    client[count].PhoneNumber = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 2:
                {
                    client[count].StartData = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 3:
                {
                    client[count].FinishData = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 4:
                {
                    client[count].Debt = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 5:
                {
                    client[count].Kredit = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                }
            }
            else if (str[i] != ',')
            {
                current_data_str += str[i];
            }
        }
        count++;
    }

    cout << "Информация о клиентах: \n\n";

    for (int i = 0; i < count; i++)
    {
        cout << client[i].FullName << ", " << client[i].PhoneNumber << ", " << client[i].StartData << ", " << client[i].FinishData << ", " << client[i].Debt << ", " << client[i].Kredit << endl;
    }
    ClientFile.close();

    InfoAboutService infoAboutService[10];
    ifstream ServiceFile("InfoAboutServise.txt");//создаем объект потока istream  по имени file
    str.clear(); count = 0;
    while (getline(ServiceFile, str))
    {
        int a = 0;
        string current_data_str;//текущая строка
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '\t')
            {
                switch (a)
                {
                case 0:
                {
                    infoAboutService[count].FullName = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 1:
                {
                    infoAboutService[count].Kod = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 2:
                {
                    infoAboutService[count].Rate = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 3:
                {
                    infoAboutService[count].Time = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                }
            }
            else if (str[i] != ',')
            {
                current_data_str += str[i];
            }
        }
        count++;
    }

    cout << "\n\nИнформация о доступных услугах: \n\n";

    for (int i = 0; i < count; i++)
    {
        cout << infoAboutService[i].FullName << ", " << infoAboutService[i].Kod << ", " << infoAboutService[i].Rate << ", " << infoAboutService[i].Time << endl;
    }

    ServiceFile.close();

    RenderedService renderedService[35];
    ifstream RenderedServiceFile("RenderedServise.txt");//создаем объект потока istream  по имени file
    str.clear(); count = 0;

    while (getline(RenderedServiceFile, str))
    {
        int a = 0;
        string current_data_str;//текущая строка
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '\t')
            {
                switch (a)
                {
                case 0:
                {
                    renderedService[count].PhoneNumber = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 1:
                {
                    renderedService[count].Kod = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 2:
                {
                    renderedService[count].Data = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                case 3:
                {
                    renderedService[count].Time = current_data_str;
                    current_data_str.clear();
                    a++;
                    break;
                }
                }
            }
            else if (str[i] != ',')
            {
                current_data_str += str[i];
            }
        }
        count++;
    }

    cout << "\n\nИнформация о выполненных услугах: \n\n";

    for (int i = 0; i < count; i++)
    {
        cout << renderedService[i].PhoneNumber << ", " << renderedService[i].Kod << ", " << renderedService[i].Data << ", " << renderedService[i].Time << endl;
    }
    RenderedServiceFile.close();

    Param parametr;
    ifstream Param_File("Param.txt");//создаем объект потока istream  по имени file
    str.clear(); count = 0;
    while (getline(Param_File, str))
    {
        switch (count)
        {
        case 0:
        {
            parametr.Servise1 = str;
            count++;
            break;
        }
        case  1:
        {
            parametr.Servise2 = str;
            count++;
            break;
        }
        case 2:
        {
            parametr.Servise3 = str;
            count++;
            break;
        }
        case 3:
        {
            parametr.summ = str;
            count++;
            break;
        }
        case 4:
        {
            parametr.Debt = str;
            count++;
            break;
        }
        }
    }


    cout << "\n\nИнформация о параметре: \n\n";

    cout << parametr.Servise1 << endl << parametr.Servise2 << endl << parametr.Servise3 << endl << parametr.summ << endl << parametr.Debt << endl;

    Param_File.close();

    cout << endl << endl;


    for (int i = 0; i < 10; i++)
    {
        if (infoAboutService[i].FullName == parametr.Servise1)
            parametr.Kod_Servise1 = infoAboutService[i].Kod;

        if (infoAboutService[i].FullName == parametr.Servise2)
            parametr.Kod_Servise2 = infoAboutService[i].Kod;

        if (infoAboutService[i].FullName == parametr.Servise3)
            parametr.Kod_Servise3 = infoAboutService[i].Kod;
    }

    string list, result;

    for (int i = 0; i < 10; i++)
    {
        int a = 0; //переменнaя-индикатор использования заданных услуг
        for (int j = 0; j < 30; j++)
        {
            if (client[i].PhoneNumber == renderedService[j].PhoneNumber)
                if (renderedService[j].Kod != parametr.Kod_Servise1 && renderedService[j].Kod != parametr.Kod_Servise2 && renderedService[j].Kod != parametr.Kod_Servise3)
                    a = 1;
        }

        if (a)
        {
            if (client[i].Debt == parametr.Debt && client[i].Kredit == parametr.summ)
                list += client[i].FullName + "\n";
        }
    }



    if (list != "")
    {
        result += "Не пользуются услугами: " + parametr.Servise1 + ", " + parametr.Servise2 + ", " + parametr.Servise3 + ", а также имеют сумму кредита, равную " + parametr.summ + " и размер задолженности, равный: " + parametr.Debt + " следующие пользователи: \n" + list;
    }
    else
    {
        result += "Нет данных!";
    }

    cout << result;

    ofstream ResultFile("Report.txt", ios::out);
    ResultFile << result;
    ResultFile.close();
}