
#include "Assignment.h"

void display_welcome(void)
{
    printf("\nWelcome to stick-man Golf! \nUse the arrow keys to select the button and confirm with the Enter key.");
}


void CreatWindow(int X, int Y)
{


    initwindow(X, Y);
    ComClr = BLACK;
    SleClr = BROWN;
    BallClr = WHITE;

    initfont();
    midi_start();
    program_change(1,116);//in hole
    program_change(2,125);//cheers

    //setup mouse and keyboard
    initmouse();
    initkeyboard();
    create_event_queue();
    reg_display_events();
    reg_mouse_events();
    reg_keyboard_events();
    cleardevice();

}

void DrawMenuButton(Button B, int Color)
{
    filled_rectangle(B.PosX - 83, B.PosY - 43,B.PosX + 83,B.PosY + 43, WHITE);
    filled_rectangle(B.PosX - 80, B.PosY - 40,B.PosX + 80,B.PosY + 40, Color);
    outtextxy(B.PosX - 30, B.PosY - 10, B.Text);
    update_display();
}

int ShowMainMenu(int X, int Y)
{

    Button Mode, RankList, Set, Exit;
    int ModeClr, ListClr, SetClr, ExClr;
    int Flag = 0,input;


    ModeClr = SleClr;
    ListClr = ComClr;
    SetClr = ComClr;
    ExClr = ComClr;


    cleardevice();

    printf("\n\n\n                  .,]O@@@@@@@`           .]/@@@@@@OO`.        /@@@@@@O.       .]O@@@@@O].          \n");
    printf("                ./@@@@@@@@@@@^        ./@@@@@@@@@@@@@@@`.     O@@@@@@O.    .,@@@@@@@@@@@@O.        \n");
    printf("              ./@@@@@@@@@@@@@^      ./@@@@@@@@@@@@@@@@@@@`    O@@@@@@O.   ./@@@@@@@@@@@@@`.        \n");
    printf("             .@@@@@@@@@@@@@@O`     ,@@@@@@@@@@@@@@@@@@@@@@O   O@@@@@@O.  .=@@@@@@@@@@@/.           \n");
    printf("            .O@@@@@@@/.           .O@@@@@@@/.     ,@@@@@@@@^  O@@@@@@O.  .O@@@@@@^                 \n");
    printf("            .@@@@@@@O.  ,OOOOOO`. ,@@@@@@@/        .@@@@@@@O. O@@@@@@O.  .O@@@@@@^                 \n");
    printf("            .@@@@@@@^.  =@@@@@@@O.=@@@@@@@^        .O@@@@@@@. O@@@@@@O.  .O@@@@@@@@@.              \n");
    printf("            .O@@@@@@@`  =@@@@@@@@^.@@@@@@@@`      ./@@@@@@@/. O@@@@@@O.  .O@@@@@@@@O.              \n");
    printf("            .,@@@@@@@@@]/[O@@@@@@^.=@@@@@@@@@O`.,/@@@@@@@@@.  O@@@@@@@  `.O@@@@@@@@@.              \n");
    printf("             .,@@@@@@@@@@@@@@@@@@` .,@@@@@@@@@@@@@@@@@@@@O.   =@@@@@@@@@O.O@@@@@@/[`.              \n");
    printf("               .O@@@@@@@@@@@@@@O`    .O@@@@@@@@@@@@@@@@@`.    .=@@@@@@@@O.O@@@@@@^                 \n");
    printf("                 .,O@@@@@@@@@/`.       .,O@@@@@@@@@@@/.         .O@@@@@@O.O@@@@@@^                 \n\n\n");
    display_welcome();


    outtextxy(X / 2 - 50, Y / 7, "Stick-man Golf" );
    outtextxy(X -250, Y - 40, "Game author: Y3864254" );

    Mode.PosX = X / 3 ;
    RankList.PosX = X / 3 ;
    Set.PosX = X * 2 / 3 ;
    Exit.PosX = X * 2 / 3 ;

    Mode.PosY = Y / 3 ;
    RankList.PosY = Y * 2 / 3 ;
    Set.PosY = Y / 3 ;
    Exit.PosY = Y * 2 / 3 ;

    strcpy(Mode.Text, "Game Mode");
    strcpy(RankList.Text, "Top 10");
    strcpy(Set.Text, "Setting");
    strcpy(Exit.Text, "Exit");

    do
    {
        DrawMenuButton(Mode,ModeClr);
        DrawMenuButton(RankList,ListClr);
        DrawMenuButton(Set,SetClr);
        DrawMenuButton(Exit,ExClr);

        update_display();
        wait_for_event();
        if(event_key_down())
        {
            input = event.keyboard.keycode;

            if (input == 67)
                break;

            switch(input)
            {
            case 84://up arrow
                Flag--;
                break;
            case 85://down arrow
                Flag++;
                break;
            case 82://left arrow
                Flag-=2;
                break;
            case 83:// right arrow
                Flag+=2;
                break;
            default:
                printf("Oops,An invalid key is input!\n");
            }
            Flag = Flag % 4;
            if (Flag < 0)
                Flag += 4;

            switch(Flag)//choose button by change the color
            {
            case 0 :
                ModeClr = SleClr;
                ListClr = ComClr;
                SetClr = ComClr;
                ExClr = ComClr;
                break;
            case 1 :
                ListClr = SleClr;
                ModeClr = ComClr;
                SetClr = ComClr;
                ExClr = ComClr;
                break;
            case 2 :
                SetClr = SleClr;
                ModeClr = ComClr;
                ListClr = ComClr;
                ExClr = ComClr;
                break;
            case 3 :
                ExClr = SleClr;
                ModeClr = ComClr;
                ListClr = ComClr;
                SetClr = ComClr;
                break;
            }


        }

    }
    while(input != 67);

    return Flag ;

}

