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

extern int DOOR_DELAY_TIME;

/* ENEMIES */

extern int ENEMY_DEFAULT_POINTS;
extern int ENEMY_DEFAULT_HEALTH_POINTS;
extern int ENEMY_DEFAULT_ATTACK_DAMAGE;

#pragma region BLADER
extern int BLADER_FIND_ROCKMAN_DISTANCE;
extern float BLADER_ATTACK_DY;
extern int BLADER_POINTS;
extern int BLADER_HEALTH_POINTS;
extern int BLADER_ATTACK_DAMAGE;
#pragma endregion


#pragma region BEAK
extern float TAN_5_TO_RAD;
extern int BEAK_BULLET_VELOCITY;
extern int BEAK_BULLET_DELAY;
extern int BEAK_BULLET_ATTACK_DAMAGE;
extern float TIME_BEAK_SHOOTING;
extern float TIME_BEAK_CHANGE_STATE;
extern float TIME_BEAK_CLOSED;
extern int BEAK_POINTS;
extern int BEAK_HEALTH_POINTS;
extern int BEAK_ATTACK_DAMAGE;
 #pragma endregion

#pragma region SUPER CUTTER
extern int CUTTER_SHOOT_DISTANCE;
extern float CUTTER_BULLET_VY;
extern int CUTTER_SHOOTING_DELAYTIME;
extern int CUTTER_POINTS;
extern int CUTTER_HEALTH_POINTS;
extern int CUTTER_ATTACK_DAMAGE;
#pragma endregion


#pragma region OCTOPUS BATTERY
extern int OCTOPUS_WAITING_DELAYTIME;
extern int OCTOPUS_VELOCITY;
extern float TIME_OCTOPUS_OPEN_EYES;
extern float TIME_OCTOPUS_CLOSE_EYES;
extern int OCTOPUS_POINTS;
extern int OCTOPUS_HEALTH_POINTS;
extern int OCTOPUS_ATTACK_DAMAGE;
#pragma endregion


#pragma region FLEA
extern int FLEA_DELAYTIME;
extern int FLEA_WAITING_WIDTH;
extern int FLEA_FLYING_WIDTH;
extern float FLEA_JUMP_HIGH_VX;
extern float FLEA_JUMP_HIGH_VY;
extern float FLEA_JUMP_FAR_VX;
extern float FLEA_JUMP_FAR_VY;
extern int FLEA_POINTS;
extern int FLEA_HEALTH_POINTS;
extern int FLEA_ATTACK_DAMAGE;
#pragma endregion


#pragma region BIGEYE
extern int BIGEYE_DELAYTIME;
extern int BIGEYE_WAITING_WIDTH;
extern int BIGEYE_FLYING_WIDTH;
extern float BIGEYE_JUMP_HIGH_VX;
extern float BIGEYE_JUMP_HIGH_VY;
extern float BIGEYE_JUMP_FAR_VX;
extern float BIGEYE_JUMP_FAR_VY;
extern int BIGEYE_POINTS;
extern int BIGEYE_HEALTH_POINTS;
extern int BIGEYE_ATTACK_DAMAGE;
#pragma endregion


#pragma region SCREW BOMBER
extern int SCREW_BOMBER_DELAYTIME;
extern int SCREW_BOMBER_SHOOTING_DISTANCE;
extern int SCREW_BOMBER_VELOCITY;
extern int SCREW_BOMBER_POINTS;
extern int SCREW_BOMBER_HEALTH_POINTS;
extern int SCREW_BOMBER_ATTACK_DAMAGE;
#pragma endregion


#pragma region FLYING SHELL
extern int FLYING_SHELL_DELAYTIME;
extern int FLYING_SHELL_RUNNING_DY;
extern int FLYING_SHELL_VELOCITY;
extern int FLYING_SHELL_POINTS;
extern int FLYING_SHELL_HEALTH_POINTS;
extern int FLYING_SHELL_ATTACK_DAMAGE;
#pragma endregion


#pragma region MET
extern int MET_ATTACK_DISTANCE;
extern int MET_DELAYTIME;
extern int MET_POINTS;
extern int MET_HEALTH_POINTS;
extern int MET_ATTACK_DAMAGE;
#pragma endregion


