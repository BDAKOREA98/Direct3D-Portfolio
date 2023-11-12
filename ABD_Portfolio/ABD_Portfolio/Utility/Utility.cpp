#include "framework.h"
#include "Utility.h"

wstring Utility::GetExtension(wstring path)
{
    UINT index = path.find_last_of('.');

    string str;

    return path.substr(index + 1, path.length());
}

string Utility::ToString(wstring str)
{
    string temp;

    temp.assign(str.begin(), str.end());

    return temp;
}

wstring Utility::ToWString(string str)
{
    wstring temp;

    temp.assign(str.begin(), str.end());

    return temp;
}

wstring Utility::GetProjectDir()
{
    WCHAR path[128];
    GetCurrentDirectory(128, path);

    wstring dir = path;

    return dir + L"/";
}

wstring Utility::GetTextureDir()
{
    return GetProjectDir() + L"_Texture/";
}

wstring Utility::GetTextDataDir()
{
    return GetProjectDir() + L"_TextData/";
}

bool Utility::StartsWith(string str, string start)
{
    string result = str.substr(0, start.size());

    return result == start;
}

bool Utility::StartsWith(wstring str, wstring start)
{
    return StartsWith(ToString(str), ToString(start));
}

vector<string> Utility::SplitString(string origin, string token)
{
    vector<string> result;

    size_t cutAt = 0;

    while (cutAt != origin.npos)
    {
        cutAt = origin.find_first_of(token);

        if (cutAt > 0)
            result.push_back(origin.substr(0, cutAt));

        origin = origin.substr(cutAt + 1);
    }

    return result;
}

string Utility::GetFileName(string path)
{
    size_t cutAt = path.find_last_of('/');

    return path.substr(cutAt + 1);
}

string Utility::GetFileNameWithoutExtension(string path)
{
    string name = GetFileName(path);

    size_t cutAt = name.find_last_of('.');

    return name.substr(0, cutAt);
}

void Utility::CreateFolder(string path)
{
    size_t cutAt = path.find_last_of('.');

    UINT size = 0;

    vector<string> folders = SplitString(path, "/");

    if (cutAt != path.npos)
        size = folders.size() - 1;
    else
        size = folders.size();


    string temp = "";

    for (UINT i = 0; i < size; i++)
    {
        temp += folders[i] + "/";

        if (!PathFileExistsA(temp.c_str()))
        {
            CreateDirectoryA(temp.c_str(), 0);
        }
    }
}
