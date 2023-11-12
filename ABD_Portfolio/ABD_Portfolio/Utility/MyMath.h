#pragma once

namespace MyMath
{
	float    Clamp(const float& value, float minValue, float maxValue);
	float Saturate(const float& value);

	float Max(const float& value1, const float& value2, const float& value3);
	float Min(const float& value1, const float& value2, const float& value3);

	float Distance(Vector3 v1, Vector3 v2);

	float Random(const float& min, const float& max);
	  int Random(const   int& min, const   int& max);
}

