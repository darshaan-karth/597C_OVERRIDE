#pragma once

#include "../src/Constants.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::MotorGroup cascadeLift({Constants::cascadeLiftMotor_port, Constants::cascadeLiftMotor2_port}, pros::v5::MotorGears::red);
inline pros::Distance cascadeLiftDistanceSensor(Constants::distance_port);

inline constexpr double lift_step_mm = 77.0;
inline constexpr double lift_max_height_mm = Constants::liftMaximumHeight_mm;
inline constexpr double lift_max_velocity_rpm = Constants::liftMaximumVelocity_rpm;
inline constexpr double lift_min_velocity_rpm = Constants::liftMinimumVelocity_rpm;
inline constexpr double lift_position_tolerance_mm = Constants::liftPositionTolerance_mm;

inline double GROUND_POSITION = 0.0;
inline double TARGET_POSITION = 0.0;
inline bool lift_control_enabled = false;
inline ez::PID liftPID(10.0, 0.0, 0.0, 0, "Lift");

inline void set_lift(int input) {
  cascadeLift.move_velocity(input);
}

bool cascadeLift_initialize();
void cascadeLift_control_step();
bool isCascadeLiftGrounded();
void cascadeLift_up();
void cascadeLift_down();
void cascadeLift_ground();
void cascadeLift_opcontrol();