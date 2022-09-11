#include <graphics.h>
#include <ctime>
#include <iostream>
#include <conio.h>
using namespace std;


class Pong{
	private:
		int x;
		int y;
		int xc;
		int yc;
		public:
			Pong()
			{
			}
			//ракетка
			void setx(int c)
			{
				x=c;
			}
			void sety(int c)
			{
				y=c;
			}
			int getx()
			{
			return x;
			}
			int gety()
			{
			return y;
			}
			
			
			
			
			//шарик
			void setxc(int c)
			{
				xc=c;
			}
			void setyc(int c)
			{
				yc=c;
			}
			int getxc()
			{
			return xc;
			}
			int getyc()
			{
			return yc;
			}
					
			void draw(int x1, int y1) {
	
			bar (x1,y1,x1+50,y1+10);

			}
			void ok(int x1, int y1) {
	
			pieslice(x1,y1,1,360,6);

			}
	

			~Pong()
			{
			}
};
class Ping : public Pong
{
	private:
		FILE  *res,*rak,*rec;
	
	public:

	Ping()
	{	
	}	
	void filew(int t, int k)
	{
	
	res = fopen("fileres.dat", "wb");
	fwrite(&t,sizeof(t), 1, res);
	fwrite(&k, sizeof(k), 1, res);
	fclose(res);
	}
	void file_r(int *t, int *k)
	{
	
	res = fopen("fileres.dat", "rb");
	fread(*(&t) ,sizeof(*t), 1, res);
	fread(*(&k), sizeof(*k), 1, res);
	fclose(res);
	}
	void file_sh( int k)
	{
	rak = fopen("filerak.dat", "wb");
	fwrite(&k, sizeof(k), 1, rak);
	fclose(rak);
	}
	void file_shr( int *k)
	{
	rak = fopen("filerak.dat", "rb");
	fread(*(&k), sizeof(*k), 1, rak);
	fclose(rak);
	}
		
	void file_rec( int k)
	{
	rec = fopen("filerecord1.dat", "wb");
	fwrite(&k, sizeof(k), 1, rec);
	fclose(rec);
	}
	void file_recr( int *k)
	{
	rec = fopen("filerecord1.dat", "rb");
	fread(*(&k), sizeof(*k), 1, rec);
	fclose(rec);
	}
		
	
	~Ping()
	{
	}
	
	
};
