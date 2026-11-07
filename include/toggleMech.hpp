#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor toggleMechMotor(Constants::toggleMotor_port);
inline pros::Optical opticalSensor(Constants::opticalSensor_port);

inline bool toggle_mech_state = false; 

void toggle_mech();
bool isToggleColorMatching();
void toggleMech_opcontrol();