#pragma region BOX

float BOX_GRAVITATIONAL_ACCELERATION = -0.001; // Gravitational acceleration
int BOX_TIME = 15;

#pragma endregion

#pragma region ROCKMAN & ROCKMAN BULLET

float RM_VY_JUMP = 0.34; // Van toc Vy cua Rockman khi nhay
float RM_V_RUN = 0.08; // Van toc chay cua Rockman
float RM_VX_STAND = 0; // van toc Vx khi Rockman dung 1 chofloat 
int CAMERA_CHANGESTAGE_DY = 3; // ...
float ROCKMAN_CHANGESTAGE_DY = 0.3;
float TIME_BLINK_OPEN = 2000; 
float TIME_BLINK_CLOSE = 200;
int RM_BULLET_WAITING_DELAYTIME = 300; // doi ten
int RM_SHOOTING_DELAYTIME = 200;

#pragma endregion

#pragma region STAIR

int STAIR_DELTA = 6;
int STAIR_DY = 1;
int DISTANCE_OUT_STAIR = 6;

#pragma endregion

#pragma region OCTOPUS BATTERY

float TIME_OCTOPUS_CLOSE_EYES = 1000;
float TIME_OCTOPUS_OPEN_EYES = 1000;
int OCTOPUS_WAITING_DELAYTIME = 1000;
int OCTOPUS_VELOCITY = 2;

#pragma endregion

#pragma region BLADER

int BLADER_FIND_ROCKMAN_DISTANCE = 50;
float BLADER_ATTACK_DY = 3.5;

#pragma endregion

#pragma region BEAK

int BEAK_BULLET_DELAY = 500;
float TAN_5_TO_RAD = 0.087266;
int BEAK_BULLET_VELOCITY = 3;
float TIME_BEAK_CLOSED = 1000;
float TIME_BEAK_SHOOTING = 2000;
float TIME_BEAK_CHANGE_STATE = 100; // thoi gian khi Beak OPENING hoac CLOSING

#pragma endregion

#pragma region SUPER CUTTER

int CUTTER_SHOOT_DISTANCE = 100;
float CUTTER_BULLET_VY = 0.4;
int CUTTER_SHOOTING_DELAYTIME = 1000;

#pragma endregion

#pragma region FLEA

int FLEA_DELAYTIME = 500;
float FLEA_JUMP_HIGH_VX = 0.2;
float FLEA_JUMP_HIGH_VY = 0.4;
float FLEA_JUMP_FAR_VX = 0.3;
float FLEA_JUMP_FAR_VY = 0.2;

#pragma endregion

#pragma region BIG EYE

int BIGEYE_DELAYTIME = 500;
float BIGEYE_JUMP_HIGH_VX = 0.05;
float BIGEYE_JUMP_HIGH_VY = 0.3;
float BIGEYE_JUMP_FAR_VX = 0.05;
float BIGEYE_JUMP_FAR_VY = 0.2;

#pragma endregion

#pragma region SCREW BOMBER

int SCREW_BOMBER_DELAYTIME = 1000;
int SCREW_BOMBER_SHOOTING_DISTANCE = 100;
int SCREW_BOMBER_VELOCITY = 3;

#pragma endregion

#pragma region FLYING SHELL

int FLYING_SHELL_DELAYTIME = 1000;
int FLYING_SHELL_RUNNING_DY = -1;
int FLYING_SHELL_VELOCITY = 3;

#pragma endregion

#pragma region CUTMAN

float CUTMAN_JUMP_VY = 0.4;

#pragma endregion