#pragma region PICKET
extern int PICKET_GAME_TIME_DELAY;
extern int PICKET_DELAYTIME;
extern int PICKET_BULLET_VY;
extern int PICKET_BULLET_V;
extern int PICKET_POINTS;
extern int PICKET_HEALTH_POINTS;
extern int PICKET_ATTACK_DAMAGE;
#pragma endregion

/* BOSSES */

#pragma region CUTMAN
extern float CUTMAN_JUMP_VY;
extern int CM_HEALTH_POINTS;
extern int CM_ATTACK_DAMAGE;
extern int CM_STARTING_DELAY_TIME;
extern int CM_WAITING_DELAY_TIME;
extern int CM_RUNNING_DELAY_TIME;
extern int CM_LONG_JUMP_VELOCITY;
extern int CM_SHORT_JUMP_VELOCITY;
extern int CM_DISTANCE_TO_ROCKMAN;
extern int CM_SCISSORS_DISTANCE_TO_ROCKMAN;
extern int CM_SCISSORS_DX_VELOCITY;
extern int CM_SCISSORS_ATTACK_DAMAGE;
extern int CM_INJURY_DELAY_TIME;
extern int CM_DISAPPEAR_GAME_TIME;
#pragma endregion

extern int GM_WAIT_R;
extern int GM_ATTACK_R;
extern int GM_HEALTH_POINTS;
extern int GM_ATTACK_DAMAGE;
extern int GM_ROCK_ATTACK_DAMAGE;
extern int GM_INJURY_DELAY_TIME;
extern int GM_DISAPPEAR_GAME_TIME;
extern int GM_ANIMATION_GAME_TIME;
extern int GM_WAITING_DELAY_TIME;
extern int GM_ATTACKING_DELAY_TIME;
extern float GUTMAN_JUMP_VY;
extern int GM_ROCK_DX_VELOCITY;

// random funtion
extern int randomFrom(int numBegin, int numEnd);
#pragma endregion

extern int MAP_FRAMES_GAME_TIME;

#pragma region Sound

#include"GameSound.h"

#define SOUND_BEAM "Data\\Sound\\Beam.wav"
#define SOUND_STAGE_SELECT "Data\\Sound\\StageSelectBGM.wav"
#define SOUND_ENEMY_CHOSEN "Data\\Sound\\EnemyChosenBGM.wav" 
#define SOUND_CUTMAN "Data\\Sound\\Cutman.wav"
#define SOUND_MENU_SELECT "Data\\Sound\\MenuSelect.wav" 
#define SOUND_GUTSMAN "Data\\Sound\\Gutsman.wav" 
#define SOUND_BONUSBALL "Data\\Sound\\BonusBall.wav" 
#define SOUND_ONEUP "Data\\Sound\\OneUp.wav" 
#define SOUND_MEGABUSTER "Data\\Sound\\MegaBuster.wav" 
#define SOUND_MEGAMAN_DAMAGE "Data\\Sound\\MegamanDamage.wav" 
#define SOUND_LAND "Data\\Sound\\MegamanLand.wav" 
#define SOUND_MEGAMAN_DEFEAT "Data\\Sound\\MegamanDefeat.wav" 
#define SOUND_LAND "Data\\Sound\\MegamanLand.wav" 
#define SOUND_ENEMY_DAMAGE "Data\\Sound\\EnemyDamage.wav" 
#define SOUND_ENEMY_SHOOT "Data\\Sound\\EnemyShoot.wav" 
#define SOUND_DINK "Data\\Sound\\Dink.wav" 
#define SOUND_GAME_START "Data\\Sound\\GameStart.wav" 
#define SOUND_BOSS_GATE "Data\\Sound\\BossGate.wav" 

#pragma endregion

extern int SMALL_LIFE_ENERGY_RECOVERY_HP;
extern int BIG_LIFE_ENERGY_RECOVERY_HP;
extern int SMALL_WEAPON_ENERGY_RECOVERY;
extern int BIG_WEAPON_ENERGY_RECOVERY;
extern int BONUS_BALL_POINTS;
extern int SMALL_LIFE_ENERGY_R;
extern int BIG_LIFE_ENERGY_R;
extern int SMALL_WEAPON_R;
extern int BIG_WEAPON_R;
extern int ONE_UP_LIFE_R;
extern int BONUS_BALL_POINTS_R;
