#ifndef _JIA_XSHADER_GLSL_
#define _JIA_XSHADER_GLSL_
//++++++++++++++++++++++++++++++++
//Author:	��ʤ��(JiaShengHua)
//Version:	1.0.0
//Date:		2014.1.1
//--------------------------------
//#include "glew.h"
#include "XBasicFun.h"
//#include "XBasicOpenGL.h"
//��������
enum _XShaderDataType		//GLSL���ݵ���������
{
	DATA_TYPE_INT,			//����
	DATA_TYPE_FLOAT,		//�����ȸ�����
	DATA_TYPE_INT_ARRAY,	//1D����
	DATA_TYPE_FLOAT_ARRAY,	//1D������
	DATA_TYPE_2INT_ARRAY,	//2D����
	DATA_TYPE_2FLOAT_ARRAY,	//2D������
	DATA_TYPE_3INT_ARRAY,	//3D����
	DATA_TYPE_3FLOAT_ARRAY,	//3D������
	DATA_TYPE_3FLOAT_MATRIX,//3x3����
	DATA_TYPE_4FLOAT_MATRIX,//4x4����
};
#define MAX_SHADER_GLSL_DATA_SUM (256)	//�������ӵ����ݵ��������
class _XShaderDataInfo
{
public:
	int m_handle;				//���ݵľ��
	//char m_name[256];			//���ݵ�����
	_XShaderDataType m_type;	//���ݵ�����
	void *m_p;					//���ݵ�ָ��
	int m_size;

	void updateData();	//��������
};
//�����ǹ���UBO�ķ�װ
class _XUBO
{
private:
	_XBool m_isInited;
	unsigned int m_uboHandle;
public:
	_XUBO()
		:m_isInited(XFalse)
	{
	}
	~_XUBO() {release();}
	void release();
	_XBool init(int size,const void * p);
	void useUBO(unsigned int index);	//indexΪ��Ӧ��shader�нṹ������
};
class _XShaderUBOData
{
public:
	unsigned int m_handle;
	char m_name[256];
	int m_offset[MAX_SHADER_GLSL_DATA_SUM];
	unsigned int m_index[MAX_SHADER_GLSL_DATA_SUM];
	int m_size;
};
class _XShaderUBOInfo
{
public:
	unsigned int m_handle;
	_XUBO *m_pUBO;

	void updateData() {m_pUBO->useUBO(m_handle);}
};
class _XShaderGLSL
{//Ŀǰ��UBO��֧������
private:
	_XBool m_isInited;		//�Ƿ��ʼ��
	int m_shaderHandle;	//shader�ľ��
	int m_dataSum;			//���ݵ�����
	_XShaderDataInfo m_dataInfo[MAX_SHADER_GLSL_DATA_SUM];	//�������ݵľ��
	int m_texSum;
	unsigned int *m_texture[MAX_SHADER_GLSL_DATA_SUM];
	int m_texHandle[MAX_SHADER_GLSL_DATA_SUM];
	int m_texType[MAX_SHADER_GLSL_DATA_SUM];

	int m_UBOSum;
	_XShaderUBOInfo m_UBOInfo[MAX_SHADER_GLSL_DATA_SUM];
public:
	_XBool init(const char* vertFile,const char* fragFile,
		_XResourcePosition resoursePosition = RESOURCE_SYSTEM_DEFINE);
	_XBool connectData(const char *name,_XShaderDataType type,int size,void *p);//��������
	_XBool connectTexture(const char *name,unsigned int * tex,int type = 0);//������ͼ
	void useShader(bool withTex0 = false);	//ʹ��shader,����withTex0�����������Ƿ���Ҫ�󶨵�һ����ͼ��
											//�����Ҫ�󶨵�һ����ͼ������Ϊtrue,��Ϊ���ڹ��õ�һ����ͼ������������������
	void useShaderEx(unsigned int tex0,int type = 0);	//���õ�ʱ��Ŵ����һ����ͼ
	void disShader();
	int getShaderHandle() { return m_shaderHandle;}
	_XShaderGLSL()
		:m_isInited(XFalse)
	{}
	//������Ϊ���������ܶ����ӵĽӿ�
	_XBool connectUBO(const char *uboName,_XUBO *ubo);
	//��shader�ж�ȡUBO�������Ϣ
	_XBool getUBOInfo(_XShaderUBOData &uboData,int valueSum,const char *uboName,const char **valueNames);	//����UBO
};

