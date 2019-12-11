
#ifndef _ASSIGNMENT_H
#define _ASSIGNMENT_H

#include <graphics_lib.h>
#include <amio_lib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    int PosX;
    int PosY;
    char Text[20];
} Button;

typedef struct
{
    int score;
    char name[20];
} Player;

Player top[10];

int ComClr, SleClr, BallClr;

int SetMode;

int GameExitFlag;

int ballX, ballY;

int *RankArray;

void CreatWindow(int X, int Y);

void display_welcome(void);

void DrawMenuButton(Button B, int color);

void DrawBackButton(int color);

int ShowMainMenu(int X, int Y);

void SettingsMenu(int X, int Y);

void  ChooseMode(int X, int Y);

int  ShowMode(int X, int Y);

void ShowRankingList(int X, int Y);

void StartGame(int X,int Y);

void CreatNewList(void);

void ReadRankList(void);

void PrintRankList(int X, int Y);

void DrawBasic(int X, int Y,int level);

double SelectAngle(int X, int Y,int level,int times,int score,int wind);

int AngleShoot(int X,int Y);

int SelectVelocity(int X,int Y,double angle,int v,int level, int times,int score,int wind);

int ShootBall(int X,int Y,double angle,int velocity,int level,int times,int score, int wind);

void MoveArms(int X,int Y,int ArmX,int ArmY,int velocity);

void DrawBasicArms(int X,int Y,int ArmX, int ArmY);

void DrawHoleCover(int X, int Y);

void DrawObstacles(int X,int Y,int level);

void DrawBunker(int X,int Y);

void DrawWater(int X,int Y);

void DrawTree(int X,int Y);

int HitObstacles(int lineX, int lineY,int ArmX,int ArmY,int X, int Y, int level,int times, int score,int wind);

void DrawMoveArms(int X,int Y,int ArmX,int ArmY,int i);

void WaitForClick(void);

void AddIntoList(int X, int Y, int score);

int ShowSettingMenu(int X, int Y);

void SetBallColor(int X,int Y);

void SetButtonColor(int X,int Y);

#endif
