// BlackJack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    int language, random1, random2, choose, suma=0, computerSuma = 0, stop;
    string y;
    bool play = true;
    
    cout << "\t\t\t\t\tWelcome to BlackJack";
    cout << "\nChose the language: ";
    cout << "\n1. English";
    cout << "\n2. Русский";
    cout << "\n3. Romana\n";
    cin >> language;

    if (language == 1)
    {
        cout << "Do you want to play (yes/no): ";
        link1://
        cin >> y;
        
        if (y == "y" || y == "yes" || y == "Yes" || y == "YES" || y == "Y")
        {
            play = true;
        }
        else
        {
            cout << "\nThanks for playing\n";
            system("pause");
            return 0;
        }
        cout << "\n\nThe game starts." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        suma = random1 + random2;
        cout << "You\'ve got two cards, it\'s " << random1 << " and " << random2 << endl;
        cout << "In total you have " << suma << " points." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        cout << "Computer got two cards.\n" << endl;
        computerSuma = random1 + random2;
        do
        {
            cout << "Choose one of the options: " << endl;
            cout << "1. Hit (take a card)" << endl;
            cout << "2. Stand" << endl;
            cout << "3. Show the cards" << endl;
            cin >> choose;
            
            if (choose == 1)
            {
                random1 = (rand() % 10) + 2;
                if (random1 == 11 && suma > 10)
                {
                    random1 = 1;
                    suma += random1;
                    cout << "\nYou got an ace but only 1 point is credited to avoid overkill";
                    cout << "\nNow you have " << suma << " points in total.\n";
                }
                else
                {
                    suma += random1;
                    cout << "\nYou got another card, now you have " << suma << " points in total.\n";
                }
                
                if (suma > 21)
                {
                    cout << "\nOverkill!" << endl;
                    cout << "You losed the game..." << endl;
                    play = false;
                }

                if (suma == 21)
                {
                    cout << "Сongratulations, you won!!!" << endl;
                    play = false;
                }
            }

            if (choose == 2)
            {
                while (computerSuma <= 16)
                {
                    random1 = (rand() % 9) + 2;
                    computerSuma += random1;
                    cout << "\nComputer got a card.\n" << endl;
                    if (computerSuma > 21)
                    {
                        cout << "\nOverkill!" << endl;
                        cout << "Computer losed the game..." << endl;
                        play = false;
                    }
                }
            }

            if (choose == 3)
            {
                cout << "You collected: " << suma << " points." << endl;
                cout << "Computer collected: " << computerSuma << " points." << endl;
                if (suma > computerSuma)
                {
                    cout << "Сongratulations, you won!!!" << endl;
                }
                else if (suma == computerSuma)
                {
                    cout << "Draw" << endl;
                }
                else
                {
                    cout << "You losed the game..." << endl;
                }
                play = false;
            }

        } while (play == true);

        cout << "\nDo you want to restart the game? (yes/no)" << endl;
        goto link1;//
    }

    if (language == 2)
    {
        cout << "Хочешь начать игру (yes/no): ";
        link2://
        cin >> y;

        if (y == "y" || y == "yes" || y == "Yes" || y == "YES" || y == "Y")
        {
            play = true;
        }
        else
        {
            cout << "\nСпасибо за игру\n";
            system("pause");
            return 0;
        }
        cout << "\n\nИгра началась." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        suma = random1 + random2;
        cout << "Ты получил 2 карты, их пунктаж " << random1 << " и " << random2 << endl;
        cout << "В сумме " << suma << " очков." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        cout << "Компьютер получил 2 карты.\n" << endl;
        computerSuma = random1 + random2;
        do
        {
            cout << "Выбери один из вариантов: " << endl;
            cout << "1. Ещё (взять карту)" << endl;
            cout << "2. Достаточно (ход переходит к компьютеру)" << endl;
            cout << "3. \"Вскрываемся\"" << endl;
            cin >> choose;

            if (choose == 1)
            {
                random1 = (rand() % 10) + 2;
                if (random1 == 11 && suma > 10)
                {
                    random1 = 1;
                    suma += random1;
                    cout << "\nТебе выпал Туз, но он превращается в 1 бал чтоб избежать \"перебора\"";
                    cout << "\nТеперь у тебя " << suma << " очков в сумме.\n";
                }
                else
                {
                    suma += random1;
                    cout << "\nТы взял ещё одну карту, теперь у тебя " << suma << " очков в сумме.\n";
                }

                if (suma > 21)
                {
                    cout << "\nПеребор!" << endl;
                    cout << "Ты проиграл..." << endl;
                    play = false;
                }

                if (suma == 21)
                {
                    cout << "Поздравляю, ты выиграл!!!" << endl;
                    play = false;
                }
            }

            if (choose == 2)
            {
                while (computerSuma <= 16)
                {
                    random1 = (rand() % 9) + 2;
                    computerSuma += random1;
                    cout << "\nКомпьютер взял карту.\n" << endl;
                    if (computerSuma > 21)
                    {
                        cout << "\nПеребор!" << endl;
                        cout << "Компьютер проиграл, вы выиграли!!!" << endl;
                        play = false;
                    }
                }
            }

            if (choose == 3)
            {
                cout << "Твоя сумма очков: " << suma << endl;
                cout << "Сумма очков компьютера: " << computerSuma << endl;
                if (suma > computerSuma)
                {
                    cout << "Поздравляю, вы выиграли!!!" << endl;
                }
                else if (suma == computerSuma)
                {
                    cout << "Ничья" << endl;
                }
                else
                {
                    cout << "Вы проиграли..." << endl;
                }
                play = false;
            }

        } while (play == true);

        cout << "\nХотите перезапустить игру? (yes/no)" << endl;
        goto link2;//
    }

    if (language == 3)
    {
        cout << "Doriti sa incepeti jocul? (da/nu): ";
        link3://
        cin >> y;

        if (y == "d" || y == "da" || y == "Da" || y == "DA" || y == "D")
        {
            play = true;
        }
        else
        {
            cout << "\nMultumim pentru joc\n";
            system("pause");
            return 0;
        }
        cout << "\n\nJocul a inceput." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        suma = random1 + random2;
        cout << "V-au cazut doua carti cu punctajul " << random1 << " si " << random2 << endl;
        cout << "In total aveti " << suma << " puncte." << endl;
        random1 = (rand() % 10) + 2;
        random2 = (rand() % 10) + 2;
        cout << "Calculatorul a primit doua carti.\n" << endl;
        computerSuma = random1 + random2;
        do
        {
            cout << "Alegeti o optiune: " << endl;
            cout << "1. Ia o carte" << endl;
            cout << "2. Asteapta (calculatorul ia o carte daca are nevoie)" << endl;
            cout << "3. Arata cartile" << endl;
            cin >> choose;

            if (choose == 1)
            {
                random1 = (rand() % 10) + 2;
                if (random1 == 11 && suma > 10)
                {
                    random1 = 1;
                    suma += random1;
                    cout << "\nV-a nimerit un as dar veti primi numai un punct pentru a evita \"overkill\"-ul";
                    cout << "\nAcum ai " << suma << " puncte in total.\n";
                }
                else
                {
                    suma += random1;
                    cout << "\nAi luat inca o carte, si acum ai " << suma << " puncte in total.\n";
                }

                if (suma > 21)
                {
                    cout << "\nOverkill!" << endl;
                    cout << "Ai pierdut jocul..." << endl;
                    play = false;
                }

                if (suma == 21)
                {
                    cout << "Felicitari, ai castigat!!!" << endl;
                    play = false;
                }
            }

            if (choose == 2)
            {
                while (computerSuma <= 16)
                {
                    random1 = (rand() % 9) + 2;
                    computerSuma += random1;
                    cout << "\nCalculatorul a primit o carte.\n" << endl;
                    if (computerSuma > 21)
                    {
                        cout << "\nOverkill!" << endl;
                        cout << "Calculatorul a pierdut..." << endl;
                        play = false;
                    }
                }
            }

            if (choose == 3)
            {
                cout << "Ai colectat: " << suma << " puncte." << endl;
                cout << "Calculatorul a colectat: " << computerSuma << " puncte." << endl;
                if (suma > computerSuma)
                {
                    cout << "Felicitari, ai castigat!!!" << endl;
                }
                else if (suma == computerSuma)
                {
                    cout << "Egalitate" << endl;
                }
                else
                {
                    cout << "Ai pierdut jocul..." << endl;
                }
                play = false;
            }

        } while (play == true);

        cout << "\nDoresti sa incerci din nou? (da/nu)" << endl;
        goto link3;//
    }

    cout << endl;
    system("pause");
    
    return 0;
}

