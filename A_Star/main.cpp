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
bool openedList[20][20];
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

void calculateHValues()
{
    for (int i = 19; i >= 0; i--)
    {
        for(int j = 0; j < 20; j++)
        {
            hValues[j][i] = j + i;
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
            openedList[i][j] = false;
            parentX[i][j] = 999;
            parentY[i][j] = 999;
            gValues[i][j] = 999;
            fValues[i][j] = 999;
            calculateHValues();
        }
    }
    closedList[0][0] = true;
    gValues[0][0] = 0;
}

void closeNode(int x, int y)
{
    closedList[x][y] = true;
}

void openNode(int x, int y)
{
    openedList[x][y] = true;
}

void calculateGValue(int x, int y)
{
    gValues[x][y] = gValues[parentX[x][y]][parentY[x][y]] + 1;
}

void calculateFValue(int x, int y)
{
    fValues[x][y] = gValues[x][y] + hValues[x][y];
}

int goUp()
{
    if (
        ((currentY + 1) > 19) ||
        (closedList[currentX][currentY + 1] == true) ||
        (nodeValues[currentX][currentY + 1] == '5')) return 0;
    else if (openedList[currentX][currentY + 1] == true)
    {
        if ( (gValues[currentX][currentY] + 1) < gValues[currentX][currentY + 1] )
        {
            parentX[currentX][currentY + 1] = currentX;
            parentY[currentX][currentY + 1] = currentY;
            return 2;
        }
    }
    else
    {
        openNode(currentX, currentY + 1);
        parentX[currentX][currentY + 1] = currentX;
        parentY[currentX][currentY + 1] = currentY;
        calculateGValue(currentX, currentY + 1);
        calculateFValue(currentX, currentY + 1);
    }
}

int goDown()
{
    if (
        ((currentY - 1) < 0) ||
        (closedList[currentX][currentY - 1] == true) ||
        (nodeValues[currentX][currentY - 1] == '5')) return 0;
    else if (openedList[currentX][currentY - 1] == true)
    {
        if ( (gValues[currentX][currentY] + 1) < gValues[currentX][currentY - 1] )
        {
            parentX[currentX][currentY - 1] = currentX;
            parentY[currentX][currentY - 1] = currentY;
            return 2;
        }
    }
    else
    {
        openNode(currentX, currentY - 1);
        parentX[currentX][currentY - 1] = currentX;
        parentY[currentX][currentY - 1] = currentY;
        calculateGValue(currentX, currentY - 1);
        calculateFValue(currentX, currentY - 1);
    }
}

int goLeft()
{
    if (
        ((currentX - 1) < 0) ||
        (closedList[currentX - 1][currentY] == true) ||
        (nodeValues[currentX - 1][currentY] == '5')) return 0;
    else if (openedList[currentX - 1][currentY] == true)
    {
        if ( (gValues[currentX][currentY] + 1) < gValues[currentX - 1][currentY] )
        {
            parentX[currentX - 1][currentY] = currentX;
            parentY[currentX - 1][currentY] = currentY;
            return 2;
        }
    }
    else
    {
        openNode(currentX - 1, currentY);
        parentX[currentX - 1][currentY] = currentX;
        parentY[currentX - 1][currentY] = currentY;
        calculateGValue(currentX - 1, currentY);
        calculateFValue(currentX - 1, currentY);
    }
}

int goRight()
{
    if (
        ((currentX + 1) > 19) ||
        (closedList[currentX + 1][currentY] == true) ||
        (nodeValues[currentX + 1][currentY] == '5')) return 0;
    else if (openedList[currentX + 1][currentY] == true)
    {
        if ( (gValues[currentX][currentY] + 1) < gValues[currentX + 1][currentY] )
        {
            parentX[currentX + 1][currentY] = currentX;
            parentY[currentX + 1][currentY] = currentY;
            return 2;
        }
    }
    else
    {
        openNode(currentX + 1, currentY);
        parentX[currentX + 1][currentY] = currentX;
        parentY[currentX + 1][currentY] = currentY;
        calculateGValue(currentX + 1, currentY);
        calculateFValue(currentX + 1, currentY);
    }
}

int calculateLowestFXPos()
{
    int lowest = 9999;
    int lowestXPos = 9999;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if ((openedList[i][j] == true) && (fValues[i][j] < lowest))
            {
                lowest = fValues[i][j];
                lowestXPos = i;
            }
        }
    }
    return lowestXPos;
}

int calculateLowestFYPos()
{
    int lowest = 9999;
    int lowestYPos = 9999;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if ((openedList[i][j] == true) && (fValues[i][j] < lowest))
            {
                lowest = fValues[i][j];
                lowestYPos = j;
            }
        }
    }
    return lowestYPos;
}

int main()
{
    readNodeValuesFromFile();
    startListsAndArrays();


    closeNode(currentX, currentY);
    goUp();
    goDown();
    goLeft();
    goRight();

    currentX = calculateLowestFXPos();
    currentY = calculateLowestFYPos();

    closeNode(currentX, currentY); //8:06

    for (int i = 19; i >= 0; i--)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << fValues[j][i] << " ";
        }
        cout << endl;
    }

//    cout << calculateLowestFXPos() << endl;
//    cout << calculateLowestFYPos() << endl;

    return 0;
}
