#include "TXLib.h"

void drawButton(int x, int y, const char* text)
{
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    Win32::RoundRect (txDC(), x+5, y+5, x+155, y+45, 30, 30);
    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    Win32::RoundRect (txDC(), x, y, x+150, y+40, 30, 30);
    txSetColor (TX_BLACK);
    txSelectFont("Times New Roman", 32);
    txDrawText(x, y, x+150, y+40, text);
}

int main()
{
    txCreateWindow (1200, 800);
    txDisableAutoPause();
    txTextCursor (false);

    HDC nos1 = txLoadImage ("Pictures/нос1.bmp");
    HDC nos2 = txLoadImage ("Pictures/нос2.bmp");
    HDC nos3 = txLoadImage ("Pictures/нос3.bmp");

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_YELLOW);
        txClear();

        drawButton(100, 30, "Овал лица");
        drawButton(260, 30, "Волосы");
        drawButton(420, 30, "Глаза");

        txTransparentBlt(txDC(), 50, 100, 50, 65, nos1, 0, 0, TX_WHITE);
        txTransparentBlt(txDC(), 50, 200, 50, 65, nos2, 0, 0, TX_WHITE);
        txTransparentBlt(txDC(), 50, 300, 50, 65, nos3, 0, 0, TX_WHITE);


        txSleep(50);
        txEnd();

    }

    txDeleteDC(nos1);
    txDeleteDC(nos2);
    txDeleteDC(nos3);


    return 0;
}

