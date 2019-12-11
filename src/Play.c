
#include "Assignment.h"


void StartGame(int X,int Y)
{
    system("cls");
    printf("Use left click to select the direction of the shot and the hitting strength.\n\n");
    printf("Use right click to exit the game.\n\n");
    printf("Start your challenge!\n\n");


    cleardevice();
    int level = 1;
    int times ;
    int score = 0 ;
    double angle;
    int v;
    int velocity;

    int wind;

    GameExitFlag = 1 ;//1 continue, o exit


    while (level < 10&&GameExitFlag == 1)
    {
        ballX = X / 7 + 20;
        ballY = Y *4 / 5 - 8;


        switch(level)
        {
        case 1:
            times = 5;
            v = 9;
            break;
        case 2:
            times = 4;
            v = 7;
            break;
        case 3:
            times = 4;
            v = 6;
            break;
        case 4:
            times = 3;
            v = 5;
            break;
        case 5:
            times = 3;
            v = 5;
            break;
        case 6:
            times = 2;
            v = 4;
            break;
        case 7:
            times = 2;
            v = 4;
            break;
        case 8:
            times = 2;
            v = 3;
            break;
        case 9:
            times = 2;
            v = 3;
            break;
        }

        if (SetMode == 0)//practice mode



            times = 9999;


        for(; times>0; times--)
        {
            DrawBasic(X,Y,level);//draw each basic thing
            DrawHoleCover(X, Y);
            DrawBasicArms(X,Y,ballX,ballY);
            filled_circle(ballX, ballY, 8,BallClr);

            if(level>3)//add wind
            {
                srand( (unsigned)time(NULL));
                wind = -20 + rand() % 40;
            }
            else
                wind = 0;

            if(GameExitFlag)
                angle = SelectAngle(X,Y,level,times,score,wind);//get angle
            if(GameExitFlag)
                velocity = SelectVelocity(X,Y,angle,v,level,times,score,wind);//get speed
            if(GameExitFlag)
            {
                if(ShootBall(X,Y,angle,velocity,level,times,score,wind) == 1)//not in hole
                {
                    score+= times+level*2;
                    if(score>100)
                        score = 100;
                    if (SetMode == 0)//practice mode
                        score = 0;
                    break;
                }
                WaitForClick();
            }

        }
        level++;
    }

    if(score!=0&&GameExitFlag)
        AddIntoList(X, Y, score);


}

void DrawBasic(int X, int Y,int level)
{
    al_draw_filled_rectangle(0, 0,X, Y *4 / 5, al_map_rgb(0,200,255));//sky
    al_draw_filled_rectangle(0,  Y *3 / 4,X, Y, al_map_rgb(0,255,127));//grass
    al_draw_filled_ellipse(X * 6 / 7, Y *4 / 5,  20, 10,al_map_rgb(180,180,180));// ball hole
    al_draw_filled_ellipse(X * 6 / 7, Y *4 / 5+10,19, 9,al_map_rgb(130,130,130));

    filled_ellipse(X*4/5,Y/4,40,24,15);
    filled_ellipse(X*4/5-60,Y/4+3,40,24,15);
    filled_ellipse(X*4/5-90,Y/4+33,40,26,15);
    filled_ellipse(X*4/5+30,Y/4+28,44,28,15);
    filled_ellipse(X*4/5-50,Y/4+55,36,20,15);
    filled_ellipse(X*4/5+10,Y/4+54,36,20,15);
    filled_ellipse(X*4/5-30,Y/4+35,40,24,15);//cloud

    DrawObstacles(X,Y,level);



    ;
}

