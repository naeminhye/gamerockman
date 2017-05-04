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

extern int STAIR_DELTA;
extern int STAIR_DY;
extern int DISTANCE_OUT_STAIR;

extern float RM_VY_JUMP;
extern float RM_V_RUN;
extern float RM_VX_STAND;
extern float ROCKMAN_CHANGESTAGE_DY;
extern int RM_BULLET_WAITING_DELAYTIME;
extern int RM_SHOOTING_DELAYTIME;
extern float TIME_BLINK_OPEN;
extern float TIME_BLINK_CLOSE;

extern int CAMERA_CHANGESTAGE_DY;

extern int BLADER_FIND_ROCKMAN_DISTANCE;
extern float BLADER_ATTACK_DY;

extern float TAN_5_TO_RAD;
extern int BEAK_BULLET_VELOCITY;
extern int BEAK_BULLET_DELAY;
extern float TIME_BEAK_SHOOTING;
extern float TIME_BEAK_CHANGE_STATE;
extern float TIME_BEAK_CLOSED;

extern int CUTTER_SHOOT_DISTANCE;
extern float CUTTER_BULLET_VY;
extern int CUTTER_SHOOTING_DELAYTIME;

extern int OCTOPUS_WAITING_DELAYTIME;
extern int OCTOPUS_VELOCITY;
extern float TIME_OCTOPUS_OPEN_EYES;
extern float TIME_OCTOPUS_CLOSE_EYES;

// random funtion
extern int randomFrom(int numBegin, int numEnd);

extern int FLEA_DELAYTIME;
extern float FLEA_JUMP_HIGH_VX;
extern float FLEA_JUMP_HIGH_VY;
extern float FLEA_JUMP_FAR_VX;
extern float FLEA_JUMP_FAR_VY;

extern int BIGEYE_DELAYTIME;
extern float BIGEYE_JUMP_HIGH_VX;
extern float BIGEYE_JUMP_HIGH_VY;
extern float BIGEYE_JUMP_FAR_VX;
extern float BIGEYE_JUMP_FAR_VY;

extern int SCREW_BOMBER_DELAYTIME;
extern int SCREW_BOMBER_SHOOTING_DISTANCE;
extern int SCREW_BOMBER_VELOCITY;

extern int FLYING_SHELL_DELAYTIME;
extern int FLYING_SHELL_RUNNING_DY;
extern int FLYING_SHELL_VELOCITY;
#pragma endregion