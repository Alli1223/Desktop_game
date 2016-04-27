#pragma once
class ISSLocation
{
public:
	ISSLocation();
	~ISSLocation();


	int lastUpdateTime;
	double longitude, latitude;
	
	void ISSLocation::displayJSONValue(web::json::value ISSData);
	void update();
	pplx::task<void> requestJSONValueAsync();
	
};

