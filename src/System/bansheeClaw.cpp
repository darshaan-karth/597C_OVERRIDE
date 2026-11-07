#include "main.h"

void claw_standby() {
  static bool claw_piston_extended = false;

  if (claw_piston_extended) {
    claw_piston_extended = false;
  } else {
    claw_piston_extended = true;
  }

  claw_piston.set(claw_piston_extended);
}

void claw_intake_piston() {
  claw_piston.set(false);
}

void claw_score() {
  clampingMotor.move(0);
  pros::delay(20);
  clampingMotor.move(-127);
}

void claw_intake() {
  pros::delay(20);
  clampingMotor.move(0);
  pros::delay(20);
  clampingMotor.move(127);
}

void claw_stop() {
  clampingMotor.move(0);
}

void bansheeClaw_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_A)) {
    claw_standby();
  }

  if (master.get_digital_new_press(DIGITAL_R1)) {
    claw_intake();
  }

  if (master.get_digital_new_press(DIGITAL_R2)) {
    claw_score();
  }

  if (master.get_digital_new_press(DIGITAL_X)) {
    claw_stop();
  }
}