void DrawHoleCover(int X, int Y)
{
    al_draw_ellipse(X * 6 / 7, Y *4 / 5,30, 20,al_map_rgb(0,255,127),20);//hole cover
    al_draw_line(X * 6 / 7, Y *4 / 5 + 10, X * 6 / 7, Y *4 / 5 - 120, al_map_rgb(255,255,0),3);  //flag stick
    al_draw_line(X * 6 / 7+2, Y *4 / 5 + 10, X * 6 / 7+2, Y *4 / 5 - 120, al_map_rgb(200,200,0),2);
    al_draw_filled_triangle(X * 6 / 7, Y *4 / 5 -116, X * 6 / 7,Y *4 / 5 -90, X * 6 / 7 + 50, Y *4 / 5 -90, al_map_rgb(255,100,100));//flag
    al_draw_filled_circle(X * 6 / 7, Y *4 / 5 -120,5,al_map_rgb(255,200,0)); //flag ball
}

void DrawBasicArms(int X,int Y,int ArmX,int ArmY)
{

    int tall = Y / 6;
    int x_position = ArmX-20 ;
    int y_position = ArmY+8 - tall;//neck
    int headradius = 8;

    int MoveBallCenterX = x_position;
    int MoveBallCenterY = y_position+tall/2-5;
    int ClubBallX, ClubBallY;
    double BallAngle;
    int Ballr = tall/2+5;
    int i=60;

    int LeftElbowX, LeftElbowY, RightElbowX, RightElbowY;
    double LeftElbowAngle, RightElbowAngle;
    int ElbowCentreX = x_position, ElbowCentreY = y_position + tall/19;
    int Elbowr = tall/4;

    filled_triangle(x_position-10,y_position+tall/19,x_position+10,y_position+tall/19,x_position,y_position+tall/2-5,LIGHTRED);//body

    line(x_position, y_position+tall/2-11,x_position, y_position+tall*2/3-5, 3);//legs
    line(x_position, y_position+tall*2/3-5,x_position-15, y_position+tall, 3);//legs
    line(x_position, y_position+tall/2-11,x_position+10, y_position+tall*2/3-5, 3);//legs
    line(x_position+10, y_position+tall*2/3-5,x_position+10, y_position+tall, 3);//legs

    BallAngle = -(-120.0+4*i)/180.0*3.14;
    ClubBallX = MoveBallCenterX+cos(BallAngle)*Ballr;
    ClubBallY = MoveBallCenterY+sin(BallAngle)*Ballr;//ball

    filled_ellipse(ClubBallX,ClubBallY-3,3,5,DARKGRAY);//ball

    LeftElbowAngle = -(-130.0+i)/180.0*3.14;//arms
    RightElbowAngle = -(-100.0+i)/180.0*3.14;
    LeftElbowX = ElbowCentreX+cos(LeftElbowAngle)*Elbowr;
    LeftElbowY = ElbowCentreY+sin(LeftElbowAngle)*Elbowr;
    line(x_position-10,y_position+tall/19,LeftElbowX,LeftElbowY,3);

    RightElbowX = ElbowCentreX+cos(RightElbowAngle)*Elbowr;
    RightElbowY = ElbowCentreY+sin(RightElbowAngle)*Elbowr;
    line(x_position+10,y_position+tall/19,RightElbowX,RightElbowY,3);

    int HandCenterX = x_position;
    int HandCenterY = y_position+tall*1/2-25;
    int HandX, HandY;
    double HandAngle;
    int Handr = tall*1/4+5;

    HandAngle = -(-120.0+3*i)/180.0*3.14;
    HandX = HandCenterX+cos(HandAngle)*Handr;
    HandY = HandCenterY+sin(HandAngle)*Handr;
    line(LeftElbowX,LeftElbowY,HandX,HandY,3);

    line(RightElbowX,RightElbowY,HandX,HandY,3);

    setcolor(DARKGRAY);
    line(HandX,HandY,ClubBallX,ClubBallY,3);

    setcolor(WHITE);

    filled_circle(x_position, y_position-headradius, headradius,WHITE);//head
    line(x_position, y_position,x_position, y_position+tall/19, 3);//neck

}


