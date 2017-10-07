//C++ A* ("A Star") algorithm.
//ALL RIGHTS RESERVED to Pawel Mastalerz
//University of Warmia and Mazury, Poland

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;


char nodeValues[20][20];
int hValues[20][20];
int gValues[20][20];
int fValues[20][20];
bool openList[20][20];
bool closedList[20][20];
int currentX = 0;
int currentY = 0;
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

void startListsAndArrays()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            closedList[i][j] = false;
            openList[i][j] = false;
            parentX[i][j] = 999;
            parentY[i][j] = 999;
            hValues[i][j] = 999;
            gValues[i][j] = 999;
            fValues[i][j] = 999;
        }
    }
    closedList[0][0] = true;
    gValues[0][0] = 0;
}

void closeCurrent()
{
    closedList[currentX][currentY] = true;
}

void calculateGValue(int x, int y)
{
    gValues[x][y] = gValues[parentX[x][y]][parentY[x][y]] + 1;
}

int goUp()
{
    if (((currentY + 1) > 19) || (closedList[currentX][currentY + 1] == true)) return 0;
    else
    {
        parentX[currentX][currentY + 1] = currentX;
        parentY[currentX][currentY + 1] = currentY;
        calculateGValue(currentX, currentY + 1);
    }
}

int goDown()
{
    if (((currentY - 1) < 0) || (closedList[currentX][currentY - 1] == true)) return 0;
    else
    {
        parentX[currentX][currentY - 1] = currentX;
        parentY[currentX][currentY - 1] = currentY;
        calculateGValue(currentX, currentY - 1);
    }
}

int goLeft()
{
    if (((currentX - 1) < 0) || (closedList[currentX - 1][currentY] == true)) return 0;
    else
    {
        parentX[currentX - 1][currentY] = currentX;
        parentY[currentX - 1][currentY] = currentY;
        calculateGValue(currentX - 1, currentY);
    }
}

int goRight()
{
    if (((currentX + 1) > 19) || (closedList[currentX + 1][currentY] == true)) return 0;
    else
    {
        parentX[currentX + 1][currentY] = currentX;
        parentY[currentX + 1][currentY] = currentY;
        calculateGValue(currentX + 1, currentY);
    }
}

int main()
{
    readNodeValuesFromFile();
    startListsAndArrays();

    closeCurrent();
    goUp();
    goDown();
    goLeft();
    goRight();

    for (int i = 19; i >= 0; i--)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << gValues[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
