#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "oyun.h"

    Position player;
    ScoreTablo *list;
    int score=0,life=3,sc=0,sp=0,game=COUNTOFLIST;

void createArea()
{
    int i,j;
    A=(char **) malloc(SIZE*sizeof(char *));
    for(i=0;i<SIZE;i++)
    {
        A[i]=(char *) malloc(SIZE*sizeof(char));
    }
    list=(ScoreTablo *) malloc(game*sizeof(ScoreTablo));
}
void freeMalloc()
{
    free(A);
    free(list);
}
void listOfHighScore()
{
    strcpy((list+0)->name,"Samet");
    strcpy((list+1)->name,"Derya");
    strcpy((list+2)->name,"Hakan");
    strcpy((list+3)->name,"Deniz");
    strcpy((list+4)->name,"Ecem");
    (list+0)->hScore=67;
    (list+1)->hScore=48;
    (list+2)->hScore=2;
    (list+3)->hScore=-15;
    (list+4)->hScore=-30;
}

void startGame()
{
    game++;
    createLabyrinth();
    createMonsters();
    scoring();
    startlocation();
    printGame();
    playerMoveControl();
}
void createLabyrinth()
{
    system("COLOR 3");
    int i,j;
	for (i=0;i<SIZE;i++)
	{
		for (j=0;j<SIZE;j++)
		{
			A[i][j]=WALL;
		}
	}

    srand(time(NULL));

    for(i=1;i<(SIZE-1);i+=1)
    {
        for(j=1;j<(SIZE-1);j++)
        {
            A[i][j]=SPACE;
        }
    }
    for(i=1;i<(SIZE-1);i+=1)
    {
        for(j=1;j<(SIZE-1);j++)
        {
            if(rand()%DENSITYofWALL==1
                && A[i+1][j]!=WALL
                    && A[i-1][j]!=WALL
                        && A[i][j-1]!=WALL
                            &&  A[i][j+1]!=WALL)
            {
                A[i][j]=WALL;
            }
        }
    }
}

void scoring()
{
    int i,j;
    srand(time(NULL));

    for(i=1;i<(SIZE-1);i+=1)
    {
        for(j=1;j<(SIZE-1);j++)
        {
            if(rand()%DENSITYofPOINT==1 && A[i][j]==SPACE)
            {
                A[i][j]=POINT;
            }
        }
    }
}

void createMonsters()
{
    int i,j;
    srand(time(NULL));

    for(i=1;i<(SIZE-1);i+=1)
    {
        for(j=1;j<(SIZE-1);j++)
        {
            if(rand()%DENSITYofMONSTER==1 && A[i][j]==SPACE)
            {
                A[i][j]=MONSTER;
            }
        }
    }
}

void startlocation()
{
    player.x=1;
    player.y=1;
    A[player.x][player.y]=PLAYER;
}

