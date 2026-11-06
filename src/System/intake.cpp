#include "main.h"
#include "pros/misc.h"

// Intake Motor Control In Function
void intakeMotor_in() {
  static bool intake_on = false;

  if (intake_on) {
    intake.move(0);
    intake_on = false;
  } else {
    cascadeLift_ground();  // Move the cascade lift to the ground position before starting the intake
    claw_intake_piston();  // Move the claw to the intake position before starting the intake
    pros::delay(20);      // Wait for the cascade lift to reach the ground position
    claw_intake();         // Move the claw to the intake position before starting the intake
    pros::delay(500);      // Wait for the claw to reach the intake position before starting the intake
    intake.move(127);
    intake_on = true;
  }
}

// Intake Motor Control Out Function
void intakeMotor_out() {
  static bool intake_on = false;

  if (intake_on) {
    intake.move(0);
    intake_on = false;
  } else {
    intake.move(-127);
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
  if (master.get_digital_new_press(DIGITAL_RIGHT)) {
    intakeMotor_in();
  }

  if (master.get_digital_new_press(DIGITAL_LEFT)) {
    intakeMotor_out();  
  }

  if (master.get_digital_new_press(DIGITAL_UP)) {
    intakePiston_toggle();
  }
}