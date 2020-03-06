#if !defined(TUYA_CLOUDLIB_HEADER_INCLUDED)
#define TUYA_CLOUDLIB_HEADER_INCLUDED
#pragma once
/*************************************************
Function:       CloudAPI
Description:    Call tuya cloud api
[in]api			API name
[in]data		parameters send to tuya cloud
[in]ver			API version
[out]result		response from tuya cloud
Return:         true/false
*************************************************/
_declspec(dllexport) bool _stdcall CloudAPI(char* api, char*data, char* ver,char*result);
/*************************************************
Function:       Login
Description:    Login tuya cloud
[in]_userName	user name
[in]_password	password
[in]_version	API version
[out]_rsp		response from tuya cloud
Return:         true/false
*************************************************/
_declspec(dllexport) bool _stdcall Login(char* _userName, char* _password, char *_version = "1.0", char*_rsp = "");
#endif