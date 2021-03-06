#ifndef _JIA_XWINDOWCORE_
#define _JIA_XWINDOWCORE_
//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		2014.3.25
//--------------------------------
#include "XOSDefine.h"
#include <string>
namespace XE{
class XWindowCore
{
public:
	virtual ~XWindowCore() {;}
	virtual bool createWindow(int width,int height,const char *windowTitle,int isFullScreen,int withFrame) = 0;
	virtual void setWindowTitle(const std::string &title) = 0;
	virtual void setCurcor(bool flag) = 0;
	virtual bool getCurcor() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual int mapKey(int key) = 0;
	virtual unsigned char *getWindowBuff() = 0;
	//virtual void toggleFullScreen() = 0;
	//virtual bool getIsFullScreen() = 0;
};
//下面是关于多重采样的设置，方法来自于NEHE的例子
namespace XEE
{
	extern bool	arbMultisampleSupported;
	extern int arbMultisampleFormat;
	//to check for our sampling
	extern bool initMultisample(HDC hdc);
}
}
#endif