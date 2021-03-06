#ifndef _JIA_XWINDOWTITLE_
#define _JIA_XWINDOWTITLE_
//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		2014.8.19
//--------------------------------
//这是一个窗口标题栏的类，用于定义和描绘窗口标题栏
#include "XControl/XDragObjectBase.h"
#include "XControl\XButton.h"
namespace XE{
class XWindowTitle:public XDragObjectBase
{
private:
	bool m_isInited;
	bool m_withText;	//是否显示文字
	XButton m_minSizeBtn;
	XButton m_exitBtn;
	XButton m_iconBtn;
	XFontUnicode m_titleFont;
	XRect m_titleRect;

	static void ctrlProc(void *,int,int);

	void (*m_winExitFun)(void *);	//退出时调用的回调函数
	void (*m_winMinFun)(void *);	//最小化时调用的回调函数
	void * m_pClass;
public:
	bool init();
	void move(float){;}	
	void draw();
	void setCallbackFun(void (*winExitFun)(void *),
		void (*winMinFun)(void *),void * pClass);
	void setWithText(bool b);
	void mouseProc(int x,int y,XMouseState mouseState){mouseEventProc(x,y,mouseState);}
	void release(){;}				

	XWindowTitle()
		:m_isInited(false)
		,m_withText(true)
		,m_winExitFun(NULL)
		,m_winMinFun(NULL)
	{}
	~XWindowTitle(){release();}
private:
	virtual XBool getIsInDragRect(float x,float y){return m_titleRect.isInRect(x,y);}	//判断位置是否在拖拽区域内
	virtual XVector2 correctPos(const XVector2 &pos){return pos;}	//更具传入的拖拽位置，修正该位置，当位置出于非法状态时，修正成合法的位置
public:
	virtual void setPosition(float x,float y){XEG.setWindowPos(x,y);}
	virtual XVector2 getPosition()const
	{
		int tmpX,tmpY;
		XEG.getWindowPos(tmpX,tmpY);
		return XVector2(tmpX,tmpY);
	}
};
#if WITH_INLINE_FILE
#include "XWindowTitle.inl"
#endif
}
#endif