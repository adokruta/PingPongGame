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
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) TimerPaddleRightUp->Enabled = true;
        if(Key == VK_DOWN) TimerPaddleRightDown->Enabled = true;
        if(Key == 0x41) TimerPaddleLeftUp->Enabled = true;
        if(Key ==0x5A) TimerPaddleLeftDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) TimerPaddleRightUp->Enabled = false;
        if(Key == VK_DOWN) TimerPaddleRightDown->Enabled = false;
        if(Key == 0x41) TimerPaddleLeftUp->Enabled = false;
        if(Key ==0x5A) TimerPaddleLeftDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerPaddleLeftUpTimer(TObject *Sender)
{
        if(PaddleLeft->Top > 10) PaddleLeft->Top -= 10;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerPaddleLeftDownTimer(TObject *Sender)
{
        if(PaddleLeft->Top + PaddleLeft->Height < Background->Height - 10) PaddleLeft->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerPaddleRightDownTimer(TObject *Sender)
{
        if(PaddleRight->Top + PaddleRight->Height < Background->Height - 10)PaddleRight->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerPaddleRightUpTimer(TObject *Sender)
{
        if(PaddleRight->Top > 10)PaddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
