#include "bits/stdc++.h"
#include "windows.h"
using namespace std;
int mode=1,range=100,guess,number,fcnt,l,r;
string premode;
void say(string s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
        Sleep(20);
    }
	printf("\n");
	return;
}
void fuck(){
	system("cls");
	say("FUCK");
	system("title FUCK");
	FUK:
	int FUCK=MessageBox(NULL,TEXT("FUCK"),TEXT("FUCK"),MB_YESNO|MB_ICONERROR|MB_DEFBUTTON3);
	if(FUCK==IDNO)goto FUK;
	system("title Fuck Sucsessfully");
}
bool CM(){
	system("title interesting guessing game");
	Sleep(500);
	fcnt=0;
	say("Please choose the mode:");
	say("MODE 1:Guess number");
	say("MODE 2:Unguess number");
	say("MODE fuck:FUCK");
	CME:
	mode=0;
	cin>>premode;
	if(premode=="1")mode=1;
	if(premode=="2")mode=2;
	if(premode=="fuck")mode=3;
	if(mode!=1&&mode!=2&&mode!=3){
		fcnt++;
		if(fcnt==5){
			fuck();
			return 0;
		}
		say("Enter the mode");
		goto CME;
	}
	return 1;
}
void ER(){
	Sleep(500);
	fcnt=0;
	say("Please enter the range:");
	say("1~2147438647");
	ERE:
	cin>>range;
	if(range<1){
		say("Enter the range");
		goto ERE;
	}
}
void GN(){
	system("cls");
	say("You chose Guess number.");
	say("You are going to guess a random number.");
	say("Then computer will tell you wherether the number you guess is too big or too small, or jut right.");
	ER();
	srand(time(NULL)+range);
	number=rand()%(range+1);
	getchar();
	system("cls");
	SG:
	say("Your guess:");
	cin>>guess;
	if(guess>number){
		say("Too big.");
		goto SG;
	}else if(guess<number){
		say("Too small.");
		goto SG;
	}else{
		say("Just right.");
		say("[ENTER TO CONTINUE...]");
		getchar();
		getchar();
		system("cls");
	}
}
bool EC(){
	fcnt=0;
	say("Please enter");
	ECE:
	cin>>number;
	if(number!=1&&number!=2&&number!=3){
		fcnt++;
		if(fcnt==5){
			fuck();
			return 0;
		}
		say("Enter!");
		goto ECE;
	}
	return 1;
}
bool UN(){
	system("cls");
	say("You chose Ungueess number.");
	say("You are going to imagine a random number.");
	say("Then computer will guess it.");
	ER();
	l=0;r=range;
	while(l<=r){
		guess=(l+r)>>1;
		say("Is this number your guess?");
		cout<<guess<<endl;
		say("1=Too small");
		say("2=Too correct");
		say("3=Too big");
		if(!EC())return 0;
		if(number==1)l=guess+1;
		if(number==2){
			say("Success!");
			getchar();
			getchar();
			return 1;
		}if(number==3)r=guess-1;
	}
	cout<<guess<<endl;
	say("Success!");
	getchar();
	getchar();
	return 1;
}
int main(){
	system("title \t");
	say("Hello.");
	say("Welcome to this interesting guessing game.");
	system("title interesting guessing game");
	start:
	if(!CM())return 0;
	if(mode==1)GN();
	else if(mode==2){
		if(!UN())return 0;
	}else{
		system("cls");
		say("OK.");
		Sleep(2000);
		for(int i=1;i<=100;i++){
			for(int i=1;i<=100;i++){
				cout<<(char)('0'+(rand()%10));
			}
			SetCursorPos(rand()%1332,rand()%722);
			cout<<endl;
		}
		fuck();
	}
	system("cls");
	goto start;
}
