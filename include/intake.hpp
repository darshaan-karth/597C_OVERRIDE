#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor intake(Constants::intakeMotor_port);
inline ez::Piston intake_piston(Constants::intake_pneumatics_port);

void intakeMotor_toggle();
void intakePiston_toggle();
void intake_opcontrol();