double SelectAngle(int X,int Y,int level,int times,int score,int wind)
{
    int ClickFlag = 1;
    int mouse_X, mouse_Y;
    int arrow_a_X, arrow_a_Y;
    int arrow_b_X, arrow_b_Y;
    int arrow_c_X, arrow_c_Y;
    int arrow_d_X, arrow_d_Y;

    double angle_mouse, angle_arrow;
    angle_arrow = 0.35;

    int r = 70 ;
    int a ;//length
    int arrow_head_length = 20;

    char outtexttime[15];

    char outtextscore[15];
    char outtextlevel[15];
    char outtextwind[15];
    sprintf(outtextwind, "wind  = %d ", wind);
    sprintf(outtextlevel, "level = %d ", level);
    sprintf(outtextscore, "score = %d ", score);
    sprintf(outtexttime, "times = %d ", times);


    if(level==1&&times>4)//print informations. provide guide in the first level
    {
        outtextxy(X/2-240, Y/5-20,"Move mouse to select angle and click to confirm.");
        outtextxy(X/2-180, Y/5,"Don't forget to consider the wind.");
        outtextxy(X/2-180, Y/5+20,"Use right click to exit the game.");
        outtextxy(X/2-110, Y/5+40,"Click to continue.");
        outtextxy(X-100,30,outtexttime);
        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,50,outtextlevel);
        outtextxy(X-100,70,outtextwind);

        update_display();
        if(GameExitFlag)
            WaitForClick();
    }
    else
    {

        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,30,outtexttime);

        outtextxy(X-100,70,outtextwind);
        outtextxy(X-100,50,outtextlevel);


        update_display();
    }

    while(ClickFlag&&GameExitFlag)//loop while no click
    {
        wait_for_event();

        if (event_close_display() )

        {
            GameExitFlag = 0 ;
            return 0;
        }

        else if (event_mouse_position_changed() ) //get mouse position
        {
            get_mouse_coordinates();
            mouse_X = XMOUSE;
            mouse_Y = YMOUSE;
        }

        else if (event_mouse_button_down())
        {
            if (event_mouse_left_button_down()) //left click
                ClickFlag = 0;
            else if (event_mouse_right_button_down())
                GameExitFlag = 0;
            return angle_mouse;

        }

        angle_mouse = atan2((-mouse_Y+ballY),(mouse_X-ballX));

        a = sqrt(pow(mouse_X-ballX,2)+pow(mouse_Y-ballY,2));//calculate arrow position
        arrow_a_X = r * (mouse_X - ballX)/a + ballX ;
        arrow_a_Y = r * (mouse_Y - ballY)/a + ballY ;
        arrow_d_X = (r-15) * (mouse_X - ballX)/a + ballX ;
        arrow_d_Y = (r-15) * (mouse_Y - ballY)/a + ballY ;

        arrow_b_X = arrow_a_X - arrow_head_length * cos(angle_mouse - angle_arrow);
        arrow_b_Y = arrow_a_Y + arrow_head_length * sin(angle_mouse - angle_arrow);
        arrow_c_X = arrow_a_X - arrow_head_length * cos(angle_mouse + angle_arrow);
        arrow_c_Y = arrow_a_Y + arrow_head_length * sin(angle_mouse + angle_arrow);

        if(arrow_a_Y < ballY + 8)//draw arrow when the mouse position is valid
        {


            DrawBasic(X,Y,level);
            DrawHoleCover(X,Y);
            DrawBasicArms(X,Y,ballX,ballY);
            filled_circle(ballX, ballY, 8,BallClr);

            line(ballX, ballY, arrow_a_X, arrow_a_Y, 3);
            filled_triangle(arrow_a_X,arrow_a_Y,arrow_b_X,arrow_b_Y,arrow_d_X,arrow_d_Y,WHITE);
            filled_triangle(arrow_a_X,arrow_a_Y,arrow_c_X,arrow_c_Y,arrow_d_X,arrow_d_Y,WHITE);

            outtextxy(X-100,70,outtextwind);
            outtextxy(X-100,50,outtextlevel);
            outtextxy(X-100,10,outtextscore);
            outtextxy(X-100,30,outtexttime);
            update_display();
        }
    }

    return 0;

}

