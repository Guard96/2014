#include <afxwin.h>
#include <afxsock.h>
#include <richedit.h>
#pragma comment(lib,"comctl32.lib")



#define IDC_Server  111
#define IDC_Client  112
#define EDITID 113
#define EDITSENDID 119
#define IDC_SB  114
#define IDC_Send  115
#define IDC_Receive  116
#define IDC_Disconnect 117
#define EDIT_IPID 118
#define WS_VERSION_REQD	0x0101
#define WM_ASYNC WM_USER+1
WSADATA stWSAData;
SOCKET Socket = INVALID_SOCKET;
SOCKET SocketClient = INVALID_SOCKET;
SOCKADDR_IN addr;
WORD WSAEvent,ResCon;
unsigned long RED;


int lenaddr,line,MessageSize;
bool Server=0,Client=0,ClientConnected=0;;
char Addr[50],Message[500],TextSend[1000],temp[256],text[256]="txt",
TextReceive[1000],Name[256];

void
Send(char *Message)
{
	if(SocketClient)
		send(Socket,Message,256,0);
	else send(SocketClient,Message,256,0);
}

void 
ToUnit(char *str1,char *str2,int LenStr,int m)
{
	int n,i;
	n=LenStr+m;
	for(i=0;i<n;i++) {
		str1[i+m]=str2[i];
	}
}

void
StrCopy(char *str1,char *str2,int m,int n)
{
	for(int i=m;i<n;i++) {
		*(str2+i-m)=*(str1+i);
		*(str2+n-m)='\0';
	}

}

