#pragma once

namespace Utility
{
	wstring GetExtension(wstring path);

	 string ToString(wstring str);
    wstring ToWString(string str);

	wstring GetProjectDir();
	wstring GetTextureDir();
}