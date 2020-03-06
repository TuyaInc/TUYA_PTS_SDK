/**********************************************************************************
*
* Filename:
* ---------
*   TY_WiFi_Test_API.h
*
* Project:
* --------
*   TY_WiFi_DLL
*
* Description:
* ------------
*  TY_WiFi_DLL export function header
*
* Author:
* -------
* -------
*
**********************************************************************************/

#if !defined(AFX_TY_WIFI_TEST_API_H_20190805__INCLUDED_)
#define AFX_TY_WIFI_TEST_API_H_20190805__INCLUDED_

#include <tchar.h>
#include <vector>

#define TY_EXPORT extern "C"  __declspec(dllexport)
#define TY_API   __stdcall

#define TY_SUCCESS  0
#define TY_ERROR    1

typedef struct GetDllVerParam
{
	char p_dllver[50];  // 用于存储获取到的版本信息
};

/**********************************************************************************
*
* 函数名：
*     GetTYWiFiDllVersion
*
* 功能：  
*     获取DLL版本信息
*
* 参数说明：
*      s_param：获取到的版本信息存储,参考结构体“GetDllVerParam”
*
**********************************************************************************/
TY_EXPORT void TY_API GetTYWiFiDllVersion(GetDllVerParam *s_param);

/**********************************************************************************
*
* 芯片型号定义
*
**********************************************************************************/
enum E_CHIP_TYPE
{
	ESP_8266,
	RTL_8710BN,
	RTL_8711AM,
	RTL_8188FTV,
	BK_7231,
	BK_7231S,
	RDA_5981X
};

typedef struct ConnectDevParam
{
	char p_dev_sn[20];     // 用于存储获取到的仪器SN号
	E_CHIP_TYPE e_type;    // 芯片型号，参考枚举“E_CHIP_TYPE”
	char p_error[256];     // 用于存储失败信息，如果函数执行成功则为空
	char p_errcode[20];    // 错误代码
};

/**********************************************************************************
*
* 函数名：
*     ConnectDevice
*
* 功能：  
*     连接仪器（在工具初始化时调用此接口）
*
* 参数说明：
*      s_param： 参考结构体“ConnectDevParam”
*
* 返回值：
*     成功返回：0
*     失败返回：1
*
**********************************************************************************/
TY_EXPORT int TY_API ConnectDevice(ConnectDevParam *s_param);

/**********************************************************************************
*
* 函数名：
*     DisconnectDevice
*
* 功能：  
*     断开仪器连接（关闭工具时调用此接口）
*
* 返回值：
*     成功返回：0
*     失败返回：1
*
**********************************************************************************/
TY_EXPORT int TY_API DisconnectDevice();

/**********************************************************************************
*
* 测试通道定义
*
**********************************************************************************/
enum E_IQ_ID
{
	IQ_ID_0,   // 第一路
	IQ_ID_1    // 第二路
};

/**********************************************************************************
*
* 仪器RF口定义
*
**********************************************************************************/
enum E_IQ_RF_PORT
{
	RF_PORT_1,   // RF1
	RF_PORT_2    // RF2
};

typedef struct WiFiCalValue
{
	char p_rate[20];         // 速率
	char p_channel[20];      // 信道
	char p_value[20];        // 测到的值
	char p_low[20];          // 下限值
	char p_high[20];         // 上限值
	char p_result[20];       // 结果，PASS or FAIL
};

typedef struct TestItemValue
{
	char p_item[20];         // 测试项名称
	char p_value[20];        // 测到的值
	char p_low[20];          // 下限值
	char p_high[20];         // 上限值
	char p_result[20];       // 结果，PASS or FAIL
};

typedef struct WiFiTestValue
{
	char p_rate[20];           // 速率
	char p_channel[20];        // 信道
	TestItemValue s_item[20];  // 每个测试项目返回的值，参考结构体“TestItemValue”
};

typedef struct BTCalValue
{
	char p_packet[20];       // 数据包的类型
	char p_channel[20];      // 信道
	char p_value[20];        // 测到的值
	char p_low[20];          // 下限值
	char p_high[20];         // 上限值
	char p_result[20];       // 结果，PASS or FAIL
};

typedef struct BTTestValue
{
	char p_packet[20];         // 数据包的类型
	char p_channel[20];        // 信道
	TestItemValue s_item[20];  // 每个测试项目返回的值，参考结构体“TestItemValue”
};

typedef struct DoTestParam
{
	E_IQ_ID e_id;            // 测试通道设置，参考枚举“E_IQ_ID”
	E_IQ_RF_PORT e_port;     // 仪器RF口设置，参考枚举“E_IQ_RF_PORT”
	int iComPort;            // 串口，列如：串口为COM3，那么此参数为3
	int iBaudrate;           // 波特率
};

typedef struct DoTestReturn
{
	WiFiCalValue s_freq[128];    // WiFi频率校准返回的值，参考结构体“WiFiCalValue”
	WiFiCalValue s_power[128];   // WiFi功率校准返回的值，参考结构体“WiFiCalValue”
	WiFiTestValue s_tx[128];     // WiFi发射测试返回的值，参考结构体“WiFiTestValue”
	WiFiTestValue s_rx[128];     // WiFi接收测试返回的值，参考结构体“WiFiTestValue”
	BTCalValue s_bt_power[128];  // 蓝牙功率校准返回的值，参考结构体“BTCalValue”
	BTTestValue s_bt_tx[128];    // 蓝牙发射测试返回的值，参考结构体“BTTestValue”
	BTTestValue s_bt_rx[128];    // 蓝牙接收测试返回的值，参考结构体“BTTestValue”
	char p_error[256];           // 用于存储失败信息，如果函数执行成功则为空
	char p_errcode[20];          // 错误代码
};

/**********************************************************************************
*
* 函数名：
*     DoTest
*
* 功能：  
*     开始测试
*
* 参数说明：
*      s_param： 参考结构体“DoTestParam”
*      s_return：参考结构体“DoTestReturn”
*
* 返回值：
*     成功返回：0
*     失败返回：1
*
**********************************************************************************/
TY_EXPORT int TY_API DoTest(DoTestParam *s_param, DoTestReturn *s_return);

typedef struct LossValue
{
	char p_channel[20];      // 用于存储校准线损的信道
	char p_loss[20];         // 用于存储校准得到的线损
};

typedef struct DoCableParam
{
	E_IQ_ID e_id;              // 测试通道设置，参考枚举“E_IQ_ID”
	E_IQ_RF_PORT e_port;       // 仪器RF口设置，参考枚举“E_IQ_RF_PORT”
	int iComPort;              // 串口，列如：串口为COM3，那么此参数为3
	int iBaudrate;             // 波特率
	LossValue s_loss[128];     // 用于存储wifi线损参数，参考结构体“LossValue”
	LossValue s_bt_loss[128];  // 用于存储bt线损参数，参考结构体“LossValue”
	char p_error[256];         // 用于存储失败信息，如果函数执行成功则为空
	char p_errcode[20];        // 错误代码
};

/**********************************************************************************
*
* 函数名：
*     DoCable
*
* 功能：  
*     线损校准
*
* 参数说明：
*      s_param： 参考结构体“DoCableParam”
*
* 返回值：
*     成功返回：0
*     失败返回：1
*
**********************************************************************************/
TY_EXPORT int TY_API DoCable(DoCableParam *s_param);

#endif // !defined(AFX_TY_WIFI_TEST_API_H_20190805__INCLUDED_)