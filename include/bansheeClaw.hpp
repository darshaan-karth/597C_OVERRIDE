#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor pitchMotor(Constants::pitchMotor_port, pros::v5::MotorGears::red);
inline pros::Motor clampingMotor(Constants::clampingMotor_port);
inline pros::Rotation clawRotationSensor(Constants::clawRotation_port);

inline bool claw_on_standby = false;  // Flag to indicate if the claw is in standby mode
inline bool claw_position_control_enabled = false;

inline constexpr double claw_position_tolerance_degrees = 2.0;
inline constexpr double claw_max_velocity_rpm = 100.0;
inline constexpr double claw_min_velocity_rpm = 10.0;
inline ez::PID pitchPositionPID(0.5, 0.0, 0.01, 0, "Banshee Claw Position");

inline void set_claw_pitch(int input) {
  pitchMotor.move_velocity(input);
}

// Zero is down; positive angles are clockwise and negative angles are counterclockwise.
bool claw_move_to_degrees(double degrees);
bool pitchClaw_wait();
void claw_standby();
void claw_score();
void claw_intake();
void bansheeClaw_opcontrol();