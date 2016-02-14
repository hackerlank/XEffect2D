#ifndef _JIA_XFONT_
#define _JIA_XFONT_
//++++++++++++++++++++++++++++++++
//Author:	��ʤ��(JiaShengHua)
//Version:	1.0.0
//Date:		2011.4.9
//--------------------------------
//�л�˵��������ÿ���ַ������ݷ����ı�ʱ����Ҫ���ַ������ڲ����ݽ��и��£��������������Ա�����һ�ε��ַ������ݣ��Ƚϲ�ͬ�Ĳ��ֲŽ��и��¡�
//Ҳ����ֱ�ӽ��ַ���ͨ��FBO����Ϊһ����ͼ��ֱ����ͨ������һ������ʾ�Ͳ���Ҫÿ�ζ����м��㣬
//���������������⣬1���ڴ����Ľϴ�2����ͼ�ĳߴ���������ֵ����ݶ������仯
#include "XFontBasic.h"
namespace XE{
#ifndef TEXT_FONT_MODE
#define TEXT_FONT_MODE " !\"#$%&\'()*+,-./0123456789:;<=>\?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#endif

class XFont:public XFontBasic
{
private:
	void updateData();			//������Ҫ�����ڲ�����
	XVector2 *m_textPosition;	//���ڱ���ÿ���ַ���λ��
	XRect *m_textRect;			//���ڱ���ÿ���ַ��ļ��к���
	XVector2 m_layout;		//����ͼƬ�Ĳ���

public:
	XBool init(const char *filename,	//����ͼƬ���ļ���
		const XVector2& size,		//��������ش�С
		const XVector2& layout,		//����ͼƬ�Ĳ���
		XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE,XBool withFBO = XFalse);		
	XBool initEx(const char *filename,XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE,XBool withFBO = XFalse);	//����ӿ�,����Դ�ж�ȡ����
	XBool initFromTTF(const char * filename,int fontSize,XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE,XBool withFBO = XFalse);	//��TTF�ļ��г�ʼ��(��δʵ��)

	XFont& operator = (const XFont& temp);
	XBool setACopy(const XFont &temp);
	XFont(const XFont &temp);	//�������캯��

	void draw();
	XFont();
	XFont(int maxStrLen);
	~XFont();
	void setMaxStrLen(int maxStrLen)
	{
		XMem::XDELETE_ARRAY(m_string);
		XMem::XDELETE_ARRAY(m_textPosition);
		XMem::XDELETE_ARRAY(m_textRect);

		if(maxStrLen < 2) m_maxStringLen = 2;
		else m_maxStringLen = maxStrLen;
		m_string = XMem::createArrayMem<char>(m_maxStringLen);
		m_string[0] = '\0';
		m_textPosition = XMem::createArrayMem<XVector2>(m_maxStringLen);
		m_textRect = XMem::createArrayMem<XRect>(m_maxStringLen);

		m_needUpdateData = XTrue;
	}
private:
	bool loadFromFolder(const char *filename);	//���ļ�����������Դ
	bool loadFromPacker(const char *filename);	//��ѹ������������Դ
	bool loadFromWeb(const char *filename);		//����ҳ�ж�ȡ��Դ
};
#if WITH_INLINE_FILE
#include "XFont.inl"
#endif
}
#endif