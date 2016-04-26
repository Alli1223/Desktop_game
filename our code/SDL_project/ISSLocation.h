#pragma once
class ISSLocation
{
public:
	ISSLocation();
	~ISSLocation();


	int currentTime;
	double longitude, latitude;
	
	void ISSLocation::DisplayJSONValue(web::json::value ISSData);
	int update();
	pplx::task<void> RequestJSONValueAsync();
	
};

