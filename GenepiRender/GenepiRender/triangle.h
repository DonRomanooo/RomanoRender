#pragma once
#include "vec3.h"

struct triangle
{
public:
	vec3 vtx0;
	vec3 vtx1;
	vec3 vtx2;
	vec3 n0;
	vec3 n1;
	vec3 n2;
	vec3 color;

	//constructors
	triangle() {}
	triangle(const vec3& vt0, const vec3& vt1, const vec3& vt2,
		const vec3& n_0, const vec3& n_1, const vec3& n_2) :
		vtx0(vt0), vtx1(vt1), vtx2(vt2),
		n0(n_0), n1(n_1), n2(n_2),
		color(1.0f, 1.0f, 1.0f) {}

	triangle(const vec3& vt0, const vec3& vt1, const vec3& vt2,
		const vec3& n_0, const vec3& n_1, const vec3& n_2,
		const vec3& col) :
		vtx0(vt0), vtx1(vt1), vtx2(vt2),
		n0(n_0), n1(n_1), n2(n_2),
		color(col) {}

	const inline vec3& get0() { return vtx0; }
	const inline vec3& get1() { return vtx1; }
	const inline vec3& get2() { return vtx2; }
};

//new triangle struct
/*struct triangle
{
public:
	vec3 vtx0, vtx1, vtx2;
	vec3 n0, n1, n2;
	vec3 color;

	//constructors
	triangle() {}
	triangle(const vec3& vt0, const vec3& vt1, const vec3& vt2,
		const vec3& n_0, const vec3& n_1, const vec3& n_2) :
		vtx0(vt0), vtx1(vt1), vtx2(vt2),
		n0(n_0), n1(n_1), n2(n_2),
		color(1.0f, 1.0f, 1.0f) {}

	triangle(const vec3& vt0, const vec3& vt1, const vec3& vt2,
		const vec3& n_0, const vec3& n_1, const vec3& n_2,
		const vec3& col) :
		vtx0(vt0), vtx1(vt1), vtx2(vt2),
		n0(n_0), n1(n_1), n2(n_2),
		color(col) {}

	triangle(const vec3& pos, const vec3& col) :
		vtx0(pos.x - 0.5, pos.y - 0.5, pos.z),
		vtx1(pos.x + 0.5, pos.y - 0.5, pos.z),
		vtx2(pos.x, pos.y + 0.5, pos.z), color(col) {}

};*/



bool intersect(const vec3& orig, const vec3& dir, triangle& tri, float& u, float& v, float& t)
{
	constexpr float epsilon = 1e-8;

	vec3 p0p1 = tri.vtx1 - tri.vtx0;
	vec3 p0p2 = tri.vtx2 - tri.vtx0;
	vec3 pvec = cross(dir, p0p2);
	float det = dot(p0p1, pvec);

	if (det < epsilon) return false;

	if (fabs(det) < epsilon) return false;

	float invDet = 1 / det;

	vec3 tvec = orig - tri.vtx0;
	u = dot(tvec, pvec) * invDet;
	if (u < 0 || u > 1) return false;

	vec3 qvec = cross(tvec, p0p1);
	v = dot(dir, qvec) * invDet;
	if (v < 0 || u + v > 1) return false;

	t = dot(p0p2, qvec) * invDet;

	return true;
}


//bool is_in(triangle& tri, node nd)
//{
//
//}