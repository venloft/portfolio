

#include <graphics.h>
#include <ctime>
#include <iostream>
#include <conio.h>
using namespace std;


void resolution(FILE *res);
void options();
void optionsA();


void record(FILE *rec1)
{	

	int record1=0;

	rec1 = fopen("filerecord1.dat", "rb+");
	fread(&record1, sizeof(record1), 1, rec1);
	cout<<"Your record is: "<<record1<<endl;
	
	fclose(rec1);	

_getch();

}

void ball(FILE *rad){
	system("CLS");
		cout<<endl<<" Radius of ball"<<endl;
	cout<<endl<<"1)5"<<endl;
	cout<<endl<<"2)10"<<endl;

	char c;
	int r;
	
	c=_getch();
	switch (c) {
		case '1':
			rad = fopen("filerad.dat", "wb");
			r=5;
			fwrite(&r, sizeof(r), 1, rad);
			fclose(rad);
			cout<<endl<<"Saved"<<endl;
			break;
		case '2':
			rad = fopen("filerad.dat", "wb");
			r=10;
			fwrite(&r, sizeof(r), 1, rad);
			fclose(rad);
			cout<<endl<<"Saved"<<endl;
			break;
			default: cout<<endl<<"Unknown command";
	}
	
_getch();


}

void racket(FILE *rak){
		cout<<endl<<" Postavit otklik posle najatia na raketky"<<endl;
	cout<<endl<<"1) Da"<<endl;
	cout<<endl<<"2) Net"<<endl;
	char c;
	int k;
	c=_getch();
	switch (c) {
		case '1':
			rak = fopen("filerak.dat", "wb");
			k=0;
			fwrite(&k, sizeof(k), 1, rak);
			fclose(rak);
			cout<<endl<<"Saved"<<endl;
			break;
		case '2':
			rak = fopen("filerak.dat", "wb");
			k=75;
			fwrite(&k, sizeof(k), 1, rak);
			fclose(rak);
			cout<<endl<<"Saved"<<endl;
			break;
			default: cout<<endl<<"Unknown command";
	}

}


void resolution(FILE *res) {	
	int w,h;
	char c;
	system("CLS");
	cout<<endl<<"Resolution"<<endl;
	cout<<endl<<"1) 800*600"<<endl;
	cout<<endl<<"2) 1200*800"<<endl;
	cout<<endl<<"3) 1600*1024"<<endl;
	c=_getch();
	switch (c) {
		case '1':
			res = fopen("fileres.dat", "wb");
			w=800; h=600;
			fwrite(&w, sizeof(w), 1, res);
			fwrite(&h, sizeof(h), 1, res);
			fclose(res);
			cout<<endl<<"Saved"<<endl;
			break;
		case '2':
			res = fopen("fileres.dat", "wb");
			w=1200; h=800;
			fwrite(&w, sizeof(w), 1, res);
			fwrite(&h, sizeof(h), 1, res);
			fclose(res);
			cout<<endl<<"Saved"<<endl;
			break;
		case '3':
			res = fopen("fileres.dat", "wb");
			w=1600; h=1024;
			fwrite(&w, sizeof(w), 1, res);
			fwrite(&h, sizeof(h), 1, res);
			fclose(res);
			cout<<endl<<"Saved"<<endl;
			break;
			default: cout<<endl<<"Unknown command";
	}


}


void optionsA()
{
	system("CLS");
	FILE *rad,*rak;
	cout<<endl<<"Options"<<endl;
	cout<<endl<<"1)Ball"<<endl;
	cout<<endl<<"2)Tennis racket"<<endl;

	char c;

	c=_getch();
	switch (c) {
		case '1':
			ball(rad);
			break;
		case '2':
			racket(rak);
			break;
			default: cout<<endl<<"Unknown command";
	}

}


