

#include "TXLib.h"

void drawMaket()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (380, 20, 990, 60);
    txRectangle (50, 75, 1320, 125);
    txRectangle (50, 155, 440, 660);
    txRectangle (490, 155, 880, 660);
    txRectangle (930, 155, 1320, 660);
}

bool click(int x)
{
    return(txMouseButtons()==1 && txMouseX()>x && txMouseX()<x+390 && txMouseY()>155 && txMouseY()<505);

}
int main()
    {
    txCreateWindow (1370, 702);
    txTextCursor(false);

    HDC Huawei_Mate_Xs_2 = txLoadImage ("image/Mate Xs 2.bmp");
    HDC Xiaomi_15_ultra = txLoadImage ("image/15 ultra.bmp");
    HDC Samsung_Galaxy_Z_fold_6 = txLoadImage ("image/Z fold 6.bmp");
    int n_question = 1;
    int count_question = 1;

    while(n_question <= count_question)
    {
        txBegin();
        drawMaket();




        txSetColor (TX_LIGHTGREEN);
        txSelectFont ("Times", 45);
        txDrawText (380, 20, 990, 60, "Номер вопроса:1");
        txDrawText (50, 75, 1320, 125, "Какой из ниже представленных телефонов является смартфоном Huawei Mate XS2");
        txBitBlt (txDC(),  50, 155, 390, 505, Huawei_Mate_Xs_2);
        txBitBlt (txDC(), 490, 155, 390, 505, Xiaomi_15_ultra);
        txBitBlt (txDC(), 930, 155, 390, 505, Samsung_Galaxy_Z_fold_6);

        if(click(50))
        {
         n_question ++;
        }

        if(click(490))
        {
         n_question ++;
        }

        if(click(930))
        {
         n_question ++;
        }

       txEnd();
       txSleep(20);
    }

    txTextCursor (false);
    return 0;
    }

