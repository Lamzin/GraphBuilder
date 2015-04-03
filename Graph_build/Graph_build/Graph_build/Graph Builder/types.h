#pragma once

#include <math.h>

#ifndef __device__
#define __device__
#endif

#ifndef __host__
#define __host__
#endif

#define types_func __host__ __device__

typedef char int8;
typedef short int int16;
typedef int int32;
typedef long long int int64;
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long long int uint64;
typedef float float32;
typedef double float64;

typedef uint8 byte;

typedef int8 s8;
typedef int16 s16;
typedef int32 s32;
typedef int64 s64;
typedef uint8 u8;
typedef uint16 u16;
typedef uint32 u32;
typedef uint64 u64;
typedef float32 f32;
typedef float64 f64;

struct uint32x2
{
	uint32 x, y;

	types_func inline uint32x2() {}
	types_func inline uint32x2(uint32 _x, uint32 _y) : x(_x), y(_y) {}

	types_func inline float getAspect() { return (float) x / (float) y; }
};
struct int32x2
{
	int32 x, y;

	types_func inline int32x2() {}
	types_func inline int32x2(int32 _x, int32 _y) : x(_x), y(_y) {}

	types_func inline float getAspect() { return (float) x / (float) y; }
};

struct uint32x3
{
	uint32 x, y, z;

	types_func inline uint32x3() {}
	types_func inline uint32x3(uint32 _x, uint32 _y, uint32 _z) : x(_x), y(_y), z(_z) {}
};

struct uint32x4
{
	uint32 x, y, z, w;

	types_func inline uint32x4() {}
	types_func inline uint32x4(uint32 _x, uint32 _y, uint32 _z, uint32 _w) : x(_x), y(_y), z(_z), w(_w) {}
};

struct uint16x3
{
	uint16 x, y, z;

	types_func inline uint16x3() {}
	types_func inline uint16x3(uint16 _x, uint16 _y, uint16 _z) : x(_x), y(_y), z(_z) {}

	types_func inline void set(uint16 _x, uint16 _y, uint16 _z) { x = _x; y = _y; z = _z; }
};

struct uint16x4
{
	uint16 x, y, z, w;

	types_func inline uint16x4() {}
	types_func inline uint16x4(uint16 _x, uint16 _y, uint16 _z, uint16 _w) : x(_x), y(_y), z(_z), w(_w) {}

	types_func inline void set(uint16 _x, uint16 _y, uint16 _z, uint16 _w) { x = _x; y = _y; z = _z; w = _w; }
};

struct uint16x2
{
	uint16 x, y;

	types_func inline uint16x2() {}
	types_func inline uint16x2(uint16 _x, uint16 _y) : x(_x), y(_y) {}

	types_func inline void set(uint16 _x, uint16 _y) { x = _x; y = _y; }

	types_func inline float getAspect() { return (float) x / (float) y; }
	types_func inline uint32 multiply() { return x * y; }
};

struct int16x2
{
	int16 x, y;

	types_func inline int16x2() {}
	types_func inline int16x2(int16 _x, int16 _y) : x(_x), y(_y) {}

	types_func inline void set(int16 _x, int16 _y) { x = _x; y = _y; }

	types_func inline int16x2 add(int16 _x, int16 _y) { return int16x2(x + _x, y + _y); }
	types_func inline float getAspect() { return (float) x / (float) y; }
	types_func inline int32 multiply() { return x * y; }
};

struct uint8x2
{
	uint8 x, y;

	types_func inline uint8x2() {}
	types_func inline uint8x2(uint8 _x, uint8 _y) : x(_x), y(_y) {}

	types_func inline void set(uint8 _x, uint8 _y) { x = _x; y = _y; }
};

struct float32x2
{
	float x, y;

	types_func inline float32x2() {}
	types_func inline float32x2(float _x, float _y) : x(_x), y(_y) {}

	types_func inline void set(float _x, float _y) { x = _x; y = _y; }

	types_func inline float32x2 operator * (float mul)		{ return float32x2(x * mul, y * mul); }
	types_func inline float32x2 operator *= (float mul)		{ return float32x2(x *= mul, y *= mul); }
	types_func inline float32x2 operator / (float div)		{ return float32x2(x / div, y / div); }
	types_func inline float32x2 operator /= (float div)		{ return float32x2(x /= div, y /= div); }
	types_func inline float32x2 operator * (float32x2 mul)	{ return float32x2(x * mul.x, y * mul.y); }
	types_func inline float32x2 operator *= (float32x2 mul)	{ return float32x2(x *= mul.x, y *= mul.y); }
	types_func inline float32x2 operator + (float32x2 add)	{ return float32x2(x + add.x, y + add.y); }
	types_func inline float32x2 operator += (float32x2 add)	{ return float32x2(x += add.x, y += add.y); }
	types_func inline float32x2 operator - (float32x2 sub)	{ return float32x2(x - sub.x, y - sub.y); }
	types_func inline float32x2 operator -= (float32x2 sub)	{ return float32x2(x -= sub.x, y -= sub.y); }
	inline void normalize()
	{
		float length = getLength();
		if (length < 0.000001f)
			length = 0.000001f;
		x /= length;
		y /= length;
	}

	types_func inline float getLength() { return sqrtf(x * x + y * y); }
};

struct float32x3
{
	float x, y, z;

	types_func inline float32x3() {}
	types_func inline float32x3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	types_func inline void set(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

	types_func inline float32x3 operator * (float mul)		{ return float32x3(x * mul, y * mul, z * mul); }
	types_func inline float32x3 operator *= (float mul)		{ return float32x3(x *= mul, y *= mul, z *= mul); }
	types_func inline float32x3 operator / (float div)		{ return float32x3(x / div, y / div, z / div); }
	types_func inline float32x3 operator /= (float div)		{ return float32x3(x /= div, y /= div, z /= div); }
	types_func inline float32x3 operator * (float32x3 mul)	{ return float32x3(x * mul.x, y * mul.y, z * mul.z); }
	types_func inline float32x3 operator *= (float32x3 mul)	{ return float32x3(x *= mul.x, y *= mul.y, z *= mul.z); }
	types_func inline float32x3 operator + (float32x3 add)	{ return float32x3(x + add.x, y + add.y, z + add.z); }
	types_func inline float32x3 operator += (float32x3 add)	{ return float32x3(x += add.x, y += add.y, z += add.z); }
	types_func inline float32x3 operator - (float32x3 sub)	{ return float32x3(x - sub.x, y - sub.y, z - sub.z); }
	types_func inline float32x3 operator -= (float32x3 sub)	{ return float32x3(x -= sub.x, y -= sub.y, z -= sub.z); }

	types_func inline float getLength() { return sqrtf(x * x + y * y + z * z); }
	types_func inline void normal()
	{
		float length = getLength();
		if (length < 0.000001f)
			length = 0.000001f;
		x /= length;
		y /= length;
		z /= length;
	}
	types_func inline void cross(float32x3 v1, float32x3 v2)
	{
		x = v1.y * v2.z - v1.z * v2.y;
		y = v1.z * v2.x - v1.x * v2.z;
		z = v1.x * v2.y - v1.y * v2.x;
	}
};

struct float32x4
{
	float x, y, z, w;

	types_func inline float32x4() {}
	types_func inline float32x4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

	types_func inline void set(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }

	types_func inline float getLength() { return sqrtf(x * x + y * y + z * z + w * w); }
};

typedef float32x2 f32x2;
typedef float32x3 f32x3;
typedef float32x4 f32x4;

types_func inline float dot(float32x3& v1, float32x3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}