#include "main.h"

void claw_standby() {
  if (claw_on_standby) {
    return;  // If the claw is already in standby, do nothing
  }
  pitchPID.target_set(90);
  clampingMotor.move(127);
  pitchClaw_wait();
  clampingMotor.move(0);
  claw_on_standby = true;
}

void claw_score() {
  if (!claw_on_standby) {
    return;  // If the claw is not in standby, do nothing
  }
  clampingMotor.move(-127);
  pros::delay(500);  // Wait for the claw to open
}

void claw_intake() {
  if (!claw_on_standby) {
    return;  // If the claw is not in standby, do nothing
  }
  pitchPID.target_set(0);
  clampingMotor.move(127);
  claw_on_standby = false;
}

void bansheeClaw_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_R1)) {
    claw_standby();
  }

  if (master.get_digital_new_press(DIGITAL_R2)) {
    claw_score();
  }

  if (master.get_digital_new_press(DIGITAL_L1)) {
    claw_intake();
  }
}