int SelectVelocity(int X,int Y,double angle,int v,int level,int times,int score, int wind)
{
    int barX, barY;
    int width;
    char outtexttime[10];
    char outtextscore[15];
    char outtextlevel[15];
    char outtextwind[15];

    sprintf(outtextwind, "wind  = %d ", wind);
    sprintf(outtextlevel, "level = %d ", level);
    sprintf(outtextscore, "score = %d ", score);
    sprintf(outtexttime, "times = %d ", times);

    if(level==1&&times<2)
    {
        outtextxy(X/2-170, Y/5-20,"Click to stop the velocity bar.");//provide guide in the beginning
        outtextxy(X/2-180, Y/5,"Don't forget to consider the wind.");
        outtextxy(X/2-100, Y/5+20,"Click to continue.");
        outtextxy(X-100,30,outtexttime);//give informations
        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,50,outtextlevel);

        outtextxy(X-100,70,outtextwind);

        update_display();
        if(GameExitFlag)
            WaitForClick();
    }
    else
    {
        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,30,outtexttime);

        update_display();
    }
    barX = X / 10 ;
    barY = Y *1 / 2;

    width = Y / 30;

    int i = 0,m = 0;
    int colorFlag = 0;



    while(GameExitFlag)
    {


        if (check_if_event())
        {
            wait_for_event();

            if (event_close_display())
                GameExitFlag = 0;
            else if (event_mouse_button_down())
            {
                if (event_mouse_left_button_down())
                    break;
                else if(event_mouse_right_button_down())
                    GameExitFlag = 0;

            }
        }
        if(colorFlag == 0)//o mean the var is moving right
        {

            al_draw_line(barX+i/2, barY, barX+i/2, barY + width, al_map_rgb(255,255-i,0),1);//bar color
        }

        else//move left

            al_draw_line(barX+1+i/2, barY, barX+1+i/2, barY + width, al_map_rgb(0,200,255),1);//background color

        if(  colorFlag == 0 && i < 255)//move right
        {
            m++;
        }
        else if(colorFlag == 0 && i >= 255)//move to the far right
        {
            colorFlag = 1;
        }
        else if(  colorFlag == 1 && i > 0)//move left
        {
            m--;
        }
        else if(colorFlag == 1 && i <= 0)//move to the far left
        {
            colorFlag = 0;
        }

        i = m / v;

        update_display();


    }
    i = 20+i / 3 ;
    return i ;


}

