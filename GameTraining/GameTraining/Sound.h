#pragma once
#define AUDIO_FORMAT_TAG		WAVE_FORMAT_PCM
#define	AUDIO_NUM_OF_CHANNEL	2
#define AUDIO_SAMPLE_SPEED		22050
#define AUDIO_BITS_PER_SAMPLE	16
#define AUDIO_FLAGS				0
#define AUDIO_BUFFER_SIZE		640000
#define AUDIO_GUID				GUID_NULL
#define SOUNDJUMP "Data\\sound\\JumpingSFX.wav"
#define SOUNDMAP1 "Data\\sound\\map1.wav"
#define SOUNDCOIN "Data\\sound\\Coin Obtained SFX.wav"
#define TAILTAILWHIP "Data\\sound\\Raccoon Tail Whip SFX.wav"
#define SOUNDMUSHROOMOBTAIN "Data\\sound\\Mushroom Obtained SFX.wav"
#define SOUNDRACONLEFTOBTAIN "Data\\sound\\Raccoon Leaf Obtained SFX.wav"
#define SOUNDLIFEUP "Data\\sound\\1-UpSFX.wav"
#define SOUNDMARIOSLIPING "Data\\sound\\Slipping SFX.wav"
#define SOUNDBEANSTALK "Data\\sound\\Beanstalk SFX.wav"
#define SOUNDPIPEMAZE "Data\\sound\\Pipe Maze SFX.wav"
#define SOUNDSQUISH "Data\\sound\\Squish SFX.wav"
#define SOUNDMARIOATTACK "Data\\sound\\Bump V1 SFX.wav"
#define SOUNDBLOCKBREAKING "Data\\sound\\Breaking Blocks SFX.wav"
#define SOUNDMARIORUNNING "Data\\sound\\Running SFX.wav"
#define SOUNDMARIOLIFEDOWN "Data\\sound\\smb3_player_down.wav"



#define AUDIO_BLOCK_ALIGN(bitPerSample, nChannels)		(WORD)(bitPerSample / 8 * nChannels)
#define AUDIO_AVERAGE_BPS(samplesPerSec, blockAlign)	(DWORD)(samplesPerSec * blockAlign)

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")

#include <sstream>
#include <iostream>
#include <dsound.h>
#include<vector>
#include "CWaveFile.h"

enum SOUND_ID
{
	ID_SOUND_MAP1,
	ID_SOUND_JUMP,
	ID_SOUND_COIN,
	ID_TAIL_TALLWHIP,
	ID_SOUND_MUSHROOM_OBTAIN,
	ID_SOUND_RACOON_LEFT_OBTAIN,
	ID_SOUND_LIFE_UP,
	ID_SOUND_MARIO_SLIPING,
	ID_SOUND_BEAN_STALK,
	ID_SOUND_PIPE_MAZE,
	ID_SOUND_SQUISH,
	ID_SOUND_MARIO_ATTACK,
	ID_SOUND_BLOCK_BREAKING
};
// -----------------------------------------------
// Name: class TSound
// Desc: used to load/ store/ play an audio with wav extension.
// -----------------------------------------------
class Sound
{
public:
	Sound(const char* audioPath);
	~Sound(void);

	static HRESULT initializeSoundClass(HWND windowsHandler);
	static HRESULT releaseSoundClass();

	HRESULT play(bool isLoop = false, DWORD priority = 0);
	HRESULT stop();


private:
	//HRESULT loadAudio(const char* audioPath);

private:
	static WAVEFORMATEX bufferFormat_;
	static DSBUFFERDESC bufferDescription_;
	static LPDIRECTSOUND8 audioHandler_;
	static HWND windowsHandler_;

	LPDIRECTSOUNDBUFFER soundBuffer_;
};
