

#include "Assignment.h"

void ChooseMode(int X,int Y)
{

    update_display();

    system("cls");
    printf("\nUse the arrow keys to select a mode. \n");
    printf("In practice mode there are an unlimited number of hitting opportunities but no scores are recorded.\n\n");
    printf("Start your challenge!\n\n");

    int SelectedButton = 0 ;
    int BackFlag = 1;

    do
    {
        cleardevice();
        SelectedButton = ShowMode(X, Y);
        switch(SelectedButton)
        {
        case 0:
            SetMode = 0;//practice mode
            StartGame(X, Y);
            break;
        case 1:
            SetMode = 1;//challenge mode
            StartGame(X, Y);
            break;
        case 2:
            BackFlag = 0;
            break;
        }
    }
    while(BackFlag);

}

int  ShowMode(int X, int Y)
{

    Button Practice, Challenge, Back;
    int PraClr, ChaClr, BackClr;

    int Flag = 0,input;


    PraClr = SleClr;
    ChaClr = ComClr;
    BackClr = ComClr;


    outtextxy(X / 2 - 50, Y / 10, "GAME MODE" );

    Practice.PosX = X / 2 ;
    Challenge.PosX = X / 2 ;
    Back.PosX =  X / 2 ;

    Practice.PosY = Y / 4 ;
    Challenge.PosY = Y  / 2 ;
    Back.PosY = Y * 3 / 4 ;

    strcpy(Practice.Text, "Practice");
    strcpy(Challenge.Text, "Challenge");
    strcpy(Back.Text, "Back");

    do
    {
        DrawMenuButton(Practice,PraClr);
        DrawMenuButton(Challenge,ChaClr);
        DrawMenuButton(Back,BackClr);

        update_display();
        wait_for_event();
        if(event_key_down())//if key down
        {
            input = event.keyboard.keycode;



            if (input == 67)//judge which key is down
                break;

            switch(input)
            {
            case 84:
                Flag--;
                break;
            case 85:
                Flag++;
                break;
            case 82:
                Flag--;
                break;
            case 83:
                Flag++;
                break;
            default:
                printf("You have pressed invalid key\n");
            }
            Flag = Flag % 3;
            if (Flag < 0)
                Flag += 3;

            switch(Flag)
            {
            case 0 :
                PraClr = SleClr;
                ChaClr = ComClr;
                BackClr = ComClr;
                break;
            case 1 :
                ChaClr = SleClr;
                PraClr = ComClr;
                BackClr = ComClr;
                break;
            case 2 :
                ChaClr = ComClr;
                PraClr = ComClr;
                BackClr = SleClr;
                break;
            }


        }

    }
    while(input != 67);


    return Flag ;



}
void WaitForClick(void)
{
    while(1)
    {
        wait_for_event();

        if (event_close_display())
            break;
        else if (event_mouse_button_down())
        {
            if (event_mouse_left_button_down())
                break;

            else if (event_mouse_right_button_down())
                GameExitFlag = 0 ;
            break;
        }

    }
}

