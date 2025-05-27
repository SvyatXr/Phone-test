#include "TXLib.h"
#include <fstream>
using namespace std;

struct Forma
{
 string text_question;
 HDC picture_answer1;
 HDC picture_answer2;
 HDC picture_answer3;
 int n_right_answer;

 void draw()
 {
        txDrawText (50, 75, 1320, 125, text_question.c_str());
        txBitBlt (txDC(),  50, 155, 390, 505, picture_answer1);
        txBitBlt (txDC(), 490, 155, 390, 505, picture_answer2);
        txBitBlt (txDC(), 930, 155, 390, 505, picture_answer3);
 }
};
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
string getPart(string str, int *pos2)
{
 int pos1 = *pos2 + 1;
 *pos2 = str.find(",", pos1);
 string part = str.substr(pos1, *pos2-pos1);
 return part;
 }
int main()
{
setlocale(LC_ALL, "Russian");
    txCreateWindow (1370, 702);
    txTextCursor(false);
    Forma form_list[20];
   int i = 0;
   string str;
   ifstream file ("1.txt");
   while(file.good())
   {
    getline(file, str);
    int pos2 = -1;
    form_list[i].text_question = getPart(str, &pos2);
    form_list[i].picture_answer1 = txLoadImage (getPart(str, &pos2).c_str());
    form_list[i].picture_answer2 = txLoadImage (getPart(str, &pos2).c_str());
    form_list[i].picture_answer3 = txLoadImage (getPart(str, &pos2).c_str());
    form_list[i].n_right_answer = atoi(getPart(str, &pos2).c_str());
    i++;
   }
   file.close();

    Forma form;
    char stroka[25];
    int n_question = 1;
    int count_question = i;
    int score = 0;

    while(n_question <= count_question)
    {
        txSetFillColour(TX_BLACK);
        txClear();
        txBegin();
        drawMaket();

        txSetColor (TX_LIGHTGREEN);
        txSelectFont ("Times", 40);

        sprintf(stroka,"Вопрос №%d из %d", n_question, count_question);
        txDrawText (380, 20, 990, 60, stroka);

        form = form_list[n_question-1];
        form.draw();

        for(int i=0; i<count_question; i++)

        if(click(50))
        {
         if(form.n_right_answer == 1) score++;
         while(txMouseButtons() == 1)
         txSleep(100);
         n_question ++;
        }

        if(click(490))
        {
         if(form.n_right_answer == 2) score++;
         while(txMouseButtons() == 1)
         txSleep(100);
         n_question ++;
        }

        if(click(930))
        {
        if(form.n_right_answer == 3) score++;
         while(txMouseButtons() == 1)
         txSleep(100);
         n_question ++;
        }

       txEnd();
       txSleep(20);
    }
    txSetFillColour(TX_BLACK);
    txClear();

    sprintf(stroka,"Ваш результат %d из %d", score, count_question);
    txDrawText (0, 0, 1370, 702, stroka);

    return 0;
    }

