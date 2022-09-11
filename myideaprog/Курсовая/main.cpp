#include "ping.cpp"

int main() { 
	
	
	system ("color 4b");
	FILE  *rad,*rec;
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
			arrow(rad);
			break;
		case '2':
			options();
			break;
		case '3':
			record(rec);
			break;	
		case '4':
			exit(0);
			break;
			default: cout<<endl<<"Unknown command";
	}
}
	return	EXIT_SUCCESS;
}