WORD 
OnClientConnect(HWND hwnd,char *Addr)
{
	WSAStartup(WS_VERSION_REQD, &stWSAData);
    Socket = socket (AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr =inet_addr(Addr);
	addr.sin_port = htons (1234);
	ResCon=connect (Socket, (struct sockaddr *)&addr,sizeof(addr));
	WSAAsyncSelect(Socket,hwnd,WM_ASYNC,FD_READ|FD_CONNECT|FD_CLOSE);
	return ResCon;

}

void
OnServerCreate(HWND hwnd)
{
	WSAStartup(WS_VERSION_REQD, &stWSAData);
	Socket = socket (AF_INET,SOCK_STREAM,0);
	WSAAsyncSelect(Socket,hwnd,WM_ASYNC, FD_ACCEPT | FD_READ|FD_CONNECT|FD_CLOSE);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr =htonl(INADDR_ANY);
	addr.sin_port = htons (1234);
	bind(Socket,(LPSOCKADDR)&addr, sizeof(struct sockaddr));
	listen (Socket, 5);
}

void
OnClose()
{
	WSACleanup();
	closesocket(Socket);
	closesocket(SocketClient);
	Server=0;
	Client=0;
	ClientConnected=false;
}

static char szAppName[] ="TCP_IP";

LRESULT CALLBACK WndProc (HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInst;

int 
WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, PSTR szCmdLine,int iCmdShow)
{

	MSG  msg;
	HWND hwnd;
	WNDCLASSEX wndclass;
	hInst=hInstance;


	wndclass.cbSize			= sizeof(wndclass);
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon          = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor        = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground  = (HBRUSH) (COLOR_BTNFACE+15) ;
    wndclass.lpszMenuName   = szAppName ;
    wndclass.lpszClassName  = szAppName ;
    wndclass.hIconSm        = LoadIcon (NULL, IDI_APPLICATION) ;

    RegisterClassEx (&wndclass) ;

    hwnd = CreateWindow(szAppName, "TCP_IP",
                        WS_SYSMENU|WS_MINIMIZEBOX|WS_TILED,
						300, 200,
						400, 350,
                        NULL, NULL, hInstance, NULL) ;


    ShowWindow (hwnd, iCmdShow) ;
    UpdateWindow (hwnd) ; 

    while (GetMessage (&msg, NULL, 0, 0)) {
           TranslateMessage (&msg) ;
           DispatchMessage (&msg) ;
         }

     return msg.wParam ;
	
}
	
LRESULT 
CALLBACK WndProc (HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
	{
		static HWND hwndClient,hwndServer,hwndEditSend,hwndList,hwndEdit_Ip,hwndEdit,hwndDisconnect,hwndSB,hwndReceive,hwndSend;
		static int cxClient,cyClient,cxChar,cyChar;
		switch(iMsg)
		{

			case WM_CREATE:

				hwndServer=CreateWindow("button","Create server",
							WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
							2,225,100,25,
							hwnd,(HMENU)IDC_Server,hInst,NULL);

				hwndSend=CreateWindow("button","SendMsg",
							WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
							250,225,100,25,
							hwnd,(HMENU)IDC_Send,hInst,NULL);

				hwndDisconnect=CreateWindow("button","Disconnect",
							WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
							250,265,100,25,
							hwnd,(HMENU)IDC_Disconnect,hInst,NULL);

				hwndEdit_Ip = CreateWindowEx (WS_EX_CLIENTEDGE,"Edit","127.0.0.1",
                            WS_CHILD | WS_VISIBLE| 
                            ES_LEFT ,
                            110,265,130,25, hwnd,(HMENU)EDIT_IPID,hInst, NULL);

				hwndClient=CreateWindow("button","Connect",
							WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
							2,265,100,25,
							hwnd,(HMENU)IDC_Client,hInst,NULL); 

				LoadLibrary ( "RICHED32.DLL");
				hwndEdit = CreateWindowEx (WS_EX_CLIENTEDGE,RICHEDIT_CLASS, NULL,
                            WS_CHILD | WS_VISIBLE|WS_VSCROLL| 
                            ES_LEFT | ES_MULTILINE |ES_READONLY|
                            ES_AUTOVSCROLL,
                            0, 0, 390, 120, hwnd,(HMENU)EDITID,hInst, NULL);
				
				hwndEditSend = CreateWindowEx (WS_EX_CLIENTEDGE,RICHEDIT_CLASS, NULL,
                            WS_CHILD | WS_VISIBLE|WS_VSCROLL|
                            ES_LEFT | ES_MULTILINE |
                            ES_AUTOVSCROLL,
                            0,130, 390,60, hwnd,(HMENU)EDITSENDID,hInst, NULL);

				hwndSB=CreateStatusWindow(WS_CHILD | WS_VISIBLE | 
                            WS_CLIPSIBLINGS | CCS_BOTTOM |SBARS_SIZEGRIP,"Not connected",
							hwnd,IDC_SB);

			SendMessage(hwndEdit, EM_LIMITTEXT, 1024 * 1024, 0);
			SendMessage(hwndEditSend, EM_LIMITTEXT, 1024 * 1024, 0);

				return 0;
			case WM_ASYNC:
				WSAEvent = WSAGETSELECTEVENT (lParam);
				switch (WSAEvent) {
					case FD_READ:
						if(Server) {

							recv(SocketClient,Message,256, 0);
							StrCopy(Message,temp,0,3);
							if (strcmp(temp,text)==0){
								StrCopy(Message,TextReceive,3,500);
								SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)TextReceive);
								SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)"\n");
							}
							

						}
						if(Client) {
							recv(Socket,Message,256, 0);
							StrCopy(Message,temp,0,3);
							if (strcmp(temp,text)==0){
								StrCopy(Message,TextReceive,3,500);
								SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)TextReceive);
								SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)"\n");
							}
							
						}
						
					break;

					
					case FD_ACCEPT:
						lenaddr=sizeof(addr);
						SocketClient=accept(Socket,(LPSOCKADDR)&addr,&lenaddr);
						if(SocketClient!=INVALID_SOCKET) ClientConnected=true;
					break;

					case FD_CLOSE:
						SetWindowText(hwndSB,"Not connected.");
						OnClose();
					break;
				}
				return 1;

			case WM_KEYDOWN:

			switch(wParam) {
				case VK_RETURN:
					SetWindowText(hwndEdit,"ENTER DONE !!!");

				break;
			}
			break; 



			case WM_SETFOCUS:
			break;

			case WM_COMMAND:
				switch(wParam) {
					case IDC_Server:
						Name[0]='F';
						Name[1]='e';
						Name[2]='d';
						Name[3]='o';
						Name[4]='r';
						Name[5]='-';
						Name[6]='>';
						Server=true;
						OnServerCreate(hwnd);
						SetWindowText(hwndSB,"Waiting...");
						if (!SetTimer (hwnd, 1, 100, NULL)) {
								MessageBox (hwnd, "Too many clocks or timers!",
								szAppName, MB_ICONEXCLAMATION | MB_OK) ;
								return FALSE ;
							}
					break;

					case IDC_Client:
						Name[0]='P';
						Name[1]='a';
						Name[2]='v';
						Name[3]='e';
						Name[4]='l';
						Name[5]='-';
						Name[6]='>';

						Client=true;
						GetWindowText(hwndEdit_Ip,Addr,255);
						ResCon=OnClientConnect(hwnd,Addr);
						if (ResCon!=0) SetWindowText(hwndSB,"Not connected.");
							else SetWindowText(hwndSB,"Connected to server.");
					break;

					case IDC_Disconnect:
						SetWindowText(hwndSB,"Not connected.");
						OnClose();					
					break;

					case IDC_Send:
						Message[0]='t';
						Message[1]='x';
						Message[2]='t';
						line = SendMessage (hwndEditSend, EM_GETLINECOUNT, 0, 0);
						MessageSize=line*47+3;
						GetWindowText(hwndEditSend,TextSend,MessageSize);
						ToUnit(Name,TextSend,MessageSize,7);
						SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)Name);
						SendMessage(hwndEdit,EM_REPLACESEL, TRUE, (long)"\n");
						ToUnit(Message,Name,MessageSize,3);
						
						if(Server) {
							send(SocketClient,Message,256, 0);
							SetWindowText(hwndEditSend,"");
						}
						if(Client) {
							send(Socket,Message, 256, 0);
							SetWindowText(hwndEditSend,"");
						}
					break;
				}
			return 0;
			case WM_TIMER :
				if(Server) {
					if (ClientConnected) {
						SetWindowText(hwndSB,"Client connected");
						KillTimer (hwnd, 1) ;
					}
				}
			return 0;
			case WM_CLOSE:
				OnClose();
				PostQuitMessage(0);
				return 0;
			
			case WM_DESTROY:
				OnClose();
				KillTimer (hwnd, 1) ;
				PostQuitMessage(0);
				return 0;

		}


	    return DefWindowProc(hwnd,iMsg,wParam,lParam);
	}
	
					
