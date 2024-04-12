#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

int main()
{
	std::string apiKey = "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";
	std::string apiUrl = "https://api.openai.com/v1/completions";


	std::string prompt = "Test";

	nlohmann::json requestBody = {
	   {"model", "gpt-3.5-turbo-instruct"},
	   {"prompt", prompt},
	   {"max_tokens", 7},
	   {"temperature", 0}
	};
	std::string requestBodyString = requestBody.dump();

	cpr::Response response = cpr::Post(cpr::Url{ apiUrl },
		cpr::Header{ {"Content-Type","application/json"},{"Authorization","Bearer " + apiKey} }, requestBodyString);

	if (response.error)
	{
		std::cerr << "Error" << response.error.message << std::endl;
	}
	else
	{
		std::cerr << "Response : " << response.text << std::endl;
	}

	return 0;
}