//ʹ��UBO����ֱ�ӵ�GLSL�����ݴ��ݣ�������Ч��
//�����ǹ���ʹ��UBO������
//GLuint blockIndex = glGetUniformBlockIndex(m_shaderHandle,"BlobSettings");  //��ȡ�ṹ�ı��
//GLint blockSize;  
//glGetActiveUniformBlockiv(m_shaderHandle,  
//                            blockIndex,  
//                            GL_UNIFORM_BLOCK_DATA_SIZE,  
//                            &blockSize);					//��ȡ�ṹ�ĳߴ�
//GLubyte *blockBuffer = (GLubyte*)malloc(blockSize);		//����һ���ڴ�ռ�
//const GLchar *names[] = {"BlobSettings.InnerColor","BlobSettings.OuterColor",  
//                            "BlobSettings.RadiusInner","BlobSettings.RadiusOuter"};  
//GLuint indices[4];  
//glGetUniformIndices(m_shaderHandle, 4, names, indices);  //��ȡÿ�������ı�ǩ
//  
//GLint offset[4];  
//glGetActiveUniformsiv(m_shaderHandle, 4, indices, GL_UNIFORM_OFFSET, offset);	//��ȡÿ��������ƫ��
//  
//GLfloat outerColor[] = {0.0f, 0.0f, 0.0f, 0.0f};  
//GLfloat innerColor[] = {1.0f, 1.0f, 0.75f, 1.0f};  
//GLfloat innerRadius = 0.25f, outerRadius = 0.45f;	//��ʼ����Ӧ�ı���
//  
//memcpy(blockBuffer + offset[0],innerColor,4 * sizeof(float));  
//memcpy(blockBuffer + offset[1],outerColor,4 * sizeof(float));  
//memcpy(blockBuffer + offset[2],&innerRadius,sizeof(float));  
//memcpy(blockBuffer + offset[3],&outerRadius,sizeof(float));		//��������
////create OpenGL buffer UBO to store the data  
//GLuint uboHandle;  
//glGenBuffers(1,&uboHandle);  
//glBindBuffer(GL_UNIFORM_BUFFER,uboHandle);  
//glBufferData(GL_UNIFORM_BUFFER,blockSize,blockBuffer,GL_DYNAMIC_DRAW);			//����UBO                   
////bind the UBO th the uniform block  
//glBindBufferBase(GL_UNIFORM_BUFFER,blockIndex,uboHandle);		//��UBO
//free(blockBuffer);												//�ͷ���ʱ���ڴ�ռ�
////GLSL�еĴ���
//layout(std140) uniform BlobSettings
//{  
//    vec4 InnerColor;  
//    vec4 OuterColor;  
//    float RadiusInner;  
//    float RadiusOuter;  
//}Blob;//Use an instance name with a uniform block  
//����ʹ��PBO�ķ�ʽ��ȡ��Ļ������������������
#ifndef GL_FRONT
#define GL_FRONT (0x4040)
#endif
enum _XPboMode
{
	PBO_MODE_UNPACK,
	PBO_MODE_PACK,
};
enum _XColorMode;
//˵������ʹ��PBO��������ͼ��ʱ��ֻ�е���Ҫ��RGBת����BGR��ʱ��������м�ֵ������������
//������ʽ��ȫû�б�Ҫ
class _XPBO	
{
private:
	_XBool m_isInited;
	unsigned int m_pboID[2];	//ʹ����ż�ֻ��ķ�ʽ
	int m_nowPBOIndex;
	int m_size;
	_XColorMode m_colorType;
	int m_w;	//��Ļ����
	int m_h;	//��Ļ�߶�
	int m_px;	//��ȡͼ������Ͻǵ�
	int m_py;
	int m_wx;	//��ȡͼ��Ŀ���
	int m_wy;
	int m_dataSize;
	_XPboMode m_mode;
public:
	_XPBO()
		:m_isInited(0)
		,m_nowPBOIndex(0)
		,m_mode(PBO_MODE_PACK)
	{
	}
	~_XPBO()
	{
		release();
	}
	void release();
	_XBool init(int w,int h,int px,int py,int wx,int wy,_XColorMode colorType,_XPboMode mode = PBO_MODE_PACK);
	_XBool getPixel(unsigned char * buff,int target = GL_FRONT);
	_XBool setPixel(unsigned char * buff);
	void bind() const;
};
////++++++++++++++++++++++++++++++++++++++++++++++
////�����ǹ���PBO��
////����
//GLuint pboID;
//unsigned char *dataBuff;
//glGenBuffersARB(1,&pboID);
//glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB,pboID);
//glBufferDataARB(GL_PIXEL_PACK_BUFFER_ARB,1280 * 720 * 3,0,GL_STREAM_READ_ARB);
//glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB,0);
////ʹ��
//glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB,pboID);
//glReadPixels(0,0,1280,720,GL_RGB,GL_UNSIGNED_BYTE,0);
////glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB, pboIds[nextIndex]); //��֪������Ǹ�ɶ��
//GLubyte* src = (GLubyte*)glMapBufferARB(GL_PIXEL_PACK_BUFFER_ARB,GL_READ_ONLY_ARB);
//if(src)
//{//�Ѿ���ȡ����
//	//���ｫ����ȡ��
//	memcpy(dataBuff,src,1280 * 720 * 3);
//	glUnmapBufferARB(GL_PIXEL_PACK_BUFFER_ARB);     // release pointer to the mapped buffer
//}
//glBindBufferARB(GL_PIXEL_PACK_BUFFER_ARB,0);
////�ͷ�
//glDeleteBuffersARB(1,&pboID);
////--------------------------------------------------
//����ʹ��VBO�ķ�ʽ��������
class _XVBO
{
private:
	_XBool m_isInited;
	_XBool m_withV;	//����
	_XBool m_withT;	//��ͼ
	_XBool m_withN;	//����
	_XBool m_withC;	//��ɫ
	_XBool m_withI;	//����
	unsigned int m_v;
	unsigned int m_t;
	unsigned int m_n;
	unsigned int m_c;
	unsigned int m_i;
	int m_size;
	int m_indexSize;	//�����Ĵ�С
public:
	_XBool init(int size,const float *v,const float *t = NULL,const float *n = NULL,const float *c = NULL,
		int iSize = 0,const unsigned int *i = NULL);
	_XBool updateDate(int size,const float *v,const float *t = NULL,const float *n = NULL,const float *c = NULL,
		int iSize = 0,const unsigned int *i = NULL);
	_XBool updateDataV(int size,const float *v);
	_XBool updateDataT(int size,const float *t);
	_XBool updateDataN(int size,const float *n);
	_XBool updateDataC(int size,const float *c);
	_XBool updateDataI(int size,const unsigned int *i);
	void use(_XBool withTex = XTrue);
	void disuse();
	void release();
	int getSize() {return m_size;}
	int getIndexSize() {return m_indexSize;}
	//temp:�����Ķ���
	//v,n,c,t:�Ƿ�����Щ����
	//cv,cn,cc,ct:�����Ƿ�Ӵ��������л�ȡ
	_XBool setAsSubject(const _XVBO &temp,_XBool v,_XBool n,_XBool c,_XBool t,_XBool i,_XBool cv,_XBool cn,_XBool cc,_XBool ct,_XBool ci);
	_XBool m_isSubject;
	_XBool m_subjectV;
	_XBool m_subjectN;
	_XBool m_subjectC;
	_XBool m_subjectT;
	_XBool m_subjectI;

