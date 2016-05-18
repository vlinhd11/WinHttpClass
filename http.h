#pragma once

#include "encoder.h"
#include "stringext.h"

#include <string>
#include <vector>
#include <map>

#include <winhttp.h>
#pragma comment(lib, "winhttp")

class CWinHttp
{
protected:

	HINTERNET			m_hSession;
	HINTERNET			m_hConnect;
	HINTERNET			m_hRequest;

	std::wstring		m_strHost;
	std::wstring		m_strPath;
	std::wstring		m_strExt;
	INTERNET_SCHEME		m_nScheme;
	INTERNET_PORT		m_nPort;

public:

	CWinHttp();

	//初始化Session
	BOOL OpenSession(
		const std::string &userAgent = "", 
		int dwAccessType = WINHTTP_ACCESS_TYPE_NO_PROXY,
		const std::string &proxyName = "",
		const std::string &proxyBypass = "",
		int dwFlags = 0
	);

	//连接服务器
	BOOL OpenConnect(const std::string &url);

	//打开请求
	BOOL OpenRequest(bool bPost = false, bool bInitContentType = false);

	//发送数据
	BOOL Send(LPVOID lpbuffer = NULL, DWORD dwsize = 0);

	//上传文件多步提交,写入数据
	BOOL Write(LPCVOID lpbuffer, DWORD dwsize);

	//获取返回内容
	std::vector<BYTE> GetResponseBody();

	//获取指定返回协议头
	std::string GetResponseHeaderValue(int dwInfoLevel, DWORD dwIndex = WINHTTP_NO_HEADER_INDEX);
	std::string GetResponseHeaderValue(const std::string &name);

	//获取全部返回协议头
	std::string GetResponseHeaders();

	//设置请求协议头
	BOOL SetRequestHeader(const std::string &name,const std::string &value);

	//设置请求referer
	BOOL SetReferer(const std::string &referer);

	//设置超时时间 OpenSession 以后调用
	BOOL SetTimeout(
		int nResolveTimeout = 3000,
		int nConnectTimeout = 3000,
		int nSendTimeout = 3000,
		int nReceiveTimeout = 3000
	);

	//设置属性
	BOOL SetOption(int Option, int value);

	//是否允许重定向 false不允许 true 允许
	BOOL SetLocal(bool Is);

	//取重定向地址
	std::string GetLocal();

	//设置Cookie
	BOOL SetCookie(const std::string &cookies);

	//获取返回cookies
	std::string GetCookie();

	//合并Cookies
	std::string MergeCookie(const std::string &oldCookies, const std::string &nowCookies);

	virtual ~CWinHttp();
};
