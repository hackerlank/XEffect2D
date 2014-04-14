#ifndef _JIA_XMUTILISTBASIC_
#define _JIA_XMUTILISTBASIC_
//++++++++++++++++++++++++++++++++
//Author:	��ʤ��(JiaShengHua)
//Version:	1.0.0
//Date:		2012.12.26
//--------------------------------

//����һ�������Ķ����б���ֻʵ����һЩ�����Ĺ���

#include "XSlider.h"
#include "XControlBasic.h"
#include "../XFontUnicode.h"
#include "../XSprite.h"
#include "XMouseRightButtonMenu.h"
#include "XMultiList.h"
#include "XCheck.h"

#ifndef DEFAULT_SLIDER_WIDTH
#define DEFAULT_SLIDER_WIDTH (32)		//Ĭ�ϵĻ���������
#endif //DEFAULT_SLIDER_WIDTH
#ifndef DEFAULT_TITLE_HEIGHT
#define DEFAULT_TITLE_HEIGHT (32.0f)
#endif	//DEFAULT_TITLE_HEIGHT
#ifndef DEFAULT_END_WIDTH
#define DEFAULT_END_WIDTH (8.0f)
#endif	//DEFAULT_END_WIDTH
#ifndef DEFAULT_CHECK_SIZE
#define DEFAULT_CHECK_SIZE (32.0f)
#endif	//DEFAULT_CHECK_SIZE
class _XMultiListBasic:public _XControlBasic
{
private:
	_XBool m_isInited;				//�Ƿ��ʼ��

	const _XTextureData *m_mutiListNormal;	//�����б�����ͨ״̬
	const _XTextureData *m_mutiListDisable;	//�����б�����Ч״̬
	const _XTextureData *m_mutiListSelect;	//�����б��б�ѡ���еı���
	const _XTextureData *m_mutiListMove;		//�ƶ�����ʱ�Ķ����ǩ
	const _XTextureData *m_mutiListTitle;		//�����б��ı��ⱳ��
	const _XTextureData *m_mutiListTitleEnd;	//�����б��ı���ָ���

	_XBool m_needShowVSlider;			//�Ƿ���Ҫ��ʾ��ֱ������
	_XSlider m_verticalSlider;		//��ֱ������
	_XBool m_needShowHSlider;			//�Ƿ���Ҫ��ʾˮƽ������
	_XSlider m_horizontalSlider;	//ˮƽ������
	
	int m_tableRowSum;				//�����е�����(������Ҫ����һ����Ч��������������ĸ���)
	_XMultiListOneRow *m_tableRow;	//�е�����
	int m_tableLineSum;				//�����е�����(������Ҫ����һ����Ч��������������ĸ���)
	_XMultiListOneBox *m_tableBox;	//����Ԫ�ص�����

	_XBool m_haveSelect;				//�Ƿ���ѡ��
	int m_selectLineOrder;			//ѡ�������һ��
	_XRect m_selectRect;			//ѡ����е��׿�
	_XBool *m_haveSelectFlag;			//���ڱ�����е������Ƿ�ѡ��
	_XKeyState m_stateOfShiftKey;			//shift������״̬������Ƭѡ

	_XResourceInfo *m_resInfo;
	_XBool m_withoutTex;	//û����ͼ����ʽ
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:
	_XBool getHaveSelectState(int i)
	{
		if(i < 0 || i >= m_tableLineSum) return XFalse;
		return m_haveSelectFlag[i];
	}
	int getTableLineSum()
	{
		return m_tableLineSum;
	}
private:
	//--------------------------------------------------------

	int m_showStartLine;			//��ʾ���Ǵӵڼ��п�ʼ��
	float m_showStartRow;			//��ʾ��ͷһ�е����ؿ���
	int m_canShowLineSum;			//�ؼ�������ʾ������

	_XBool m_needShowMove;			//�Ƿ���Ҫ��ʾ�ƶ�������

	_XSprite m_spriteBackGround;	//�ؼ��Ĵ󱳾�
	_XSprite m_spriteSelect;		//�ؼ���ѡ��(��ʱֻ�ܵ���ѡ��)
	_XSprite m_spriteMove;			//����ƶ��Ķ�����

