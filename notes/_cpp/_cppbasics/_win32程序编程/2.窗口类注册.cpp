#include <Windows.h>
//2.定义窗口处理函数处理消息
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wp, LPARAM lp) {
	return DefWindowProc(hWnd, msgID, wp, lp);
}
//1.定义winMain入口函数
int WINAPI WinMain(HINSTANCE hins, HINSTANCE hPre, LPSTR lpCmd, int nCmd) {
	WNDCLASS wc = { 0 };
	wc.hInstance = hins;
	//2.定义窗口处理函数处理消息
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "jcl";
	wc.style = CS_NOCLOSE;
	//3.注册窗口类(把数据写入操作系统内核)
	RegisterClass(&wc);
	//4.创建窗口(写入内存)
	
	HWND hWnd = CreateWindow("jcl", "Test", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hins, NULL);
	//第三个可以是
	 //HWND hWnd = CreateWindow("edit", "Test", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hins, NULL);
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