int ShootBall(int X,int Y,double angle,int velocity,int level,int times, int score, int wind)
{

    int InHoleFlag ;
    int ObstacleFlag ;
    int OutScreenFlag ;
    int i;
    int ArmX,ArmY;

    InHoleFlag = 1;
    ObstacleFlag = 1;
    OutScreenFlag = 1;

    double vx, vy;

    double t;//time

    char outtexttime[15];
    char outtextscore[15];
    char outtextlevel[15];
    char outtextwind[15];

    ArmX = ballX;
    ArmY = ballY;
    sprintf(outtextwind, "wind  = %d ", wind);

    sprintf(outtextlevel, "level = %d ", level);

    sprintf(outtextscore, "score = %d ", score);

    sprintf(outtexttime, "times = %d ", times);
    outtextxy(X-100,10,outtextscore);

    outtextxy(X-100,70,outtextwind);

    outtextxy(X-100,50,outtextlevel);

    outtextxy(X-100,30,outtexttime);

    update_display();

    vx = velocity  * cos(angle) + wind;

    vy = velocity  * sin(angle);

    t = 0.1;//assume the time between frames is 0.1

    i = 0;

    while ((ballY < Y *4 / 5 - 7)&&(InHoleFlag == 1)&&(ObstacleFlag == 1)&&GameExitFlag)//Draw the first parabola
    {
        if (ballX > X+8||ballX+8<0)
        {
            outtextxy(X/2-250, Y/5,"Oops! The ball is out of course! Click to retry.");
            OutScreenFlag = 0 ;
            update_display();
            break;
        }//ball go out of screen
        ballX += vx * t;
        vy -= 9.81 * t;

        ballY -= vy * t;

        DrawBasic(X, Y,level);
        DrawHoleCover(X,Y);
        if(i<61)//swing when shooting ball
        {
            DrawMoveArms(X,Y,ArmX,ArmY,i);
            i+=3;
        }
        else
            DrawBasicArms(X,Y,ArmX,ArmY);//swing over


        filled_circle(ballX, ballY, 8,BallClr );

        outtextxy(X-100,70,outtextwind);
        outtextxy(X-100,50,outtextlevel);
        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,30,outtexttime);

        update_display();

        if((X*6/7-20<ballX)&&(X*6/7+20>ballX)&&(Y*4/5-10<ballY+8)&&(Y*4/5+10>ballY+8))//into hole
        {
            InHoleFlag = 0;
            break;
        }
        else
            ObstacleFlag = HitObstacles(ballX, ballY,ArmX,ArmY, X, Y, level,times,score,wind);
    }



    vx = velocity *2 / 3  * cos(angle);
    vy = velocity *2 / 3  * sin(angle);
    ballY = Y *4 / 5 - 8;
    while ((ballY < Y *4 / 5 - 7)&&(InHoleFlag ==1)&&(ObstacleFlag == 1)&&GameExitFlag)//Draw the second parabola
    {
        if (ballX > X+8||ballX+8<0)
        {
            outtextxy(X/2-250, Y/5,"Oops! The ball is out of course! Click to retry.");

            OutScreenFlag = 0 ;

            update_display();
            break;
        }

        ballX += vx * t;

        vy -= 9.81 * t;

        ballY -= vy * t;

        DrawBasic(X, Y,level);
        DrawHoleCover(X,Y);
        DrawBasicArms(X,Y,ArmX,ArmY);
        filled_circle(ballX, ballY, 8,BallClr);

        outtextxy(X-100,70,outtextwind);
        outtextxy(X-100,50,outtextlevel);
        outtextxy(X-100,10,outtextscore);

        outtextxy(X-100,30,outtexttime);
        update_display();

        if((X*6/7-20<ballX)&&(X*6/7+20>ballX)&&(Y*4/5-10<ballY+8)&&(Y*4/5+10>ballY+8))
        {
            InHoleFlag = 0;
            break;
        }
        else
            ObstacleFlag = HitObstacles(ballX, ballY,ArmX,ArmY, X, Y, level,times,score,wind);
    }

    ballY = Y *4 / 5 - 8;
    while((vx > 0.01) && (InHoleFlag ==1)&&(ObstacleFlag == 1)&&GameExitFlag)//roll
    {
        if (ballX > X+8||ballX+8<0)
        {
            outtextxy(X/2-250, Y/5,"Oops! The ball is out of course! Click to retry.");

            OutScreenFlag = 0 ;
            update_display();
            break;
        }
        vx-=0.1;
        ballX += vx * t;
        DrawBasic(X, Y,level);
        DrawHoleCover(X,Y);
        DrawBasicArms(X,Y,ArmX,ArmY);
        filled_circle(ballX, ballY, 8,BallClr );//draw every thing

        outtextxy(X-100,70,outtextwind);//give information
        outtextxy(X-100,50,outtextlevel);
        outtextxy(X-100,10,outtextscore);
        outtextxy(X-100,30,outtexttime);
        update_display();

        if((X*6/7-20<ballX)&&(X*6/7+20>ballX)&&(Y*4/5-10<ballY+8)&&(Y*4/5+10>ballY+8))
        {
            InHoleFlag = 0;
            break;
        }
        else

            ObstacleFlag = HitObstacles(ballX, ballY,ArmX,ArmY, X, Y, level, times, score,wind);


    }
    if(OutScreenFlag == 0 )
    {
        ballX = X / 7 + 20;
        ballY = Y *4 / 5 - 8;
    }
    if(ObstacleFlag == 0)
    {
        switch(level)
        {
        case 3:
        case 5:
        case 8:
        case 4:
        case 6:
        case 9:
            ballX = X / 7 + 20;
            ballY = Y *4 / 5 - 8;
            break;
        }
    }

    if(InHoleFlag == 0)
    {
        midi_note(60, 1, 100);// in hole voice
        for(i=0; i<15; i++)
        {

            ballY+=1;
            DrawBasic(X, Y,level);
            DrawBasicArms(X,Y,ArmX,ArmY);
            filled_circle(ballX, ballY, 8,BallClr );
            DrawHoleCover(X,Y);
            outtextxy(X-100,10,outtextscore);
            outtextxy(X-100,30,outtexttime);

            outtextxy(X-100,70,outtextwind);
            outtextxy(X-100,50,outtextlevel);
            outtextxy(X/2-50, Y/5,"nice shot!");
            update_display();

            pausefor(5);
        }
        midi_note(60, 2, 100);//cheers sound
        pause(2000);
        midi_note(60, 2, 0);

        WaitForClick();
        return 1;
    }
    else
    {

        return 0;
    }
    ballY = Y *4 / 5 - 8;

    if(GameExitFlag)
        return 0;


}

