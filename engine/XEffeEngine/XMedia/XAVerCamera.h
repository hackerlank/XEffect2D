#ifndef _JIA_XAVERCAMERA_
#define _JIA_XAVERCAMERA_
//++++++++++++++++++++++++++++++++
//Author:    ��ʤ��(JiaShengHua)
//Version:    1.0.0
//Date:       2014.1.1
//--------------------------------
#include "XMedia/XCameraBasic.h"

#include "AVer/AVerCapAPI.h"
#pragma comment(lib,"../lib/AVer/AVerCapAPI.lib")

class _XAVerCamera:public _XCameraBasic
{
private:
	HANDLE m_hHDCaptureDevice;		//����ͷ���豸ָ��
	int m_deviceSum;				//����ͷ�豸������
	int m_deviceOrder;				//����ͷ�豸�ı��
	unsigned char *m_frameDataBuff1;//������������ҷ�ת������
	unsigned char *m_frameDataBuff;	//����ͷÿ֡������
	unsigned char *m_texDataBuff;	//��ͼ������
	unsigned char *m_pixelsData;
	int m_px;
	int m_py;
	_XBool m_isUp2Down;		//�Ƿ����·�ת
	_XBool m_isLeft2Right;	//�Ƿ����ҷ�ת
	friend BOOL WINAPI avCameraCB(VIDEO_SAMPLE_INFO VideoInfo, BYTE *pbData,LONG lLength, __int64 tRefTime, LONG lUserData);
	_XBool m_isNewFrame;

	_XBool setPixels(const _XCameraData &data);
public:
	void setUp2Down(_XBool flag){m_isUp2Down = flag;}
	void setLeft2Right(_XBool flag){m_isLeft2Right = flag;}

	void getData(unsigned char * p) const
	{
		if(!m_isInited) return;
		memcpy(p,m_pixelsData,m_buffSize);
	}
	unsigned char * getDataP() const
	{
		if(!m_isInited) return NULL;
		return m_pixelsData;
	}
	//int getBuffSize() const {return m_buffSize;}
	_XBool init(_XCameraData &data);
	_XBool upDateFrame();
	//void draw();
	_XAVerCamera()
		:m_frameDataBuff1(NULL)
		,m_frameDataBuff(NULL)
		,m_texDataBuff(NULL)
		,m_isUp2Down(XFalse)
		,m_isLeft2Right(XFalse)
		,m_isNewFrame(XFalse)
	{
	}
	~_XAVerCamera()
	{
		release();
	}
	void release();
};

#endif