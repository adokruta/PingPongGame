//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8, y = -8; 
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        // bounce from above
        if(Ball->Top <= Background->Top) y = -y;
        // bounce from below
        if(Ball->Top + Ball->Height >= Background->Height) y =-y;
}
//---------------------------------------------------------------------------
