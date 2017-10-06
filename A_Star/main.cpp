//C++ A* ("A Star") algorithm.
//ALL RIGHTS RESERVED to Pawel Mastalerz
//University of Warmia and Mazury, Poland

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;


char nodeValues[20][20];
int hValues[20][20];
bool openList[20][20];
bool closedList[20][20];
int currentX = 19;
int currentY = 1;
int parentX[20][20];
int parentY[20][20];

void readNodeValuesFromFile()
{
    FILE *inputGrid;
    inputGrid = fopen("C:\\Users\\Home\\Desktop\\A gwiazdka\\Pawel_Mastalerz\\AStar\\A_Star\\bin\\Debug\\grid.txt", "r");
    if (inputGrid != NULL)
    {
        char gridNumericValue[3]; // No idea why there should be 3 instead of 2.
        for (int i = 19; i >= 0; i--)
        {
            for(int j = 0; j < 20; j++)
            {
                fgets(gridNumericValue, 3, inputGrid); // Same here. It works, so not that I'm complaining.
                nodeValues[j][i] = (gridNumericValue[0]);
            }
        }
    }
    else cout << "Input grid file missing" << endl;
    fclose(inputGrid);
}

void calculateHValues()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            hValues[i][j] = i + j;
        }
    }
}

void startListsAndArrays()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            closedList[i][j] = false;
        }
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            openList[i][j] = false;
        }
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            parentX[i][j] = 99;
            parentY[i][j] = 99;
        }
    }
}

void closeCurrent()
{
    closedList[currentX][currentY] = true;
}

int goUp()
{
    if (((currentY + 1) > 19) || (closedList[currentX][currentY + 1] == true)) return 0;
    else
    {
        parentX[currentX][currentY + 1] = currentX;
        parentY[currentX][currentY + 1] = currentY;
    }
}

int goDown()
{
    if (((currentY - 1) < 0) || (closedList[currentX][currentY - 1] == true)) return 0;
    else
    {
        parentX[currentX][currentY - 1] = currentX;
        parentY[currentX][currentY - 1] = currentY;
    }
}

int goLeft()
{
    if (((currentX - 1) < 0) || (closedList[currentX - 1][currentY] == true)) return 0;
    else
    {
        parentX[currentX - 1][currentY] = currentX;
        parentY[currentX - 1][currentY] = currentY;
    }
}

int goRight()
{
    if (((currentX + 1) > 19) || (closedList[currentX + 1][currentY] == true)) return 0;
    else
    {
        parentX[currentX + 1][currentY] = currentX;
        parentY[currentX + 1][currentY] = currentY;
    }
}

int main()
{
    readNodeValuesFromFile();
    startListsAndArrays();
    calculateHValues();

    closeCurrent();
    goUp();
    goDown();
    goLeft();
    goRight();

    for (int i = 19; i >= 0; i--)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << parentY[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
