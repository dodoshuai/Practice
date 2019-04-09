#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#define ok 0
#define eror 1
#define NUME 15
#pragma comment ( lib, "Winmm.lib" )
/*mciSendString( "open ./source/skycity.mp3 alias skycity", 0, 0, 0 );
mciSendString( "play skycity repeat ", 0, 0, 0 );*/
enum direction
{
left,up,right,down
};
enum condition
{
normal,addSpeed,addAggressivity,invincible,addOneLife,killAll
};
struct property
{
condition con;
int x;
int y;
int clock;
int flag;
};


struct ENEMY
{
int x;
int y;
int life;    //有25 50 75三种生命值坦克
int aggressivity;   //默认为20
direction dir;
};
struct USER     //速度为3
{
int x;
int y;
int life;   //默认为50
int aggressivity;  //默认为25
direction dir; 
condition speed;  //加子弹速度状态
condition atack;  //加攻击力状态
condition defence;  //无敌状态
int clocks;
int clocka;
int clockd;
};
struct BOMB   // r=4,circle
{
int x;
int y;
int aggressivity;
int speed;          //速度默认为5
direction dir;
};
ENEMY enm[ NUME ];
USER use1,use2;
int MODEL=0;  //为0表示单玩家，为1表示双玩家
int enemyNum=0, use1BNum=0,use2BNum=0;
BOMB enemyBomb[NUME],use1Bomb,use2Bomb;
bool FLAGBOMB1=false,FLAGBOMB2=false,flagB[NUME],flagLife[NUME];


int moveLength=5,BombNormalSpeed=5,BombAddSpeed=5,endOfGame=1;
int wall[10][3],use1life=3,use2life=3,use1Score=0,use2Score=0,highmark=0;
property pro[5];


int controlEnemy();
int controlUser();
int drawtank(int i,int j,int life,direction dir);
int drawBomb();
int controlBomb();
int tankMove();
int initGame();
int drawHome();
int is_collision(int x1,int y1,int x2,int y2,direction dir);
bool isTarget(USER tar,BOMB bomb);
bool isTarget2(ENEMY tar,BOMB bomb);
bool is_warded(int x,int y,direction dir,int tank);
int start_interface();
int control_property();
int control_userInfo(int count);
int init_userinfo();

void main()
{ 
int i=0,flag=0,temp1,count=0;
for(i=0;i<NUME;i++)
{
flagLife[i]=false;
flagB[i]=false;
}
for(i=0;i<4;i++)
{
wall[i][0]=430,wall[i][1]=630-i*20,wall[i][2]=1;
wall[i+5][0]=520,wall[i+5][1]=630-i*20,wall[i+5][2]=1;
pro[i].flag=0;
}
pro[4].flag=0;
wall[4][0]=480,wall[4][1]=590,wall[4][2]=1;
wall[9][0]=480,wall[9][1]=570,wall[9][2]=1;
for(i=0;i<3;i++)
{
temp1=wall[4][i];
wall[4][i]=wall[8][i];
wall[8][i]=temp1;
}
use1life=3,use2life=3;
use1.life=0,use2.life=0;
use1Score=0,use2Score=0,highmark=0;
moveLength=5,BombNormalSpeed=5,BombAddSpeed=5,endOfGame=1;
FLAGBOMB1=false,FLAGBOMB2=false;
enemyNum=0, use1BNum=0,use2BNum=0;
srand((unsigned)time(0));
initgraph(1200,650);
start_interface();

mciSendString( "open ./source/intimateLover.mp3 alias Lover", 0, 0, 0 );
mciSendString( "open ./source/begin.mp3 alias begin", 0, 0, 0 );
mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "open ./source/eatting.mp3 alias eatting", 0, 0, 0 );
mciSendString( "open ./source/getLife.mp3 alias getLife", 0, 0, 0 );
mciSendString( "open ./source/launchBomb.mp3 alias launchBomb", 0, 0, 0 );
mciSendString( "open ./source/lose.mp3 alias lose", 0, 0, 0 );
mciSendString( "open ./source/moveSelf.mp3 alias moveSelf", 0, 0, 0 );
mciSendString( "open ./source/background.mp3 alias background", 0, 0, 0 );
mciSendString( "open ./source/shoot.mp3 alias shoot", 0, 0, 0 );
mciSendString( "open ./source/bomb.wav alias bomb", 0, 0, 0 );
mciSendString( "play moveSelf repeat", 0, 0, 0 );
mciSendString( "pause moveSelf", 0, 0, 0 );
mciSendString( "play Lover", 0, 0, 0 );

init_userinfo();
mciSendString( "play begin ", 0, 0, 0 );
initGame();
}
int initGame()
{
IMAGE p;
int i=0,k=0,m,count=0,countBeginMusic=0;
loadimage(&p,"./source/home.jpg", 40, 40);
BeginBatchDraw();
setfont( 30, 0,"楷体");
drawtank(use1.x,use1.y,use1.life,use1.dir);
drawtank(use2.x,use2.y,use2.life,use2.dir);
while(endOfGame)
{
controlEnemy();
controlUser();
controlBomb();
control_property();
for(i=0;i<NUME;i++)           //判断敌军子弹是否出界
{
if(flagB[i]==true)
if(enemyBomb[i].x<0||enemyBomb[i].y<0||enemyBomb[i].x>1000||enemyBomb[i].y>650)
{
flagB[i]=false;
}
}
tankMove();
drawBomb();
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true)
{
drawtank(enm[i].x,enm[i].y,enm[i].life,enm[i].dir);
}
}
if(use1.defence==invincible)
{
for(m=use1.x+5;m<=use1.x+45;m+=5)
{
circle(m,use1.y,5);
circle(m,use1.y+50,5);
}
for(m=use1.y+5;m<=use1.y+45;m+=5)
{
circle(use1.x,m,5);
circle(use1.x+50,m,5);
}
clearrectangle(use1.x,use1.y,use1.x+50,use1.y+50);
}
drawtank(use1.x,use1.y,use1.life,use1.dir);
if(MODEL)
{
if(use2.defence==invincible)
{
for(m=use2.x+5;m<=use2.x+45;m+=5)
{
circle(m,use2.y,5);
circle(m,use2.y+50,5);
}
for(m=use2.y+5;m<=use2.y+45;m+=5)
{
circle(use2.x,m,5);
circle(use2.x+50,m,5);
}
clearrectangle(use2.x,use2.y,use2.x+50,use2.y+50);
}
drawtank(use2.x,use2.y,use2.life,use2.dir);
}
drawHome();
setfillcolor(GREEN);
   solidrectangle(1000,0,1010,650);
