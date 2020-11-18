#pragma once

namespace plutoscript
{
	struct Vec3
	{
		float x;
		float y;
		float z;

		Vec3() : x(0.0f), y(0.0f), z(0.0f) { }
		Vec3(const float f[3]): x(f[0]), y(f[1]), z(f[2]) { }
		Vec3(const float fx, const float fy, const float fz) : x(fx), y(fy), z(fz) { }
		Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) { }

		operator std::string() const
		{
			return ("(" + std::to_string(this->x) + "," + std::to_string(this->y) + "," + std::to_string(this->z) + ")");
		}
	};
}
