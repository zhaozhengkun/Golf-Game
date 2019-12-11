
#include "Assignment.h"


void ShowRankingList(int X, int Y)
{
    system("cls");
    printf("\n\nUse Enter key to close ranking list.\n");

    ReadRankList();
    PrintRankList(X, Y);

}

void ReadRankList(void)
{
    int i;
    FILE *RankFp;

    RankFp = fopen("List.txt", "r");
    if(RankFp)
    {
        while (!feof(RankFp))//if there is a list, read it
        {
            for(i=0; i<10; i++)
                fscanf(RankFp, "%d%s", &top[i].score,top[i].name);

        }
        fclose(RankFp);
    }
    else//if there is not a list , create one
    {

        fclose(RankFp);
        CreatNewList();
    }


}

void CreatNewList(void)
{
    FILE *RankFp = fopen("List.txt", "w");
    int i;

    top[0].score = 50;//give the original scores
    top[1].score = 40;
    top[2].score = 35;
    top[3].score = 20;
    top[4].score = 19;
    top[5].score = 19;
    top[6].score = 17;
    top[7].score = 15;
    top[8].score = 13;
    top[9].score = 10;

    strcpy(top[0].name, "Emily");//give the original names
    strcpy(top[1].name, "Monica");
    strcpy(top[2].name, "Lisa");
    strcpy(top[3].name, "John");
    strcpy(top[4].name, "Cody");
    strcpy(top[5].name, "Dennis");
    strcpy(top[6].name, "Jack");
    strcpy(top[7].name, "Tony");
    strcpy(top[8].name, "Wang");
    strcpy(top[9].name, "Grace");


    for(i = 0; i < 10; i++)
    {
        fprintf(RankFp, "%d %s ", top[i].score,top[i].name);//show ranking list
    }
    fclose(RankFp);


    ;
}

void PrintRankList(int X, int Y)
{
    int i;
    char outtextscore[5];

    cleardevice();
    outtextxy(((X / 2) - 40), Y / 13, "TOP 10");//title
    outtextxy(((X / 3) - 40), Y / 12, "Name");
    outtextxy(((2 * X / 3) - 40), Y / 12, "Score");


    for(i = 0; i < 10; i++)
    {
        outtextxy(((X / 3) - 40), Y / 12 * ( i + 2), top[i].name);//print name
        sprintf(outtextscore, "%d", top[i].score);
        outtextxy(((2 * X / 3) - 40), Y / 12 * ( i + 2), outtextscore);//print scores

    }

    DrawBackButton(SleClr);
    update_display();
    do//wait for enter key
    {

        wait_for_event();
        if(event_key_down())
        {

            if(event.keyboard.keycode == 67)
                break;
            else
                printf("Oops,An invalid key is input!");
        }

    }
    while(1);
}


void DrawBackButton(int Color)//draw a button to indicate go back
{
    Button B;

    B.PosX = 80;
    B.PosY = 50;

    strcpy(B.Text, "Back");
    filled_rectangle(B.PosX - 50, B.PosY - 20,B.PosX + 50,B.PosY + 20, Color);
    moveto(B.PosX - 50, B.PosY - 20);
    lineto(B.PosX + 50, B.PosY - 20,2);
    lineto(B.PosX + 50, B.PosY + 20,2);
    lineto(B.PosX - 50, B.PosY + 20,2);
    lineto(B.PosX - 50, B.PosY - 20,2);
    outtextxy(B.PosX - 20, B.PosY - 10, B.Text);

    update_display();
}

void AddIntoList(int X, int Y, int score)
{
    int i;
    int rank;


    ReadRankList();
    for(i=0; i<10; i++)
    {
        if(score > top[i].score)
            break;
    }
    rank = i;

    if(i!=10)
    {
        cleardevice();
        outtextxy(X/2-100,Y/2-20,"congratulations! You got a new high score!");
        update_display();
        outtextxy(X/2-100,Y/2,"Please input your name in another window;)");//give information in graphic window
        system("cls");
        printf("Please input your name here and confirm with enter key\n(The length is limited to 20 characters)\n");//give information in original window
        for(i=8; i>=rank; i--)
        {
            strcpy(top[i+1].name,top[i].name);//add into list

            top[i+1].score = top[i].score;

        }
        scanf("%19s", top[rank].name);
        top[rank].score = score;



    }

    FILE *RankFp = fopen("List.txt", "w");

    for(i = 0; i < 10; i++)//write into file
    {
        fprintf(RankFp, "%d %s ", top[i].score,top[i].name);
    }
    fclose(RankFp);

    PrintRankList(X,Y);

}
