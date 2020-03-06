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
	char p_dllver[50];  // ���ڴ洢��ȡ���İ汾��Ϣ
};

/**********************************************************************************
*
* ��������
*     GetTYWiFiDllVersion
*
* ���ܣ�  
*     ��ȡDLL�汾��Ϣ
*
* ����˵����
*      s_param����ȡ���İ汾��Ϣ�洢,�ο��ṹ�塰GetDllVerParam��
*
**********************************************************************************/
TY_EXPORT void TY_API GetTYWiFiDllVersion(GetDllVerParam *s_param);

/**********************************************************************************
*
* оƬ�ͺŶ���
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
	char p_dev_sn[20];     // ���ڴ洢��ȡ��������SN��
	E_CHIP_TYPE e_type;    // оƬ�ͺţ��ο�ö�١�E_CHIP_TYPE��
	char p_error[256];     // ���ڴ洢ʧ����Ϣ���������ִ�гɹ���Ϊ��
	char p_errcode[20];    // �������
};

/**********************************************************************************
*
* ��������
*     ConnectDevice
*
* ���ܣ�  
*     �����������ڹ��߳�ʼ��ʱ���ô˽ӿڣ�
*
* ����˵����
*      s_param�� �ο��ṹ�塰ConnectDevParam��
*
* ����ֵ��
*     �ɹ����أ�0
*     ʧ�ܷ��أ�1
*
**********************************************************************************/
TY_EXPORT int TY_API ConnectDevice(ConnectDevParam *s_param);

/**********************************************************************************
*
* ��������
*     DisconnectDevice
*
* ���ܣ�  
*     �Ͽ��������ӣ��رչ���ʱ���ô˽ӿڣ�
*
* ����ֵ��
*     �ɹ����أ�0
*     ʧ�ܷ��أ�1
*
**********************************************************************************/
TY_EXPORT int TY_API DisconnectDevice();

/**********************************************************************************
*
* ����ͨ������
*
**********************************************************************************/
enum E_IQ_ID
{
	IQ_ID_0,   // ��һ·
	IQ_ID_1    // �ڶ�·
};

/**********************************************************************************
*
* ����RF�ڶ���
*
**********************************************************************************/
enum E_IQ_RF_PORT
{
	RF_PORT_1,   // RF1
	RF_PORT_2    // RF2
};

typedef struct WiFiCalValue
{
	char p_rate[20];         // ����
	char p_channel[20];      // �ŵ�
	char p_value[20];        // �⵽��ֵ
	char p_low[20];          // ����ֵ
	char p_high[20];         // ����ֵ
	char p_result[20];       // �����PASS or FAIL
};

typedef struct TestItemValue
{
	char p_item[20];         // ����������
	char p_value[20];        // �⵽��ֵ
	char p_low[20];          // ����ֵ
	char p_high[20];         // ����ֵ
	char p_result[20];       // �����PASS or FAIL
};

typedef struct WiFiTestValue
{
	char p_rate[20];           // ����
	char p_channel[20];        // �ŵ�
	TestItemValue s_item[20];  // ÿ��������Ŀ���ص�ֵ���ο��ṹ�塰TestItemValue��
};

typedef struct BTCalValue
{
	char p_packet[20];       // ���ݰ�������
	char p_channel[20];      // �ŵ�
	char p_value[20];        // �⵽��ֵ
	char p_low[20];          // ����ֵ
	char p_high[20];         // ����ֵ
	char p_result[20];       // �����PASS or FAIL
};

typedef struct BTTestValue
{
	char p_packet[20];         // ���ݰ�������
	char p_channel[20];        // �ŵ�
	TestItemValue s_item[20];  // ÿ��������Ŀ���ص�ֵ���ο��ṹ�塰TestItemValue��
};

typedef struct DoTestParam
{
	E_IQ_ID e_id;            // ����ͨ�����ã��ο�ö�١�E_IQ_ID��
	E_IQ_RF_PORT e_port;     // ����RF�����ã��ο�ö�١�E_IQ_RF_PORT��
	int iComPort;            // ���ڣ����磺����ΪCOM3����ô�˲���Ϊ3
	int iBaudrate;           // ������
};

typedef struct DoTestReturn
{
	WiFiCalValue s_freq[128];    // WiFiƵ��У׼���ص�ֵ���ο��ṹ�塰WiFiCalValue��
	WiFiCalValue s_power[128];   // WiFi����У׼���ص�ֵ���ο��ṹ�塰WiFiCalValue��
	WiFiTestValue s_tx[128];     // WiFi������Է��ص�ֵ���ο��ṹ�塰WiFiTestValue��
	WiFiTestValue s_rx[128];     // WiFi���ղ��Է��ص�ֵ���ο��ṹ�塰WiFiTestValue��
	BTCalValue s_bt_power[128];  // ��������У׼���ص�ֵ���ο��ṹ�塰BTCalValue��
	BTTestValue s_bt_tx[128];    // ����������Է��ص�ֵ���ο��ṹ�塰BTTestValue��
	BTTestValue s_bt_rx[128];    // �������ղ��Է��ص�ֵ���ο��ṹ�塰BTTestValue��
	char p_error[256];           // ���ڴ洢ʧ����Ϣ���������ִ�гɹ���Ϊ��
	char p_errcode[20];          // �������
};

/**********************************************************************************
*
* ��������
*     DoTest
*
* ���ܣ�  
*     ��ʼ����
*
* ����˵����
*      s_param�� �ο��ṹ�塰DoTestParam��
*      s_return���ο��ṹ�塰DoTestReturn��
*
* ����ֵ��
*     �ɹ����أ�0
*     ʧ�ܷ��أ�1
*
**********************************************************************************/
TY_EXPORT int TY_API DoTest(DoTestParam *s_param, DoTestReturn *s_return);

typedef struct LossValue
{
	char p_channel[20];      // ���ڴ洢У׼������ŵ�
	char p_loss[20];         // ���ڴ洢У׼�õ�������
};

typedef struct DoCableParam
{
	E_IQ_ID e_id;              // ����ͨ�����ã��ο�ö�١�E_IQ_ID��
	E_IQ_RF_PORT e_port;       // ����RF�����ã��ο�ö�١�E_IQ_RF_PORT��
	int iComPort;              // ���ڣ����磺����ΪCOM3����ô�˲���Ϊ3
	int iBaudrate;             // ������
	LossValue s_loss[128];     // ���ڴ洢wifi����������ο��ṹ�塰LossValue��
	LossValue s_bt_loss[128];  // ���ڴ洢bt����������ο��ṹ�塰LossValue��
	char p_error[256];         // ���ڴ洢ʧ����Ϣ���������ִ�гɹ���Ϊ��
	char p_errcode[20];        // �������
};

/**********************************************************************************
*
* ��������
*     DoCable
*
* ���ܣ�  
*     ����У׼
*
* ����˵����
*      s_param�� �ο��ṹ�塰DoCableParam��
*
* ����ֵ��
*     �ɹ����أ�0
*     ʧ�ܷ��أ�1
*
**********************************************************************************/
TY_EXPORT int TY_API DoCable(DoCableParam *s_param);

#endif // !defined(AFX_TY_WIFI_TEST_API_H_20190805__INCLUDED_)