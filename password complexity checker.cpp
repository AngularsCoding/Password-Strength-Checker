#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void drawBorder(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187; // top right border
    char br = 188; // bottom right border
    char tl = 201; // top left border
    char bl = 200; // bottom left border
    int width = 30; 
    int height = 3;
    
    for( int i=1; i<=height; i++ ){
		for( int j=1; j<=width; j++ ){
	    	gotoxy(j+x,i+y);
	    	if( i==1 && j==1 ) cout<< tl;
			else if( i==height && j==1 ) cout<< bl;
	    	else if( i==1 && j==width ) cout<< tr;
			else if( i==height && j==width ) cout<< br;
			else if( i==1 || i==height ) cout<< h;
			else if( j==1 || j==width ) cout<< v;
		}
	}
}

int main() {
    srand((unsigned) time(NULL));
	
	system("cls");
 	  
 	char password[21];
 	int length;
 	
	char op;
	do{
		system("cls");
		
		cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl;
		cout<<endl;
		cout<<"\t\t  ±±±±± "<<endl;
		cout<<"\t\t  ±   ± "<<endl;
		cout<<"\t\t±±±±±±±±±"<<endl;
		cout<<"\t\t±±±± ±±±±"<<endl;
		cout<<"\t\t±±±±±±±±±"<<endl; 
		
		cout<<endl;
		cout<<"        PASSWORD  STRENGTH  CHECKER      "<<endl;
		cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl<<endl; 
		  
		cout<<endl<<"\tEnter Password: ";
		cin>> password;
			   
		char pass[21] = "";
		int excess = strlen(password) - 6;
		int baseScore = 50;
		
		int numUpper = 0;
		int numSymbol = 0;
		int numLower = 0;
		int numDigit = 0;
		
		int bonusExcess = 3;
		int bonusUpper = 4;
		int bonusNumbers = 5;
		int bonusSymbols = 5;
		int bonusCombo = 0; 
		int bonusFlatLower = 0;
		int bonusFlatNumber = 0;
		
		int i;
		for( i=0; i<strlen(password); i++ ){
			if( password[i] >= 48 && password[i] <= 57 ){  // 0-9
				numDigit++;
			}
			if( password[i] >= 97 && password[i] <= 125 ){ // a-z
				numLower++;
			}
			if( password[i] >= 65 && password[i] <= 90 ){ // A-Z
				numUpper++;
			}
			if( password[i] >= 33 && password[i] <= 47 ){ //symbols
				numSymbol++;
			}
		}
		
		if (numUpper>0 && numDigit>0 && numSymbol>0)
		{
			bonusCombo = 25; 
		}
	
		else if ((numUpper>0 && numDigit>0) || (numUpper>0 && numSymbol>0) || (numDigit>0 && numSymbol>0))
		{
			bonusCombo = 15; 
		}
		
		int score = baseScore + (excess*bonusExcess) + (numUpper*bonusUpper) + 
				(numDigit*bonusNumbers) + (numSymbol*bonusSymbols) + 
				bonusCombo + bonusFlatLower + bonusFlatNumber;	
		 
		gotoxy(8,14); 
		cout<<"Checking Password Strength...";
		gotoxy(8,15); 
		for(int i=0; i<27; i++){
			cout<<(char)176;
			Sleep(100);
		}
		  
		drawBorder(7,17);
		
		gotoxy(10,19); 
		if (score<50)
		{
			cout<<"Password Status: Weak"; 
		}
		else if (score>=50 && score<75)
		{
			cout<<"Password Status: Average"; 
		}
		else if (score>=75 && score<100)
		{
			cout<<"Password Status: Strong"; 
		}
		else if (score>=100)
		{
			cout<<"Password Status: Secure"; 
		} 
		
		gotoxy(9,23); cout<<"Do you want to generate password again (y/n): ";
		op = getch();
	}while(op=='y' || op=='Y');
	
    return 0;
}
