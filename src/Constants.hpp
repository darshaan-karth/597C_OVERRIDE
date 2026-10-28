#pragma once

#include <cmath>
#include <cstdint>

namespace Constants {

// =================================
// ==   Motor & Pneumatic Ports   ==
// =================================

// DriveTrain Motor Ports
constexpr int8_t fl_p = -13;  // Front Left
constexpr int8_t bl_p = -11;  // Back Left

constexpr int8_t fr_p = 18;  // Front Right
constexpr int8_t br_p = 17;  // Back Right

// Sensor Port
constexpr int8_t imu_port = 5;
constexpr int8_t distance_port = 6;
constexpr int8_t clawRotation_port = 7;

// Intake Pneumatic Mechanism Port
constexpr unsigned char intake_pneumatics_port = 'E';  // Port for the Pneumatic intake

// Intake Motor Port
constexpr int8_t intakeMotor_port = 2;

// Banshee Claw Motor Ports
constexpr int8_t pitchMotor_port = 10;
constexpr int8_t clampingMotor_port = 20;

// Casacade Lift Motor Ports
constexpr int8_t cascadeLiftMotor_port = 1;
constexpr int8_t cascadeLiftMotor2_port = 3;

// ======================
// == Drive Control    ==
// ======================

constexpr uint8_t threshold = 9;  // Joystick deadzone (7–10%)

// ======================
// == Auton Config     ==
// ======================

constexpr bool isBlue = true;
}  // namespace Constants