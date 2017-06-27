#pragma region BOX

float BOX_GRAVITATIONAL_ACCELERATION = -0.0015; // Gravitational acceleration
int BOX_TIME = 15;

#pragma endregion

#pragma region BASE OBJECT
int BASE_OBJECT_TICK_PER_FRAME = 100;
#pragma endregion


#pragma region ROCKMAN & ROCKMAN BULLET

int RM_MAX_HEALTH_POINT = 28;
int RM_DEFAULT_LIFE = 3;
int RM_WIDTH = 20;
int RM_HEIGHT = 24;
int RM_JUMP_WIDTH = 14;
int RM_GROUND_WIDTH = 21;
int RM_STAIR_SHOOT_WIDTH = 16;
int RM_DELAY_GAME_TIME = 500;
int RM_DISAPPEAR_GAME_TIME = 20;
int RM_INJURY_DELAY_TIME = 500;
int RM_FLICKER_DELAY_TIME = 2000;
float RM_VY_JUMP = 0.4; // Van toc Vy cua Rockman khi nhay
float RM_V_RUN = 0.08; // Van toc chay cua Rockman
float RM_VX_STAND = 0; // van toc Vx khi Rockman dung 1 chofloat 
int CAMERA_CHANGESTAGE_DY = 3; // ...
float ROCKMAN_CHANGESTAGE_DY = 0.3;
float TIME_BLINK_OPEN = 2000; 
float TIME_BLINK_CLOSE = 200;
int RM_BULLET_WAITING_DELAYTIME = 300; // doi ten
int RM_SHOOTING_DELAYTIME = 400;
int RM_DEATH_DELAYTIME = 1000;
float RM_VX_RECOIL = 0.1;
float RM_VY_RECOIL = 0.2;

int RM_CUT_BULLET_A = 50;

#pragma endregion

#pragma region CAMERA
int DOOR_CAMERA_CHANGING_DX = 3;
#pragma endregion

int DOOR_DELAY_TIME = 500;

/*STAIR*/

int STAIR_DELTA = 6;
int STAIR_DY = 1;
int DISTANCE_OUT_STAIR = 6;

// --------- ENEMIES --------- //

int ENEMY_DEFAULT_POINTS = 100;
int ENEMY_DEFAULT_HEALTH_POINTS = 1;
int ENEMY_DEFAULT_ATTACK_DAMAGE = 1;

/* OCTOPUS BATTERY */

float TIME_OCTOPUS_CLOSE_EYES = 1000;
float TIME_OCTOPUS_OPEN_EYES = 1000;
int OCTOPUS_WAITING_DELAYTIME = 1000;
int OCTOPUS_VELOCITY = 2;
int OCTOPUS_POINTS = 300;
int OCTOPUS_HEALTH_POINTS = 5;
int OCTOPUS_ATTACK_DAMAGE = 4;


/* BEAK */

int BEAK_BULLET_DELAY = 500;
float TAN_5_TO_RAD = 0.087266;
int BEAK_BULLET_VELOCITY = 3;
float TIME_BEAK_CLOSED = 1000;
float TIME_BEAK_SHOOTING = 2000;
float TIME_BEAK_CHANGE_STATE = 100; // thoi gian khi Beak OPENING hoac CLOSING
int BEAK_POINTS = 200;
int BEAK_HEALTH_POINTS = 1;
int BEAK_ATTACK_DAMAGE = 1;

/* BLADER */

int BLADER_FIND_ROCKMAN_DISTANCE = 50;
float BLADER_ATTACK_DY = 3.5;
int BLADER_POINTS = 500;
int BLADER_HEALTH_POINTS = 1;
int BLADER_ATTACK_DAMAGE = 3;


#pragma region SUPER CUTTER

int CUTTER_SHOOT_DISTANCE = 100;
float CUTTER_BULLET_VY = 0.4;
int CUTTER_SHOOTING_DELAYTIME = 1000;
int CUTTER_POINTS = 500;
int CUTTER_ATTACK_DAMAGE = 4;

#pragma endregion

#pragma region FLEA

int FLEA_DELAYTIME = 500;
int FLEA_WAITING_WIDTH = 15;
int FLEA_FLYING_WIDTH = 19;
float FLEA_JUMP_HIGH_VX = 0.2;
float FLEA_JUMP_HIGH_VY = 0.4;
float FLEA_JUMP_FAR_VX = 0.3;
float FLEA_JUMP_FAR_VY = 0.2;
int FLEA_POINTS = 300;
int FLEA_HEALTH_POINTS = 1;
int FLEA_ATTACK_DAMAGE = 2;

