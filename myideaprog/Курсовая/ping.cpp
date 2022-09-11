#include <graphics.h>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <string>
#include "ping.h"
using namespace std;


void resolution(FILE *res);
void options();
void optionsA();


void record(FILE *rec1)
{	
	Ping y;
	int record1=0;

	

	y.file_recr(&record1);
	cout<<"Your record is: "<<record1<<endl;
_getch();

}

void ball(FILE *rad){
	system("CLS");
	cout<<endl<<" Radius of ball"<<endl;
	cout<<endl<<"1)5"<<endl;
	cout<<endl<<"2)10"<<endl;
	Ping y;
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
	Ping y;
	c=_getch();
	switch (c) {
		case '1':
			k=0;
			y.file_sh(k);

			break;
		case '2':
			k=75;
			y.file_sh(k);

			break;
			default: cout<<endl<<"Unknown command";
	}

}


void resolution(FILE *res) {	
	int w,h;
	Ping y;
	char c;
	system("CLS");
	cout<<endl<<"Resolution"<<endl;
	cout<<endl<<"1) 800*600"<<endl;
	cout<<endl<<"2) 1200*800"<<endl;
	cout<<endl<<"3) 1600*1024"<<endl;
	c=_getch();
	switch (c) {
		case '1':
			
			w=800; h=600;
			y.filew(w,h);

			cout<<endl<<"Saved"<<endl;
			break;
		case '2':
			
			w=1200; h=800;
			y.filew(w,h);
			cout<<endl<<"Saved"<<endl;
			break;
		case '3':
			
			w=1600; h=1024;
			y.filew(w,h);
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


void arrow(FILE *rad) { 
	int w=800,h=600,r=5,k=0,record=0,record1=0;
	//таймер для работы рандомных чисел
	srand(time(NULL));
	Ping y;
	y.file_r(&w,&h);


	rad = fopen("filerad.dat", "rb");
	fread(&r, sizeof(r), 1, rad);
	fclose(rad);
	y.file_shr(&k);


	initwindow (w, h);
	Pong x;
	int speedy=2,speedx=2,y1,x1;
	x.setx(w/2);
	x.sety(h-100);
	x.setxc(rand()%w);
	x.setyc(rand()%110+20);	

	char button;
	while(speedx==0)
	{
	speedx=2;
	speedx*=rand()%2-1;
	}
	do {
		
		x.draw (x.getx(),x.gety());
	x.setxc(x.getxc()+speedx);
	x.setyc(x.getyc()+speedy);

		
		x.ok(x.getxc(),x.getyc());
	
		
		if (kbhit())
		button = getch();
		delay(8);
		clearviewport();
	
			if (button == 75) 
			{
			if(x.getx()<=0)
			{
			x1=0;
			}
			else
			{
			x.setx(x.getx()-7);  
			button=k;}
			}

			if (button == 77) 
			{
			if(x.getx()>=w-60)
			{
			x1=0;
			}
			else
			{
			x.setx(x.getx()+7); 
			button=k+2;}
			}



		
			if(((x.gety()<x.getyc()+r)and(x.getxc()>x.getx()))and((x.gety()+10>x.getyc())and(x.getx()+50>x.getxc())))
			{
			if((x.getxc()<=x.getx())and(x.getyc()>x.gety())or((x.getxc()>=x.getx()+50)and(x.getyc()>x.gety())))	
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

			
			
		
			if(x.getxc()+r>w)
			{
			speedx*=-1;
			}
			
		
			if(x.getyc()<0)
			{
			speedy*=-1;
			}
			
	
			if(x.getxc()<0)
			{
			speedx*=-1;
			}
			
			
			
			
			if(h<x.getyc())
			{
			break;
			}
	} while (button!=27);
			y.file_recr(&record1);
			if(record>record1)
			{
			record1=record;	
			y.file_rec(record1);
			
			}
			
			clearviewport();
			outtextxy(w/2-30,h/2,"GAME OVER");
			getch();
	closegraph();
}


