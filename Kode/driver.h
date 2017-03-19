//static values
static int targetFloor;
static int currentFloor;
static bool IsAtFloor;
static  elev_motor_direction_t motorDirection;

static bool floorMatrix[4][3] = {
	//up, down, command
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

//target functions
void drv_setFloorMatrix(int floor, tag_elev_lamp_type buttonType, bool value);
void drv_wipeFloorMatrix(void);
bool drv_passingFloorWithRequest(int floor);
bool drv_isAtTargetFloor(void);


//set functions
void drv_setMotorDirection(elev_motor_direction_t direction);
void drv_setDoorLamp(bool doorOpen);
void drv_setStopLamp(bool lampOn);
void drv_setCurrentFloor(void);
void drv_updateFloorLampsFromMatrix(void);


//get functions
bool drv_getIsAtFloor(void);
bool drv_getStopButton(void);
elev_motor_direction_t drv_getDirection(void);
int drv_getTargetFloor(void);
int drv_getCurrentFloor(void);


//priority handling code!!
elev_motor_direction_t drv_dirToTargetFloor(void);
