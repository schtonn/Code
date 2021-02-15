#include<windows.h>
#include<conio.h>
#include "bits/stdc++.h"
#define R register
#define EN puts("")
#define LL long long
using namespace std;
//data start
int language=0;//0chinese
int size_x,size_y;
int tmp_map[155][55],Map[155][55];
struct three_space_data{
	int first,second,third;
};
vector<three_space_data>three_space_tmp;
vector<three_space_data>three_space;
struct snack_data{
	int head_x,head_y;
	int tail_x,tail_y;
	int way;//0up,1down,2left,3right
	int speed;
	int appearance_head,appearance_body;
	int eat_num;
	int turn[155][55];
}snack;
const int way_x[4]={0,0,-1,1};
const int way_y[4]={-1,1,0,0};
int max_score;
map<char,int>map_appearance;
char appearance[72]={'$','%','&','*','@','?','+','-',':',';','0','1','2','3','4','5','6','7','8','9',
'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M',
'n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
struct food_data{
	int x,y;
	int special;
}food;
//data end

//define start
inline int check_tmp_map();
//define end

//function start
inline int max(int xx,int yy){return xx>yy?xx:yy;}
inline int abs(int x){return x>0?x:-x;}
inline void pos(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{short(x),short(y)});
    //gotoxy(x,y);
}
inline void get_output(char &ccc,int x,int y){
	DWORD lenlen;
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),&ccc,1,{short(x),short(y)},&lenlen);
}
inline int get_way_by_two_block(int x1,int y1,int x2,int y2){
	if(x1==x2){
		if(y2==y1+1) return 0;
		return 1;
	}
	//y1==y2
	if(x2==x1+1) return 2;
	return 3;
}
inline int isnear(int ix,int iy,int jx,int jy){
	if(ix==jx&&abs(iy-jy)==1) return 1;
	if(iy==jy&&abs(ix-jx)==1) return 1;
	return 0;
}
inline void set_color(int red,int green,int blue){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|
	(FOREGROUND_RED)*red|(FOREGROUND_GREEN*green)|(FOREGROUND_BLUE*blue));
}
inline void inti(){
	map_appearance['$']=1;
	FILE *fp=freopen("save.save","r",stdin);
	if(fp==NULL){
		size_x=size_y=11;
		snack.speed=1;
		snack.appearance_head=4;snack.appearance_body=0;
		goto READ_OVER;
	}
	
	scanf("%d",&max_score);
	scanf("%d%d",&size_x,&size_y);
	if(size_x<0||size_x>150||size_y<0||size_y>50) goto FILE_ERROR;
	scanf("%d",&snack.speed);
	if(snack.speed<0||snack.speed>100) goto FILE_ERROR;
	scanf("%d%d",&snack.appearance_head,&snack.appearance_body);
	if(snack.appearance_head<0||snack.appearance_head>71) goto FILE_ERROR;
	if(snack.appearance_body<0||snack.appearance_body>71) goto FILE_ERROR;
	for(R int i=0;i<size_x;i++)for(R int j=0;j<size_y;j++){
		scanf("%d",&tmp_map[i][j]);
		if(tmp_map[i][j]!=0&&tmp_map[i][j]!=1) goto FILE_ERROR;
		Map[i][j]=tmp_map[i][j];
	}
	READ_OVER:;
	fclose(stdin);
	freopen("CON","r",stdin);
	check_tmp_map();
	{
		int len__=three_space_tmp.size();
		for(R int i=0;i<len__;i++) three_space.push_back(three_space_tmp[i]);
	}
	return;
	
	FILE_ERROR:;
	MessageBox(NULL,TEXT("file error!"),TEXT(""),MB_OK);
	exit(0);
}
inline void save(){
	freopen("save.save","w",stdout);
	printf("%d\n",max_score);
	printf("%d %d\n",size_x,size_y);
	printf("%d\n",snack.speed);
	printf("%d %d\n",snack.appearance_head,snack.appearance_body);
	for(R int i=0;i<size_x;i++){
		for(R int j=0;j<size_y;j++) printf("%d ",Map[i][j]);
		EN;
	}
	fclose(stdout);
	freopen("CON","w",stdout);
}
//function end

