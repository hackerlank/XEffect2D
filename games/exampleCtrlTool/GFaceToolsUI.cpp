#include "GFaceToolsUI.h"

using namespace XE;
bool GFaceToolsUI::createUI()
{
	m_isShowFeatureDataChk.initWithoutSkin("是否显示特征点");
	m_isShowFeatureDataChk.setPosition(5,485);
	m_isShowFeatureDataChk.setScale(1,1);
	m_dataResourcesTypeCmb.initWithoutSkin(128,2,2);
	m_dataResourcesTypeCmb.setPosition(275,484);
	m_dataResourcesTypeCmb.setScale(1,1);
	m_dataResourcesTypeCmb.setMenuStr("摄像头;视频文件;");
	m_startOrStopBtn.initWithoutSkin("开始",XVector2(128,32));
	m_startOrStopBtn.setPosition(438,484);
	m_startOrStopBtn.setScale(1,1);
	m_chooseFileBtn.initWithoutSkin("选择文件",XVector2(128,32));
	m_chooseFileBtn.setPosition(5,520);
	m_chooseFileBtn.setScale(1,1);
	m_curFilenameTxt.init("F:/xiajia.avi");
	m_curFilenameTxt.setPosition(138,520);
	m_curFilenameTxt.setScale(1,1);
	m_camIndexTxt.init("编号:");
	m_camIndexTxt.setPosition(5,554);
	m_camIndexTxt.setScale(1,1);
	m_camIndexEdt.initWithoutSkin(XVector2(32,32),"0");
	m_camIndexEdt.setPosition(82,554);
	m_camIndexEdt.setScale(1,1);
	m_camWidthTxt.init("宽:");
	m_camWidthTxt.setPosition(117,554);
	m_camWidthTxt.setScale(1,1);
	m_camWidthEdt.initWithoutSkin(XVector2(70,32),"1024");
	m_camWidthEdt.setPosition(164,554);
	m_camWidthEdt.setScale(1,1);
	m_camHeightTxt.init("高:");
	m_camHeightTxt.setPosition(236,554);
	m_camHeightTxt.setScale(1,1);
	m_camHeightEdt.initWithoutSkin(XVector2(70,32),"768");
	m_camHeightEdt.setPosition(282,554);
	m_camHeightEdt.setScale(1,1);
	m_isShowCurDataChk.initWithoutSkin("是否实时显示");
	m_isShowCurDataChk.setPosition(355,554);
	m_isShowCurDataChk.setScale(1,1);
	m_basicInfoMTxt.initWithoutSkin(XVector2(1014,144),"基本信息:");
	m_basicInfoMTxt.setPosition(5,588);
	m_basicInfoMTxt.setScale(1,1);
	m_auInfoMTxt.initWithoutSkin(XVector2(185,480),"AU信息:");
	m_auInfoMTxt.setPosition(646,2);
	m_auInfoMTxt.setScale(1,1);
	m_suInfoMTxt.initWithoutSkin(XVector2(185,480),"SU信息:");
	m_suInfoMTxt.setPosition(834,2);
	m_suInfoMTxt.setScale(1,1);
	m_oscSenderIPTxt.init("IP:");
	m_oscSenderIPTxt.setPosition(576,484);
	m_oscSenderIPTxt.setScale(1,1);
	m_oscSenderIPEdt.initWithoutSkin(XVector2(256,32),"127.0.0.1");
	m_oscSenderIPEdt.setPosition(622,485);
	m_oscSenderIPEdt.setScale(1,1);
	m_oscSenderIPEdt.setComment("Osc通讯的IP地址");
	m_oscSenderPortTxt.init("发送端口:");
	m_oscSenderPortTxt.setPosition(577,520);
	m_oscSenderPortTxt.setScale(1,1);
	m_oscSenderPortEdt.initWithoutSkin(XVector2(164,32),"12345");
	m_oscSenderPortEdt.setPosition(714,519);
	m_oscSenderPortEdt.setScale(1,1);
	m_oscRecvPortTxt.init("接收端口:");
	m_oscRecvPortTxt.setPosition(576,554);
	m_oscRecvPortTxt.setScale(1,1);
	m_oscRecvPortEdt.initWithoutSkin(XVector2(164,32),"54321");
	m_oscRecvPortEdt.setPosition(714,554);
	m_oscRecvPortEdt.setScale(1,1);
	return true;
}
