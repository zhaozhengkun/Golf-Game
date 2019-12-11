
#include "Assignment.h"


int main(void)
{

    int WINDOW_SIZE_X = 1000, WINDOW_SIZE_Y = 600;
    int SelectedButton ;
    int ExitFlag = 1 ;

    CreatWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    do
    {
        cleardevice();
        system("cls");

        SelectedButton = ShowMainMenu(WINDOW_SIZE_X, WINDOW_SIZE_Y);//select a button


        switch(SelectedButton)
        {
        case 0:
            ChooseMode(WINDOW_SIZE_X, WINDOW_SIZE_Y);
            break;
        case 1:
            ShowRankingList(WINDOW_SIZE_X, WINDOW_SIZE_Y);
            break;
        case 2:
            SettingsMenu(WINDOW_SIZE_X, WINDOW_SIZE_Y);
            break;
        case 3:
            ExitFlag = 0;
            break;
        default:
            break;
        }
        fflush(stdin);

    }
    while(ExitFlag);

    closemouse();
    closekeyboard();
    midi_close();
    closegraph();
    return 0;
}
