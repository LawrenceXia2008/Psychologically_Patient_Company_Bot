#include <iostream>
#include <string>
#include <afxinet.h> //定义了MFC CInternetSession类等
#include<Windows.h>
using namespace std;
bool PostHttpPage(const std::string& hostName,
	const std::string& pathName,
	const std::string& postData)
{
	using namespace std;

	CInternetSession session("your app agent name");

	try
	{
		INTERNET_PORT nPort = 8081;
		DWORD dwRet = 0;

		CHttpConnection* pServer = session.GetHttpConnection(
			hostName.c_str(), nPort);
		CHttpFile* pFile = pServer->OpenRequest(CHttpConnection::
			HTTP_VERB_POST, pathName.c_str());

		CString strHeaders = "Content-Type: text/plain"; //请求头  /*application/x-www-form-urlencoded*/

																			   //开始发送请求

		pFile->SendRequest(strHeaders, (LPVOID)postData.c_str(),
			postData.size());
		pFile->QueryInfoStatusCode(dwRet);

		if (dwRet == HTTP_STATUS_OK)
		{
			CString result, newline;

			while (pFile->ReadString(newline))
			{//循环读取每行内容
				result += newline + "\r\n";
			}

			std::cout << result << std::endl;//显示返回内容
		}
		else
		{
			std::cout << dwRet << endl;
			return false;
		}
		delete pFile;
		delete pServer;
	}
	catch (CInternetException* pEx)
	{
		//catch errors from WinInet
		TCHAR pszError[200];
		pEx->GetErrorMessage(pszError, 200);

		std::cout << pszError << std::endl;//显示异常信息
		return false;
	}
	session.Close();

	return true;
}
#pragma once