void options()
{	
	FILE *res;
	char c;
	system("CLS");
	cout<<endl<<"1.Resolution"<<endl;
	cout<<endl<<"2.Options of the ball and tennis racket"<<endl;

	
	c=_getch();
	switch (c) {
		case '1':
			resolution(res);
			break;
		case '2':
			optionsA();
			break;
			default: cout<<endl<<"Unknown command";
	}


_getch();

}


void draw(int x, int y) {
	
bar (x,y,x+50,y+10);

}


void ok(int xc,int yc)
{
	pieslice(xc,yc,1,360,6);
}


void arrow(FILE *res, FILE *rad, FILE *rak,FILE *rec1) { 
	int w=800,h=600,r=5,k=0,record=0,record1=0;
	//таймер для работы рандомных чисел
	srand(time(NULL));
	
	res = fopen("fileres.dat", "rb");
	fread(&w, sizeof(w), 1, res);
	fread(&h, sizeof(h), 1, res);
	fclose(res);
	rad = fopen("filerad.dat", "rb");
	fread(&r, sizeof(r), 1, rad);
	fclose(rad);
	rak = fopen("filerak.dat", "rb");
	fread(&k, sizeof(k), 1, rad);
	fclose(rak);

	initwindow (w, h);

	int speedy=2,speedx=2;
	int x = w/2, y = h-100;
	int xc=rand()%w, yc=rand()%110+20;
	char button;
	while(speedx==0)
	{
	speedx=2;
	speedx*=rand()%2-1;
	}
	do {
		
		draw (x, y);
		
		xc+=speedx;
		yc+=speedy;
		ok(xc,yc);
	
		
		if (kbhit())
		button = getch();
		delay(8);
		clearviewport();
	
			if (button == 75) 
			{
			if(x<=0)
			{
			x+=0;
			}
			else
			{
			x -=7;
			button=k;}
			}

			if (button == 77) 
			{
			if(x>=w-60)
			{
			x+=0;
			}
			else
			{
			x += 7;
			button=k+2;}
			}



		
			if(((y<yc+r)and(xc>x))and((y+10>yc)and(x+50>xc)))
			{
			if((xc<=x)and(yc>y)or((xc>=x+50)and(yc>y)))	
			{
			speedx*=-1;
			record++;
			}
			else
			{
			
			speedy*=-1;
			record++;
			speedx+=1;}
			}

			
			
		
			if(xc+r>w)
			{
			speedx*=-1;
			}
			
		
			if(yc<0)
			{
			speedy*=-1;
			}
			
	
			if(xc<0)
			{
			speedx*=-1;
			}
			
			
			
			
			if(h<yc)
			{
			break;
			}
	} while (button!=27);
			rec1 = fopen("filerecord1.dat", "rb+");
			fread(&record1, sizeof(record1), 1, rec1);
			if(record>record1)
			{
			rec1 = fopen("filerecord1.dat", "wb");
			record1=record;
			fwrite(&record1, sizeof(record1), 1, rec1);
			}
			fclose(rec1);	
			clearviewport();
			outtextxy(w/2-30,h/2,"GAME OVER");
			getch();
	closegraph();
}

int main() { 
	
	
	system ("color 4b");
	FILE  *res, *rad, *rak, *rec, *rec1;
	while(1){
	system("CLS");
	char c;
	printf(" \n\t\t\t\t\t\t MENU \n" );
	printf(" \n\t\t\t\t\t 1)Start the game \n");
	printf(" \n\t\t\t\t\t 2)Options \n"  );
	printf(" \n\t\t\t\t\t 3)Record \n"  );
	printf(" \n\t\t\t\t\t 4)Vixod \n"  );
	c=_getch();

	switch (c) {
		case '1':
			arrow(res,rad,rak,rec1);
			break;
		case '2':
			options();
			break;
		case '3':
			record(rec1);
			break;	
		case '4':
			exit(0);
			break;
			default: cout<<endl<<"Unknown command";
	}
}
	return	EXIT_SUCCESS;
}
