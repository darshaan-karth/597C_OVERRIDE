#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::MotorGroup cascadeLift({Constants::cascadeLiftMotor_port, Constants::cascadeLiftMotor2_port});
inline pros::Distance cascadeLiftDistanceSensor(Constants::distance_port);

enum class LiftMode{PID, MANUAL};

inline LiftMode lift_mode = LiftMode::PID;
inline double TARGET_POSITION = 0.0;
inline ez::PID liftPID(10.0, 0.0, 0.0, 0, "Lift");

inline void set_lift(int input) {
  cascadeLift.move(input);
}

double getLiftHeight();
void liftMoveTo(double height);

void cascadeLift_up();
void cascadeLift_down();
void cascadeLift_ground();
void cascadeLift_opcontrol();