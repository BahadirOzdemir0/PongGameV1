#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>


// Used functions
void OyunAlani(); 
void gotoxy(short x,short y);
void puanyazdir();
void paletciz();


void gotoxy(short x,short y)  // Moves cursor to the specified column and row
{
    HANDLE hConsoleOutput;
    COORD Cursor_Pos ={x-1,y-1};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,Cursor_Pos);
}

void OyunAlani()
{
    // Draws the game area

    for(int i =1;i<=120;i++)
    {
        gotoxy(i,30);
        printf("%c",220);
    }
    for(int i =1;i<=30;i++)
    {
        gotoxy(120,i);
        printf("%c",220);
    }
    for(int i =1;i<=120;i++)
    {
        gotoxy(i,1);
        printf("%c",220);
    }
    for(int i =1;i<=30;i++)
    {       
        gotoxy(1,i);
        printf("%c",220);
    }
    //---------------------------------
}

void puanyazdir(int sagoyuncu,int soloyuncu)  // Writes the score of the right and left player to the top-right corner
{
    gotoxy(122,1);
    printf("PLAYER1:%d",sagoyuncu);  
    
    gotoxy(122,4);
    printf("PLAYER2:%d",soloyuncu);
}

void paletciz(int solx,int soly,int sagx,int sagy)   // Draws paddles before the game starts
{
    for(int i=soly-2;i<=soly+2;i++) 
    {
        gotoxy(solx,i);
        printf("%c",221);
        printf("\e[?25l");
        gotoxy(sagx,i);
        printf("%c",221);
        printf("\e[?25l");
    }
}

main()
{
    Sleep(2000);
    
    int soloyuncu=0,sagoyuncu=0; 
    // Scores for the left and right players
    
    while(1)
    {
        system("CLS");
        OyunAlani();
        
        puanyazdir(sagoyuncu,soloyuncu);

        srand(clock());
        
        int top = rand()%2; // If top is 1, it goes left; if 0, it goes right
        
        int top2,top3;   // top3 determines if the ball is moving straight or diagonally
        
        top2=rand()%2;   // If top2 is 1, it always moves upwards; if 0, downwards
        
        int solx=4,soly=15,sagx=117,sagy=15,durumsa=9,durumso=9;  // durumsa 1 up, 0 down
        int zorluk=12;
        int bitti=1;
        char tus;
        int tx=60,ty=16;
        gotoxy(tx,ty);
        printf("%c",248);

        paletciz(solx,soly,sagx,sagy);
        
        do
        {
            if(kbhit())
            {
                tus = getch();
            
                switch(tus)
                {   
                    case 'S':
                    durumsa=0;
                    break;
                    case 'W':
                    durumsa=1;
                    break;
                    case 'w':
                    durumsa=1;
                    break;
                    case 's':
                    durumsa=0;
                    break;
                    case 72:
                    durumso=1;
                    break;
                    case 80:
                    durumso=0;
                    break;
                }
            }
            // Ball bounce!!
            for(int i=soly-2;i<=soly+2;i++)
            {
                if(i==ty && tx==5)
                    top=0,top2=rand()%2;
            }
        
            for(int i=sagy-2;i<=sagy+2;i++)
            {       
                if(i==ty && tx==116) 
                    top=1,top2=rand()%2;
            }
            
            if(ty==2)
                 top2=0;
            if(ty==29)
                 top2=1;

            // Scoring

            if(tx==3)
            {
                soloyuncu++;
                bitti=0;
            }
            
            if(tx == 117)
            {
                sagoyuncu++;
                bitti=0;
            }
            
            Sleep(20);
        
            // Paddle movement up and down------
            if(durumsa==1)
            {
                if(soly != 4)
                {
                    for (int i=soly-2;i<=soly+2;i++)
                    {
                        gotoxy(solx,i);
                        printf(" ");
                    }
                    soly--;
                    for (int i=soly-2;i<=soly+2;i++)
                    {
                        gotoxy(solx,i);
                        printf("%c",221);
                        printf("\e[?25l");
                    }
                }
            }       
                
            if(durumsa==0)
            {
                if(soly !=27)
                {
                    for (int i=soly-2;i<=soly+2;i++)
                    {
                    gotoxy(solx,i);
                    printf(" ");
                    }
                    soly++;
                    for (int i=soly-2;i<=soly+2;i++)
                    {
                        gotoxy(solx,i);
                        printf("%c",221);
                        printf("\e[?25l");
                    }
                }
            }
                
            if(durumso==1)
            {
                if(sagy != 4)
                {
                    for (int i=sagy-2;i<=sagy+2;i++) // Moves the right paddle up
                    {
                        gotoxy(sagx,i);
                        printf(" ");
                    }
                    
                    sagy--;
                    
                    for (int i=sagy-2;i<=sagy+2;i++) // Draws the right paddle
                    {
                        gotoxy(sagx,i);
                        printf("%c",221);
                        printf("\e[?25l");
                    }
                }   
            }
            if(durumso==0)
            {   
                if(sagy != 27)
                {
                    for (int i=sagy-2;i<=sagy+2;i++)
                    {
                    gotoxy(sagx,i);
                    printf(" ");
                    }
                    sagy++;
                    for (int i=sagy-2;i<=sagy+2;i++)
                    {
                        gotoxy(sagx,i);
                        printf("%c",221);
                        printf("\e[?25l");
                    }
                }
            }

            // Ball section!!!!! 1 left 0 right  printf("%c",248);-------------------------------------------------------------------------------------------------

            if(top==1)
            { // Ball moving left
            
                if(top2==1)
                { // Ball moves upwards
                
                    top3=rand()%zorluk;
                
                    if(top3==0)
                    { // 20% chance to move diagonally
                        gotoxy(tx,ty);
                        printf(" ");
                    
                        tx--;
                        ty--;
                    
                        gotoxy(tx,ty);
                        printf("%c",184);
                    
                    }
                    else
                    { // 80% chance to move straight
                
                        gotoxy(tx,ty);
                        printf(" ");
                    
                        tx--;
                    
                        gotoxy(tx,ty);
                        printf("%c",184);
                    }
                
                }
                else if(top2==0)
                { // Ball moves downwards
                
                    top3=rand()%zorluk;
                    if(top3==0)
                    { // 20% chance to move diagonally
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx--;
                        ty++;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);    
                    }
                    else
                    { // 80% chance to move straight
                
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx--;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);
                    }
                
                }
        
            }
            else if(top==0)
            { // Ball moving right
        
                if(top2==1)
                { // Ball moves upwards
    
                    top3=rand()%zorluk;
                    
                    if(top3==0)
                    { // 20% chance to move diagonally
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx++;
                        ty--;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);
                        
                    }
                    else
                    { // 80% chance to move straight
                    
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx++;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);
                    }
        
                }
                else if(top2==0)
                { // Ball moves downwards
                    
                    top3=rand()%zorluk;
                    if(top3==0)
                    { // 20% chance to move diagonally
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx++;
                        ty++;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);
                        
                    }
                    else
                    { // 80% chance to move straight
                    
                        gotoxy(tx,ty);
                        printf(" ");
                        
                        tx++;
                        
                        gotoxy(tx,ty);
                        printf("%c",184);
                    }
                    
                }

            }

        }while(bitti);

        gotoxy(122,1);
        printf("PLAYER
