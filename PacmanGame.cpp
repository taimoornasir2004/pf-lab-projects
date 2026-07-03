#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void erase1(int g, int h);
void erase2(int g, int h);
void erase3(int g, int h);
void printMaze();
void gotoxy(int x, int y);
void showGhost1(int g, int h);
void showGhost2(int g, int h);
void showGhost3(int g, int h);
void erase(int x, int y);
void printPacman(int x, int y);
char getCharAtxy(short int x, short int y);

fstream maz;

int main()
{
    int life = 3;
    int score = 0;
    for (int i = 1; i <= 3; i++)
    {

        system("color 06");
        int pacmanX = 4;
        int pacmanY = 4;
        int g1 = 4;
        int h1 = 3;
        int g2 = 17;
        int h2 = 5;
        int g3 = 30;
        int h3 = 6;
        char nextLocation;
        bool gameRunning = true;

        system("cls");
        printMaze();
        printPacman(pacmanX, pacmanY);
        showGhost1(g1, h1);
        showGhost2(g2, h2);
        showGhost3(g3, h3);

        while (gameRunning)
        {
            if (GetAsyncKeyState(VK_LEFT))
            {
                nextLocation = getCharAtxy(pacmanX - 1, pacmanY);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(pacmanX, pacmanY);
                    pacmanX = pacmanX - 1;
                    printPacman(pacmanX, pacmanY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_RIGHT))
            {
                nextLocation = getCharAtxy(pacmanX + 1, pacmanY);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(pacmanX, pacmanY);
                    pacmanX = pacmanX + 1;
                    printPacman(pacmanX, pacmanY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_UP))
            {
                nextLocation = getCharAtxy(pacmanX, pacmanY - 1);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(pacmanX, pacmanY);
                    pacmanY = pacmanY - 1;
                    printPacman(pacmanX, pacmanY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_DOWN))
            {
                nextLocation = getCharAtxy(pacmanX, pacmanY + 1);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(pacmanX, pacmanY);
                    pacmanY = pacmanY + 1;
                    printPacman(pacmanX, pacmanY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gameRunning = false;
            }

            if (gameRunning)
            {
                char nextLocation1 = getCharAtxy(g1 + 1, h1);
                if (nextLocation1 == ' ')
                {
                    erase1(g1, h1);
                    g1 = g1 + 1;
                    showGhost1(g1, h1);
                }

                char nextLocation2 = getCharAtxy(g2, h2 + 1);
                if (nextLocation2 == ' ')
                {
                    erase2(g2, h2);
                    h2 = h2 + 1;
                    showGhost2(g2, h2);
                }

                char nextLocation3 = getCharAtxy(g3, h3 + 1);
                if (nextLocation3 == ' ')
                {
                    erase3(g3, h3);
                    h3 = h3 + 1;
                    showGhost3(g3, h3);
                }

                if (nextLocation1 != ' ')
                {
                    gotoxy(g1, h1);
                    cout << " ";
                    g1 = 3;
                    h1 = 3;
                }

                if (nextLocation2 != ' ')
                {
                    gotoxy(g2, h2);
                    cout << " ";
                    g2 = 17;
                    h2 = 1;
                }
                if (nextLocation3 != ' ')
                {
                    gotoxy(g3, h3);
                    cout << " ";
                    g3 = 30;
                    h3 = 1;
                }

                if (nextLocation1 == 'P' || nextLocation2 == 'P' || nextLocation3 == 'P')
                {
                    gameRunning = false;
                    life--;
                }
            }

            Sleep(200);
            gotoxy(10, 10);
            cout << "Your Score = " << score;
            gotoxy(10, 12);
            cout << " Lifes: " << life;
        }
    }

    return 0;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void erase(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void showGhost1(int g, int h)
{
    gotoxy(g, h);
    cout << "G";
}

void showGhost2(int g, int h)
{
    gotoxy(g, h);
    cout << "G";
}

void showGhost3(int g, int h)
{
    gotoxy(g, h);
    cout << "G";
}

void printPacman(int x, int y)
{
    gotoxy(x, y);
    cout << "P";
}

void printMaze()
{
    string x;
    maz.open("maze.txt", ios::in);
    while (!maz.eof())
    {
        getline(maz, x);
        cout << x << endl;
    }
    maz.close();
}

void erase1(int g, int h)
{
    gotoxy(g, h);
    cout << " ";
    Sleep(40);
}

void erase2(int g, int h)
{
    gotoxy(g, h);
    cout << " ";
    Sleep(40);
}

void erase3(int g, int h)
{
    gotoxy(g, h);
    cout << " ";
    Sleep(40);
}
