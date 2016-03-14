#pragma once

#include "../stdafx.hpp"

namespace wicx
{
	class RegMan
	{
	public:
		HRESULT SetSZ( wchar_t const *keyName, wchar_t const *valueName, LPCWSTR value )
		{
			return SetRaw( keyName, valueName, REG_SZ, value, sizeof(wchar_t)*(wcslen(value)) );
		}

		HRESULT SetDW( wchar_t const *keyName, wchar_t const *valueName, DWORD value )
		{
			return SetRaw( keyName, valueName, REG_DWORD, &value, sizeof(value) );
		}

		HRESULT SetBytes( wchar_t const *keyName, wchar_t const *valueName, void *value, size_t count )
		{
			return SetRaw( keyName, valueName, REG_BINARY, value, count );
		}

		void Unregister();

	private:
		std::vector< wchar_t const * > m_keys;

		HRESULT SetRaw( wchar_t const *keyName, wchar_t const *valueName, unsigned type, void const *value, size_t valueSize );
	};
}
