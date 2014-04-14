//++++++++++++++++++++++++++++++++
//Author:	贾胜华(JiaShengHua)
//Version:	1.0.0
//Date:		See the header file
//--------------------------------
#include "XArcBall.h"

void _XArcBall::mapToSphere(_XVector2 point,_XVector3& vec) const	//将2D坐标映射成3D坐标
{
	//Adjust point coords and scale down to range of [-1 ... 1]
	point.x  = (point.x * m_sizeWRate) - 1.0f;
	point.y  = 1.0f - (point.y * m_sizeHRate);
	//Compute the square of the length of the vector to the point from the center
	float length = point.getLengthSqure();
	//If the point is mapped outside of the sphere... (length > radius squared)
	if(length > 1.0f)
	{//Compute a normalizing factor (radius / sqrt(length))
		float norm = 1.0f / sqrtf(length);
		//Return the "normalized" vector, a point on the sphere
		vec.x = point.x * norm;
		vec.y = point.y * norm;
		vec.z = 0.0f;
	}else    //Else it's on the inside
	{
		//Return a vector to a point mapped inside the sphere sqrt(radius squared - length)
		vec.x = point.x;
		vec.y = point.y;
		vec.z = sqrtf(1.0f - length);
	}
}
void _XArcBall::drag(_XVector2 point,_XVector4& rotate)
{
	mapToSphere(point,m_dragVector);	//Map the point to the sphere
	//Return the quaternion equivalent to the rotation
	_XVector3 perp = m_clickVector * m_dragVector;	//Compute the vector perpendicular to the begin and end vectors
	//Compute the length of the perpendicular vector
	if(perp.getLength() > (1.0e-5))    //if its non-zero
	//if(perp.getLength() >= 0.0f)    //if its non-zero
	{//We're ok, so return the perpendicular vector as the transform after all
		rotate.x = perp.x;
		rotate.y = perp.y;
		rotate.z = perp.z;
		//In the quaternion values, w is cosine (theta / 2), where theta is rotation angle
		rotate.w = m_clickVector.dot(m_dragVector);
	}else                                    //if its zero
	{//The begin and end vectors coincide, so return an identity transform
		rotate.x = 
		rotate.y = 
		rotate.z = 
		rotate.w = 0.0f;
		printf("Error!\n");
	}
}