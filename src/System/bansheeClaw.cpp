#include "main.h"

namespace {
constexpr uint32_t claw_move_timeout_ticks =
    static_cast<uint32_t>(3000 / ez::util::DELAY_TIME);

bool get_claw_position_degrees(double& degrees) {
  const int32_t position = clawRotationSensor.get_position();
  if (position == PROS_ERR) {
    pitchMotor.move_velocity(0);
    return false;
  }

  degrees = position / 100.0;
  return true;
}
}  // namespace

bool claw_move_to_degrees(double degrees) {
  if (!std::isfinite(degrees)) {
    pitchMotor.move_velocity(0);
    return false;
  }

  if (clawRotationSensor.get_position() == PROS_ERR) {
    pitchMotor.move_velocity(0);
    return false;
  }

  pitchPositionPID.target_set(degrees);
  return true;
}

bool pitchClaw_wait() {
  for (uint32_t tick = 0; tick < claw_move_timeout_ticks; ++tick) {
    double current_degrees;
    if (!get_claw_position_degrees(current_degrees)) {
      return false;
    }

    if (std::abs(pitchPositionPID.target_get() - current_degrees) <=
        claw_position_tolerance_degrees) {
      return true;
    }

    pros::delay(ez::util::DELAY_TIME);
  }

  double current_degrees;
  if (get_claw_position_degrees(current_degrees)) {
    pitchPositionPID.target_set(current_degrees);
  }
  pitchMotor.move_velocity(0);
  return false;
}

void claw_standby() {
  pitchMotor.move(127);
}

void claw_score() {
  pitchMotor.move(-127);
}

void claw_intake() {
  pitchMotor.move(0);
}

void bansheeClaw_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_X)) {
    claw_intake();
  }

  if (master.get_digital_new_press(DIGITAL_L1)) {
    claw_standby();
  }

  if (master.get_digital_new_press(DIGITAL_L2)) {
    claw_score();
  }
}