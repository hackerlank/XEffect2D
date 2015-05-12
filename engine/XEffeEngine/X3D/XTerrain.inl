inline float _XTerrain::getHeight(float x,float z) const
{
	if(x < 0 || x >= m_width) return 0.0f;
	if(z < 0 || z >= m_height) return 0.0f;
	return m_terrainData[(int)(z * m_width + x)];
}
inline _XVector2 _XTerrain::getTexturePosition(float x,float z) const
{
	if(x < 0) x = 0;
	if(x >= m_width) x = m_width;
	if(z < 0) z = 0;
	if(z >= m_height) z = m_height;
	//return _XVector2(x,z) / m_texture.textureSize;
	return _XVector2(x / m_width,z / m_height);
}
inline void _XTerrain::updateTexture(const unsigned char * data)
{
	if(data == NULL ||
		!m_isInited ||
		!m_withTexture) return;
	m_texture.texture.updateTexture(data);
}
inline void _XTerrain::setTexture(unsigned int tex)	//����������ڲ���
{
	if(!m_isInited ||
		!m_withTexture) return;
	m_texture.texture.m_texture = tex;
}
inline void _XTerrain::setTexture(const _XTextureData &tex)
{
	if(!m_isInited ||
		!m_withTexture) return;
	m_texture.setACopy(tex);
}
inline void _XTerrain::release()
{
	if(!m_isInited) return;
	XDELETE_ARRAY(m_terrainData);
	XDELETE_ARRAY(m_tempFitTerrain);
	m_vbo.release();
	releaseMemory();
	m_isInited = XFalse;
}
inline void _XTerrain::setReflectRate(float rate)
{
	if(rate < 0.0f) rate = 0.0f;
	if(rate > 1.0f) rate = 1.0f;
	m_reflectRate = rate;
}
inline _XVector3 _XTerrain::myNormalize(float x,float z) 
{//�����ض��Ż��Ĺ�һ������
	float d = 1.0f / sqrt(x * x + 1.0f + z * z);
	return _XVector3(x * d,d,z * d);
}
inline _XVector3 _XTerrain::getMyNormal(int x,bool flag)	
{//�����ض��Ż������ߺ���
	//_XVector3 w,v;
	if(flag) return myNormalize(m_newH[x] - m_newH[x + 1],m_newH[x] - m_newH[x + m_width]);	//�ϰ����
	else return myNormalize(m_newH[x + m_width] - m_newH[x + 1 + m_width],m_newH[x + 1] - m_newH[x + 1 + m_width]);	//�°����
}