control_userInfo(count);
putimage(480, 610, &p, SRCINVERT);
FlushBatchDraw();
count++;
countBeginMusic++;
if(count==301)
count=0;
if(countBeginMusic==200)
{
mciSendString( "close begin", 0, 0, 0 );
mciSendString( "play background repeat", 0, 0, 0 );
}
if(countBeginMusic==600)
countBeginMusic=230;


Sleep(20);
mciSendString( "pause moveSelf", 0, 0, 0 );
clearrectangle(0,0,1000,650);
}
Sleep(50000);
return ok;
}
int init_userinfo()
{
FILE * fp;
int score=0;
if(use1life>0&&use1.life<=0)
{
use1.x=380;
use1.y=600;
use1.life=50;
use1.aggressivity=25;
use1.dir=up;
use1.speed=normal;
use1.atack=normal;
use1.defence=normal;
}
else
{
if(MODEL==1)
{
if(use2life<=0&&use2.life<=0)
{
setfont( 30, 0,"楷体");
outtextxy(350,300,"Game End!!");
if(use1Score>use2Score)
{
score=use1Score;

}
else
{
score=use2Score;
}
if(score>highmark)
{
if((fp=fopen("gameMark.txt","w"))==NULL)
{
printf("File open eror!\n");
exit(eror);
}
else
{
fprintf(fp,"%d",score);
if(fclose(fp))
{
printf("file close eror\n");
exit(eror);
}
}
}
}
}
else if(use1life<=0&&use1.life<=0)
{
setfont( 30, 0,"楷体");
outtextxy(350,300,"Game End!!");
if(use1Score>highmark)
{
if((fp=fopen("gameMark.txt","w"))==NULL)
{
printf("File open eror!\n");
exit(eror);
}
else
{
fprintf(fp,"%d",use1Score);
if(fclose(fp))
{
printf("file close eror\n");
exit(eror);
}
}
}
}
}
if(MODEL==1)
{
if(use2life>0&&use2.life<=0)
{
use2.x=570;
use2.y=600;
use2.life=50;
use2.aggressivity=25;
use2.dir=up;
use2.speed=normal;
use2.atack=normal;
use2.defence=normal;
}
}
return ok;
}
int control_userInfo(int count)
{
char num[10];
FILE * fp;
int k;
if(count==0)  //读出历史最高分
{
if((fp=fopen("gameMark.txt","r"))==NULL)
{
printf("File open eror!\n");
exit(eror);
}
else
{
fscanf(fp,"%d",&highmark);
if(fclose(fp))
{
printf("file close eror\n");
exit(eror);
}
}
}
setfont( 20, 0,"楷体");
outtextxy(1020,50,"Score:");
sprintf(num, "%d", use1Score);
outtextxy(1080,50,num);
outtextxy(1020,90,"HP:");
setcolor(WHITE);
rectangle(1059,89,1161,111);
k=use1.life*2;
if(k<0)
k=0;
setfillcolor(RED);
solidrectangle(1060,90,1060+k,110);
setfillcolor(BLUE);
solidrectangle(1060+k,90,1160,110);
outtextxy(1020,120,"life:");
sprintf(num, "%d", use1life);
outtextxy(1080,120,num);
outtextxy(1070,200,"Player1");


outtextxy(1020,320,"Highrest:");
sprintf(num, "%d", highmark);
outtextxy(1110,320,num);


if(MODEL==1)
{
outtextxy(1020,350,"Score:");
sprintf(num, "%d", use2Score);
outtextxy(1080,350,num);


outtextxy(1020,90,"HP:");
k=use1.life*2;
if(k<0)
k=0;
setfillcolor(RED);
   solidrectangle(1060,390,1060+k,410);
setfillcolor(BLUE);
solidrectangle(1060+k,390,1160,410);
outtextxy(1020,420,"life:");
    sprintf(num, "%d", use2life);
    outtextxy(1080,420,num);
outtextxy(1070,500,"Player2");
}
if(count==300)  //存入历史记录最高分
{
if((MODEL==0&&use1Score>highmark)||(MODEL==1&&use1Score>highmark&&use1Score>use2Score))
{
if((fp=fopen("gameMark.txt","w"))==NULL)
{
printf("File open eror!\n");
exit(eror);
}
else
{
fprintf(fp,"%d",use1Score);
if(fclose(fp))
{
printf("file close eror\n");
exit(eror);
}
}
}
else if(MODEL==1&&use2Score>highmark&&use2Score>use1Score)
{
if((fp=fopen("gameMark.txt","w"))==NULL)
{
printf("File open eror!\n");
exit(eror);
}
else
{
fprintf(fp,"%d",use2Score);
if(fclose(fp))
{
printf("file close eror\n");
exit(eror);
}
}
}
}
return ok;
}
int control_property()
{
int i=0,j=0;
for(i=0;i<5;i++)//控制生成道具并对已经生成的道具存在时间递减，当clock等于0，道具消失。
{
if(pro[i].flag==0)
{
j=rand()%500;
if(j==1)
{
//控制道具生成位置不与玩家坦克位置相冲突。
pro[i].flag=1;
while(1)
{
pro[i].x=rand()%960;
   pro[i].y=rand()%610;
if(MODEL==0)
{
if(pro[i].x-use1.x>-50&&pro[i].x-use1.x<50&&pro[i].y-use1.y>-50&&pro[i].y-use1.y<50)
continue;
else 
break;
}
else
{
if((pro[i].x-use1.x>-50&&pro[i].x-use1.x<50&&pro[i].y-use1.y>-50&&pro[i].y-use1.y<50)
||(pro[i].x-use2.x>-50&&pro[i].x-use2.x<50&&pro[i].y-use2.y>-50&&pro[i].y-use2.y<50))
continue;
else 
break;
}
}
pro[i].clock=500;
j=rand()%5;
switch(j)
{
case 0:
pro[i].con=addSpeed;
break;
case 1:
pro[i].con=addAggressivity;
break;
case 2:
pro[i].con=invincible;
break;
case 3:
pro[i].con=addOneLife;
break;
case 4:
pro[i].con=killAll;
break;
}
}
}
else
{
if(pro[i].clock<=0)
pro[i].flag=0;
else
pro[i].clock--;

}
}
//判断玩家坦克是否接到道具,并修改接到道具的玩家坦克的相应成员变量。
for(i=0;i<5;i++)
{
if(pro[i].flag==1)
{
if(use1.x-pro[i].x>-50&&use1.x-pro[i].x<40&&use1.y-pro[i].y>-50&&use1.y-pro[i].y<40)
{
pro[i].flag=0;
mciSendString( "close eatting", 0, 0, 0 );
mciSendString( "open ./source/eatting.mp3 alias eatting", 0, 0, 0 );
mciSendString( "play eatting", 0, 0, 0 );
if(pro[i].con==addOneLife)
{
use1life++;
mciSendString( "close getLife", 0, 0, 0 );
   mciSendString( "open ./source/getLife.mp3 alias getLife", 0, 0, 0 );
   mciSendString( "play getLife", 0, 0, 0 );
}
else if(pro[i].con==killAll)
{
for(j=0;j<NUME;j++)
{
if(flagLife[j]==true)
{
use1Score += enm[j].life;
flagLife[j]=false;
enemyNum--;
}
}
}
else if(pro[i].con==addAggressivity)
{
use1.atack=addAggressivity;
use1.aggressivity = 100;
use1.clocka = 500;
}
else if(pro[i].con==addSpeed)
{
use1.speed = addSpeed;
use1.clocks = 500;
}
else
{
use1.defence = invincible;
use1.clockd = 500;
}
}
if(MODEL==1)
{
if(use2.x-pro[i].x>-50&&use2.x-pro[i].x<40&&use2.y-pro[i].y>-50&&use2.y-pro[i].y<40)
{
mciSendString( "close eatting", 0, 0, 0 );
       mciSendString( "open ./source/eatting.mp3 alias eatting", 0, 0, 0 );
   mciSendString( "play eatting", 0, 0, 0 );
pro[i].flag=0;
if(pro[i].con==addOneLife)
{
use2life++;
}
else if(pro[i].con==killAll)
{
for(j=0;j<NUME;j++)
{
if(flagLife[j]==true)
{
use2Score += enm[j].life;
flagLife[j]=false;
enemyNum--;
}
}
}
else if(pro[i].con==addAggressivity)
{
use2.atack=addAggressivity;
use2.aggressivity = 100;
use2.clocka = 500;
}
else if(pro[i].con==addSpeed)
{
use2.speed = addSpeed;
use2.clocks = 500;
}
else
{
use2.defence = invincible;
use2.clockd = 500;
}
}
}
}
}
//玩家的道具状态计时器递减并恢复计时器到达0的道具状态效果。
if(use1.defence==invincible)
{
use1.clockd--;
if(use1.clockd<=0)
use1.defence=normal;
}
if(use1.atack==addAggressivity)
{
use1.clocka--;
if(use1.clocka<=0)
use1.atack=normal;
}
if(use1.speed==addSpeed)
{
use1.clocks--;
if(use1.clocks<=0)
use1.speed=normal;
}
if(MODEL==1)
{
if(use2.defence==invincible)
{
use2.clockd--;
if(use1.clockd<=0)
   use1.defence=normal;
}
if(use2.atack==addAggressivity)
{
use2.clocka--;
if(use2.clocka<=0)
{
use2.atack=normal;
use2.aggressivity=25;
}
}
if(use2.speed==addSpeed)
{
use2.clocks--;
if(use2.clocks<=0)
{
use2.speed=normal;
}
}
}
//draw 道具
for(i=0;i<5;i++)
{
if(pro[i].flag==1)
{
switch(pro[i].con)
{
case addSpeed:
rectangle(pro[i].x+13,pro[i].y+10,pro[i].x+27,pro[i].y+30);
line(pro[i].x+13,pro[i].y+10,pro[i].x+20,pro[i].y);
line(pro[i].x+27,pro[i].y+10,pro[i].x+20,pro[i].y);
line(pro[i].x+13,pro[i].y+30,pro[i].x,pro[i].y+40);
line(pro[i].x+27,pro[i].y+30,pro[i].x+40,pro[i].y+40);
line(pro[i].x+20,pro[i].y+30,pro[i].x+20,pro[i].y+40);
break;
case addAggressivity:
rectangle(pro[i].x,pro[i].y+20,pro[i].x+40,pro[i].y+40);
solidcircle(pro[i].x+20,pro[i].y+30,5);
rectangle(pro[i].x+17,pro[i].y,pro[i].x+23,pro[i].y+25);
break;
case addOneLife:
setfillcolor(RED);
solidrectangle(pro[i].x,pro[i].y+15,pro[i].x+40,pro[i].y+40);
solidrectangle(pro[i].x+18,pro[i].y+4,pro[i].x+22,pro[i].y+15);
solidellipse(pro[i].x+17,pro[i].y,pro[i].x+23,pro[i].y+4);
break;
case invincible:
line(pro[i].x,pro[i].y,pro[i].x,pro[i].y+30);
line(pro[i].x+40,pro[i].y,pro[i].x+40,pro[i].y+30);
line(pro[i].x+20,pro[i].y+10,pro[i].x+20,pro[i].y+40);
line(pro[i].x,pro[i].y,pro[i].x+20,pro[i].y+10);
line(pro[i].x+40,pro[i].y,pro[i].x+20,pro[i].y+10);
line(pro[i].x,pro[i].y+30,pro[i].x+20,pro[i].y+40);
line(pro[i].x+40,pro[i].y+30,pro[i].x+20,pro[i].y+40);
line(pro[i].x,pro[i].y+15,pro[i].x+20,pro[i].y+25);
line(pro[i].x+40,pro[i].y+15,pro[i].x+20,pro[i].y+25);
break;
case killAll:
setfillcolor(YELLOW);
solidcircle(pro[i].x+20,pro[i].y+25,15);
solidrectangle(pro[i].x+18,pro[i].y+4,pro[i].x+22,pro[i].y+10);
solidrectangle(pro[i].x+15,pro[i].y,pro[i].x+25,pro[i].y+4);
line(pro[i].x+15,pro[i].y+2,pro[i].x+10,pro[i].y+7);

break;
}
}
}
return ok;
}
int controlBomb()  //对击中的坦克的生命值减定量,并改变子弹位置。
{
int i;
for(i=0;i<NUME;i++)  //判断是否击中玩家坦克
{
if(MODEL==0&&flagB[i]==true)
{
if(isTarget(use1,enemyBomb[i]))
{
if(use1.defence==normal)
{
use1.life -= enemyBomb[i].aggressivity;
}
flagB[i]=false;
}
}
else if(flagB[i]==true)
{
if(isTarget(use1,enemyBomb[i]))
{
flagB[i]=false;
}
else
{
if(isTarget(use2,enemyBomb[i]))
{
flagB[i]=false;
}
}
}
}
for(i=0;i<NUME;i++)  //判断敌军坦克和玩家坦克子弹是否发生碰撞
{
if(flagB[i]==true&&FLAGBOMB1==true)
{ 
if((enemyBomb[i].x-use1Bomb.x<8&&enemyBomb[i].x-use1Bomb.x>-8)
&&(enemyBomb[i].y-use1Bomb.y<8&&enemyBomb[i].y-use1Bomb.y>-8))
{
mciSendString( "close bombing", 0, 0, 0 );
   mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
flagB[i]=false;
FLAGBOMB1=false;
}
else if(MODEL==1&&FLAGBOMB2==true&&(enemyBomb[i].x-use2Bomb.x<8&&enemyBomb[i].x-use2Bomb.x>-8)
&&(enemyBomb[i].y-use2Bomb.y<8&&enemyBomb[i].y-use2Bomb.y>-8))
{
mciSendString( "close bombing", 0, 0, 0 );
   mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
flagB[i]=false;
FLAGBOMB2=false;
}
}
}
/*for(i=0;i<NUME;i++)  //判断敌军坦克和玩家坦克子弹是否发生碰撞
{
if(flagB[i]==true&&FLAGBOMB1==true)
{
if((enemyBomb[i].x-use1Bomb.x<8&&enemyBomb[i].x-use1Bomb.x>-8)
&&(enemyBomb[i].y-use1Bomb.y<8&&enemyBomb[i].y-use1Bomb.y>-8))
{
mciSendString( "play bombing ", 0, 0, 0 );
flagB[i]=false;
FLAGBOMB1=false;
}
else if(MODEL==1&&FLAGBOMB2==true&&(enemyBomb[i].x-use2Bomb.x<8&&enemyBomb[i].x-use2Bomb.x>-8)
&&(enemyBomb[i].y-use2Bomb.y<8&&enemyBomb[i].y-use2Bomb.y>-8))
{
flagB[i]=false;
FLAGBOMB2=false;
}
}
}*/
for(i=0;i<NUME;i++)  //改变敌军子弹位置
{
if(flagB[i]==true)
{
switch (enemyBomb[i].dir)
{
case up:
enemyBomb[i].y += enemyBomb[i].speed;
break;
case down:
enemyBomb[i].y -= enemyBomb[i].speed;
break;
case left:
enemyBomb[i].x -= enemyBomb[i].speed;
break;
case right:
enemyBomb[i].x += enemyBomb[i].speed;
break;
}
}
}
if(FLAGBOMB1==true)   //改变玩家坦克子弹位置
{
switch (use1Bomb.dir)
{
case up:
use1Bomb.y -= use1Bomb.speed;
break;
case down:
use1Bomb.y += use1Bomb.speed;
break;
case left:
use1Bomb.x -= use1Bomb.speed;
break;
case right:
use1Bomb.x += use1Bomb.speed;
break;
}
if(use1Bomb.x<0||use1Bomb.y<0||use1Bomb.x>1000||use1Bomb.y>650)    //判断玩家1子弹是否出界
{
    mciSendString( "close bombing", 0, 0, 0 );
mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
FLAGBOMB1=false;
}
}
if(MODEL==1&&FLAGBOMB2==true)
{
switch (use2Bomb.dir)
{
case up:
use2Bomb.y -= moveLength;
break;
case down:
use2Bomb.y += moveLength;
break;
case left:
use2Bomb.x -= moveLength;
break;
case right:
use2Bomb.x += moveLength;
break;
}
if(use2Bomb.x<0||use2Bomb.y<0||use2Bomb.x>1000||use2Bomb.y>650)  //判断玩家2子弹是否出界
{
mciSendString( "close bombing", 0, 0, 0 );
mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
   mciSendString( "play bombing", 0, 0, 0 );
FLAGBOMB2=false;
}
}
for(i=0;i<NUME;i++)           //判断敌军子弹是否出界
{
if(flagB[i]==true)
if(enemyBomb[i].x<0||enemyBomb[i].y<0||enemyBomb[i].x>1000||enemyBomb[i].y>650)
{
   flagB[i]=false;
}
}
return ok;

}
bool isTarget(USER tar,BOMB bomb)
{
if(bomb.x-tar.x>-4&&bomb.x-tar.x<54&&bomb.y-tar.y>-4&&bomb.y-tar.y<54)
return true;
else 
return false;
}
bool isTarget2(ENEMY tar,BOMB bomb)
{
if(bomb.x-tar.x>-4&&bomb.x-tar.x<54&&bomb.y-tar.y>-4&&bomb.y-tar.y<54)
return true;
else 
return false;
}
int controlUser()//监控键盘，控制玩家坦克的位置、状态、生命
{
char b;
int flag=0,i=0;
if(use1.life<=0||use2.life<=0)
init_userinfo();
if(kbhit())
{
b=getch();
if((b==32)&&FLAGBOMB1==false)  //监控空格键玩家1发射子弹
{
mciSendString( "close launchBomb ", 0, 0, 0 );
mciSendString( "open ./source/launchBomb.mp3 alias launchBomb", 0, 0, 0 );
mciSendString( "play launchBomb ", 0, 0, 0 );
FLAGBOMB1=true;
switch (use1.dir)
{
case up:
use1Bomb.dir=up;
use1Bomb.x=use1.x+25;
use1Bomb.y=use1.y+4;
break;
case down:
use1Bomb.dir=down;
use1Bomb.x=use1.x+25;
use1Bomb.y=use1.y+54;
break;
case left:
use1Bomb.dir=left;
use1Bomb.x=use1.x-4;
use1Bomb.y=use1.y+25;
break;
case right:
use1Bomb.dir=right;
use1Bomb.x=use1.x+54;
use1Bomb.y=use1.y+25;
break;
}
use1Bomb.aggressivity=use1.aggressivity;
if(use1.speed==addSpeed)
use1Bomb.speed = BombNormalSpeed + BombAddSpeed;
else 
use1Bomb.speed = BombNormalSpeed;
}
else
{ 
switch(b)
{
case 'w':  //控制玩家1坦克行驶
case 'W':
mciSendString( "resume moveSelf ", 0, 0, 0 );
use1.dir=up;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.y>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,up))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.y -=10;
else
use1.y -=5;
}
}
break;
case 's':
case 'S':
mciSendString( "resume moveSelf ", 0, 0, 0 );
use1.dir=down;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.y<=595)

