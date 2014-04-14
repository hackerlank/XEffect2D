#ifndef _JIA_XERRORREPORTER_
#define _JIA_XERRORREPORTER_
//这是一个人性化的异常错误处理的类，这个类所处理的错误，一般都是非常严重的错误。
//系统检查到错误或者收到抛出的异常时，调用这个类，类提示发生严重错误，以及发生错误所在的文件和行，并提示用户退出，并保存屏幕截图和日志文件。
//生成错误报告，如果在图形化界面没有初始化的前提下，直接生成错误报告，并退出。
//++++++++++++++++++++++++++++++++
//Author:    贾胜华(JiaShengHua)
//Version:    1.0.0
//Date:      2014.3.8
//--------------------------------
//注意：这个类目前存在多线程安全性的问题，在使用时需要避免在多线程中调用，需要注意多线程安全问题。

#include <string>
#include "XControl/XControls.h"

#define ERROR_REPORTER_TXT_FILENAME ("ErrorReport.txt")	//错误报告的文件名
#define ERROR_REPORTER_PIC_FILENAME ("ErrorReport.png")	//错误报告的文件名

class _XErrorReporter
{
protected:
    _XErrorReporter()
		:m_isInited(false)
		,m_isBtnChecked(false)
		,m_needShow(false)
		,m_isMainThreadProc(false)
	{}
    _XErrorReporter(const _XErrorReporter&);
	_XErrorReporter &operator= (const _XErrorReporter&);
    virtual ~_XErrorReporter()
	{}
public:
    static _XErrorReporter& GetInstance()
	{
		static _XErrorReporter m_instance;
		return m_instance;
	}
private:
	bool m_isInited;	//图形化界面是否初始化
	bool m_isBtnChecked;

	_XSprite m_screenShot;
	_XSprite m_background;
	_XButton m_button;
	_XFontUnicode m_font;
	_XFontUnicode m_fontDescrip;
	_XEdit m_edit;
	bool reportFile(const std::string &errorDescription,const std::string &filename,int line,const std::string &funName);
	int inputEvent();
	friend void errorReporterBtnProc(void *pClass,int id);

	//下面是为了多线程安全而定义的
	bool m_needShow;	//是否需要显示错误报告界面
	std::string m_errDescription;	//错误描述
	std::string m_errFilename;		//错误发生的文件名
	std::string m_errFunname;		//错误发生的函数名
	int m_errLine;					//错误发生的行号
	bool m_isMainThreadProc;		//是否主线程接收了事件处理
public:
	bool init(_XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE);	//初始化
	void draw()
	{
		m_screenShot.draw();
		m_background.draw();
		m_font.draw();
		m_fontDescrip.draw();
	}
	//__DATE__ __TIME__ __FUNCDNAME__ __TIMESTAMP__
	void reportError(const std::string & errorDescription,const std::string &filename,int line,const std::string &funName);
	void errorProc();
	bool isErrored(){return m_needShow;}
	void setMainProc(){m_isMainThreadProc = true;}
	bool getIsMainProc(){return m_isMainThreadProc;}
};
inline void reportError(const std::string & errorDescription,const std::string &filename,int line,const std::string &funName)
{
	_XErrorReporter::GetInstance().reportError(errorDescription,filename,line,funName);
}
#define REPORT_ERROR(p) reportError(p,__FILE__,__LINE__,__FUNCDNAME__)
#endif