void DrawObstacles(int X,int Y,int level)
{
    switch(level)
    {
    case 2:
    case 7:
        DrawBunker(X, Y);
        break;
    case 3:
    case 5:
    case 8:
        DrawWater(X,Y);
        break;
    case 4:
    case 6:
    case 9:
        DrawTree(X,Y);
    default:
        break;

    }
}

void DrawBunker(int X,int Y)
{
    al_draw_filled_ellipse(X*3/9,  Y *4 / 5,130, 50, al_map_rgb(255,193,80));
    al_draw_filled_rectangle(X*3/9-130, Y *3/4-50,X*3/9+130,  Y *3/4, al_map_rgb(0,200,255));
}

void DrawWater(int X,int Y)
{
    al_draw_filled_ellipse(X*4/10,  Y *4 / 5,130, 60, al_map_rgb(50,225,255));
    al_draw_filled_rectangle(X*4/10-140, Y *3/4-50,X*4/10+140,  Y *3/4, al_map_rgb(0,200,255));
    ;
}

void DrawTree(int X,int Y)
{
    al_draw_filled_rectangle(X*1/2-X*1/100, Y*1/2+Y*1/9,X*1/2+X*1/100,  Y *4/5, al_map_rgb(200,120,60));
    al_draw_filled_ellipse(X*1/2,  Y *4 / 5,X*1/100, 6, al_map_rgb(200,120,60));//tree body
    al_draw_filled_rectangle(X*1/2+X*1/100-5, Y*1/2+Y*1/9,X*1/2+X*1/100,  Y *4/5+3, al_map_rgb(170,100,40));

    al_draw_filled_triangle(X*1/2,Y*1/2+Y*1/18+Y*1/18,X*1/2-X*1/15,Y*1/2+Y*1/9+Y*1/18+Y*1/18,X*1/2+X*1/15,Y*1/2+Y*1/9+Y*1/18+Y*1/18,al_map_rgb(0,150,0));//Leaves
    al_draw_filled_triangle(X*1/2,Y*1/2+Y*1/18,X*1/2-X*1/15,Y*1/2+Y*1/9+Y*1/18,X*1/2+X*1/15,Y*1/2+Y*1/9+Y*1/18,al_map_rgb(0,165,0));
    al_draw_filled_triangle(X*1/2,Y*1/2,X*1/2-X*1/15,Y*1/2+Y*1/9,X*1/2+X*1/15,Y*1/2+Y*1/9,al_map_rgb(0,180,0));


    ;
}

