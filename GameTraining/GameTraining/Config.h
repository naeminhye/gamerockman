#pragma once

#define FPS 160

#pragma region String

#define TITLE_STR "Mega Man"
#define CVFORM_CLASS_NAME "MegaManForm"  

#pragma endregion


#pragma region Size

#define FORM_WIDTH 256*2
#define FORM_HEIGHT 216*2

#define BACKBUFFER_WIDTH 256
#define BACKBUFFER_HEIGHT 216

#pragma endregion

#pragma region Constants

extern float BOX_GRAVITATIONAL_ACCELERATION;
extern int BOX_TIME;

extern int BASE_OBJECT_TICK_PER_FRAME;

extern int DOOR_CAMERA_CHANGING_DX;

#pragma region STAIR
extern int STAIR_DELTA;
extern int STAIR_DY;
extern int DISTANCE_OUT_STAIR;
#pragma endregion

#pragma region ROCKMAN
extern int RM_MAX_HEALTH_POINT;
extern int RM_DEFAULT_LIFE;
extern int RM_WIDTH;
extern int RM_JUMP_WIDTH;
extern int RM_GROUND_WIDTH;
extern int RM_STAIR_SHOOT_WIDTH;
extern int RM_HEIGHT;
extern int RM_DELAY_GAME_TIME;
extern int RM_DISAPPEAR_GAME_TIME;
extern float ROCKMAN_DEAD_VELOCITY;
extern int RM_INJURY_DELAY_TIME;
extern int RM_FLICKER_DELAY_TIME;
extern float RM_VY_JUMP;
extern float RM_V_RUN;
extern float RM_VX_STAND;
extern float ROCKMAN_CHANGESTAGE_DY;
extern int RM_BULLET_WAITING_DELAYTIME;
extern int RM_SHOOTING_DELAYTIME;
extern float TIME_BLINK_OPEN;
extern float TIME_BLINK_CLOSE;
extern int RM_DEATH_DELAYTIME;
extern float RM_VX_RECOIL;
extern float RM_VY_RECOIL;

extern int RM_CUT_BULLET_A;
#pragma endregion


extern int CAMERA_CHANGESTAGE_DY;

/* ENEMIES */

#pragma region BLADER
extern int BLADER_FIND_ROCKMAN_DISTANCE;
extern float BLADER_ATTACK_DY;
#pragma endregion


#pragma region BEAK
extern float TAN_5_TO_RAD;
extern int BEAK_BULLET_VELOCITY;
extern int BEAK_BULLET_DELAY;
extern float TIME_BEAK_SHOOTING;
extern float TIME_BEAK_CHANGE_STATE;
extern float TIME_BEAK_CLOSED;
#pragma endregion


#pragma region SUPER CUTTER
extern int CUTTER_SHOOT_DISTANCE;
extern float CUTTER_BULLET_VY;
extern int CUTTER_SHOOTING_DELAYTIME;
#pragma endregion


#pragma region OCTOPUS BATTERY
extern int OCTOPUS_WAITING_DELAYTIME;
extern int OCTOPUS_VELOCITY;
extern float TIME_OCTOPUS_OPEN_EYES;
extern float TIME_OCTOPUS_CLOSE_EYES;
#pragma endregion


#pragma region FLEA
extern int FLEA_DELAYTIME;
extern int FLEA_WAITING_WIDTH;
extern int FLEA_FLYING_WIDTH;
extern float FLEA_JUMP_HIGH_VX;
extern float FLEA_JUMP_HIGH_VY;
extern float FLEA_JUMP_FAR_VX;
extern float FLEA_JUMP_FAR_VY;
#pragma endregion


#pragma region BIGEYE
extern int BIGEYE_DELAYTIME;
extern int BIGEYE_WAITING_WIDTH;
extern int BIGEYE_FLYING_WIDTH;
extern float BIGEYE_JUMP_HIGH_VX;
extern float BIGEYE_JUMP_HIGH_VY;
extern float BIGEYE_JUMP_FAR_VX;
extern float BIGEYE_JUMP_FAR_VY;
#pragma endregion


#pragma region SCREW BOMBER
extern int SCREW_BOMBER_DELAYTIME;
extern int SCREW_BOMBER_SHOOTING_DISTANCE;
extern int SCREW_BOMBER_VELOCITY;
#pragma endregion


#pragma region FLYING SHELL
extern int FLYING_SHELL_DELAYTIME;
extern int FLYING_SHELL_RUNNING_DY;
extern int FLYING_SHELL_VELOCITY;
#pragma endregion


#pragma region MET
extern int MET_ATTACK;
extern int MET_DELAYTIME;
#pragma endregion


#pragma region PICKET
extern int PICKET_DELAYTIME_FRAME;
extern int PICKET_DELAYTIME;
extern int PICKET_BULLET_VY;
extern int PICKET_BULLET_V;
#pragma endregion

/* BOSSES */

#pragma region CUTMAN
extern float CUTMAN_JUMP_VY;
#pragma endregion

extern int GM_WAIT_R;
extern int GM_ATTACK_R;

// random funtion
extern int randomFrom(int numBegin, int numEnd);
#pragma endregion

#pragma region Sound

#include"GameSound.h"

#define SOUND_BEAM "Data\\Sound\\Beam.wav"
#define SOUND_STAGE_SELECT "Data\\Sound\\StageSelectBGM.wav"
#define SOUND_ENEMY_CHOSEN "Data\\Sound\\EnemyChosenBGM.wav" 
#define SOUND_CUTMAN "Data\\Sound\\Cutman.wav"
#define SOUND_MENU_SELECT "Data\\Sound\\MenuSelect.wav" 
#define SOUND_GUTSMAN "Data\\Sound\\Gutsman.wav" 
#define SOUND_BONUSBALL "Data\\Sound\\BonusBall.wav" 
#define SOUND_MEGABUSTER "Data\\Sound\\MegaBuster.wav" 
#define SOUND_MEGAMAN_DAMAGE "Data\\Sound\\MegamanDamage.wav" 
#define SOUND_LAND "Data\\Sound\\MegamanLand.wav" 
#define SOUND_MEGAMAN_DEFEAT "Data\\Sound\\MegamanDefeat.wav" 
#define SOUND_LAND "Data\\Sound\\MegamanLand.wav" 
#define SOUND_ENEMY_DAMAGE "Data\\Sound\\EnemyDamage.wav" 
#define SOUND_ENEMY_SHOOT "Data\\Sound\\EnemyShoot.wav" 

#pragma endregion