	_XVBO()
		:m_isInited(XFalse)
		,m_withV(XFalse)
		,m_withT(XFalse)
		,m_withN(XFalse)
		,m_withC(XFalse)
		,m_isSubject(XFalse)
		,m_v(0)
		,m_n(0)
		,m_t(0)
		,m_c(0)
		,m_i(0)
	{
	}
	~_XVBO()
	{
		release();
	}
};
#define MAX_FBO_TEXTURE_SUM (256)
enum _XFBOTextureType
{
	TEXTURE_RGB,
	TEXTURE_RGBA,	//��ͨ��RGBA��ͼ
	TEXTURE_RGBA_F,	//RGBA����float����
	TEXTURE_DEEPTH,	//�����ͼ
};
extern _XBool isFBOSupported();		//�жϵײ��Ƿ�֧��FBO
extern _XBool isFramebufferReady();	//�ж�FBO״̬�Ƿ����
//�����Ƕ�FBO��֧��
class _XFBO
{
private:
	unsigned int m_fboId;								//FBO��ID
	unsigned int m_rboId;							//RBO��ID
	unsigned int m_textureId[MAX_FBO_TEXTURE_SUM];    //FBO��Ӧ��ͼ��ID
	int m_nowFBOTextureSum;
	int m_maxTextureSum;	//һ����ͬʱʹ�õ���ͼ������
	//int m_upTextureSum;		//�ϴΰ󶨵���ͼ����
public:
	_XBool init(int w,int h,_XFBOTextureType type = TEXTURE_RGBA); //w��h�������ĳߴ磬���س�ʼ���Ƿ�ɹ�
	void useFBO(bool newSize = false,int w = 0,int h = 0);	//����Ϊ�Ƿ�ʹ���µ��ӿھ���
	void useFBO3D();	//���3D����������װһ��
	void attachTex(int order = 0);	//��Ҫ��useFBO֮�����
	_XBool attachTexs(int sum,int index,...);	//��Ҫ��useFBO֮�����
	void removeFBO();
	void removeFBO3D();
	void addOneTexture(int w,int h,_XFBOTextureType type = TEXTURE_RGBA);
	unsigned int getTexture(int order)	//��������
	{
		if(order >= 0 && order < m_nowFBOTextureSum)
		{
			return m_textureId[order];
		}
		return 0;
	}
	void release();
	_XFBO()
		:m_nowFBOTextureSum(0)
	{}
	~_XFBO() {release();}
};

//Ϊ�˽��shader��FBO�Ľ�϶�����ĺ���
extern void drawBlankPlane(int w,int h,unsigned int tex,_XShaderGLSL *pShader = NULL);
#endif //_JIA_XSHADER_GLSL_