#ifndef VECTOR_VECTOR3D_H
#define VECTOR_VECTOR3D_H

#include "vector_Point3d.h"
//class Point3d;
class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z);
	void print() const;
    friend void Point3d::moveByVector(const Vector3d& v);
    
};
#endif
