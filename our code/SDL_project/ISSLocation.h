#pragma once
class ISSLocation
{
public:
	ISSLocation();
	~ISSLocation();


	int lastUpdateTime;
	double longitude, latitude;
	double backgroundXPos, backgroundYPos;
	
	void ISSLocation::displayJSONValue(web::json::value ISSData);
	void update();
	pplx::task<void> requestJSONValueAsync();
	
};

