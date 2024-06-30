

SendMessage:发送消息阻塞等待消息结果返回
直接向窗口过程发送
PostMessage:投递消息，直接返回不等待结果返回，消息投递到消息队列中

//步骤:
//1.定义消息#define WM_MyMessage WM_USER + Ox1
//2.在窗口创建的时候我们发送一下这个消息,或者我们将窗口的名称修改

#include <Windows.h>
#include <string>
HANDLE g_output = 0;
//定义自己的消息
#define WM_XIAOQIANG (WM_USER + 0x1)

void showXY(HWND hWnd, LPARAM lp) {
	short x = LOWORD(lp);
	short y = LOWORD(lp);
	char* buffer = new char[10];
	wsprintf(buffer, "x:%d y:%d\n", x, y);
	int result = MessageBox(hWnd, "显示坐标", "XY坐标", MB_YESNO);
	switch (result) {
	case IDYES:
		MessageBox(hWnd, buffer, "确认", MB_OK);
		break;
	case IDNO:
		MessageBox(hWnd, buffer, "否认", MB_OK);
		break;
	}
}

//窗口创建成功显示之前初始化
void createMe(HWND hWnd,LPARAM lp) {
	CREATESTRUCT* cs = (CREATESTRUCT*)lp;
	char* test = (char*)cs->lpCreateParams;
	MessageBox(hWnd, test, "确认", MB_OK);
}
//
void SizeMe(HWND hWnd, LPARAM lp) {
	short x = LOWORD(lp);
	short y = HIWORD(lp);
	char* buffer = new char[10];
	wsprintf(buffer, "size->x:%d y:%d\n", x, y);
	WriteConsole(g_output, buffer, strlen(buffer), NULL, NULL);
}
void ShowMe(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	int number = (int)wParam;
	const char* text = (const char*)lParam;
	char buffer[256];
	wsprintf(buffer, "Number: %d, Text: %s", number, text);
	SetWindowText(hWnd, buffer);
}
//SendMessage:发送消息阻塞等待消息结果返回
//直接向窗口过程发送
//PostMessage : 投递消息，直接返回不等待结果返回，消息投递到消息队列中

//一些消息概念
//系统消息 0-ox03FF 1024个
//用户消息 0x0400-0x7FFF 31743个
// 用户消息需要自定义消息宏:WM_USER(0x400)
// 消息的创建,发送和接收都要自行处理
//2.定义窗口处理函数处理消息
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wp, LPARAM lp) {
	switch (msgID) {
	//窗口销毁
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	//窗口最大最小的关闭的时候
	case WM_SYSCOMMAND:
		showXY(hWnd, lp);
		break;
	//窗口创建成功未显示之前,窗口创建的初始化
	case WM_CREATE:
		createMe(hWnd, lp);
		{
			//就假如说窗口创建完毕的时候我么发送一个执行hook的消息.
			int someNumber = 42;
			const char* someText = "小强hook";

			PostMessage(hWnd, WM_XIAOQIANG, someNumber, (LPARAM)someText);
		}
		break;
	//窗口大小变化的时候会调用,lp的低字节为水平位置,高字节为垂直位置
	case WM_SIZE:
		SizeMe(hWnd, lp);
		break; 

	case WM_XIAOQIANG:
		ShowMe(hWnd, wp,lp);
		break;
	}

	return DefWindowProc(hWnd, msgID, wp, lp);
}
//1.定义winMain入口函数
int WINAPI WinMain(HINSTANCE hins, HINSTANCE hPre, LPSTR lpCmd, int nCmd) {
	AllocConsole();//创建控制台
	g_output = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	WNDCLASS wc = { 0 };
	wc.hInstance = hins;
	//2.定义窗口处理函数处理消息
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "jcl";
	//3.注册窗口类(把数据写入操作系统内核)
	RegisterClass(&wc);
	//可以传入参数
	const char* test = "hello";
	//4.创建窗口(写入内存)
	HWND hWnd = CreateWindow("jcl", "Test", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hins,(char*)test);
	//第三个可以是
	 //HWND hWnd = CreateWindow("edit", "Test", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hins, NULL);
	
	//定义子窗口
	wc.hInstance = hins;
	//2.定义子窗口处理函数处理消息
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = "child";
	RegisterClass(&wc);
	HWND c1 = CreateWindow("child", "Test1", WS_OVERLAPPEDWINDOW | WS_CHILD|WS_VISIBLE, 0, 0, 200, 200, hWnd, NULL, hins, NULL);
	HWND c2 = CreateWindow("child", "Test2", WS_OVERLAPPEDWINDOW | WS_CHILD | WS_VISIBLE, 200, 200, 200, 200, hWnd, NULL, hins, NULL);
	 //5.显示窗口(根据第四步)
	ShowWindow(hWnd, SW_SHOW);
	//重新绘制一遍
	UpdateWindow(hWnd);
	//6.消息处理-消息循环-消息翻译-消息派发
	MSG nMsg = { 0 };
	const char* buffer = "有消息";
	//while (GetMessage(&nMsg, NULL, 0, 0)) {
	//	//消息翻译
	//	TranslateMessage(&nMsg);
	//	DispatchMessage(&nMsg);
	//	WriteConsole(g_output, buffer, strlen(buffer), NULL, NULL);
	//}

	while (true) {
		if (PeekMessage(&nMsg, NULL, 0, 0, PM_NOREMOVE)) {
			if (GetMessage(&nMsg, NULL, 0, 0)) {
				TranslateMessage(&nMsg);
				DispatchMessage(&nMsg);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			//没有消息
			WriteConsole(g_output, buffer, strlen(buffer), NULL, NULL);
		}
	}
	return 0;

}


