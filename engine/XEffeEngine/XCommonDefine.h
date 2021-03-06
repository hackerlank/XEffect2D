#ifndef _JIA_XCOMMONDEFINE_
#define _JIA_XCOMMONDEFINE_
//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		2014.1.1
//--------------------------------
//所有公共的宏开关都定义在此处，以便于统一修改
//注意：3D中1.0f代表1毫米，既1mm
#include <string>
namespace XE{
#define CREATE_WINDOW_WITH_SDL		//是否使用SDL建立窗口(已经经过大量测试)
#ifndef CREATE_WINDOW_WITH_SDL
#define CREATE_WINDOW_WITH_GLUT		//是否使用GLUT建立窗口(尚未经过大量测试)
#endif
#define WITH_INLINE_FILE (1)			//是否使能inline文件的形式 0更快的编译速度，1更好的执行性能
#if WITH_INLINE_FILE
#define INLINE inline
#else
#define INLINE 
#endif
#define BACKGROUND_ALPHA_MODE (1)		//窗口透明的实现方式:0、鼠标不能穿越透明区域，1、速度较为慢
#define WITH_OBJECT_MANAGER (0)			//是否允许使用物件管理
#define WITH_FULL_ALL_CHINESE (1)		//是否支持全中文
#define WITH_COMMON_RESOURCE_FOLDER (1)	//是否使用公用文件夹
#define WITHXSPRITE_EX (1)				//是否使用加强版的sprite，这里关系到是否使用归一化的纹理坐标
#define BASE_RESOURCE_PATH "ResourcePack/"	//默认封包资源文件夹的路径，放在这个文件夹下的资源才会被封包
#define WITH_64BIT_SUPPLY (0)	//是否支持64位的函数
//#define WITHXEE_CURSOR		//是否使用自己的光标，如果取消这个宏则直接使用windows的光标

#define WITH_LOG (1)
#define WITH_ENGINE_STATISTICS	(1)		//是否启用引擎内部统计
//#define DEBUG_MODE		//所有需要调试与正式版本不同的模块都需要添加这个头文件
//#define GET_ALL_PIXEL		//统计整体的贴图面积，用于标称游戏的贴图效率

#define XEE_SYSTEM_CONFIG "XEEConfig.xml"	//默认引擎配置文件

#define MAX_FILE_NAME_LENGTH (256)	//文件名的长度

//这里是对资源位置的定义
enum XResourcePosition
{
	RESOURCE_LOCAL_FOLDER = 0,	//本地对应的文件夹
	RESOURCE_LOCAL_PACK,		//本地压缩包
	RESOURCE_WEB,				//网络资源
	RESOURCE_SYSTEM_DEFINE,		//遵从系统设置
	RESOURCE_AUTO,				//自动载入，优先从压缩包中取，取不到才从文件夹中读取
};

enum XWindowSizeMode		//窗口尺寸的适应模式
{
	WINDOW_SIZE_MODE_CLIP_LP,		//左上角为基准点裁剪	pos,配合pos的数值可以实现任一点为基准点裁剪
	WINDOW_SIZE_MODE_CLIP_MID,		//中点为基准点裁剪		pos
	WINDOW_SIZE_MODE_CLIP_RESIZE,	//短边拉伸长边裁剪		pos
	WINDOW_SIZE_MODE_RESIZE_CLIP,	//长边拉伸短边填空白	pos
	WINDOW_SIZE_MODE_RESIZE,		//缩放拉伸				pos
};
enum XWindowRotateMode		//窗口的旋转模式
{
	WINDOW_ROTATE_MODE_0,			//0度旋转	
	WINDOW_ROTATE_MODE_90,			//90度旋转		
	WINDOW_ROTATE_MODE_180,			//180度旋转		
	WINDOW_ROTATE_MODE_270,			//270度旋转	
};
enum XWindowTurnOverMode	//窗口的反转模式
{
	WINDOW_TURNOVER_MODE_NULL,		//不反转
	WINDOW_TURNOVER_MODE_LTR,		//左右反转
	WINDOW_TURNOVER_MODE_TTD,		//上下反转
	WINDOW_TURNOVER_MODE_LTR_TTD,	//上下左右反转
};
enum XWindowType
{
	WINDOW_TYPE_NORMAL,			//普通类型的窗口
	WINDOW_TYPE_EX,				//强化版的窗口类型
	WINDOW_TYPE_3D,				//3D窗口类型
};
enum XColorMode		//颜色模式
{
	COLOR_RGBA,
	COLOR_RGB,
	COLOR_GRAY,
	COLOR_RGBA_F,	//内部用RGBA32F
	COLOR_GRAY_F,	//内部用R32F	//这个需要验证	GL_LUMINANCE精度只有8个bits
	COLOR_BGRA,
	COLOR_BGR,
	COLOR_DEPTH,	//深度贴图
	COLOR_RED,		//这种速度较快
};
struct XWindowInfo
{
	int w;				//窗口的宽度pixel
	int h;				//窗口的高度pixel
	std::string windowTitle;	//窗口的标题
	int sceneW;			//场景的宽度pixel
	int sceneH;			//场景的高度pixel
	int isFullScreen;	//是否全屏
	int isTouch;		//是否使用触摸屏 这里设置这个参数的原因在于全屏时隐藏光标的情况下使用触摸屏时SDL有问题。(目前不使用SDL的隐藏光标的接口，这个问题已经解决)
	int withLog;		//日志输出模式
	int isShowCursor;	//是否显示光标
	int positionX;		//窗口原点相对于场景的坐标X
	int positionY;		//窗口原点相对于场景的坐标Y
	int withFrame;		//是否拥有边框
	XWindowType windowType;	//窗口类型
	XWindowSizeMode mode;
	int CFGMode;		//配置类的工作模式
	int startDelayTimer;	//启动延迟的时间，单位ms
	bool isStartDelay;	//是否开启启动延迟
	bool isShowVersion;		//是否显示版本号
	bool isAutoShutDown;	//是否自动关机
	bool isShowConsole;		//是否显示控制台
	bool isProjectAsDaemon;	//是否作为后台程序
	std::string versionString;	//版本号字符串
	int autoShutDownYear;	//自动关机的时间
	int autoShutDownMonth;	
	int autoShutDownDay;	
	int autoShutDownHour;	
	int autoShutDownMinute;	
	int autoShutDownSecond;	
	int BGVolume;	//背景音量
	int FWVolume;	//前景音量
	XWindowRotateMode rotateMode;		//旋转的模式
	XWindowTurnOverMode turnOverMode;	//翻转模式
	XResourcePosition defResourcePos;	//默认的资源位置
	std::string systemFontFile;	//系统字体文件路径
	std::string commonResourcePos;	//公用资源文件的位置
	//下面是设置窗口的位置的参数
	bool isInitWindowPos;	//是否设置窗口的位置
	bool isAlwaysTop;		//是否制置顶
	bool withCustomTitle;	//是否使用自己的标题栏，尚未在配置工具中添加
	bool withAlphaBG;		//是否使用背景透明
	int windowPosX;			//窗口的位置
	int windowPosY;
	int systemFontSize;
	int logicFps;	//逻辑帧率,<=0为不受限制
	int drawFps;	//显示帧率,<=0为不受限制
	bool withException;			//是否处理异常
	bool withLowConsumption;	//是否开启低耗模式
	bool withClearBG;			//是否清楚背景
	bool isRestartWhenCrash;	//程序crash之后是否重新启动程序
	bool isSingletonMode;	//是否只有一个实例
	XWindowInfo()
		:w(800)
		,h(600)
		,sceneW(800)
		,sceneH(600)
		,isFullScreen(0)
		,isTouch(0)
		,withLog(3)	//LB_LEVEL_ALL
		,isShowCursor(1)
		,positionX(0)
		,positionY(0)
		,startDelayTimer(0)
		,autoShutDownYear(-1)	//自动关机的时间
		,autoShutDownMonth(-1)	
		,autoShutDownDay(-1)	
		,autoShutDownHour(-1)	
		,autoShutDownMinute(-1)	
		,autoShutDownSecond(-1)	
		,withFrame(1)
		,mode(WINDOW_SIZE_MODE_CLIP_LP)
		,rotateMode(WINDOW_ROTATE_MODE_0)
		,turnOverMode(WINDOW_TURNOVER_MODE_NULL)
		,windowType(WINDOW_TYPE_NORMAL)
		,CFGMode(0)
		,isStartDelay(false)
		,isShowVersion(false)
		,isAutoShutDown(false)
		,isShowConsole(true)
		,isProjectAsDaemon(false)
		,defResourcePos(RESOURCE_AUTO)
		,BGVolume(100)	//背景音量
		,FWVolume(100)	//前景音量
		,isInitWindowPos(false)
		,windowPosX(0)
		,windowPosY(0)
		,isAlwaysTop(false)
		,withCustomTitle(false)
		,windowTitle("xiajia_1981@163.com")
		,versionString("1.0.0.0")
#if WITH_COMMON_RESOURCE_FOLDER
		,systemFontFile("../../Common/SIMLI.TTF")
		,commonResourcePos("../../Common/")
#else
		,systemFontFile("SIMLI.TTF")
		,commonResourcePos("./")
#endif
		,systemFontSize(30)
		,withAlphaBG(false)
		,logicFps(-1)
		,drawFps(30)
		,withException(true)
		,withLowConsumption(true)	//是否开启低耗模式
		,withClearBG(true)			//是否清楚背景
		,isRestartWhenCrash(false)
		,isSingletonMode(false)
	{}
	XWindowInfo(int width,int height,XWindowType type = WINDOW_TYPE_NORMAL)
		:w(width)
		,h(height)
		,sceneW(width)
		,sceneH(height)
		,isFullScreen(0)
		,isTouch(0)
		,withLog(3)	//LB_LEVEL_ALL
		,isShowCursor(1)
		,positionX(0)
		,positionY(0)
		,startDelayTimer(0)
		,autoShutDownYear(-1)	//自动关机的时间
		,autoShutDownMonth(-1)	
		,autoShutDownDay(-1)	
		,autoShutDownHour(-1)	
		,autoShutDownMinute(-1)	
		,autoShutDownSecond(-1)	
		,withFrame(1)
		,mode(WINDOW_SIZE_MODE_CLIP_LP)
		,rotateMode(WINDOW_ROTATE_MODE_0)
		,turnOverMode(WINDOW_TURNOVER_MODE_NULL)
		,windowType(type)
		,CFGMode(0)
		,isStartDelay(false)
		,isShowVersion(false)
		,isAutoShutDown(false)
		,isShowConsole(true)
		,isProjectAsDaemon(false)
		,defResourcePos(RESOURCE_AUTO)
		,BGVolume(100)	//背景音量
		,FWVolume(100)	//前景音量
		,isInitWindowPos(false)
		,windowPosX(0)
		,windowPosY(0)
		,isAlwaysTop(false)
		,withCustomTitle(false)
		,windowTitle("xiajia_1981@163.com")
		,versionString("1.0.0.0")
#if WITH_COMMON_RESOURCE_FOLDER
		,systemFontFile("../../Common/SIMLI.TTF")
		,commonResourcePos("../../Common/")
#else
		,systemFontFile("SIMLI.TTF")
		,commonResourcePos("./")
#endif
		,systemFontSize(30)
		,withAlphaBG(false)
		,logicFps(-1)
		,drawFps(30)
		,withException(true)
		,withLowConsumption(true)	//是否开启低耗模式
		,withClearBG(true)			//是否清楚背景
		,isRestartWhenCrash(false)
		,isSingletonMode(false)
	{}
};
}
#endif