//game start
inline void build_game_space(){
	memset(snack.turn,-1,sizeof snack.turn[155][55]);
	system("cls");
	pos(0,size_y);
	for(R int i=0;i<=size_x;i++) putchar('-');
	for(R int i=0;i<=size_y;i++){pos(size_x,i);putchar('|');}
	pos(0,0);
	for(R int j=0;j<size_y;j++){
		for(R int i=0;i<size_x;i++) putchar(Map[i][j]?'#':'\0');
		EN;
	}
	pos(size_x+2,size_y/2-3);printf("SCORE:");
	pos(size_x+2,size_y/2-1);printf("HI-SC:%d",max_score);
	pos(0,size_y+1);
}
inline void print_special_food(){
	int red,green,blue;
	pos(food.x,food.y);
	RAND_COLOR:;
	red=rand()%2,green=rand()%2,blue=rand()%2;
	if((red&green&blue)||(!(red|green|blue))) goto RAND_COLOR;
	set_color(red,green,blue);
	int special_food_appearance=rand()%72;
	putchar(appearance[special_food_appearance]);
	set_color(1,1,1);
}
inline void get_new_food(){
	char tmp;
	RAND_AGAIN:;
	food.x=rand()%size_x;
	food.y=rand()%size_y;
	get_output(tmp,food.x,food.y);
	if(tmp!=' '&&tmp!='\0') goto RAND_AGAIN;
	food.special=0;
	pos(food.x,food.y);
	if((double)rand()/RAND_MAX<0.066){
		food.special=1;
		print_special_food();
	}
	else putchar('&');
}
inline void build_snack_food(){
	three_space_data start=three_space[rand()%three_space.size()];
	int fir=start.first,sec=start.second,thi=start.third;
	int firx=fir%size_x,firy=fir/size_x;
	int secx=sec%size_x,secy=sec/size_x;
	int thix=thi%size_x,thiy=thi/size_x;
	pos(firx,firy);putchar(appearance[snack.appearance_head]);
	pos(secx,secy);putchar(appearance[snack.appearance_body]);
	pos(thix,thiy);putchar(appearance[snack.appearance_body]);
	get_new_food();
	pos(0,size_y+1);
	snack.head_x=firx;snack.head_y=firy;
	snack.tail_x=thix;snack.tail_y=thiy;
	snack.turn[secx][secy]=get_way_by_two_block(firx,firy,secx,secy);
	snack.turn[thix][thiy]=get_way_by_two_block(secx,secy,thix,thiy);
	snack.turn[firx][firy]=snack.way=get_way_by_two_block(firx,firy,secx,secy);
}
inline void start_game(){
	build_game_space();
	build_snack_food();
	Sleep(2000);
	R int now_score=0;
	for(;;){
		Sleep(1000/snack.speed);
		if(kbhit()){
			R int num=getch();
			if(num==224){
				num=getch();
				if(num==72) num=0;
				else if(num==80) num=1;
				else if(num==75) num=2;
				else if(num==77) num=3;
				if((num==snack.way)||((num^1)==snack.way)) goto FAIL_MOVE;
				snack.way=num;
				snack.turn[snack.head_x][snack.head_y]=num;
			}
			else if(num==27){
				if(MessageBox(NULL,TEXT("Exit?"),TEXT(""),MB_YESNO)==7) goto FAIL_MOVE;
				max_score=max(max_score,now_score);
				return;
			}
		}
		FAIL_MOVE:;
		int _head_x=snack.head_x+way_x[snack.way],_head_y=snack.head_y+way_y[snack.way];
		char head_;
		get_output(head_,_head_x,_head_y);
		if(_head_x<0||_head_y<0) goto DIED;
		if(head_!='\0'&&head_!=' '&&!(_head_x==food.x&&_head_y==food.y)){
			DIED:;
			MessageBox(NULL,TEXT("you died!"),TEXT(""),MB_OK);
			max_score=max(max_score,now_score);
			return;
		}
		pos(_head_x,_head_y);putchar(appearance[snack.appearance_head]);
		snack.turn[_head_x][_head_y]=snack.way;
		pos(snack.head_x,snack.head_y);putchar(appearance[snack.appearance_body]);
		snack.head_x=_head_x;snack.head_y=_head_y;
		if(food.x==snack.head_x&&food.y==snack.head_y){
			snack.eat_num++;
			now_score+=food.special?10:1;
			pos(size_x+8,size_y/2-3);printf("%d",now_score);
			get_new_food();
		}
		if(snack.eat_num>0){
			snack.eat_num--;
			goto NO_SUBTAIL;
		}
		{
			int _tail_x=snack.tail_x+way_x[snack.turn[snack.tail_x][snack.tail_y]];
			int _tail_y=snack.tail_y+way_y[snack.turn[snack.tail_x][snack.tail_y]];
			pos(snack.tail_x,snack.tail_y);putchar(' ');
//			pos(_tail_x,_tail_y);putchar('$');
			pos(0,size_y+1);
			snack.turn[snack.tail_x][snack.tail_y]=-1;
			snack.tail_x=_tail_x;snack.tail_y=_tail_y;
		}
		NO_SUBTAIL:;
		if(food.special) print_special_food();
		pos(snack.head_x,snack.head_y);
	}
}
//game end

