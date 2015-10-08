#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Joysticks
const int DRIVER_JOYSTICK_PORT = 0;
const int COPILOT_JOYSTICK_PORT = 1;

//Motors
const int FRONT_LEFT_DRIVE_MOTOR = 0;
const int BACK_LEFT_DRIVE_MOTOR = 1;
const int BACK_RIGHT_DRIVE_MOTOR = 2;
const int FRONT_RIGHT_DRIVE_MOTOR = 3;
const int LEFT_RISER_MOTOR_PORT = 4;
const int RIGHT_RISER_MOTOR_PORT = 6;

//Digital inputs
const int LEFT_RESET_LIMIT_PORT = 1;
const int RIGHT_RESET_LIMIT_PORT = 0;

const int LEFT_ENCODER_A_PORT = 2;
const int LEFT_ENCODER_B_PORT = 3;

const int RIGHT_ENCODER_A_PORT = 4;
const int RIGHT_ENCODER_B_PORT = 5;

//Analog Inputs
const int GYRO_PORT = 0;

//other
const int RISER_SPEED = 5;
const int MAX_HEIGHT = 600;

#endif