	friend void funMutiListBasicValueChangeV(void *pClass,int objectID);
	friend void funMutiListBasicValueChangeMoveV(void *pClass,int objectID);
	friend void funMutiListBasicValueChangeH(void *pClass,int objectID);
	friend void funMutiListBasicValueChangeMoveH(void *pClass,int objectID);
	friend void funMutiListBasicStateChange(void *pClass,int objectID);

	//������Ϊ��ʵ���������ı��������������ʱ����
	_XBool m_mouseLeftButtonDown;		//�������Ƿ���
	int m_startX;					//��꿪ʼ�϶������
	int m_changeRowOrder;			//�϶��еı��
	_XMultiListOneRow * m_changeRow;	//�϶��е�ָ��
//	int m_rowDx;					//�϶��е���ʾƫ��λ��

	//������Ϊ��ʵ������϶��ƶ��ж�����ı���
	_XBool m_mouseMoveDown;	//����Ƿ��а����϶�
	int m_oldLineOrder;		//��갴�����ڵ��У����ڼ�����Ҫ����ƶ�

	void (*m_funCheckStateChange)(void *,int ID);	//״̬ѡ�����仯��ʱ����õĺ���
	void (*m_funSelectChange)(void *,int ID);		//ѡ�����仯ʱ����
	void *m_pClass;				//�ص������Ĳ���

public:
	int getSelectOrder() const	//����ѡ��������к�
	{
		return m_selectLineOrder;
	}
	void setCallbackFun(void (* funSelectChange)(void *,int),void (* funCheckStateChange)(void *,int),void *pClass);
	void clearAllSelect();	//������е�ѡ��

	void setTileStr(const char *str,int order);		//����ĳ�����������
	void setBoxStr(const char *str,int line,int row);	//����ĳһ����Ԫ�������
	_XBool setRowWidth(int temp,int order);		//��������һ�еĿ���
private:
	void updateShowChange();					//�����б���ı仯��Ϣ�����б����еı������ʾ���
	int m_showPixWidth;							//��ʾ��������ؿ���
	int m_showPixHight;							//��ʾ��������ظ߶�
	void updateSliderState();					//���ݱ������������»�������״̬
	void updateSelectLine();					//����ѡ���е�״̬
	void initANewRowData(_XMultiListOneRow * upRow,int i);	//��ʼ��һ���µı���
	void initANewBoxData(_XMultiListOneBox * nowBox,_XMultiListOneRow * nowRow,int i,int j);	//��ʼ��һ���б�Ԫ�ص�����

	_XFontUnicode m_caption;
	_XVector2 m_fontSize;
	_XFColor m_textColor;			//���ֵ���ɫ
	float m_nowTextWidth;			//��ǰ���������
	float m_nowTextHeight;			//��ǰ������߶�

	_XCheck *m_check0;		//�Ƿ�ɼ���״̬ѡ���İ�ť
	_XCheck *m_check1;		//�Ƿ�ɱ༭��״̬ѡ���İ�ť
	_XBool *m_check0State;		//�Ƿ�ɼ���״̬
	_XBool *m_check1State;		//�Ƿ�ɱ༭��״̬
public:
	_XBool getCheckState(int order,int lineOrder)
	{
		if(!m_isInited) return XFalse;
	//	if(lineOrder < 0 || lineOrder >= min(m_tableLineSum,m_canShowLineSum)) return XFalse;
	//	if(order == 0) return m_check0[lineOrder].getState();
	//	else return m_check1[lineOrder].getState();
		if(lineOrder < 0 || lineOrder >= m_tableLineSum) return XFalse;
		if(order == 0) return m_check0State[lineOrder];
		else return m_check1State[lineOrder];
	}
	void setCheckState(int order,int lineOrder,_XBool state)
	{
		if(!m_isInited) return;
	//	if(lineOrder < 0 || lineOrder >= min(m_tableLineSum,m_canShowLineSum)) return;
	//	if(order == 0) m_check0[lineOrder].setState(state);
	//	else m_check1[lineOrder].setState(state);
		if(lineOrder < 0 || lineOrder >= m_tableLineSum) return;
		if(order == 0) m_check0State[lineOrder] = state;
		else m_check1State[lineOrder] = state;
		//��������б����ѡ��״̬����Ϣ
		if(lineOrder >= m_showStartLine && lineOrder < min(m_showStartLine + m_canShowLineSum,m_tableLineSum))
		{
			if(m_check0State[lineOrder]) m_check0[lineOrder - m_showStartLine].setState(XTrue);
			else m_check0[lineOrder - m_showStartLine].setState(XFalse);
			if(m_check1State[lineOrder]) m_check1[lineOrder - m_showStartLine].setState(XTrue);
			else m_check1[lineOrder - m_showStartLine].setState(XFalse);
		}
	}