//custom start
const int appearance_x=80,appearance_y=5;
const int map_x=80,map_y=7;
const int speed_x=80,speed_y=9;
const int back_custom_x=80,back_custom_y=13;
const int setsize_x=80,setsize_y=11;
int point_custom;
inline void build_custom(){
	system("cls");
	point_custom=0;
	pos(appearance_x-1,appearance_y);putchar('*');
	pos(appearance_x,appearance_y);
	puts("APPEARANCE");
	pos(map_x,map_y);
	puts("MAP");
	pos(speed_x,speed_y);
	puts("SPEED");
	pos(setsize_x,setsize_y);
	puts("SIZE");
	pos(back_custom_x,back_custom_y);
	puts("EXIT");
	pos(0,0);
}
inline void change_point_custom(){
	pos(appearance_x-1,appearance_y);putchar(' ');
	pos(map_x-1,map_y);putchar(' ');
	pos(speed_x-1,speed_y);putchar(' ');
	pos(back_custom_x-1,back_custom_y);putchar(' ');
	pos(setsize_x-1,setsize_y);putchar(' ');
	if(point_custom==0){pos(appearance_x-1,appearance_y);putchar('*');}
	else if(point_custom==1){pos(map_x-1,map_y);putchar('*');}
	else if(point_custom==2){pos(speed_x-1,speed_y);putchar('*');}
	else if(point_custom==3){pos(setsize_x-1,setsize_y);putchar('*');}
	else{pos(back_custom_x-1,back_custom_y);putchar('*');}
	pos(0,0);
}

