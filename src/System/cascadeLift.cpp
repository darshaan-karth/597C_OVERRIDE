#include "main.h"

double getLiftHeight() {
  return cascadeLiftDistanceSensor.get() / 25.4;
}

void liftMoveTo(double height) {
  height = std::clamp(height, 0.0, 39.0);
  liftPID.target_set(height);
  lift_mode = LiftMode::PID;
}

void cascadeLift_up() {
  TARGET_POSITION = std::clamp(TARGET_POSITION + Constants::liftInterval_in, 0.0, 39.0);
  liftPID.target_set(TARGET_POSITION);
  lift_mode = LiftMode::PID;
}

void cascadeLift_down() {
  TARGET_POSITION = std::clamp(TARGET_POSITION - Constants::liftInterval_in, 0.0, 39.0);
  liftPID.target_set(TARGET_POSITION);
  lift_mode = LiftMode::PID;
}

void cascadeLift_ground() {
  TARGET_POSITION = 0.0;
  liftPID.target_set(TARGET_POSITION);
  lift_mode = LiftMode::PID;
  lift_wait();
}

void cascadeLift_opcontrol() {
  lift_mode = LiftMode::MANUAL;

  bool up = master.get_digital(DIGITAL_L1);
  bool down = master.get_digital(DIGITAL_L2);

  if (up && !down) {
    cascadeLift.move(127);
  } else if (down && !up) {
    cascadeLift.move(-127);
  } else {
    cascadeLift.move(0);
  }
}
