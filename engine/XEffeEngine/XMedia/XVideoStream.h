#ifndef _JIA_XVIDEOSTREAM_
#define _JIA_XVIDEOSTREAM_
//++++++++++++++++++++++++++++++++
//Author:    贾胜华(JiaShengHua)
//Version:    1.0.0
//Date:       2011.7.6
//--------------------------------
#include "XFfmpeg.h"

#define VEDIO_STREAM_FORMAT (AV_CODEC_ID_MPEG2VIDEO)

//视频流编码
class _XVideoEncode
{
private:
	_XBool m_isOpen;
	AVCodecContext *m_videoCodec;
	AVFrame *m_pFrameRGB;
	AVFrame *m_pFrameYUV;
	int m_videoOutbufSize;
    uint8_t *m_videoOutbuf;

	SwsContext *m_pSwsContext;	//用于进行图像格式转换
	int imgConvert(AVPicture *dst,const AVPicture *src,int src_height)
	{
		if(m_pSwsContext == NULL) return 0;
		return sws_scale(m_pSwsContext, src->data, src->linesize,  
            0,src_height, dst->data, dst->linesize); 
	}
public:
	AVPacket m_packet;
	int m_videoFrameIndex;
public:
	_XBool open(int w,int h,int rate);
	_XBool encodeDataRGB(unsigned char *in);
	void release();

	_XVideoEncode()
		:m_isOpen(XFalse)
		,m_videoCodec(NULL)
		,m_pFrameRGB(NULL)
		,m_pFrameYUV(NULL)
		,m_videoOutbuf(NULL)
	{}
	~_XVideoEncode()
	{
		release();
	}
};
//视屏流解码
class _XVideoDecode
{
private:
	_XBool m_isOpen;	//是否已经打开
	AVCodecContext *m_videoCodec;

	AVFrame *m_pFrame;
	AVPacket m_packet;
	unsigned char *m_pixelData;
	AVPicture m_frameData;

	SwsContext *m_pSwsContext;	//用于进行图像格式转换
	int imgConvert(AVPicture *dst,const AVPicture *src,int src_height)
	{
		return sws_scale(m_pSwsContext, src->data, src->linesize,  
            0,src_height, dst->data, dst->linesize); 
	}
public:
	_XBool open(int w,int h);	//使用默认的ID
	_XBool decodeData(void * data,int len);
	void release();
	unsigned char *getPixels() {return m_pixelData;}

	_XVideoDecode()
		:m_isOpen(XFalse)
		,m_pFrame(NULL)
		,m_pixelData(NULL)
		,m_videoCodec(NULL)
		,m_pSwsContext(NULL)
	{
	}
	~_XVideoDecode()
	{
		release();
	}
};

#endif