	_XBool init(const _XVector2& position,		//�ռ����ڵ�λ��
		const _XRect& Area,					//�ؼ���ʵ����ʾ����
		const _XMultiListTexture &tex,		//�ؼ�����ͼ
		const _XCheckTexture &checktex0,		//��ѡ�����ͼ
		const _XCheckTexture &checktex1,		//��ѡ�����ͼ
		const _XFontUnicode &font,			//�ؼ���ʹ�õ�����
		float strSize,						//��������Ŵ�С
		int rowSum,					//�ؼ��е�����
		int lineSum,				//�ؼ��е�����
		//const _XMouseRightButtonMenu& mouseMenu,	//�ؼ���ʹ�õ��Ҽ��˵�(Ŀǰ��Ч)
		const _XSlider &vSlider,	//��ֱ������
		const _XSlider &hSlider);	//ˮƽ������
	_XBool initEx(const _XVector2& position,		//�ռ����ڵ�λ��
		const _XMultiListTexture &tex,		//�ؼ�����ͼ
		const _XCheckTexture &checktex0,		//��ѡ�����ͼ
		const _XCheckTexture &checktex1,		//��ѡ�����ͼ
		const _XFontUnicode &font,			//�ؼ���ʹ�õ�����
		float strSize,						//��������Ŵ�С
		int rowSum,					//�ؼ��е�����
		int lineSum,				//�ؼ��е�����
		//const _XMouseRightButtonMenu& mouseMenu,	//�ؼ���ʹ�õ��Ҽ��˵�(Ŀǰ��Ч)
		const _XSlider &vSlider,	//��ֱ������
		const _XSlider &hSlider);	//ˮƽ������
	_XBool initPlus(const char *path,		//��ѡ�����ͼ
		const _XFontUnicode &font,			//�ؼ���ʹ�õ�����
		float strSize,						//��������Ŵ�С
		int rowSum,					//�ؼ��е�����
		int lineSum,				//�ؼ��е�����
		//const _XMouseRightButtonMenu& mouseMenu,	//�ؼ���ʹ�õ��Ҽ��˵�(Ŀǰ��Ч)
		_XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE);	
	_XBool initWithoutTex(const _XRect& area,
		const _XFontUnicode &font,			//�ؼ���ʹ�õ�����
		float strSize,						//��������Ŵ�С
		int rowSum,					//�ؼ��е�����
		int lineSum);
protected:
	void draw();					//��溯��
	void drawUp(){};						//do nothing
	_XBool mouseProc(float x,float y,_XMouseState mouseState);					//������궯������Ӧ����
	_XBool keyboardProc(int keyOrder,_XKeyState keyState);
	void insertChar(const char *ch,int len){;}
	_XBool canGetFocus(float x,float y);	//�����жϵ�ǰ����Ƿ���Ի�ý���
	_XBool canLostFocus(float x,float y) {return XTrue;}
public:
	_XBool exportData(const char *fileName = NULL);			//���ݵ���
	_XBool importData(const char *fileName = NULL);			//���ݵ���
	_XBool setRowSum(int rowSum);		//��������������������հף�����ɾ��	;��Ҫ������ƣ�����������;�Ĵ���������ս�����߼�����
	_XBool setLineSum(int lineSum);	//���������������Ĳ�����հף�����ɾ��	;��Ҫ������ƣ�����������;�Ĵ���������ս�����߼�����
	_XBool deleteLine(int order);		//ɾ��ĳһ��
	_XBool deleteRow(int order);		//ɾ��ĳһ��
	_XBool insertALine(int order);		//��order������һ��
	_XBool insertARow(int order);		//��order������һ��
	_XBool moveDownLine(int order);	//��order������
	_XBool moveRightRow(int order);	//��order������

