#include "TXLib.h"
int main()

    {
    txCreateWindow (800, 600);

    HDC catImage = txLoadImage("Cat.bmp");

    int x = 0, y = 0;
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), x, y, 0, 0, catImage);

        if (GetAsyncKeyState (VK_RIGHT)) x++;
        if (GetAsyncKeyState (VK_LEFT)) x--;
        if (GetAsyncKeyState (VK_UP)) y--;
        if (GetAsyncKeyState (VK_DOWN)) y++;
        txSleep();
        }

    txDeleteDC (catImage);

    return 0;
    }