inline void change_appearance(){
	system("cls");
	puts("ENTER=Set/ESC=Quit");
	for(R int i=0;i<=6;i++) putchar(appearance[snack.appearance_body]);
	putchar(appearance[snack.appearance_head]);
	pos(6,1);
	int now=0,appearance_head_tmp=snack.appearance_head,appearance_body_tmp=snack.appearance_body;
	for(;;){
		if(kbhit()){
			R int num=getch();
			if(num==27){//Esc
				int tmp=MessageBox(NULL,TEXT("Save changes?"),TEXT(""),MB_YESNOCANCEL);
				if(tmp==2) continue;
				if(tmp==6){
					if(appearance_head_tmp==appearance_body_tmp){
						pos(0,2);puts("You can't tell head and body!");
						pos(now?7:6,1);
						continue;
					}
					pos(0,2);puts("Successful...");
					snack.appearance_head=appearance_head_tmp;
					snack.appearance_body=appearance_body_tmp;
					break;
				}
				else{
					pos(0,2);
					puts("Exiting without saving...");
					break;
				}
			}
			else if(num==13){
				now^=1;
				pos(now?7:6,1);
			}
			else if(num==224){
				num=getch();
				if(num==75){
					if(now) appearance_head_tmp=appearance_head_tmp-1<0?71:appearance_head_tmp-1;
					else appearance_body_tmp=appearance_body_tmp-1<0?71:appearance_body_tmp-1;
				}
				if(num==77){
					if(now) appearance_head_tmp=(appearance_head_tmp+1)%72;
					else appearance_body_tmp=(appearance_body_tmp+1)%72;
				}
				pos(0,1);
				for(R int i=0;i<=6;i++) putchar(appearance[appearance_body_tmp]);
				putchar(appearance[appearance_head_tmp]);
				pos(now?7:6,1);
			}
		}
	}
	pos(0,4);
	puts("Press any key to continue...");
	getchar();
}
inline int getnear(int xx,int yy){
	int _xx,_yy;
	_xx=xx-1;_yy=yy;
	if(_xx>0&&!tmp_map[_xx][_yy]) return _yy*size_x+_xx;
	_xx=xx+1;
	if(_xx<size_x&&!tmp_map[_xx][_yy]) return _yy*size_x+_xx;
	_xx=xx;_yy=yy-1;
	if(_yy>0&&!tmp_map[_xx][_yy]) return _yy*size_x+_xx;
	_yy=yy+1;
	if(_yy<size_y&&!tmp_map[_xx][_yy]) return _yy*size_x+_xx;
	return -1;
}
inline int check_tmp_map(){
	three_space_tmp.clear();
	R int size_xy=size_x*size_y,return_1=0;
	for(R int i=0;i<size_xy;i++)if(!tmp_map[i%size_x][i/size_x]){
		R int ix=i%size_x,iy=i/size_x;
		for(R int j=i+1;j<size_xy;j++)if(!tmp_map[j%size_x][j/size_x]){
			R int jx=j%size_x,jy=j/size_x;
			if(!isnear(ix,iy,jx,jy)) continue;
			int getnear_i=getnear(ix,iy);
			if(getnear_i!=-1&&getnear_i!=j){
				three_space_tmp.push_back((three_space_data){j,i,getnear_i});
				return_1=1;continue;
			}
			int getnear_j=getnear(jx,jy);
			if(getnear_j!=-1&&getnear_j!=i){
				three_space_tmp.push_back((three_space_data){i,j,getnear_j});
				return_1=1;continue;
			}
		}
	}
	return return_1;
}
inline void change_map(){
	build_game_space();
	for(R int i=0;i<size_x;i++)for(R int j=0;j<size_y;j++) tmp_map[i][j]=Map[i][j];
	MessageBox(NULL,TEXT("Enter=Set/Esc=Quit"),TEXT("INFO"),MB_OK);
	R int now_x=0,now_y=0;
	pos(0,0);
	for(;;){
		if(kbhit()){
			R int num=getch();
			if(num==27){//Esc
				int tmp=MessageBox(NULL,TEXT("Save changes?"),TEXT(""),MB_YESNOCANCEL);
				if(tmp==2) continue;
				if(tmp==6){
					if(!check_tmp_map()){
						pos(0,size_y+1);
						puts("Go away!");
						pos(now_x,now_y);
						continue;
					}
					for(R int i=0;i<size_x;i++)for(R int j=0;j<size_y;j++) Map[i][j]=tmp_map[i][j];
					three_space.clear();
					int three_space_tmp_size=three_space_tmp.size();
					for(R int i=0;i<three_space_tmp_size;i++) three_space.push_back(three_space_tmp[i]);
					pos(0,size_y+1);
					puts("Success...");
					break;
				}
				else{
					pos(0,size_y+1);
					puts("Exitng without saving...");
					break;
				}
			}
			else if(num==13){
				tmp_map[now_x][now_y]^=1;
				if(!tmp_map[now_x][now_y]) putchar(' ');
				else putchar('#');
			}
			else if(num==224){
				num=getch();
				if(num==72){
					if(now_y>0) now_y--;
				}
				else if(num==80){
					if(now_y<size_y-1) now_y++;
				}
				else if(num==75){//left
					if(now_x>0) now_x--;
				}
				else if(num==77){//right
					if(now_x<size_x-1) now_x++;
				}
			}
			pos(now_x,now_y);
		}
	}
	pos(0,size_y+1);
	puts("Press any key to continue...");
	getchar();
}
inline void change_size(){
	char ss[5007];
	system("cls");
	pos(0,0);
	puts("ROW(10<x<151)COL(10<x<51)Enter=Set...");
	printf("Enter ROW:");
	int xx=0;scanf("%s",ss);
	int len_s=strlen(ss);
	for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<='9') xx=xx*10+ss[i]-'0';
	while(xx<=10||xx>150){
		printf("10<x<151!\nPlease retry");
		scanf("%s",ss);len_s=strlen(ss);
		xx=0;
		for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<'9') xx=xx*10+ss[i]-'0';
	}
	printf("Enter COL:");
	int yy=0;scanf("%s",ss);
	len_s=strlen(ss);
	for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<='9') yy=yy*10+ss[i]-'0';
	while(yy<=10||yy>50){
		printf("10<x<51!%d\nPlease retry",yy);
		scanf("%s",ss);len_s=strlen(ss);
		yy=0;
		for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<='9') yy=yy*10+ss[i]-'0';
	}
	if(MessageBox(NULL,TEXT("Save changes?"),TEXT(""),MB_YESNO)==6){
		size_x=xx;size_y=yy;
		puts("Success...");
		for(R int i=0;i<size_x;i++)for(R int j=0;j<size_y;j++) tmp_map[i][j]=Map[i][j];
		check_tmp_map();
		int len_=three_space_tmp.size();
		three_space.clear();
		for(R int i=0;i<len_;i++) three_space.push_back(three_space_tmp[i]);
	}
	else puts("Exitng withou saving...");
	puts("\nPress any key to continue...");
	getchar();
}
inline void change_speed(){
	char ss[5007];
	system("cls");
	pos(0,0);
	puts("SPEED 1-100...");
	printf("ER");
	int speedd=0;scanf("%s",ss);
	int len_s=strlen(ss);
	for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<='9') speedd=speedd*10+ss[i]-'0';
	while(speedd<1||speedd>100) {
		printf("0<x<100!\nFUCKYOU");
		scanf("%s",ss);len_s=strlen(ss);
		speedd=0;
		for(R int i=0;i<len_s;i++)if(ss[i]>='0'&&ss[i]<'9') speedd=speedd*10+ss[i]-'0';
	}
	if(MessageBox(NULL,TEXT("SURERE"),TEXT(""),MB_YESNO)==6){
		snack.speed=speedd;
		puts("SUCCESS...");
	}
	else puts("ERRRR...");
	//Sleep(1000);
	puts("\nFHHHHH...");
	getch();
}
inline void custom(){
	build_custom();
	for(;;){
		if(kbhit()){
			int num=getch();
			if(num==224){
				num=getch();
				if(num==72){//up
					if(point_custom>0) point_custom--;
					else point_custom=4;
					change_point_custom();
				}
				else if(num==80){//down
					if(point_custom<4) point_custom++;
					else point_custom=0;
					change_point_custom();
				}
				continue;
			}
			if(num==13){//enter
				if(point_custom==0){
					change_appearance();
					system("cls");
					build_custom();
					continue;
				}
				else if(point_custom==1){
					change_map();
					system("cls");
					build_custom();
					continue;
				}
				else if(point_custom==2){
					change_speed();
					system("cls");
					build_custom();
					continue;
				}
				else if(point_custom==3){
					change_size();
					system("cls");
					build_custom();
					continue;
				}
				else return;
			}
		}
	}
}
//custom end