int HitObstacles(int lineX, int lineY,int ArmX, int ArmY,int X, int Y, int level,int times, int score, int wind)
{

    int i;
    ALLEGRO_FONT *font = al_load_font("data/fixed_font.tga", 0, 0);
    char outtexttime[10];
    char outtextscore[15];
    char outtextlevel[15];
    char outtextwind[15];
    sprintf(outtextwind, "wind  = %d ", wind);
    sprintf(outtextlevel, "level = %d ", level);
    sprintf(outtextscore, "score = %d ", score);
    sprintf(outtexttime, "times = %d ", times);

    switch(level)
    {
    case 2:
    case 7://bunker levels

        if((lineX+8<X*3/9+130)&&(lineX-8 > X*3/9-130)&&(Y*4/5-2<lineY+8))
        {
            al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5, ALLEGRO_ALIGN_CENTRE,"You hit the bunker!");
            al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5+20, ALLEGRO_ALIGN_CENTRE, "Click to continue.");

            update_display();

            ballY = Y *4 / 5 + 3;


            return 0;
        }
        break;
    case 3:
    case 5:
    case 8://water levels
        if((X*4/10+130>lineX+10)&&(lineX-10 > X*4/10-130)&&(Y*4/5-10<lineY+8)&&(Y*4/5+10>lineY+8))
        {

            for(i=0; i<20; i++)
            {

                lineY+=1;
                DrawBasic(X, Y,level);
                DrawBasicArms(X,Y,ArmX,ArmY);
                filled_circle(lineX, lineY, 8,BallClr);//ball
                if((X*4/10+130>lineX+16+3)&&(lineX-16-3 > X*4/10-130))
                {
                    al_draw_circle(lineX,lineY-8,16,al_map_rgb(50,225,255),5);
                    al_draw_filled_rectangle(lineX-20, Y *3/4-20,lineX+20,  Y *3/4, al_map_rgb(0,200,255));
                }

                DrawHoleCover(X,Y);
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5, ALLEGRO_ALIGN_CENTRE, "You hit the pool!");
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5+20, ALLEGRO_ALIGN_CENTRE, "Click to continue.");

                outtextxy(X-100,50,outtextlevel);
                outtextxy(X-100,70,outtextwind);
                outtextxy(X-100,30,outtexttime);
                outtextxy(X-100,10,outtextscore);

                update_display();

                pausefor(40);
            }
            return 0;
        }
        break;
    case 4:
    case 6:
    case 9://tree levels
        if(lineX+8>(X*1/2-X*1/15)&&(lineX-8<X*1/2+X*1/15)&&(lineY>Y*1/2+Y*1/9)&&(lineY<Y*1/2+Y*2/9))//hit the tree body
        {
            for(; lineY<Y*4/5; lineY++)
            {

                lineY+=1;
                DrawBasic(X, Y,level);
                DrawBasicArms(X,Y,ArmX,ArmY);
                DrawHoleCover(X,Y);
                filled_circle(lineX, lineY, 8,BallClr );
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5, ALLEGRO_ALIGN_CENTRE, "You hit the tree!");
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5+20, ALLEGRO_ALIGN_CENTRE, "Click to continue.");


                outtextxy(X-100,70,outtextwind);

                outtextxy(X-100,50,outtextlevel);
                outtextxy(X-100,30,outtexttime);
                outtextxy(X-100,10,outtextscore);

                update_display();
            }


            return 0;

        }
        if((lineX+8>(X*1/2-X*1/100))&&(lineX-8<X*1/2+X*1/100)&&(lineY+8>Y*1/2+Y*2/9)&&(lineY-8 <Y * 4 / 5 ) )//hi the leaves
        {
            for(; lineY<Y*4/5; lineY++)
            {

                lineY+=1;
                DrawBasic(X, Y,level);
                DrawBasicArms(X,Y,ArmX,ArmY);
                DrawHoleCover(X,Y);
                filled_circle(lineX, lineY, 8,BallClr );
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5, ALLEGRO_ALIGN_CENTRE, "You hit the tree!");
                al_draw_text(font, al_map_rgb(255,255,255), X/2, Y/5+20, ALLEGRO_ALIGN_CENTRE, "Click to continue.");

                outtextxy(X-100,30,outtexttime);
                outtextxy(X-100,10,outtextscore);
                outtextxy(X-100,70,outtextwind);
                outtextxy(X-100,50,outtextlevel);

                update_display();


            }
            return 0;
        }
        break;


    }
    return 1;
}