{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,down))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.y +=10;
else
use1.y +=5;
}
}
break;
case 'a':
case 'A':
mciSendString( "resume moveSelf ", 0, 0, 0 );
use1.dir=left;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.x>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,left))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.x -=10;
else
use1.x -=5;
}
}
break;
case 'd':
case 'D':
mciSendString( "resume moveSelf ", 0, 0, 0 );
use1.dir=right;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.x<=945)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,right))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.x +=10;
else
use1.x +=5;
}
}
break;
}
} 
switch(b) //控制玩家1或玩家2坦克行驶
{
case 72:
mciSendString( "resume moveSelf ", 0, 0, 0 );
if(MODEL==0)
{
use1.dir=up;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.y>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,up))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.y -=10;
else
use1.y -=5;
}
}
}
else
{
use2.dir=up;
if(is_warded(use2.x,use2.y,use2.dir,0))
       flag=1;
if(use2.y>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use2.x,use2.y,enm[i].x,enm[i].y,up))
flag=1;
}
if(flag==0)
{
if(use2.speed==addSpeed)
use2.y -=10;
else
use2.y -=5;
}
}
}
break;
case 80:
mciSendString( "resume moveSelf ", 0, 0, 0 );
if(MODEL ==0)
{
use1.dir=down;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.y<=595)

