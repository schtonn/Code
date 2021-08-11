#include "bits/stdc++.h"
#include<Windows.h>//ShellExecuteA()
using namespace std;

void open(char*website){
    ShellExecuteA(0,"open",website,0,0,SW_SHOW);
}
void move(int x,int y){
    mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,x,y,0,0);
}
void click(int x,int y){
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
void fastshut(){
    keybd_event(VK_CONTROL,0,2,0);
    keybd_event(VK_MENU,0,2,0);
    keybd_event(VK_ESCAPE,0,2,0);
    Sleep(100);
    keybd_event(VK_ESCAPE,0,0,0);
    Sleep(100);
    keybd_event(VK_ESCAPE,0,2,0);
    Sleep(100);
    keybd_event(VK_ESCAPE,0,0,0);
    Sleep(100);
    keybd_event(VK_ESCAPE,0,2,0);
    Sleep(100);
    keybd_event(VK_LWIN,0,0,0);
    keybd_event('R',0,0,0);
    keybd_event('R',0,2,0);
    keybd_event(VK_LWIN,0,2,0);
    char c[]="SHUTDOWN -S -T 1000";
    for(int i=0;i<(int)sizeof(c);i++){
        if(c[i]==' '){
            keybd_event(VK_SPACE,0,0,0);
            keybd_event(VK_SPACE,0,2,0);
        }else if(c[i]=='-'){
            keybd_event(VK_SUBTRACT,0,0,0);
            keybd_event(VK_SUBTRACT,0,2,0);
        }else if('0'<=c[i]&&c[i]<='9'){
            keybd_event(0x30+c[i]-'0',0,0,0);
            keybd_event(0x30+c[i]-'0',0,2,0);
        }else{
            keybd_event(c[i],0,0,0);
            keybd_event(c[i],0,2,0);
        }
        Sleep(10);
    }
}
void dodge(){
    RECT rect;
    HWND hwnd=GetForegroundWindow();
    POINT ptB={0,0};
    for(int i=1;i<=100;i++){
        int p=1;
        LPPOINT pos=&ptB;
        while(p){
            GetWindowRect(hwnd,&rect);
            GetCursorPos(pos);
            long l=rect.left,r=rect.right,t=rect.top,b=rect.bottom;
            if(pos->x<r&&pos->x>l&&pos->y<b&&pos->y>t){
                mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE,rand()*rand()%65536,rand()*rand()%65536,0,0);
                Sleep(30);
                p=0;
            }
            Sleep(30);
            int a=GetKeyState(VK_ESCAPE),c=GetKeyState(VK_MENU);
            if(a<0||c<0){
                fastshut();
                return;
            }
        }
    }
}
void shut(){
    keybd_event(VK_LWIN,0,0,0);
    keybd_event('R',0,0,0);
    keybd_event('R',0,2,0);
    keybd_event(VK_LWIN,0,2,0);
    Sleep(100);
    char c[]="SHUTDOWN -S -T 1000";
    for(int i=0;i<(int)sizeof(c);i++){
        if(c[i]==' '){
            keybd_event(VK_SPACE,0,0,0);
            keybd_event(VK_SPACE,0,2,0);
        }else if(c[i]=='-'){
            keybd_event(VK_SUBTRACT,0,0,0);
            keybd_event(VK_SUBTRACT,0,2,0);
        }else if('0'<=c[i]&&c[i]<='9'){
            keybd_event(0x30+c[i]-'0',0,0,0);
            keybd_event(0x30+c[i]-'0',0,2,0);
        }else{
            keybd_event(c[i],0,0,0);
            keybd_event(c[i],0,2,0);
        }
        Sleep(30);
    }
    dodge();
}
int main(){
    shut();
    keybd_event(VK_RETURN,0,0,0);
    keybd_event(VK_RETURN,0,2,0);
    return 0;
}