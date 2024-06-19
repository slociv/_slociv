#include <Windows.h>


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
		break;
	}
	
	return DefWindowProc(hWnd, msgID, wp, lp);
}
//1.定义winMain入口函数
int WINAPI WinMain(HINSTANCE hins, HINSTANCE hPre, LPSTR lpCmd, int nCmd) {
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
	while (GetMessage(&nMsg, NULL, 0, 0)) {
		//消息翻译
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	return 0;

}


