#pragma once

#include <cmath>
#include <cstdint>

namespace Constants {

// =================================
// ==   Motor & Pneumatic Ports   ==
// =================================

// DriveTrain Motor Ports
constexpr int8_t fl_p = -16;  // Front Left
constexpr int8_t bl_p = -15;  // Back Left

constexpr int8_t fr_p = 14;  // Front Right
constexpr int8_t br_p = 5;  // Back Right

// Sensor Port
constexpr int8_t imu_port = 8;
constexpr int8_t distance_port = 19;
constexpr int8_t clawRotation_port = 9;

// Intake Pneumatic Mechanism Port
constexpr unsigned char intake_pneumatics_port = 'E';  // Port for the Pneumatic intake

// Intake Motor Port
constexpr int8_t intakeMotor_port = -20;

// Banshee Claw Motor Ports
constexpr int8_t pitchMotor_port = -1;
constexpr int8_t clampingMotor_port = 2;

// Casacade Lift Motor Ports
constexpr int8_t cascadeLiftMotor_port = 11;
constexpr int8_t cascadeLiftMotor2_port = -12;
constexpr bool liftDistanceIncreasesAsLiftRises = true;
constexpr double liftMaximumHeight_mm = 1016.0;
constexpr double liftMaximumVelocity_rpm = 200.0;
constexpr double liftMinimumVelocity_rpm = 20.0;
constexpr double liftPositionTolerance_mm = 8.0;

// ======================
// == Drive Control    ==
// ======================

constexpr uint8_t threshold = 9;  // Joystick deadzone (7–10%)

// ======================
// == Auton Config     ==
// ======================

constexpr bool isBlue = true;
}  // namespace Constants