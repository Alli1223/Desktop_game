#pragma once
class Map
{
public:
	Map(const std::string& filename);
	~Map();

	int getWidth() const { return width; }
	int getHeight() const { return height; }

	

private:
	//For a 800px X 800px window size there are 16 cols X 16 rows
	const char* MAP_NAME = "Resources\\Map\\test_map.txt";
	int width;
	int height;
};


