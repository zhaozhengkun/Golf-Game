
#include "Assignment.h"

void SettingsMenu(int  X, int Y)
{

    update_display();

    system("cls");
    printf("\nUse the arrow keys to select buttons. \n");

    int SelectedButton = 0 ;
    int BackFlag = 1;

    do
    {
        cleardevice();
        SelectedButton = ShowSettingMenu(X, Y);
        switch(SelectedButton)//go to inside menu
        {
        case 0:
            SetBallColor(X,Y);
            break;
        case 1:
            SetButtonColor(X,Y);
            break;
        case 2:
            BackFlag = 0;
            break;
        }
    }
    while(BackFlag);


};

int ShowSettingMenu(int X, int Y)
{
    Button BallColor, ButtonColor, Back;
    int BallClr, BtnClr, BackClr;

    int Flag = 0,input;


    BallClr = SleClr;
    BtnClr = ComClr;
    BackClr = ComClr;


    outtextxy(X / 2 - 50, Y / 10, "SETTINGS" );

    BallColor.PosX = X / 2 ;
    ButtonColor.PosX = X / 2 ;
    Back.PosX =  X / 2 ;

    BallColor.PosY = Y / 4 ;
    ButtonColor.PosY = Y  / 2 ;
    Back.PosY = Y * 3 / 4 ;

    strcpy(BallColor.Text, "BallType");
    strcpy(ButtonColor.Text, "ButtonType");
    strcpy(Back.Text, "Back");

    do
    {
        DrawMenuButton(BallColor,BallClr);
        DrawMenuButton(ButtonColor,BtnClr);
        DrawMenuButton(Back,BackClr);

        update_display();
        wait_for_event();
        if(event_key_down())
        {
            input = event.keyboard.keycode;

            if (input == 67)//enter
                break;

            switch(input)
            {
            case 84://up
                Flag--;
                break;
            case 85://down
                Flag++;
                break;
            case 82://left
                Flag--;
                break;
            case 83://right
                Flag++;
                break;
            default:
                printf("You have pressed invalid key\n");
            }
            Flag = Flag % 3;
            if (Flag < 0)
                Flag += 3;

            switch(Flag)//change the button color
            {
            case 0 :
                BallClr = SleClr;
                BtnClr = ComClr;
                BackClr = ComClr;
                break;
            case 1 :
                BtnClr = SleClr;
                BallClr = ComClr;
                BackClr = ComClr;
                break;
            case 2 :
                BtnClr = ComClr;
                BallClr = ComClr;
                BackClr = SleClr;
                break;
            }


        }

    }
    while(input != 67);//return when press enter

    return Flag ;


}

void SetBallColor(int X,int Y)
{
    cleardevice();

    Button White, Red, Gray, Brown;
    int WhiteClr, RedClr, GrayClr, BrownClr;
    int Flag = 0,input;


    WhiteClr = WHITE;
    RedClr = ComClr;
    GrayClr = ComClr;
    BrownClr = ComClr;

    cleardevice();

    outtextxy(X / 2 - 50, Y / 7, "Style of Ball" );

    White.PosX = X / 3 ;
    Red.PosX = X / 3 ;
    Gray.PosX = X * 2 / 3 ;
    Brown.PosX = X * 2 / 3 ;

    White.PosY = Y / 3 ;
    Red.PosY = Y * 2 / 3 ;
    Gray.PosY = Y / 3 ;
    Brown.PosY = Y * 2 / 3 ;

    strcpy(White.Text, "White");
    strcpy(Red.Text, "Red");
    strcpy(Gray.Text, "Gray");
    strcpy(Brown.Text, "Brown");

    do
    {
        DrawMenuButton(White,WhiteClr);
        DrawMenuButton(Red,RedClr);
        DrawMenuButton(Gray,GrayClr);
        DrawMenuButton(Brown,BrownClr);

        update_display();
        wait_for_event();
        if(event_key_down())
        {
            input = event.keyboard.keycode;

            if (input == 67)//enter
                break;

            switch(input)
            {
            case 84://arrow keys
                Flag--;
                break;
            case 85:
                Flag++;
                break;
            case 82:
                Flag-=2;
                break;
            case 83:
                Flag+=2;
                break;
            default:
                printf("Oops,An invalid key is input!\n");
            }
            Flag = Flag % 4;
            if (Flag < 0)
                Flag += 4;

            switch(Flag)
            {
            case 0 :
                WhiteClr = WHITE;
                RedClr = ComClr;
                GrayClr = ComClr;
                BrownClr = ComClr;
                break;
            case 1 :
                RedClr = LIGHTRED;
                WhiteClr = ComClr;
                GrayClr = ComClr;
                BrownClr = ComClr;
                break;
            case 2 :
                GrayClr = LIGHTGRAY;
                WhiteClr = ComClr;
                RedClr = ComClr;
                BrownClr = ComClr;
                break;
            case 3 :
                BrownClr = BROWN;
                WhiteClr = ComClr;
                RedClr = ComClr;
                GrayClr = ComClr;
                break;
            }


        }

    }
    while(input != 67);

    switch(Flag)
    {
    case 0 :
        BallClr = WHITE ;
        break;
    case 1 :
        BallClr = LIGHTRED ;
        break;
    case 2 :
        BallClr = LIGHTGRAY ;
        break;
    case 3 :
        BallClr = BROWN ;
        break;
    }

}


