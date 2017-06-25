#include "GameSound.h"


GameSound* GameSound::instance_ = nullptr;


GameSound::GameSound()
{
}


GameSound::~GameSound()
{

	loadedSound_.clear();
}

string GameSound::switchID(int id)
{
	string soundLink;
	switch (id)
	{
	case ID_SOUND_JUMP:
	{
		soundLink = SOUNDJUMP;
		break;
	}
	case ID_SOUND_MAP1:
	{
		soundLink = SOUNDMAP1;
		break;
	}
	case ID_SOUND_COIN:
	{
		soundLink = SOUNDCOIN;
		break;
	}
	case ID_TAIL_TALLWHIP:
	{
		soundLink = TAILTAILWHIP;
		break;
	}
	case ID_SOUND_MUSHROOM_OBTAIN:
	{
		soundLink = SOUNDMUSHROOMOBTAIN;
		break;
	}
	case ID_SOUND_RACOON_LEFT_OBTAIN:
	{
		soundLink = SOUNDRACONLEFTOBTAIN;
		break;
	}
	case ID_SOUND_LIFE_UP:
	{
		soundLink = SOUNDLIFEUP;
		break;
	}
	case ID_SOUND_MARIO_SLIPING:
	{
		soundLink = SOUNDMARIOSLIPING;
		break;
	}
	case ID_SOUND_BEAN_STALK:
	{
		soundLink = SOUNDBEANSTALK;
		break;
	}
	case ID_SOUND_PIPE_MAZE:
	{
		soundLink = SOUNDPIPEMAZE;
		break;
	}
	case ID_SOUND_SQUISH:
	{
		soundLink = SOUNDSQUISH;
		break;
	}
	case ID_SOUND_MARIO_ATTACK:
	{
		soundLink = SOUNDMARIOATTACK;
		break;
	}
	case ID_SOUND_BLOCK_BREAKING:
	{
		soundLink = SOUNDBLOCKBREAKING;
		break;
	}
	//case ID_SOUND_TANK_HIT:
	//{
	//	soundLink = SOUND_TANK_HIT;
	//	break;
	//}
	//case ID_SOUND_TANK_MOVE:
	//{
	//	soundLink = SOUND_TANK_MOVE;
	//	break;
	//}

	//case ID_SOUND_ALLY_EXPLODE:
	//{
	//	soundLink = SOUND_ALLY_EXPLODE;
	//	break;
	//}
	//case ID_SOUND_ITEM_APPEAR:
	//{
	//	soundLink = SOUND_ITEM_APPEAR;
	//	break;
	//}
	//case ID_SOUND_ITEM_EAT:
	//{
	//	soundLink = SOUND_ITEM_EAT;
	//	break;
	//}
	//case ID_SOUND_LIFE_UP:
	//{
	//	soundLink = SOUND_LIFE_UP;
	//	break;
	//}
	//case ID_SOUND_STEEL_WALL_EXPLODE:
	//{
	//	soundLink = SOUND_STEEL_WALL_EXPLODE;
	//	break;
	//}
	//case ID_SOUND_COUNT_SCORE:
	//{
	//	soundLink = SOUND_COUNT_SCORE;
	//	break;
	//}
	//case ID_SOUND_GAME_OVER:
	//{
	//	soundLink = SOUND_GAME_OVER;
	//	break;
	//}
	//default:
	//	break;
	//}
	}
	return soundLink;
}

void GameSound::initialize(HWND windowsHandler)
{
	Sound::initializeSoundClass(windowsHandler);
}


void GameSound::play(string soundLink, bool repeat /*= false*/, bool playFromStart /*= true*/)
{
	try
	{
		if (playFromStart)
			loadedSound_.at(soundLink)->stop();
	//	stop(soundLink);

		loadedSound_.at(soundLink)->play(repeat);
	}
	catch (exception)
	{
		loadedSound_.insert(SoundPair(soundLink, new Sound(soundLink.c_str())));
		loadedSound_.at(soundLink)->play(repeat);
	}
}
void GameSound::Play(int id, bool repeat)
{
	Stop(id);
	play(switchID(id), repeat);
}


GameSound* GameSound::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new GameSound();
	}

	return instance_;
}




void GameSound::stop(string soundLink)
{
	try
	{
		loadedSound_.at(soundLink)->stop();
	}
	catch (exception)
	{

	}
}

void GameSound::Stop(int id)
{
	stop(switchID(id));
}
