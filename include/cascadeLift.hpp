#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::MotorGroup cascadeLift({Constants::cascadeLiftMotor_port, Constants::cascadeLiftMotor2_port});
inline pros::Distance cascadeLiftDistanceSensor(Constants::distance_port);

inline double GROUND_POSITION = 0.0;  // Position value indicating the ground position
inline double TARGET_POSITION = 0.0;  // Position value indicating the target position for the lift

inline ez::PID liftPID(0.5, 0.0, 0.0, 0, "Lift");  // PID for the Cascade Lift

inline void set_lift(int input) {
  cascadeLift.move(input);
}

inline void lift_wait() {
  while (liftPID.exit_condition({pros::Motor(Constants::cascadeLiftMotor_port), pros::Motor(Constants::cascadeLiftMotor2_port)},
                                true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}

bool isCascadeLiftGrounded();
void cascadeLift_up();
void cascadeLift_down();
void cascadeLift_ground();
void cascadeLift_opcontrol();