#pragma endregion

#pragma region BIG EYE

int BIGEYE_DELAYTIME = 500;
int BIGEYE_WAITING_WIDTH = 40;
int BIGEYE_FLYING_WIDTH = 48;
float BIGEYE_JUMP_HIGH_VX = 0.05;
float BIGEYE_JUMP_HIGH_VY = 0.3;
float BIGEYE_JUMP_FAR_VX = 0.05;
float BIGEYE_JUMP_FAR_VY = 0.2;
int BIGEYE_POINTS = 9000;
int BIGEYE_HEALTH_POINTS = 20;
int BIGEYE_ATTACK_DAMAGE = 10;

#pragma endregion

#pragma region SCREW BOMBER

int SCREW_BOMBER_DELAYTIME = 1000;
int SCREW_BOMBER_SHOOTING_DISTANCE = 100;
int SCREW_BOMBER_VELOCITY = 3;
int SCREW_BOMBER_POINTS = 500;
int SCREW_BOMBER_HEALTH_POINTS = 3;
int SCREW_BOMBER_ATTACK_DAMAGE = 1;
// SCREW BOMBER BULLET ATTACK DAMAGE = 2

#pragma endregion

#pragma region FLYING SHELL

int FLYING_SHELL_DELAYTIME = 1000;
int FLYING_SHELL_RUNNING_DY = -1;
int FLYING_SHELL_VELOCITY = 3;
float ROCKMAN_DEAD_VELOCITY = 0.5;
int FLYING_SHELL_POINTS = 800;
int FLYING_SHELL_HEALTH_POINTS = 1;
int FLYING_SHELL_ATTACK_DAMAGE = 1;
// FLYING SHELL BULLET ATTACK DAMAGE = 2

#pragma endregion 

#pragma region MET

int MET_ATTACK_DISTANCE = 100;
int MET_DELAYTIME = 1000;
int MET_POINTS = 500;
int MET_HEALTH_POINTS = 1;
int MET_ATTACK_DAMAGE = 1;
// MET BULLET ATTACK DAMAGE = 2

#pragma endregion 

#pragma region PICKET_MAN 

int PICKET_GAME_TIME_DELAY = 200;
int PICKET_DELAYTIME = 2000;
int PICKET_BULLET_VY = 0.38;
int PICKET_BULLET_V = 1500;
int PICKET_POINTS = 200;
int PICKET_HEALTH_POINTS = 10;
int PICKET_ATTACK_DAMAGE = 3;
// PICKET (pickaxe) ATTACK DAMAGE = 10

#pragma endregion 

// --------------------------- //

// ---------- BOSSES --------- //

/* CUTMAN */

float CUTMAN_JUMP_VY = 0.4;
int CM_LONG_JUMP_VELOCITY	= 2;
int CM_SHORT_JUMP_VELOCITY	= 1;

int CM_STARTING_DELAY_TIME = 1000;
int CM_WAITING_DELAY_TIME = 500;
int CM_RUNNING_DELAY_TIME = 1000;

int CM_HEALTH_POINTS = 28;
int CM_ATTACK_DAMAGE = 10;

int CM_DISTANCE_TO_ROCKMAN = 150;

int CM_SCISSORS_DISTANCE_TO_ROCKMAN = 10;
int CM_SCISSORS_DX_VELOCITY = 2;

// Cutman Random Action Numbers
int CM_NON_WAIT_R = 1; // Cutman, Non-attacking, Waiting
int CM_NON_SHOOT_R = 2; // Cutman, Non-attacking, Shooting
int CM_NON_RUN_R = 3; // Cutman, Non-attacking, Running
int CM_NON_JUMP_SHORT_R = 5; // Cutman, Non-attacking, Short Jumping
int CM_NON_JUMP_LONG_R = 5; // Cutman, Non-attacking, Long Jumping

int CM_WAIT_R				= 1;					// Cutman, Attacking, Waiting
int CM_RUN_R				= 3;			// Cutman, Attacking, Running
int CM_JUMP_SHORT_R			= 5;		// Cutman, Attacking, Short Jumping
int CM_JUMP_LONG_R			= 5; // Cutman, Attacking, Long Jumping


/* GUTSMAN */

int GM_WAIT_R		= 1;
int GM_ATTACK_R		= 3;

// --------------------------- //

int MAP_FRAMES_GAME_TIME = 100;