#ifndef ps2emu_Callbacks_h
#define ps2emu_Callbacks_h

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ps2emu
{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Callbacks
{
public:

	typedef void (*GifCallback)(void* userData, const void* data);

	static void setGifCallback(void* userData, GifCallback function);
	static void callGif(const void* data);

private:

	static GifCallback m_gifCallback;
	static void* m_gifUserData;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

#endif