void SetButtonColor(int X,int Y)
{
    cleardevice();

    Button Blue, Red, Gray, Brown;
    int BlueClr, RedClr, GrayClr, BrownClr;
    int Flag = 0,input;

    BlueClr = BLUE;
    RedClr = ComClr;
    GrayClr = ComClr;
    BrownClr = ComClr;

    cleardevice();

    outtextxy(X / 2 - 50, Y / 7, "Style of Button" );

    Blue.PosX = X / 3 ;
    Red.PosX = X / 3 ;
    Gray.PosX = X * 2 / 3 ;
    Brown.PosX = X * 2 / 3 ;

    Blue.PosY = Y / 3 ;
    Red.PosY = Y * 2 / 3 ;
    Gray.PosY = Y / 3 ;
    Brown.PosY = Y * 2 / 3 ;

    strcpy(Blue.Text, "Blue");
    strcpy(Red.Text, "Red");
    strcpy(Gray.Text, "Gray");
    strcpy(Brown.Text, "Brown");

    do
    {
        DrawMenuButton(Blue,BlueClr);
        DrawMenuButton(Red,RedClr);
        DrawMenuButton(Gray,GrayClr);
        DrawMenuButton(Brown,BrownClr);

        update_display();
        wait_for_event();
        if(event_key_down())
        {
            input = event.keyboard.keycode;


            if (input == 67)//enter
                break;

            switch(input)
            {
            case 84://arrow keys
                Flag--;
                break;
            case 85:
                Flag++;
                break;
            case 82:
                Flag-=2;
                break;
            case 83:
                Flag+=2;
                break;
            default:
                printf("Oops,An invalid key is input!\n");
            }
            Flag = Flag % 4;
            if (Flag < 0)
                Flag += 4;

            switch(Flag)//change button color
            {
            case 0 :
                BlueClr = BLUE;
                RedClr = ComClr;
                GrayClr = ComClr;
                BrownClr = ComClr;
                break;
            case 1 :
                RedClr = RED;
                BlueClr = ComClr;
                GrayClr = ComClr;
                BrownClr = ComClr;
                break;
            case 2 :
                GrayClr = DARKGRAY;
                BlueClr = ComClr;
                RedClr = ComClr;
                BrownClr = ComClr;
                break;
            case 3 :
                BrownClr = BROWN;
                BlueClr = ComClr;
                RedClr = ComClr;
                GrayClr = ComClr;
                break;
            }


        }

    }
    while(input != 67);

    switch(Flag)//set color
    {
    case 0 :
        SleClr = BLUE ;
        break;
    case 1 :
        SleClr = RED ;
        break;
    case 2 :
        SleClr = DARKGRAY ;
        break;
    case 3 :
        SleClr = BROWN ;
        break;
    }

}
