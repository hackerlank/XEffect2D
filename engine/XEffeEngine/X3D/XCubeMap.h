#ifndef _JIA_XCUBEMAP_
#define _JIA_XCUBEMAP_
#include "XPixelCommon.h"
//++++++++++++++++++++++++++++++++
//Author:	��ʤ��(JiaShengHua)
//Version:	1.0.0
//Date:		2014.4.1
//--------------------------------
namespace XE{
class XCubeMap
{
private:
	bool m_isInited;	//�Ƿ��ʼ��
	unsigned int m_texture;

	bool loadPic(const std::string & name,int index,XResourcePosition resPos);
	void release();
public:
	bool init(const std::string &path,XResourcePosition resPos = RESOURCE_SYSTEM_DEFINE);
	void draw();
	unsigned int getTexture() const {return m_texture;}

	XCubeMap()
		:m_isInited(false)
		,m_texture(0)
	{}
	~XCubeMap(){release();}
};
}
#endif