void playerMoveControl()
{
    char direct;
    while(1!=0)
    {
        direct = getch();

        switch(direct)
        {
            case LEFT :
                if((unsigned char) A[player.y][player.x-1]!=WALL )
                {
                    if(A[player.y][player.x-1]==MONSTER)
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][--player.x]=PLAYER;
                        life-=1;
                        score-=10;
                        printGame(A);
                        endOfTheGame();
                    }
                    else if(A[player.y][player.x-1]==POINT)
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][--player.x]=PLAYER;
                        score+=3;
                        printGame(A);
                        endOfTheGame();
                    }
                    else
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][--player.x]=PLAYER;
                        printGame(A);
                    }

                }
                break;
            case RIGHT :
                if((unsigned char) A[player.y][player.x+1]!=WALL )
                {
                    if(A[player.y][player.x+1]==MONSTER)
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][++player.x]=PLAYER;
                        life-=1;
                        score-=10;
                        printGame(A);
                        endOfTheGame();
                    }
                    else if(A[player.y][player.x+1]==POINT)
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][++player.x]=PLAYER;
                        score+=3;
                        printGame(A);
                        endOfTheGame();

                    }
                    else
                    {
                        A[player.y][player.x]=SPACE;
                        A[player.y][++player.x]=PLAYER;
                        printGame(A);
                    }
                }
                break;
            case UP :
                if((unsigned char)A[player.y-1][player.x]!=WALL )
                {
                    if(A[player.y-1][player.x]==MONSTER)
                    {
                        A[player.y][player.x]=SPACE;
                        A[--player.y][player.x]=PLAYER;
                        life-=1;
                        score-=10;
                        printGame(A);
                        endOfTheGame();
                    }
                    else if(A[player.y-1][player.x]==POINT)
                    {
                        A[player.y][player.x]=SPACE;
                        A[--player.y][player.x]=PLAYER;
                        score+=3;
                        printGame(A);
                        endOfTheGame();
                    }
                    else
                    {
                        A[player.y][player.x]=SPACE;
                        A[--player.y][player.x]=PLAYER;
                        printGame(A);
                    }
                }
                break;
            case DOWN :
                if((unsigned char)A[player.y+1][player.x]!=WALL )
                {
                    if(A[player.y+1][player.x]==MONSTER)
                    {
                        A[player.y][player.x]=SPACE;
                        A[++player.y][player.x]=PLAYER;
                        life-=1;
                        score-=10;
                        printGame(A);
                        endOfTheGame();
                    }
                    else if(A[player.y+1][player.x]==POINT)
                    {
                        A[player.y][player.x]=SPACE;
                        A[++player.y][player.x]=PLAYER;
                        score+=3;
                        printGame(A);
                        endOfTheGame();
                    }
                    else
                    {
                        A[player.y][player.x]=SPACE;
                        A[++player.y][player.x]=PLAYER;
                        printGame(A);
                    }

                }
                break;
        }
    }
}
void playAgain()
{
    char key;
    key=getch();
    if(key=='a')
    {
        system("EXIT");
    }
    else
    {
        life=3;
        score=0;
        startGame();
    }
}
void sorting(ScoreTablo x)
{
    int i,j;
    ScoreTablo temp;
    for(i=0;i<5;i++)
    {
        if(x.hScore>(list+i)->hScore)
        {
            for(j=5;j>i;j--)
            {
                strcpy((list+j)->name,(list+j-1)->name);
                (list+j)->hScore=(list+j-1)->hScore;
            }
            strcpy((list+i)->name,x.name);
            (list+i)->hScore=x.hScore;
            break;
        }
    }

}
void highScore()
{
    int i;
    ScoreTablo scoreOfPlayer;
    printf("NAME : ");
    scanf("%s",&scoreOfPlayer.name);
    scoreOfPlayer.hScore=score;
    system("CLS");
    printf("Name : %s\t Score : %d\n",scoreOfPlayer.name,score);
    printf("\nHIGH SCORE\n");
    sorting(scoreOfPlayer);
    for(i=0;i<5;i++)
    {
        printf("%s\t%d\n",(list+i)->name,(list+i)->hScore);
    }
}
void endOfTheGame()
{
    int i,j;
    if(life==0)
    {
        system("CLS");
        system("COLOR 4");
        printf("\nGAME OVER\n");
        highScore();
        printf("\nPRESS ONE KEY FOR PLAY AGAIN\n");
        playAgain();

    }
    else
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=0;j<SIZE;j++)
            {
                if(A[i][j]==POINT)
                {
                    sc++;
                }
            }
        }
        if(sc==0)
        {
            score+=life*10;
            system("CLS");
            system("COLOR 2");
            printf("CONGRATULATIONS\n");
            highScore();
            printf("\nPRESS ONE KEY FOR PLAY AGAIN\n");
            playAgain();
        }
        else
        {
            sc=0;
        }
    }
}
void printGame()
{
    int i,j;
    system("CLS");
    for (i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			printf("%c",A[i][j]);
		}
		printf("\n");
	}
	printf("SCORE : %d\n",score);
	printf("LIFE : %d",life);
}
