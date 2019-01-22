#define SIZE 25
#define WALL 178
#define SPACE ' '
#define PLAYER '*'
#define DENSITYofWALL 7
#define POINT '3'
#define MONSTER '#'
#define DENSITYofMONSTER 15
#define DENSITYofPOINT 25
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27
#define COUNTOFLIST 6
typedef struct {
    int x;
    int y;
}Position;
typedef struct {
    char name[15];
    int hScore;
}ScoreTablo;

char **A;

void createArea();
void freeMalloc();
void listOfHighScore();
void startGame();
void createLabyrinth();
void scoring();
void createMonsters();
void startlocation();
void playerMoveControl();
void playAgain();
void sorting(ScoreTablo x);
void highScore();
void endOfTheGame();
void printGame();