void DrawMoveArms(int X,int Y,int ArmX,int ArmY,int i)
{
    int tall = Y / 6;
    int x_position = ArmX-20;
    int y_position = ArmY+8 - tall;//neck
    int headradius = 8;


    int MoveBallCenterX = x_position;
    int MoveBallCenterY = y_position+tall/2-5;
    int ClubX, ClubY;
    double BallAngle;
    int Ballr = tall/2+5;

    int LeftElbowX, LeftElbowY, RightElbowX, RightElbowY;
    double LeftElbowAngle, RightElbowAngle;
    int ElbowCentreX = x_position, ElbowCentreY = y_position + tall/19;
    int Elbowr = tall/4;

    int HandCenterX = x_position;
    int HandCenterY = y_position+tall*1/2-25;
    int HandX, HandY;
    double HandAngle;
    int Handr = tall*1/4+5;
    if(i<61)
    {
        filled_triangle(x_position-10,y_position+tall/19,x_position+10,y_position+tall/19,x_position,y_position+tall/2-5,LIGHTRED);//body

        line(x_position, y_position+tall/2-11,x_position, y_position+tall*2/3-5, 3);//legs
        line(x_position, y_position+tall*2/3-5,x_position-15, y_position+tall, 3);//legs
        line(x_position, y_position+tall/2-11,x_position+10, y_position+tall*2/3-5, 3);//legs
        line(x_position+10, y_position+tall*2/3-5,x_position+10, y_position+tall, 3);//legs

        BallAngle = -(-120.0+4*i)/180.0*3.14;
        ClubX = MoveBallCenterX+cos(BallAngle)*Ballr;
        ClubY = MoveBallCenterY+sin(BallAngle)*Ballr;

        filled_ellipse(ClubX,ClubY-3,3,5,DARKGRAY);//club head


        LeftElbowAngle = -(-130.0+i)/180.0*3.14;//move the arms
        RightElbowAngle = -(-100.0+i)/180.0*3.14;
        LeftElbowX = ElbowCentreX+cos(LeftElbowAngle)*Elbowr;
        LeftElbowY = ElbowCentreY+sin(LeftElbowAngle)*Elbowr;
        line(x_position-10,y_position+tall/19,LeftElbowX,LeftElbowY,3);

        RightElbowX = ElbowCentreX+cos(RightElbowAngle)*Elbowr;
        RightElbowY = ElbowCentreY+sin(RightElbowAngle)*Elbowr;
        line(x_position+10,y_position+tall/19,RightElbowX,RightElbowY,3);



        HandAngle = -(-120.0+3*i)/180.0*3.14;
        HandX = HandCenterX+cos(HandAngle)*Handr;
        HandY = HandCenterY+sin(HandAngle)*Handr;
        line(LeftElbowX,LeftElbowY,HandX,HandY,3);

        line(RightElbowX,RightElbowY,HandX,HandY,3);

        setcolor(DARKGRAY);
        line(HandX,HandY,ClubX,ClubY,3);

        setcolor(WHITE);

        filled_circle(x_position, y_position-headradius, headradius,WHITE);//head
        line(x_position, y_position,x_position, y_position+tall/19, 3);//neck

    }

}





