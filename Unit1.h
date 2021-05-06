//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *Ball;
        TTimer *TimerBall;
        TImage *PaddleLeft;
        TImage *PaddleRight;
        TTimer *TimerPaddleLeftUp;
        TTimer *TimerPaddleLeftDown;
        TTimer *TimerPaddleRightUp;
        TTimer *TimerPaddleRightDown;
        TButton *ButtonNewGame;
        TLabel *Label1;
        TButton *ButtonNextRound;
        TLabel *LabelNumberOfBounces;
        TLabel *LabelPunctation;
        TLabel *LabelPointInformation;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerPaddleLeftUpTimer(TObject *Sender);
        void __fastcall TimerPaddleLeftDownTimer(TObject *Sender);
        void __fastcall TimerPaddleRightDownTimer(TObject *Sender);
        void __fastcall TimerPaddleRightUpTimer(TObject *Sender);
        void __fastcall ButtonNewGameClick(TObject *Sender);
        void __fastcall ButtonNextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
