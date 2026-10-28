#include "main.h"

bool isCascadeLiftGrounded() {
  // Check if the cascade lift is at the ground position using the distance sensor
  return cascadeLiftDistanceSensor.get() <= GROUND_POSITION;
}

void cascadeLift_up() {
  if (!claw_on_standby) {
    return;  // If the claw is not in standby, do not allow the lift to move
  }
  TARGET_POSITION = clamp(TARGET_POSITION + 77.0, GROUND_POSITION, 1016.0);  // Move the target position up by 77.0 mm from the current target position, but not above the maximum height of 1016 mm
  liftPID.target_set(TARGET_POSITION);
  //lift_wait();  // Wait for the lift to reach the target position before allowing further movement
}

void cascadeLift_down() {
  if (!claw_on_standby) {
    return;  // If the claw is not in standby, do not allow the lift to move
  }
  TARGET_POSITION = clamp(TARGET_POSITION - 77.0, GROUND_POSITION, 1016.0);  // Move the target position down by 77.0 mm from the current target position, but not below the ground position
  liftPID.target_set(TARGET_POSITION);
  //lift_wait();  // Wait for the lift to reach the target position before allowing further movement
}

void cascadeLift_ground() {
  TARGET_POSITION = GROUND_POSITION;
  liftPID.target_set(TARGET_POSITION);
  //lift_wait();  // Wait for the lift to reach the ground position before allowing further movement
}

void cascadeLift_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_L1)) {
    cascadeLift_up();
  }

  if (master.get_digital_new_press(DIGITAL_L2)) {
    cascadeLift_down();
  }
}