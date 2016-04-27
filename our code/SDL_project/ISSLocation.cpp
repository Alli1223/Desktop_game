#include "stdafx.h"
#include "ISSLocation.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

ISSLocation::ISSLocation()
{
}


ISSLocation::~ISSLocation()
{
}


void ISSLocation::displayJSONValue(web::json::value ISSData)
{
	if (!ISSData.is_null())
	{
		for (auto iter = ISSData.as_object().cbegin(); iter != ISSData.as_object().cend(); ++iter)
		{
			const json::value &key = json::value::string(iter->first);
			const json::value &value = iter->second;

			if (value.is_object() || value.is_array())
			{
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"Parent: " << key.as_string() << std::endl;
					//Parent is the object in this case iss_position
					//Parent contains the latitude & longitude
				}
				displayJSONValue(value);
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"End of Parent: " << key.as_string() << std::endl;
					//break; //break makes it only get the  latitude & longitude and not the message on timestamp
					//Probably need timestamp to choose when to update data
				}
			}
			else
			{
				if (key.serialize() == (L"\"timestamp""\""))
				{
					std::wcout << L"timestamp found" << std::endl;
					lastUpdateTime = value.as_integer();
				}
				else if (key.serialize() == (L"\"longitude""\""))
				{
					std::wcout << L"longitude found" << std::endl;
					longitude = value.as_double();
				}
				else if (key.serialize() == (L"\"latitude""\""))
				{
					std::wcout << L"latitude found" << std::endl;
					latitude = value.as_double();
				}
				std::wcout << L"Key: " << key.serialize() << L", Value: " << value.serialize() << std::endl;
			}
		}
	}
}


// Retrieves a JSON value from an HTTP request.
pplx::task<void> ISSLocation::requestJSONValueAsync()
{
	http_client client(L"http://api.open-notify.org/iss-now.json");
	return client.request(methods::GET).then([](http_response response) -> pplx::task<json::value>
	{
		if (response.status_code() == status_codes::OK)
		{
			return response.extract_json();
		}
		return pplx::task_from_result(json::value());
	})
		.then([&](pplx::task<json::value> previousTask)
	{
		try
		{
			const json::value& v = previousTask.get();
			// JSON object
			displayJSONValue(v);
			std::cout << "Success" << std::endl;
		}
		catch (const http_exception& e)
		{
			// Error catch
			std::wostringstream ss;
			ss << e.what() << std::endl;
			std::wcout << ss.str();
		}
	});
}


void ISSLocation::update()
{
	time_t currentTime = time(0);
	if (lastUpdateTime < currentTime + 2)
	{// Currently updates location every 5 seconds 
		//Only update when character is in idle state?
		requestJSONValueAsync().wait();
		//latitude +/-90
		//longitude +/-180
		backgroundXPos = (latitude / 90) * 800; //800 = Screen height
		backgroundYPos = (longitude / 180) * 800; //800 = Screen width

	}
}