	using _XObjectBasic::setPosition;	//���⸲�ǵ�����
	void setPosition(float x,float y);

	using _XObjectBasic::setSize;		//���⸲�ǵ�����
	void setSize(float x,float y);			//���óߴ�

	void setTextColor(const _XFColor& color) 
	{
		if(!m_isInited) return;
		m_textColor = color;
		m_caption.setColor(m_textColor);
	}	//�����������ɫ
	_XFColor getTextColor() const {return m_textColor;}	//��ȡ�ؼ��������ɫ
	void setColor(const _XFColor& color) 
	{
		if(!m_isInited) return;
		m_color = color;
		m_spriteBackGround.setColor(m_color);
		m_spriteSelect.setColor(m_color);
		m_spriteMove.setColor(m_color);
		m_caption.setColor(m_textColor * m_color);
		updateChildColor();
	}	//���ð�ť����ɫ

	using _XObjectBasic::setColor;		//���⸲�ǵ�����
	void setColor(float r,float g,float b,float a) 
	{
		if(!m_isInited) return;
		m_color.setColor(r,g,b,a);
		m_spriteBackGround.setColor(m_color);
		m_spriteSelect.setColor(m_color);
		m_spriteMove.setColor(m_color);
		m_caption.setColor(m_textColor * m_color);
		updateChildColor();
	}	//���ð�ť����ɫ
	void setAlpha(float a) 
	{
		if(!m_isInited) return;
		m_color.setA(a);
		m_spriteBackGround.setColor(m_color);
		m_spriteSelect.setColor(m_color);
		m_spriteMove.setColor(m_color);
		m_caption.setColor(m_textColor * m_color);
		updateChildAlpha();
	}	//���ð�ť����ɫ

	_XMultiListBasic();
	~_XMultiListBasic();
	void release();
private:
	void releaseTempMemory();	//�ͷŲ��������ڴ�ռ�
public:
	//���涨�������������
	_XBool addALine();					//��ĩβ����һ��
	_XBool addARow();					//��ĩβ����һ��
	_XBool deleteNowSelectLine();		//ɾ��ѡȡ��һ��
	_XBool deleteSelectLines();		//ɾ�����б�ѡ�е�����
	_XBool moveUpLine(int order);		//��order������
	_XBool moveLeftRow(int order);		//��order������
	//Ϊ��֧����������������ؼ��������ṩ���������ӿڵ�֧��
	_XBool isInRect(float x,float y);		//��x��y�Ƿ���������ϣ����x��y����Ļ�ľ�������
	_XVector2 getBox(int order);			//��ȡ�ĸ���������꣬Ŀǰ�Ȳ�������ת������
	virtual void justForTest() {;}
private://Ϊ�˷�ֹ���������ɵĴ����������ظ�ֵ�������͸�ֵ���캯��
	_XMultiListBasic(const _XMultiListBasic &temp);
	_XMultiListBasic& operator = (const _XMultiListBasic& temp);
};

inline _XBool _XMultiListBasic::addALine()					//��ĩβ����һ��
{
	return setLineSum(m_tableLineSum + 1);
}
inline _XBool _XMultiListBasic::addARow()					//��ĩβ����һ��
{
	return setRowSum(m_tableRowSum + 1);
}
inline _XBool _XMultiListBasic::deleteNowSelectLine()			//ɾ��ѡȡ��һ��
{
	if(!m_isInited) return XFalse;
	if(!m_haveSelect) return XFalse;
	return deleteLine(m_selectLineOrder);
}
inline _XBool _XMultiListBasic::deleteSelectLines()
{
	if(!m_isInited) return XFalse;
	for(int i = 0;i < m_tableLineSum;++ i)
	{
		if(m_haveSelectFlag[i])
		{
			deleteLine(i);
			-- i;
		}
	}
	m_haveSelect = XFalse;	//���ѡ��ı��
	m_selectLineOrder = 0;
	return XTrue;
}
inline _XBool _XMultiListBasic::moveUpLine(int order)		//��order������
{
	return moveDownLine(order - 1);
}
inline _XBool _XMultiListBasic::moveLeftRow(int order)		//��order������
{
	return moveRightRow(order - 1);
}

#endif