#ifndef _JIA_XSOUNDSDLMIXER_
#define _JIA_XSOUNDSDLMIXER_
//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		2014.3.20
//--------------------------------
#include "XSoundCore.h"
#include "SDL_mixer.h"

class _XSoundSDLMixer:public _XSoundCore
{
protected:
	_XSoundSDLMixer() {}
	_XSoundSDLMixer(const _XSoundSDLMixer&);
	_XSoundSDLMixer &operator= (const _XSoundSDLMixer&);
	virtual ~_XSoundSDLMixer() {}
public:
	static _XSoundSDLMixer& GetInstance()
	{
		static _XSoundSDLMixer m_instance;
		return m_instance;
	}
private:
public:
	bool init();
	void close() 
	{
		//SDL_CloseAudio();
		Mix_CloseAudio();
	}

	//music部分
	bool loadMusic(const std::string &filename,void *&p)
	{
		p = (void *)Mix_LoadMUS(filename.c_str());
		return p != NULL;
	}
	void clearMusic(void *p){Mix_FreeMusic((Mix_Music *)p);}
	int setMusicVolume(int v) {return Mix_VolumeMusic(v);} 
	int getMusicVolume() {return Mix_VolumeMusic(-1);} 
	int playMusic(void *p,int loop){return Mix_PlayMusic((Mix_Music*)p,loop);};
	int musicFadeIn(void * p,int loop,int ms) {return Mix_FadeInMusic((Mix_Music*)p,loop,ms);}
	int musicFadeOut(int ms){return Mix_FadeOutMusic(ms);}

	void pauseMusic(){Mix_PauseMusic();}
	void resumeMusic() {Mix_ResumeMusic();}
	void rewindMusic() {Mix_RewindMusic();}
	bool isMusicPause() {return Mix_PausedMusic() == 1;}
	bool isMusicPlaying() {return Mix_PlayingMusic() == 1;}
	int haltMusic() {return Mix_HaltMusic();} 
	//sound部分
	bool loadSound(const std::string &filename,void *&p)	//从文件中读取声音资源
	{
		p = (void *)Mix_LoadWAV(filename.c_str());
		return p != NULL;
	}
	bool loadSound(void *data,int len,void *&p)
	{
		SDL_RWops *fileData = SDL_RWFromMem(data,len);
		p = (void *)Mix_LoadWAV_RW(fileData,1);	//载入完成之后直接释放资源
		return p != NULL;
	}
	void clearSound(void * p) {Mix_FreeChunk((Mix_Chunk * )p);}
	int setVolume(int c,int v) {return Mix_Volume(c,v);}
	int getVolume(int c) {return Mix_Volume(c,-1);}
	int playSound(void *p,int loop) {return Mix_PlayChannel(-1,(Mix_Chunk *)p,loop);}

	int soundFadeIn(void * p,int loop,int ms){return Mix_FadeInChannel(-1,(Mix_Chunk*)p,loop,ms);}
	int soundFadeOut(int c,int ms){return Mix_FadeOutChannel(c,ms);}
	void pauseSound(int c) {Mix_Pause(c);}
	void resumeSound(int c) {Mix_Resume(c);}
	bool isSoundPause(int c) {return Mix_Paused(c) == 1;}
	bool isSoundPlaying(int c) {return Mix_Playing(c) == 1;}
	int haltSound() {return Mix_HaltChannel(-1);} 
	int haltSound(int c) {return Mix_HaltChannel(c);} 

	//下面是关于回调函数部分
	void setCallBack(SND_CALLBACK_FUN fun, void *arg) {Mix_HookMusic((void (__cdecl *)(void *,Uint8 *,int))fun,arg);}
	//为了替换fadein和fadeout 接口下面定义
	void update(int stepTime) {;}

	unsigned char * getData(void *p) {return ((Mix_Chunk*)p)->abuf;}
	int getDataLen(void *p) {return ((Mix_Chunk*)p)->alen;}
	void setData(void *p,unsigned char * d) {((Mix_Chunk*)p)->abuf = d;}
	void setDataLen(void *p,int len) {((Mix_Chunk*)p)->alen = len;}

};

#endif