	//6.消息处理-消息循环-消息翻译-消息派发
	MSG nMsg = { 0 };
	while (GetMessage(&nMsg, NULL, 0, 0)) {
		//消息翻译
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	return 0;

GetMessage(&nMsg, NULL, 0, 0)

BOOL GetMessage(
  [out]          LPMSG lpMsg,//指向消息的指针，从线程消息队列中接收消息
  [in, optional] HWND  hWnd,//取得消息窗口的句柄
  [in]           UINT  wMsgFilterMin,//指定被检索的最小消息的整数
  [in]           UINT  wMsgFilterMax//指定被检索的最大消息的整数
);

GetMessage 取得指定窗口联系的消息
不接受其他线程或应用程序的消息
获取消息成功后将从消息队列中删除该消息
函数一直等待有消息到来才有返回值