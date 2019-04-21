#pragma once
class SaveToBMP
{
public:
	struct rgb_data {
		float r, g, b;
	};
	void save_bitmap(const char*, int, int, int, rgb_data*);

};

