

#include "TXLib.h"

void drawMaket()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (380, 20, 990, 60);
    txRectangle (50, 75, 1320, 125);
    txRectangle (50, 155, 440, 675);
    txRectangle (490, 155, 880, 675);
    txRectangle (930, 155, 1320, 675);
}
int main()
    {
    txCreateWindow (1370, 702);

   drawMaket();




    txSetColor (TX_LIGHTGREEN);
    txSelectFont ("Times", 45);
    txDrawText (380, 20, 990, 60, "Номер вопроса:1");
    txDrawText (50, 75, 1320, 125, "Какой из ниже представленных телефонов является смартфоном Huawei Mate XS2");






    txTextCursor (false);
    return 0;
    }