//menu start
const int setting_x=80,setting_y=5;
const int custom_x=80,custom_y=7;
const int start_game_x=80,start_game_y=9;
const int over_x=80,over_y=11;
int now_point;
inline void build_menu(){
	now_point=0;
	pos(custom_x-1,custom_y);
	putchar('*');
	pos(custom_x,custom_y);
	puts("CUSTOM");
	pos(start_game_x,start_game_y);
	puts("START");
	pos(over_x,over_y);
	puts("EXIT");
	pos(0,0);
}
inline void change_point(){
	pos(setting_x-1,setting_y);putchar(' ');
	pos(custom_x-1,custom_y);putchar(' ');
	pos(start_game_x-1,start_game_y);putchar(' ');
	pos(over_x-1,over_y);putchar(' ');
	if(now_point==0){pos(custom_x-1,custom_y);putchar('*');}
	else if(now_point==1){pos(start_game_x-1,start_game_y);putchar('*');}
	else{pos(over_x-1,over_y);putchar('*');}
	pos(0,0);
}
inline void menu(){
	for(;;){
		if(kbhit()){
			int num=getch();
			if(num==224){
				num=getch();
				if(num==72){//up
					if(now_point>0) now_point--;
					else now_point=2;
					change_point();
				}
				else if(num==80){//down
					if(now_point<2) now_point++;
					else now_point=0;
					change_point();
				}
			}
			if(num==13){
				if(now_point==0){custom();system("cls");build_menu();}
				else if(now_point==1){start_game();system("cls");build_menu();}
				else{save();return;}
			}
		}
	}
}
//menu end

int main(){
	srand(time(0));
	inti();
	build_menu();
	menu();
	system("cls");
	pos(0,0);
	return 0;
}
