调用方法：
1. 添加CppCloudLib.lib 和CloudExport.h
2  调用接口
_declspec(dllexport) bool _stdcall CloudAPI(char* api, char*data, char* ver,char*result);
_declspec(dllexport) bool _stdcall Login(char* _userName, char* _password, char *_version = "1.0", char*_rsp = "");

示例：
char ret[2048]="" ;
bool r = false;	
r = Login("aaaaa", "bbbbb", "1.0", ret);	
r = CloudAPI("s.pt.dev.authorize.api.token.get", "{ \"tokenId\":\"gc9j9uAgcT7sXEKE\",\"sftVersion\" : \"1.0.6\" }", "1.0", ret);
