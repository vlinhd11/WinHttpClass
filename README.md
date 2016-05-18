# WinHttpClass
This library  implements winhttp API windows for a simple package, so that the operation is more simple!

# header files

<a href='https://github.com/ybhacker/encoder'>encoder.h</a>

<a href='https://https://github.com/ybhacker/string-utils'>stringext.h</a>


## Test

```c++
#include "http.h"
int main()
{
	CWinHttp *http = new CWinHttp();
	BOOL bResult = http->OpenSession("Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0; KB974487)");
	bResult = http->SetTimeout(3000, 3000, 3000, 3000);
	bResult = http->OpenConnect("http://www.baidu.com/");
	bResult = http->OpenRequest();
	bResult = http->SetReferer("http://www.baidu.com");
	bResult = http->SetLocal(false);//禁止重定向
	bResult = http->SetCookie("name=value");
	bResult = http->Send();
	std::vector<BYTE> response = http->GetResponseBody();

	std::string result;
	result.insert(result.begin(), response.begin(), response.end());

	result = CEncoder::U2A_(result);//utf-8 convert to gb2312
	printf("%s \n", result.c_str());

	std::string headers = http->GetResponseHeaders();
	printf("headers %s \n", headers.c_str());

	std::string statusCode = http->GetResponseHeaderValue(WINHTTP_QUERY_STATUS_CODE);
	printf("statusCode %s \n", statusCode.c_str());

	std::string local = http->GetLocal();
	printf("local %s \n", local.c_str());

	std::string cookies = http->GetCookie();
	printf("cookies %s \n", cookies.c_str());

	cookies = http->MergeCookie(cookies, "BAIDUID=26989AD75E0ACAE255E6DC5614A95D4E:FG=test;");
	printf("merge cookies %s \n", cookies.c_str());

	getchar();
  return 0;
}
```

```
<html>
<head><title>302 Found</title></head>
<body bgcolor="white">
<center><h1>302 Found</h1></center>
<hr><center>pr-nginx_1-0-274_BRANCH Branch
Time : Tue May 17 16:43:46 CST 2016</center>
</body>
</html>

headers HTTP/1.1 302 Moved Temporarily
Connection: Keep-Alive
Date: Wed, 18 May 2016 01:56:21 GMT
Content-Length: 215
Content-Type: text/html
Location: https://www.baidu.com/
P3P: CP=" OTI DSP COR IVA OUR IND COM "
Server: BWS/1.1
Set-Cookie: BAIDUID=8A547ACDAE7E6E7FAA1566A24C1F387E:FG=1; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: BIDUPSID=8A547ACDAE7E6E7FAA1566A24C1F387E; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: PSTM=1463536581; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: BD_LAST_QID=13327324373218173616; path=/; Max-Age=1
X-UA-Compatible: IE=Edge,chrome=1

statusCode 302
local https://www.baidu.com/
cookies BAIDUID=8A547ACDAE7E6E7FAA1566A24C1F387E:FG=1; BD_LAST_QID=13327324373218173616; BIDUPSID=8A547ACDAE7E6E7FAA1566A24C1F387E; Max-Age=1; PSTM=1463536581; domain=.baidu.com; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/
merge cookies BAIDUID=26989AD75E0ACAE255E6DC5614A95D4E:FG=test; BD_LAST_QID=13327324373218173616; BIDUPSID=8A547ACDAE7E6E7FAA1566A24C1F387E; Max-Age=1; PSTM=1463536581; domain=.baidu.com; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/
```
