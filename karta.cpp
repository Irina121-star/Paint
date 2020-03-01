#include "TXLib.h"

int main ()
{
    txCreateWindow (800, 600);
    txBegin();

    HDC mapImage = txLoadImage ("fon.bmp");
    HDC bacImage = txLoadImage ("pod_fon.bmp");

    int x = 0, y = 500, r = 10;
    int oldx = x, oldy = y;

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++)
        {
            txSetFillColor (TX_BLACK);
            txClear();

            if (!GetKeyState ('B'))
                txBitBlt (txDC (), 0, 0, 0, 0, bacImage);

            COLORREF color = txGetPixel (x, y);
            if (color == RGB(129, 192, 0))
                {
                x = oldx;
                y = oldy;
                }

            if (!GetKeyState ('A'))
                txBitBlt (txDC (), 0, 0, 0, 0, mapImage);

            txSetColor (TX_PINK, 5);
            txCircle (x, y, r);

            r = 10;
            if (color == RGB (255, 255, 255)) r = 10;
            if (color == RGB (129, 192, 0)) r = (t/10 % 2) * 20;


            oldx = x, oldy = y;
            if (GetAsyncKeyState (VK_RIGHT)) x = x + 5;
            if (GetAsyncKeyState (VK_LEFT)) x = x - 5;
            if (GetAsyncKeyState (VK_UP)) y = y - 5;
            if (GetAsyncKeyState (VK_DOWN)) y = y + 5;


        int st = (GetAsyncKeyState (VK_SHIFT)? 30 : 10);
        if (GetAsyncKeyState (VK_RIGHT)) x = x + st;
        if (GetAsyncKeyState (VK_LEFT))  x = x - st;
        if (GetAsyncKeyState (VK_UP))    y = y - st;
        if (GetAsyncKeyState (VK_DOWN))  y = y + st;



        txSleep();
        }
    return 0;
}


