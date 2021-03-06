///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String::String()
{
	m_string = DataPtr<c8>(m_buffer,1,0);
	m_string[0] = '\0';
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String::String(const c8* in)
{
	*this = in;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String::String(const String& in)
{
	*this = in;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String::~String()
{
	m_string.free();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline const c8* String::contents() const
{
	return m_string.objects();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline u32 String::length() const
{
	return m_string.count()-1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline bool String::empty() const
{
	return m_string.count() == 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String& String::operator = (const String& in)
{
	assign(in.m_string.objects(), in.m_string.count());
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline String::operator const c8*() const
{
	return m_string.objects();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline const c8* String::str() const
{
	return m_string.objects();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::compare(const zenic::String& string) const
{
	return compare(0, length(), string, 0, string.length());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::compare(uint pos, uint len, const zenic::String& string) const
{
	return compare(pos, len, string, 0, string.length());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::icompare(const zenic::String& string) const
{
	return icompare(0, length(), string, 0, string.length());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::icompare(uint pos, uint len, const zenic::String& string) const
{
	return icompare(pos, len, string, 0, string.length());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::compare(uint pos1, uint len1, const String& string, uint pos2, uint len2) const
{
	uint len = len1 < len2 ? len1 : len2;
	return compare(contents() + pos1, string.contents() + pos2, len);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline int String::icompare(uint pos1, uint len1, const String& string, uint pos2, uint len2) const
{
	uint len = len1 < len2 ? len1 : len2;
	return icompare(contents() + pos1, string.contents() + pos2, len);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

