#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor pitchMotor({Constants::pitchMotor_port});
inline pros::Motor clampingMotor({Constants::clampingMotor_port});
inline pros::Rotation clawRotationSensor({Constants::clawRotation_port});

inline bool claw_on_standby = false;  // Flag to indicate if the claw is in standby mode

inline ez::PID pitchPID(0.5, 0.0, 0.0, 0, "Banchee Claw");  // PID for the pitch motor

inline void set_claw_pitch(int input) {
  pitchMotor.move(input);
}

inline void pitchClaw_wait() {
  while (pitchPID.exit_condition({pitchMotor}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}

void claw_standby();
void claw_score();
void claw_intake();
void bansheeClaw_opcontrol();