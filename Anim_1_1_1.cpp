#include "TXLib.h"
int main()

    {
    txCreateWindow (800, 600);

    HDC tabImage = txLoadImage("Cat.bmp");
    HDC frontImage = txLoadImage("zelen.bmp");

    int x = 0, y = 0;
    while (!(GetAsyncKeyState (VK_ESCAPE)))
        {
        txBitBlt         (txDC(), 0, 0, 0, 0, tabImage);
        txTransparentBlt (txDC(), x, y, 0, 0, frontImage, 0, 0, RGB (255, 0, 255));

        if (GetAsyncKeyState (VK_RIGHT)) x++;
        if (GetAsyncKeyState (VK_LEFT)) x--;
        if (GetAsyncKeyState (VK_UP)) y--;
        if (GetAsyncKeyState (VK_DOWN)) y++;

        txSleep();
        }

    txDeleteDC (tabImage);
    txDeleteDC (frontImage);
    return 0;
    }

