#ifndef _JIA_XACTIONMANAGER_
#define _JIA_XACTIONMANAGER_
//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		2013.3.5
//--------------------------------
#include "XActionDescription.h"
#include <map>
namespace XE{
//将指定目录下的所有AD文件全部载入，并按照AD名称保存
//从资源文件中读取数据会存在问题，尚需修改
class XDir;
class XActionMananger
{
	//+++++++++++++++++++++++++++++++++++++++++++
	//下面需要将其设计为Singleton模式
protected:
	XActionMananger()
		:m_isInited(XFalse)
	{
	}
	XActionMananger(const XActionMananger&);
	XActionMananger &operator= (const XActionMananger&);
	virtual ~XActionMananger() {release();}
public:
	static XActionMananger& GetInstance()
	{
		static XActionMananger m_instance;
		return m_instance;
	}
	//-------------------------------------------
private:
	XBool m_isInited;	//是否已经载入
	std::map<int,XActionDescription *> m_actionDescriptions;	//所有的动作描述符
	std::map<std::string,int> m_actionDesMap;
	std::vector<int> m_actionIDList;							//AD的ID列表

	XBool isActionDescriptionFile(const char * filename);
	//从文件夹中读取动作描述文件
	void loadActionDesFromFold(const XDir *dir);
public:
	XBool loadAllActionDes(const char * path = NULL);	//将指定目录下的动作全部载入 //内部资源读取会存在问题
	XBool saveAllActionDes();	//将所有动作保存到默认目录中

	XBool pushAActionDescription(XActionDescription * tempAD)
	{//添加一个AD到队列
		if(tempAD == NULL) return XFalse;
		if(getActionDes(tempAD->getName()) != NULL) return XFalse;	//同名
		if(getActionDes(tempAD->getID()) != NULL) return XFalse;		//同ID
		//推入一个
		m_actionDescriptions.insert(std::pair<int,XActionDescription *>(tempAD->getID(),tempAD));
		m_actionDesMap.insert(std::pair<std::string,int>(tempAD->getName(),tempAD->getID()));
		m_actionIDList.push_back(tempAD->getID());
		return XTrue;
	}
	XActionDescription *getActionDes(int ID)		//方便ID调用
	{
		if(m_actionDescriptions.count(ID) == 0) return NULL;
		return m_actionDescriptions[ID];
	}
	XActionDescription *getActionDes(const char * name)	//方便名字调用
	{
		if(name == NULL) return NULL;
		if(m_actionDesMap.count(name) == 0) return NULL;
		int id = m_actionDesMap[name];
		return getActionDes(id);
	}
	XActionDescription *getActionDesByIndex(int index)	//主要是为了遍历
	{
		int sum = m_actionIDList.size();
		if(index < 0 || index >= sum) return NULL;
		return getActionDes(m_actionIDList[index]);
	}
	XBool getIsReferenced(XActionDescription * AD);
	int getADSum()
	{
		if(!m_isInited) return 0;
		return m_actionDesMap.size();
	}
//++++++++++++++++++++++++++++++++++++++++++++++++++
	//下面是对AD的控制接口(尚未实现)
	//void play(int ID);		//播放动画
	//void stop(int ID);		//停止动画播放
	//void pause(int ID);		//暂停播放
	//void setShow(int ID);	//显示动画
	//void disShow(int ID);	//隐藏动画
	//XBool getIsEnd(int ID);	//判断动画是否播放完成

	//void play(const char * name);
	////....上面的对应接口
	//void draw();
	//void move(float stepTime);
//--------------------------------------------------

	void release();	//资源释放	
	void deleteAActionDesNoReference(XActionDescription * AD);
	XBool setADName(XActionDescription * AD,const char *name);
};
}
#endif