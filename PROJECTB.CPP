#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#define left 75
#define right 77
#define esc 27
#define e 101
#define m 109
#define h 104
void help()
{
cleardevice();
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(0,0,4);
outtextxy(getmaxx()/2,20,"Help");
settextstyle(3,0,3);
outtextxy(5,60,"-> To play this awesome game use navigation button ");
outtextxy(5,85,"    Left and Right.");
outtextxy(5,110,"-> There are 3 modes to play Easy, Medium and Hard.");
outtextxy(5,135,"-> Every time ball return from pad score will increase");
outtextxy(5,160,"    as well as speed.");
outtextxy(5,185,"-> Hope you enjoy the game.");
outtextxy(50,250,"     To resume enter any key");
getch();
}
void menu()
{
    rectangle(150,100,450,280);
    settextstyle(0,0,4);
    outtextxy(getmaxx()/2-150,30,"Game Mode ");
    settextstyle(0,0,2);
    outtextxy(getmaxx()/2-120,130,"Easy   -> e ");
    outtextxy(getmaxx()/2-120,155,"Medium -> m ");
    outtextxy(getmaxx()/2-120,180,"Hard   -> h");
    outtextxy(getmaxx()/2-120,205,"Exit   -> esc");
    outtextxy(getmaxx()/2-120,230,"Help   -> x");
    settextstyle(12,0,2);
    outtextxy(getmaxx()/2-100,300,"Credit: Chandi Charan Mahato ");
    setlinestyle(0,0,3);
    setlinestyle(0,0,3);
    line(150,320,500,320);
}
void exit()
{
    rectangle(100,100,500,250);
    settextstyle(0,0,3);
    outtextxy(getmaxx()/2-150,140,"Game Over! ");
    outtextxy(getmaxx()/2-170,180,"Your Score: ");
    settextstyle(12,0,2);
    outtextxy(getmaxx()/2-100,300,"Credit: Chandi Charan Mahato ");
    setlinestyle(0,0,3);
    line(150,320,500,320);
}
int main()
{
    int gd=EGA,gm=EGAHI,x=20,y=20,speed=5,s=0,score=0,padX=getmaxx(),padY=getmaxy()+180,turnX=1,turnY=1,gameEnd=0;
    char str[3],str1[3];
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    choice:
    setbkcolor(0);
    char g;
    menu();
    gotoxy(50,17);
    cin>>g;
    if(g==101)
    s=1;
    else if(g==109)
    s=2;
    else if(g==104)
    s=3;
    else if(g==120)
    {
    help();
    cleardevice();
    goto choice;
    }
    else if(g==esc)
    exit(0);
    else
    {
    cleardevice();
    outtextxy(getmaxx()/2-100,160,"Wrong Input ");
    setlinestyle(0,0,3);
    line(getmaxx()/2-120,getmaxy()/2,320,getmaxy()/2);
    outtextxy(getmaxx()/2-100,300,"Credit: Chandi Charan Mahato ");
    setlinestyle(0,0,3);
    line(150,320,500,320);
    sleep(2);
    cleardevice();
    goto choice;
    }
    while(gameEnd==0)
    {
	rectangle(0,0,500,getmaxy());            //game box
	rectangle(505,0,getmaxx(),120);          //score box
	rectangle(505,125,getmaxx(),225);        //for help desk
	rectangle(505,230,getmaxx(),getmaxy());  //for credit box

	//for Score Output
	settextstyle(0,0,3);
	outtextxy(510,5,"Score");
	settextstyle(0,0,2);
	sprintf(str,"%d",score);
	outtextxy(560,40,str);

	//For Speed Output
	settextstyle(0,0,3);
	outtextxy(510,65,"Speed");
	sprintf(str1,"%d",speed);
	settextstyle(0,0,2);
	outtextxy(560,95,str1);

	//for navigation help
	settextstyle(0,0,1);
	outtextxy(515,140,"  -> For Left");
	outtextxy(515,160,"  <- For Right");
	outtextxy(515,180,"  esc For Exit");
	outtextxy(515,200,"  H For Help");

	//for Credit box
	settextstyle(0,0,2);
	outtextxy(510,240," CREDIT");
	settextstyle(0,0,1);
	outtextxy(510,275," Chandi Charan");
	outtextxy(515,295,"    Mahato");

//Ball Movement
	if(x >= 475)
	    turnX=0;
	else if(x <= 20)
	    turnX=1;
	if((x >= padX-50 && x <= padX+150) && (y >= padY+135 && y <= padY+150))
	{
	    turnY=0;
	    score+=10;
	    speed+=s;
	}
	if(y >= getmaxy()-20)
	    gameEnd=1;
	else if(y <= 20)
	    turnY=1;
	if(turnX == 1)
	    x+=speed;
	else if(turnX==0)
	    x-=speed;
	if(turnY == 1)
	    y+=speed;
	else if(turnY==0)
	    y-=speed;

//Pad Movement

	if(kbhit())
	{
	    switch(getch())
	    {
	    case left:
		if(padX > (getmaxx()/2)-280)
		    padX-=20;
		break;
	    case right:
		if(padX < (getmaxx()/2)+120)
		    padX+=20;
		break;
	    case 104:
		help();
		break;
	    case esc:
		exit(0);
	    }
	}
//ball
	setfillstyle(1,2);
	circle(abs(x),abs(y),20);
//pad
	setcolor(GREEN);
	setfillstyle(2,4);
	rectangle(padX-50,padY+150,padX+50,padY+155);
	delay(100);
	cleardevice();
    }
    cleardevice();
    exit();
    settextstyle(0,0,2);
    sprintf(str,"%d",score);
    outtextxy(getmaxx()/2+120,getmaxy()/2+10,str);
    settextstyle(0,0,1);
    outtextxy(getmaxx()/2-100,getmaxy()/2+50,"Press y to restart");
    char r;
    cin>>r;
    if(r=='y')
    {
    cleardevice();
    goto choice;
    }
    else
    exit(0);
    getch();
    closegraph();
}

