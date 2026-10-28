#include "main.h"

// Intake Motor Control Toggle Function
void intakeMotor_toggle() {
  static bool intake_on = false;

  if (intake_on) {
    intake.move(0);
    intake_on = false;
  } else {
    cascadeLift_ground();  // Move the cascade lift to the ground position before starting the intake
    claw_intake();  // Move the claw to the intake position before starting the intake
    pros::delay(500);  // Wait for the claw to reach the intake position before starting the intake
    intake.move(127);
    intake_on = true;
  }
}

// Intake Piston Control Toggle Function
void intakePiston_toggle() {
  static bool piston_extended = false;

  if (piston_extended) {
    piston_extended = false;
  } else {
    piston_extended = true;
  }

  intake_piston.set(piston_extended);
}

// Intake Opcontrol Function
void intake_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_L1)) {
    intakeMotor_toggle();
  }

  if (master.get_digital_new_press(DIGITAL_L2)) {
    intakePiston_toggle();
  }
}