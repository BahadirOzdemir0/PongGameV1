#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>


//kullanýnlan fonksiyonlar
void OyunAlani(); 
void gotoxy(short x,short y);
void puanyazdir();
void paletciz();


void gotoxy(short x,short y)  //istenen sütun ve satýra gitmek için
{
		
	HANDLE hConsoleOutput;
	COORD Cursor_Pos ={x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,Cursor_Pos);
}
void OyunAlani()
{
//oyun alaný çizdirir

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
void puanyazdir(int sagoyuncu,int soloyuncu)  //sað ve sol oyuncunun puanlarýný sað köþeye yazar
{
	gotoxy(122,1);
	printf("PLAYER1:%d",sagoyuncu);  
	
	gotoxy(122,4);
	printf("PLAYER2:%d",soloyuncu);
}
void paletciz(int solx,int soly,int sagx,int sagy)   //sað ve sola oyun baþlamadan önce palet çizer
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
	//Sað ve sol oyuncunun puanlarý
	
	while(1)
	{
		system("CLS");
		OyunAlani();
		
		puanyazdir(sagoyuncu,soloyuncu);

		srand(clock());
		
		int top = rand()%2;//top 1 ise sola gide 0 ise saða
		
		int top2,top3;   //top 3 en son düz mü yoksa çapraz mý gideceðini belirler
		
		top2=rand()%2;   //top2 1 ise hep yukarý eðimle gider 0 ise aþaðý eðimle gider
	
	
		int solx=4,soly=15,sagx=117,sagy=15,durumsa=9,durumso=9;  //durumsa 1 yukarý 0 aþaðý
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
			//top sekme !!
			for(int i=soly-2;i<=soly+2;i++)
			{
				if(i==ty and tx==5)
					top=0,top2=rand()%2;
				
			}
		
			for(int i=sagy-2;i<=sagy+2;i++)
			{		
				if(i==ty and tx==116) 
					top=1,top2=rand()%2;
			}
			
			if(ty==2)
				 top2=0;
			if(ty==29)
				 top2=1;
		
		
		
		
		
		//puanlama
		
		
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
		
			//paletin aþaðý yukarý ayarý------
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
					for (int i=sagy-2;i<=sagy+2;i++)//paleti asiler
					{
						gotoxy(sagx,i);
						printf(" ");
					}
					
					sagy--;
					
					for (int i=sagy-2;i<=sagy+2;i++)//paleti çizer
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

			//top bölgesi!!!!! 1 sol 0 sað  printf("%c",248);-------------------------------------------------------------------------------------------------

			if(top==1)
			{ ///soloa gidioyr
			
			
		
				if(top2==1)
				{//top hep yukarý eðimle gider
				
					top3=rand()%zorluk;
				
					if(top3==0)
					{//%20 ihtimalle çapraz gitcek
						gotoxy(tx,ty);
						printf(" ");
					
						tx--;
						ty--;
					
						gotoxy(tx,ty);
						printf("%c",184);
					
					}
					else
					{///80 ihtimalle düz				
				
						gotoxy(tx,ty);
						printf(" ");
					
						tx--;
					
						gotoxy(tx,ty);
						printf("%c",184);
					}
				
				}
				else if(top2==0)
				{// hep aþaðý eðimle gidecek
				
					top3=rand()%zorluk;
					if(top3==0)
					{//%20 ihtimalle çapraz gitcek
						gotoxy(tx,ty);
						printf(" ");
						
						tx--;
						ty++;
						
						gotoxy(tx,ty);
						printf("%c",184);	
					}
					else
					{///80 ihtimalle düz				
				
						gotoxy(tx,ty);
						printf(" ");
						
						tx--;
						
						gotoxy(tx,ty);
						printf("%c",184);
					}
				
				}
		
			}
			else if(top==0)
			{//top saða gitcek
		
				if(top2==1)
				{//top hep yukarý eðimle gider
	
					top3=rand()%zorluk;
					
					if(top3==0)
					{//%20 ihtimalle çapraz gitcek
						gotoxy(tx,ty);
						printf(" ");
						
						tx++;
						ty--;
						
						gotoxy(tx,ty);
						printf("%c",184);
						
					}
					else
					{///80 ihtimalle düz				
					
						gotoxy(tx,ty);
						printf(" ");
						
						tx++;
						
						gotoxy(tx,ty);
						printf("%c",184);
					}
		
				}
				else if(top2==0)
				{// hep aþaðý eðimle gidecek
					
					top3=rand()%zorluk;
					if(top3==0)
					{//%20 ihtimalle çapraz gitcek
						gotoxy(tx,ty);
						printf(" ");
						
						tx++;
						ty++;
						
						gotoxy(tx,ty);
						printf("%c",184);
						
					}
					else
					{///80 ihtimalle düz				
					
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
		printf("PLAYER1:%d",sagoyuncu);
		
		
		gotoxy(122,4);
		printf("PLAYER2:%d",soloyuncu);
		
		if(sagoyuncu==10)
		{
			
			system("CLS");
			gotoxy(50,15);
			printf("OYUNCU1 KAZANDI");
			soloyuncu=0;
			sagoyuncu=0;
			Sleep(5000);
			
		}
		if(soloyuncu==10)
		{
			
			system("CLS");
			gotoxy(50,15);
			printf("OYUNCU2 KAZANDI");
			soloyuncu=0;
			sagoyuncu=0;
			Sleep(5000);
		}


	}


getch();

}



