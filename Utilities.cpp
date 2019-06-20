#include "Utilities.h"
#using <System.dll>
#include <string>
#include <vector>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Net;

void systemStringToStandardString(String^ in, string& out)
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(in)).ToPointer();
	out = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

string urlToString(string url)
{
	WebClient^ client = gcnew WebClient;
	client->Headers->Add("user-agent", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.6 (KHTML, like Gecko) Louis/20.0.1092.0 Safari/536.6");
	Stream^ data = client->OpenRead(gcnew String(url.c_str()));
	StreamReader^ reader = gcnew StreamReader(data);
	String^ str = reader->ReadToEnd();
	string retVal;
	systemStringToStandardString(str, retVal);
	data->Close();
	reader->Close();

	return retVal;
}

vector<string> split(string in, vector<string> delimiters)
{
	vector<string> retVal;

	for (int i = 0; i < in.length(); i++)
	{
		for (int j = 0; j < delimiters.size(); j++)
		{
			if (in.substr(i, delimiters[j].length()) == delimiters[j])
			{
				retVal.push_back(in.substr(0, i));

				in.erase(0, i + delimiters[j].length());

				i = 0;
			}
		}
	}

	retVal.push_back(in);

	return retVal;
}

string replace(string str, string out, string in)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.substr(i, out.length()) == out)
		{
			str.replace(i, out.length(), in);
		}
	}

	return str;
}

string newLeft(string str, int len, int spaces)
{
	if (str.length() >= len)
	{
		string retVal = "";

		for (int i = 0; i < len; i++)
		{
			retVal += str[i];
		}

		return retVal;
	}
	else if (str.length() < len)
	{
		string retVal = "";

		for (int i = 0; i < spaces; i++)
		{
			retVal += " ";
		}

		return retVal;
	}
}