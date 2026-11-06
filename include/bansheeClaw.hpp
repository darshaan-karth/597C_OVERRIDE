#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline ez::Piston claw_piston(Constants::claw_pneumatics_port);
inline pros::Motor clampingMotor(Constants::clampingMotor_port);
inline pros::Motor toggleMechMotor(Constants::toggleMotor_port);

inline bool claw_on_standby = false;  // Flag to indicate if the claw is in standby mode

// Zero is down; positive angles are clockwise and negative angles are counterclockwise.

void claw_standby();
void claw_score();
void claw_intake();
void claw_stop();
void claw_intake_piston();
void toggle_mech();
void bansheeClaw_opcontrol();