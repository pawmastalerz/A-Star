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
int currentX = 0;
int currentY = 0;
int parent[20][20];

void readNodeValuesFromFile()
{
    FILE *inputGrid;
    inputGrid = fopen("C:\\Users\\Home\\Desktop\\A gwiazdka\\Pawel_Mastalerz\\AStar\\A_Star\\bin\\Debug\\grid.txt", "r");
    if (inputGrid != NULL)
    {
        char gridNumericValue[3]; // No idea why there should be 3 instead of 2.
        for (int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                fgets(gridNumericValue, 3, inputGrid); // Same here. It works, so not that I'm complaining.
                nodeValues[i][j] = (gridNumericValue[0]);
            }
        }
    }
    else cout << "Input grid file missing" << endl;
    fclose(inputGrid);
}

void showNodeValues()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << nodeValues[i][j] << " ";
        }
        cout << endl;
    }
}

void calculateHValues()
{
    for (int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            hValues[i][j] = i + j;
        }
    }
}

void showHValues()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << hValues[i][j] << " ";
        }
        cout << endl;
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
            parent[i][j] = 99;
        }
    }
}

void closeCurrent()
{
    closedList[currentX][currentY] = true;
}

int main()
{
    readNodeValuesFromFile();
    startListsAndArrays();
    calculateHValues();

    closeCurrent();

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << closedList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
