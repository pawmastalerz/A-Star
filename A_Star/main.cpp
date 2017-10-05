//C++ A* ("A Star") algorithm.
//ALL RIGHTS RESERVED to Pawel Mastalerz
//University of Warmia and Mazury, Poland

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    char nodeValues[20][20];
    for (int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                nodeValues[i][j] = '0';
            }
        }

    FILE *inputGrid;
    inputGrid = fopen("C:\\Users\\Home\\Desktop\\A gwiazdka\\Pawel_Mastalerz\\AStar\\A_Star\\bin\\Debug\\grid.txt", "r");
    if (inputGrid != NULL)
    {
        char gridNumericValue[3]; // No idea why there should be 3 instead of 2.
        for (int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                fgets(gridNumericValue, 3, inputGrid); // Same here. It works, so not like I'm complaining.
                nodeValues[i][j] = (gridNumericValue[0]);
            }
        }
    }
    else cout << "Input grid file missing" << endl;
    fclose(inputGrid);

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << nodeValues[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