{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,down))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.y +=10;
else
use1.y +=5;
}
}
}
else
{
use2.dir=down;
if(is_warded(use2.x,use2.y,use2.dir,0))
       flag=1;
if(use2.y<=595)

{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use2.x,use2.y,enm[i].x,enm[i].y,down))
flag=1;
}
if(flag==0)
{
if(use2.speed==addSpeed)
use2.y -=10;
else
use2.y -=5;
}
}
}
break;
case 75:
mciSendString( "resume moveSelf ", 0, 0, 0 );
if(MODEL==0)
{
use1.dir=left;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.x>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,left))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.x -=10;
else
use1.x -=5;
}
}
}
else
{
use2.dir=left;
if(is_warded(use2.x,use2.y,use2.dir,0))
       flag=1;
if(use2.x>=5)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use2.x,use2.y,enm[i].x,enm[i].y,left))
flag=1;
}
if(flag==0)
{
if(use2.speed==addSpeed)
use2.x -=10;
else
use2.x -=5;
}
}
}
break;
case 77:
mciSendString( "resume moveSelf ", 0, 0, 0 );
if(MODEL==0)
{
use1.dir=right;
if(is_warded(use1.x,use1.y,use1.dir,0))
       flag=1;
if(use1.x<=945)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use1.x,use1.y,enm[i].x,enm[i].y,right))
flag=1;
}
if(flag==0)
{
if(use1.speed==addSpeed)
use1.x +=10;
else
use1.x +=5;
}
}
}
else
{
use2.dir=right;
if(is_warded(use2.x,use2.y,use2.dir,0))
       flag=1;
if(use2.x<=945)
{
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true&&is_collision(use2.x,use2.y,enm[i].x,enm[i].y,right))
flag=1;
}
if(flag==0)
{
if(use2.speed==addSpeed)
use2.x +=10;
else
use2.x +=5;
}
}
}
break;
}
if(MODEL==1)
{
if((b=='0'||b=='l'||b=='L')&&FLAGBOMB2==false)  //监控玩家2发射子弹
{
mciSendString( "close launchBomb ", 0, 0, 0 );
   mciSendString( "open ./source/launchBomb.mp3 alias launchBomb", 0, 0, 0 );
    mciSendString( "play launchBomb ", 0, 0, 0 );
FLAGBOMB2=true;
switch (use2.dir)
{
case up:
use2Bomb.dir=up;
use2Bomb.x=use2.x+25;
use2Bomb.y=use2.y+4;
break;
case down:
use2Bomb.dir=down;
use2Bomb.x=use2.x+25;
use2Bomb.y=use2.y+54;
break;
case left:
use2Bomb.dir=left;
use2Bomb.x=use2.x-4;
use2Bomb.y=use2.y+25;
break;
case right:
use2Bomb.dir=right;
use2Bomb.x=use2.x+54;
use2Bomb.y=use2.y+25;
break;
}
use2Bomb.aggressivity=use2.aggressivity;
if(use2.atack==addAggressivity)
use2Bomb.aggressivity += 25;
if(use2.speed==addSpeed)
use2Bomb.speed = BombNormalSpeed + BombAddSpeed;
else 
use2Bomb.speed = BombNormalSpeed;
}
}
}
return ok;
}
int controlEnemy()  //控制敌军坦克的生成、击毁消失和发射炮弹。
{
int add=0,i=0,x=0,y=0,flag=0,j=0,k=0,pos=0;
if(enemyNum<4)  //坦克数量少于4就新生成坦克
{
   add=rand()%4+1;
for(i=0;i<add;)
{
x=rand()%951;
for(j=0;j<NUME;j++)
{
if(flagLife[j]==true)
if(enm[j].x-x<=50&&enm[j].x-x>=-50) //坦克位置发生冲突
   flag=1;
}
if(flag==0)
{
for(pos=0;pos<NUME;pos++)
{
if(flagLife[pos]==false)
break;
}
if(flagLife[pos]==false)
{
enm[pos].x=x;
enm[pos].y=y;
enm[pos].life=(rand()%3+1)*25;
enm[pos].aggressivity=20;
j=rand()%4;
switch(j)
{
case 0:
enm[pos].dir=up;
break;
case 1:
enm[pos].dir=right;
break;
case 2:
enm[pos].dir=down;
break;
case 3:
enm[pos].dir=left;
break;
}
i++;
enemyNum++;
flagLife[pos]=true;
}
else
{
break;  //没有足够位置生成新坦克。
}
}
else
flag=0;
}
}
for(i=0;i<NUME;i++)  //判断是否击中敌军坦克
{
if(MODEL==0&&flagLife[i]==true&&FLAGBOMB1==true)
{
if(isTarget2(enm[i],use1Bomb))
{
mciSendString( "close bombing", 0, 0, 0 );
   mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
if(enm[i].life>use1Bomb.aggressivity)
use1Score += use1Bomb.aggressivity;
else
use1Score += enm[i].life;
enm[i].life -= use1Bomb.aggressivity;
FLAGBOMB1=false;
break;
}
}
else if(MODEL==1&&flagLife[i]==true&&FLAGBOMB1==true)
{
if(isTarget2(enm[i],use1Bomb))
{
mciSendString( "close bombing", 0, 0, 0 );
   mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
if(enm[i].life>use1Bomb.aggressivity)
use1Score += use1Bomb.aggressivity;
else
use1Score += enm[i].life;
enm[i].life -= use1Bomb.aggressivity;
FLAGBOMB1=false;
break;
}
if(MODEL==1&&flagLife[i]==true&&FLAGBOMB2==true)
{
if(isTarget2(enm[i],use2Bomb))
{
mciSendString( "close bombing", 0, 0, 0 );
mciSendString( "open ./source/bombing.mp3 alias bombing", 0, 0, 0 );
mciSendString( "play bombing", 0, 0, 0 );
if(enm[i].life>use2Bomb.aggressivity)
use2Score += use2Bomb.aggressivity;
else
use2Score += enm[i].life;
enm[i].life -= use2Bomb.aggressivity;
FLAGBOMB2 = false;
break;
}
}
}
}
for(i=0;i<NUME;i++)   //坦克被击毁
{
if(flagLife[i]==true&&enm[i].life<=0)
{
flagLife[i]=false;
enemyNum--;
}
if(flagLife[i]==true&&flagB[i]==false)  // 1/35的概率发射炮弹
{
k=rand()%50;
if(k==3)  //k=3代表发炮
{
flagB[i]=1;
enemyBomb[i].aggressivity=enm[i].aggressivity;
enemyBomb[i].dir=enm[i].dir;
enemyBomb[i].speed=BombNormalSpeed;
switch (enm[i].dir)
{
case up:
enemyBomb[i].x=enm[i].x+25;
enemyBomb[i].y=enm[i].y+4;
break;
case down:
enemyBomb[i].x=enm[i].x+25;
enemyBomb[i].y=enm[i].y+54;
break;
case left:
enemyBomb[i].x=enm[i].x-4;
enemyBomb[i].y=enm[i].y+25;
break;
case right:
enemyBomb[i].x=enm[i].x+54;
enemyBomb[i].y=enm[i].y+25;
break;
}
}
}
}
return ok;
}
int tankMove()
{
int i,d=0,j=0,k=0,flag=0;
for(i=0;i<NUME;i++)
{
if(flagLife[i]==true)
{
d=rand()%30;
if(d==4)  // 1/5概率改变方向
{
if(enm[i].dir=up)
j=0;
else if(enm[i].dir=right)
j=1;
else if(enm[i].dir=down)
j=2;
else 
j=3;
do{
d=rand()%4;
}while(d==j);
switch(d)
{
case 0:
enm[i].dir=up;
break;
case 1:
enm[i].dir=right;
break;
case 2:
enm[i].dir=down;
break;
case 3:
enm[i].dir=left;
break;
}
}
else     //坦克位置改变。
{
switch (enm[i].dir)
{
case up:
if(enm[i].y>=2)
{
if(is_warded(enm[i].x,enm[i].y,enm[i].dir,1))
               flag=1;
for(k=0;k<NUME;k++)
{
if(flagLife[k]==true&&k!=i&&enm[k].x-enm[i].x<50&&enm[k].x-enm[i].x>-50&&enm[i].y-enm[k].y>=50&&enm[i].y-enm[k].y<52)
flag=1;
}
if(use1.x-enm[i].x<50&&use1.x-enm[i].x>-50&&enm[i].y-use1.y>=50&&enm[i].y-use1.y<52)
flag=1;
else if(MODEL==1&&use2.x-enm[i].x<50&&use2.x-enm[i].x>-50&&enm[i].y-use2.y>=50&&enm[i].y-use2.y<52)
flag=1;
if(flag==0)
enm[i].y -= 2;
else
flag=0;
}
else
enm[i].dir=down;
break;
case down:
if(enm[i].y<=598)
{
if(is_warded(enm[i].x,enm[i].y,enm[i].dir,1))
               flag=1;
for(k=0;k<NUME;k++)
{
if(flagLife[k]==true&&k!=i&&enm[k].x-enm[i].x<50&&enm[k].x-enm[i].x>-50&&enm[k].y-enm[i].y>=50&&enm[k].y-enm[i].y<52)
flag=1;
}
if(use1.x-enm[i].x<50&&use1.x-enm[i].x>-50&&use1.y-enm[i].y>=50&&use1.y-enm[i].y<52)
flag=1;
else if(MODEL==1&&use2.x-enm[i].x<50&&use2.x-enm[i].x>-50&&use2.y-enm[i].y>=50&&use2.y-enm[i].y<52)
flag=1;
if(flag==0)
   enm[i].y += 2;
else 
flag=0;
}
else
enm[i].dir=up;
break;
case left:
if(enm[i].x>=2)
{
if(is_warded(enm[i].x,enm[i].y,enm[i].dir,1))
               flag=1;
for(k=0;k<NUME;k++)
{
if(flagLife[k]==true&&k!=i&&enm[k].y-enm[i].y<50&&enm[k].y-enm[i].y>-50&&enm[i].x-enm[k].x>=50&&enm[i].x-enm[k].x<52)
flag=1;
}
if(use1.y-enm[i].y<50&&use1.y-enm[i].y>-50&&enm[i].x-use1.x>=50&&enm[i].x-use1.x<52)
flag=1;
else if(MODEL==1&&use2.y-enm[i].y<50&&use2.y-enm[i].y>-50&&enm[i].x-use2.x>=50&&enm[i].x-use2.x<52)
flag=1;
if(flag==0)
   enm[i].x -= 2;
else 
flag=0;;
}
else
enm[i].dir=right;
break;
case right:
if(enm[i].x<=948)
{
if(is_warded(enm[i].x,enm[i].y,enm[i].dir,1))
               flag=1;
for(k=0;k<NUME;k++)
{
if(flagLife[k]==true&&k!=i&&enm[k].y-enm[i].y<50&&enm[k].y-enm[i].y>-50&&enm[k].x-enm[i].x<52&&enm[k].x-enm[i].x>=50)
flag=1;
}
if(use1.y-enm[i].y<50&&use1.y-enm[i].y>-50&&use1.x-enm[i].x<52&&use1.x-enm[i].x>=50)
flag=1;
else if(MODEL==1&&use2.y-enm[i].y<50&&use2.y-enm[i].y>-50&&use2.x-enm[i].x<52&&use2.x-enm[i].x>=50)
flag=1;
if(flag==0)
   enm[i].x += 2;
else
flag=0;  
}
else
enm[i].dir=right;
break;
}
}
}
}
return ok;
}
int is_collision(int x1,int y1,int x2,int y2,direction dir)
{
int flag=0;
switch(dir)
{
case up:
if(x1-x2<50&&x1-x2>-50&&y1-y2<54&&y1-y2>0)
flag=1;
break;
case down:
if(x1-x2<50&&x1-x2>-50&&y2-y1<54&&y2-y1>0)
flag=1;
break;
case left:
if(y1-y2<50&&y1-y2>-50&&x1-x2<54&&x1-x2>0)
flag=1;
break;
case right:
if(y1-y2<50&&y1-y2>-50&&x2-x1<54&&x2-x1>0)
flag=1;
break;
}
return flag;
}
int drawtank(int i,int j,int life,direction dir)//long=50,wide=50
{
if(life<=25)
{
setfillcolor(WHITE);
setcolor(WHITE);
}
else if(life<=50&&life>25)
{
setfillcolor(YELLOW);
setcolor(YELLOW);
}
else 
{
setfillcolor(GREEN);
setcolor(GREEN);
}
if(dir==up)
{
rectangle(i+5,j+10,i+45,j+50);
for(int k=0;k<4;k++)
{
circle(i+5,j+15+k*10,5);
circle(i+45,j+15+k*10,5);
}
clearrectangle(i+5+1,j+10+1,i+45-1,j+50-1);
rectangle(i,j+5,i+5,j+50);
rectangle(i+45,j+5,i+50,j+50);
rectangle(i+10,j+15,i+40,j+45);
rectangle(i+23,j,i+27,j+25);
solidcircle(i+25,j+30,5);
rectangle(i+18,j+20,i+32,j+40);
}
else if(dir==down)
{
rectangle(i+5,j,i+45,j+40);
for(int k=0;k<4;k++)
{
circle(i+5,j+5+k*10,5);
circle(i+45,j+5+k*10,5);
}
clearrectangle(i+5+1,j+1,i+45-1,j+40-1);
rectangle(i,j,i+5,j+45);
rectangle(i+45,j,i+50,j+45);
rectangle(i+10,j+5,i+40,j+35);
rectangle(i+23,j+25,i+27,j+50);
solidcircle(i+25,j+20,5);
rectangle(i+18,j+10,i+32,j+30);
}
else if(dir==left)
{
rectangle(i+10,j+5,i+50,j+45);
for(int k=0;k<4;k++)
{
circle(i+15+k*10,j+5,5);
circle(i+15+k*10,j+45,5);
}
clearrectangle(i+10+1,j+5+1,i+50-1,j+45-1);
rectangle(i+5,j,i+50,j+5);
rectangle(i+5,j+45,i+50,j+50);
rectangle(i+15,j+10,i+45,j+40);
rectangle(i,j+23,i+25,j+27);
solidcircle(i+30,j+25,5);
rectangle(i+20,j+18,i+40,j+32);
}
else
{
   rectangle(i,j+5,i+40,j+45);
for(int k=0;k<4;k++)
{
circle(i+5+k*10,j+5,5);
circle(i+5+k*10,j+45,5);
}
clearrectangle(i+1,j+5+1,i+40-1,j+45-1);
rectangle(i,j,i+45,j+5);
rectangle(i,j+45,i+45,j+50);
rectangle(i+5,j+10,i+35,j+40);
rectangle(i+25,j+23,i+50,j+27);
solidcircle(i+20,j+25,5);
rectangle(i+10,j+18,i+30,j+32);
}
return ok;
}
int drawBomb()
{
int i=0;
setfillcolor(WHITE);
for(i=0;i<NUME;i++)
{
if(flagB[i]==true)
{
solidcircle(enemyBomb[i].x,enemyBomb[i].y,4);
}
}
if(FLAGBOMB1==true)
{
if(use1Bomb.aggressivity==25)
solidcircle(use1Bomb.x,use1Bomb.y,4);
else
{
setfillcolor(RED);
solidcircle(use1Bomb.x,use1Bomb.y,4);
setfillcolor(WHITE);
}
}
if(MODEL==1&&FLAGBOMB2==true)
{
if(use2Bomb.aggressivity==25)
solidcircle(use2Bomb.x,use2Bomb.y,4);
else
{
setfillcolor(RED);
solidcircle(use2Bomb.x,use2Bomb.y,4);
setfillcolor(WHITE);
}
}
return ok;
}
int drawHome()
{
int i=0;
for(i=0;i<8;i++)
{
if(wall[i][2]==1)
{
setfillcolor(RED);
solidrectangle(wall[i][0]+2,wall[i][1]+1,wall[i][0]+50-2,wall[i][1]+20-1);
setfillcolor(GREEN);
   solidrectangle(wall[i][0]+10,wall[i][1]+4,wall[i][0]+50-10,wall[i][1]+20-4);
}
}
if(wall[8][2]==1)
{
setfillcolor(RED);
solidrectangle(wall[8][0]+2,wall[8][1]+1,wall[8][0]+40-2,wall[8][1]+20-1);
setfillcolor(GREEN);
solidrectangle(wall[8][0]+10,wall[8][1]+4,wall[8][0]+40-10,wall[8][1]+20-4);
}
if(wall[9][2]==1)
{
setfillcolor(RED);
solidrectangle(wall[9][0]+2,wall[9][1]+1,wall[9][0]+40-2,wall[9][1]+20-1);
setfillcolor(GREEN);
solidrectangle(wall[9][0]+10,wall[9][1]+4,wall[9][0]+40-10,wall[9][1]+20-4);
}
return ok;
}
bool is_warded(int x,int y,direction dir,int tank)//判断是否有墙挡住坦克前进
{
int i=0,temp=5;
bool flag=false;
if(tank==1)
tank=2;
switch(dir)
{
case up:
y += temp;
break;
case down:
y -= temp;
break;
case left:
x -= temp;
break;
case right:
x += temp;
break;
}
for(i=0;i<8;i++)  //the wall of home
{
if(wall[i][2]==1&&i!=8&&i!=9)
{
if(dir==up)
{
if((y-wall[i][1])<20&&y-wall[i][1]>14&&x-wall[i][0]>-50&&x-wall[i][0]<50)
{
flag = true;
break;
} 
}
else if(dir==down)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<-44&&x-wall[i][0]>-50&&x-wall[i][0]<50)
{
flag = true;
break;
} 
}
else if(dir==left)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<20&&x-wall[i][0]<50&&x-wall[i][0]>44)
{
flag = true;
break;
} 
}
else if(dir==right)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<20&&x-wall[i][0]>-50&&x-wall[i][0]<0)
{
flag = true;
break;
} 
}
}
}
for(i=8;i<10;i++)
{
if(wall[i][2]==1)
{
if(dir==up)
{
if((y-wall[i][1])<20&&y-wall[i][1]>14&&x-wall[i][0]>-40&&x-wall[i][0]<40)
{
flag = true;
break;
} 
}
else if(dir==down)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<-44&&x-wall[i][0]>-40&&x-wall[i][0]<40)
{
flag = true;
break;
} 
}
else if(dir==left)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<20&&x-wall[i][0]<40&&x-wall[i][0]>34)
{
flag = true;
break;
} 
}
else if(dir==right)
{
if(y-wall[i][1]>-50&&y-wall[i][1]<20&&x-wall[i][0]>-50&&x-wall[i][0]<-44)
{
flag = true;
break;
} 
}
}
}
return flag;
}
int start_interface()
{
int flag=1,flag1=0,flag2=0,flag3=0,count=0,i=0,j=0,pos=0,first=460,add=0;
char str[20]={"<< slide to start"},s[5];
IMAGE phob,pho;
MOUSEMSG p;
loadimage(&phob,"./source/arrowBK.jpg", 280, 40);
loadimage(&pho,"./source/arrow.jpg", 50, 40);
    settextstyle(40, 20, _T("楷体"));
settextcolor(YELLOW);
setcolor(YELLOW);
BeginBatchDraw();
while(flag)
{
settextcolor(YELLOW);
outtextxy(340,100,"90版经典坦克大战专属版");
outtextxy(500,300,"one player");
outtextxy(500,380,"two player");
rectangle(500-5,300-3,700+5,340+3);
rectangle(500-5,380-3,700+5,420+3);
rectangle(500-10,300-6,700+10,340+6);
rectangle(500-10,380-6,700+10,420+6);


settextcolor(RED);
outtextxy(430,500,str);
settextcolor(WHITE);
putimage(460, 560, &phob, SRCINVERT);
clearrectangle(460,560,510,600);
putimage(460, 560, &pho, SRCINVERT);
for(i=pos,j=0;j<3&&i<17;i++,j++)
s[j]=str[i];
s[j]='\0';
outtextxy(430+pos*20,500,s);


if(flag1==0)
setfillcolor(WHITE);
else 
setfillcolor(GREEN);
solidrectangle(430,310,460,330);
solidcircle(430,320,10);
solidcircle(460,320,10);
if(flag2==0)
setfillcolor(WHITE);
else 
setfillcolor(GREEN);
solidrectangle(430,390,460,410);
solidcircle(430,400,10);
solidcircle(460,400,10);
if(flag1==0)
setfillcolor(GREEN);
else 
setfillcolor(WHITE);
solidcircle(430+flag1*30,320,9);
if(flag2==0)
setfillcolor(GREEN);
else 
setfillcolor(WHITE);
solidcircle(430+flag2*30,400,9);
if(MouseHit())
{
p=GetMouseMsg();
if(p.mkLButton==true)
{
if((p.x-430)*(p.x-430)+(p.y-320)*(p.y-320)<100||(p.x>=430&&p.x<=460&&p.y>=310&&p.y<=330)||
(p.x-460)*(p.x-460)+(p.y-320)*(p.y-320)<100)
{
if(flag1==0)
flag1=1;
else
flag1=0;
}
if((p.x-430)*(p.x-430)+(p.y-400)*(p.y-400)<100||(p.x>=430&&p.x<=460&&p.y>=390&&p.y<=410)||
(p.x-460)*(p.x-460)+(p.y-400)*(p.y-400)<100)
{
if(flag2==0)
flag2=1;
else
flag2=0;
}
if(flag1+flag2==1)
{
if(p.x>460&&p.x<510&&p.y>560&&p.y<600)
{
first=p.x;
p=GetMouseMsg();
if(p.uMsg==WM_MOUSEMOVE)
{
while(1)
{
p=GetMouseMsg();
add=p.x-first;
if(add>230)
add=230;
if(add>=0)
{
clearrectangle(460, 560,740,600);
putimage(460, 560, &phob, SRCINVERT);
clearrectangle(460+add,560,510+add,600);
putimage(460+add, 560, &pho, SRCINVERT);
}
if(p.uMsg==WM_LBUTTONUP)
{
if(p.x-first>220&&p.y>560&&p.y<600)
{
flag=0;
break;
}
else
{
while(add>0)
{
clearrectangle(460, 560,740,600);
putimage(460, 560, &phob, SRCINVERT);
clearrectangle(460+add,560,510+add,600);
putimage(460+add, 560, &pho, SRCINVERT);
add -=5;
FlushBatchDraw();
Sleep(20);
}
break;
}
}
FlushBatchDraw();
//Sleep(10);
}
}
}
}
}
}
count++;
if(count==28)
{
count=0;
pos++;
}
if(pos==17)
pos=0;
FlushBatchDraw();
Sleep(5);
cleardevice();
}
if(flag1==1&&flag2==0)
MODEL=0;
else if(flag1==0&&flag2==1)
MODEL=1;
else
{
printf("game init eror!!");
exit(1);
}
return 1;
}
