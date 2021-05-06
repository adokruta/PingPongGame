//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8, y = -8;
int changeDirection = 4, changeInterval = 4;
int numberOfBounces = 0, gameSpeed = 20;
int leftPlayerPoints = 0, rightPlayerPoints = 0;
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
        TimerBall->Interval = gameSpeed;

        AnsiString nrOfBounces, leftPP, rightPP;

        // bounce from above
        if(Ball->Top <= Background->Top) y = -y;
        // bounce from below
        if(Ball->Top + Ball->Height >= Background->Height) y =-y;
        // crush conditions
        if(Ball->Left + Ball->Width <= PaddleLeft->Left ||
           Ball->Left >= PaddleRight->Left+PaddleRight->Width)
        {
                if( Ball->Left + Ball->Width <= PaddleLeft->Left)
                {
                        rightPlayerPoints++;
                        LabelPointInformation->Caption = "Punkt dla gracza prawego >";
                }
                else
                {
                        leftPlayerPoints++;
                        LabelPointInformation->Caption = "< Punkt dla gracza lewego";
                }

                TimerBall->Enabled = false;
                Ball->Visible = false;
                ButtonNewGame->Visible = true;
                ButtonNextRound->Visible = true;

                nrOfBounces = IntToStr(numberOfBounces);
                leftPP = IntToStr(leftPlayerPoints);
                rightPP = IntToStr(rightPlayerPoints);

                LabelNumberOfBounces->Caption = "Liczba odbic: " + nrOfBounces;
                LabelNumberOfBounces->Visible = true;

                LabelPunctation->Caption = leftPP + ":" + rightPP;
                LabelPunctation->Visible = true;

                LabelPointInformation->Visible = true;

        }
        //bounce from left paddle
        else if(Ball->Top + Ball->Height/2 >= PaddleLeft->Top &&
                Ball->Top + Ball->Height/2 <= PaddleLeft->Top + PaddleLeft->Height &&
                Ball->Left <= PaddleLeft->Left + PaddleLeft->Width)
        {
                if(x < 0) x = 8;
                TimerBall->Interval = gameSpeed;

                if( Ball->Top + Ball->Height/2 >= PaddleLeft->Top + 60 &&
                    Ball->Top + Ball->Height/2 <= PaddleLeft->Top + 90)
                    {
                        x += changeDirection;
                        TimerBall->Interval -= changeInterval;
                    }

                numberOfBounces ++;
                if(numberOfBounces%5 == 0 && TimerBall->Interval > 1 ) gameSpeed --;
        }
        // bounce from right paddle
        else if(Ball->Top + Ball->Height/2 >= PaddleRight->Top &&
                 Ball->Top + Ball->Height/2 <= PaddleRight->Top + PaddleRight->Height &&
                 Ball->Left + Ball->Width >= PaddleRight->Left)
        {
                if(x > 0) x = -8;
                TimerBall->Interval = gameSpeed;

                if( Ball->Top + Ball->Height/2 >= PaddleRight->Top + 60 &&
                    Ball->Top + Ball->Height/2 <= PaddleRight->Top + 90)
                    {
                        x -= changeDirection;
                        TimerBall->Interval -= changeInterval;
                    }

                 numberOfBounces ++;
                 if(numberOfBounces%5 == 0 && TimerBall->Interval > 1 ) gameSpeed --;
        }





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
void __fastcall TForm1::ButtonNewGameClick(TObject *Sender)
{
         x = -8;
         y = -8;
         Ball->Left = 700;
         Ball->Top = 300;
         Ball->Visible = true;
         TimerBall->Enabled = true;
         ButtonNewGame->Visible = false;
         ButtonNextRound->Visible = false;
         Label1->Visible = false;
         LabelNumberOfBounces->Visible = false;
         LabelPunctation->Visible = false;
         LabelPointInformation->Visible = false;

         leftPlayerPoints = 0;
         rightPlayerPoints = 0;
         numberOfBounces = 0;
         gameSpeed = 20;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNextRoundClick(TObject *Sender)
{
         x = -8;
         y = -8;
         Ball->Left = 700;
         Ball->Top = 300;
         Ball->Visible = true;
         TimerBall->Enabled = true;
         ButtonNewGame->Visible = false;
         ButtonNextRound->Visible = false;
         Label1->Visible = false;
         LabelNumberOfBounces->Visible = false;
         LabelPunctation->Visible = false;
         LabelPointInformation->Visible = false;

         numberOfBounces = 0;
         gameSpeed = 20;
}
//---------------------------------------------------------------------------

