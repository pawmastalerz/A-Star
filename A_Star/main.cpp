#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int nodes[20][20] = {0};
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << nodes[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
