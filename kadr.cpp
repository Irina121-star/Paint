#include "TXLib.h"
int main()

    {
    txCreateWindow (800, 600);

    HDC catImage = txLoadImage("Cat.bmp");

    const int frameX = 5;
    const int frameY = 3;

    int frameSizeX = txGetExtentX (catImage) / frameX;
    int frameSizeY = txGetExtentY (catImage) / frameX;

    int anim = 0;

    for ( int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++)
    {
        txBitBlt         (txDC(), 100, 100, frameSizeX, frameSizeY,
        catImage, (t% frameX) * frameSizeX, anim*frameSizeY);

        if (txGetAsyncKeyState ('1')) anim = 0;
        if (txGetAsyncKeyState ('2')) anim = 1;
        if (txGetAsyncKeyState ('3')) anim = 2;

        int ch = 0;
        if (_kbhit()) ch = _getch();
        txSleep();
        }

    txDeleteDC (catImage);
    return 0;
    }

