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
constexpr int8_t imu_port = 7;
constexpr int8_t distance_port = 19;

// Intake Ports
constexpr unsigned char intake_pneumatics_port = 'A';  // Port for the Pneumatic intake
constexpr int8_t intakeMotor_port = -20;

// Banshee Claw Ports
constexpr int8_t clampingMotor_port = 2;
constexpr unsigned char claw_pneumatics_port = 'B';  // Port for the Pneumatic claw

//Toggle Mech Ports
constexpr int8_t toggleMotor_port = -1;
constexpr int8_t opticalSensor_port = 20;

// Casacade Lift Motor Ports & Constants
constexpr int8_t cascadeLiftMotor_port = 11;
constexpr int8_t cascadeLiftMotor2_port = -12;
constexpr double liftInterval_in = 3.0;

// ======================
// == Drive Control    ==
// ======================

constexpr uint8_t threshold = 9;  // Joystick deadzone (7–10%)

// ======================
// == Auton Config     ==
// ======================

constexpr bool isBlue = true;
}  // namespace Constants