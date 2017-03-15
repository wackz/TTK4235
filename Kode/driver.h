
//set functions
void drv_setMotorDirection(elev_motor_direction_t direction);
void drv_setDoors(bool doorOpen);


//get functions
bool drv_isAtFloor(void);
int drv_currentFloor(void);
bool drv_getStopButton(void);