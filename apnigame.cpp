#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void eraseBullet(int x, int y);
void moveBullet(int &bulletX, int &bulletY, bool &bulletActive);
void fireBullet(int &bulletX, int &bulletY, bool &bulletActive, int x, int y);
void checkBulletCollision(int bulletX, int bulletY, int &enemyX, int &enemyY);

void erase1(int g, int h);
void erase2(int g, int h);
void erase3(int g, int h);
void printMaze();
void gotoxy(int x, int y);
void showEnemy1(int g, int h);
void showEnemy2(int g, int h);
void showEnemy3(int g, int h);
void erase(int x, int y);
void printMan(int x, int y);
char getCharAtxy(short int x, short int y);

fstream maze;

int main()
{
    int life = 3;
    int score = 0;
    for (int i = 1; i <= 3; i++)
    {

        system("color 06");
        int manX = 4;
        int manY = 4;
        int g1 = 4;
        int h1 = 3;
        int g2 = 17;
        int h2 = 5;
        int g3 = 30;
        int h3 = 6;
        int bulletX = 0;
        int bulletY = 0;
        bool bulletActive = false;
        char nextLocation;
        bool gameRunning = true;
        bool gameWon = false;

        system("cls");
        printMaze();
        printMan(manX, manY);
        showEnemy1(g1, h1);
        showEnemy2(g2, h2);
        showEnemy3(g3, h3);

        while (gameRunning)
        {
            if (GetAsyncKeyState(VK_LEFT))
            {
                nextLocation = getCharAtxy(manX - 1, manY);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(manX, manY);
                    manX = manX - 1;
                    printMan(manX, manY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_RIGHT))
            {
                nextLocation = getCharAtxy(manX + 1, manY);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(manX, manY);
                    manX = manX + 1;
                    printMan(manX, manY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_UP))
            {
                nextLocation = getCharAtxy(manX, manY - 1);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(manX, manY);
                    manY = manY - 1;
                    printMan(manX, manY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_DOWN))
            {
                nextLocation = getCharAtxy(manX, manY + 1);
                if (nextLocation == ' ' || nextLocation == '.')
                {
                    erase(manX, manY);
                    manY = manY + 1;
                    printMan(manX, manY);
                    if (nextLocation == '.')
                    {
                        score = score + 1;
                    }
                }
            }

            if (GetAsyncKeyState(VK_SPACE))
            {
                if (!bulletActive)
                {
                    fireBullet(bulletX, bulletY, bulletActive, manX, manY);
                }
            }

            moveBullet(bulletX, bulletY, bulletActive);
            checkBulletCollision(bulletX, bulletY, g1, h1);
            checkBulletCollision(bulletX, bulletY, g2, h2);
            checkBulletCollision(bulletX, bulletY, g3, h3);

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
                    showEnemy1(g1, h1);
                }

                char nextLocation2 = getCharAtxy(g2, h2 + 1);
                if (nextLocation2 == ' ')
                {
                    erase2(g2, h2);
                    h2 = h2 + 1;
                    showEnemy2(g2, h2);
                }

                char nextLocation3 = getCharAtxy(g3, h3 + 1);
                if (nextLocation3 == ' ')
                {
                    erase3(g3, h3);
                    h3 = h3 + 1;
                    showEnemy3(g3, h3);
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

                if (nextLocation1 == 'M' || nextLocation2 == 'M' || nextLocation3 == 'M')
                {
                    gameRunning = false;
                    life--;
                }

                if (score >= 26) // Adjust the winning score as needed
                {
                    gameWon = true;
                    gameRunning = false;
                }
            }

            Sleep(200);
            gotoxy(10, 10);
            cout << "Your Score = " << score;
            gotoxy(10, 12);
            cout << " Lifes: " << life;
        }
        if (gameWon)
        {
            gotoxy(10, 15);
            cout << "Congratulations! You won!";
        }
        else
        {
            gotoxy(10, 15);
            cout << "Game Over! You ran out of lives.";
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

void showEnemy1(int g, int h)
{
    gotoxy(g, h);
    cout << "E";
}

void showEnemy2(int g, int h)
{
    gotoxy(g, h);
    cout << "E";
}

void showEnemy3(int g, int h)
{
    gotoxy(g, h);
    cout << "E";
}

void printMan(int x, int y)
{
    gotoxy(x, y);
    cout << "M";
}

void printMaze()
{
    string x;
    maze.open("mymaze.txt", ios::in);
    while (!maze.eof())
    {
        getline(maze, x);
        cout << x << endl;
    }
    maze.close();
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

void checkBulletCollision(int bulletX, int bulletY, int &enemyX, int &enemyY)
{
    if (bulletX == enemyX && bulletY == enemyY)
    {
        // Handle collision logic (e.g. reset ghost position)
        enemyX = 3; // Reset ghost X position
        enemyY = 3; // Reset ghost Y position
    }
}

void fireBullet(int &bulletX, int &bulletY, bool &bulletActive, int x, int y)
{
    bulletX = x + 1; // Set the initial position to the right of the player
    bulletY = y;
    bulletActive = true;
    gotoxy(bulletX, bulletY);
    cout << "^";
}


void moveBullet(int &bulletX, int &bulletY, bool &bulletActive)
{
    if (bulletActive)
    {
        eraseBullet(bulletX, bulletY);

        // Check if the next position is a space (' ') before moving the bullet
        char nextLocation = getCharAtxy(bulletX + 1, bulletY);
        if (nextLocation == ' ')
        {
            bulletX++; // Move the bullet to the right
            gotoxy(bulletX, bulletY);
            cout << "^";
        }
        else
        {
            bulletActive = false; // Bullet hit a wall, deactivate it
        }

        // Adjust the limit based on the maze width
        if (bulletX >= 79)
        {
            bulletActive = false;
        }
    }
}



void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}