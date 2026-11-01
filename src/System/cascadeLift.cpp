#include "main.h"

namespace {
constexpr int32_t maximum_valid_distance_mm = 2000;

bool get_lift_height_mm(double& height_mm) {
  const int32_t distance_mm = cascadeLiftDistanceSensor.get();
  if (distance_mm == PROS_ERR || distance_mm <= 0 ||
      distance_mm > maximum_valid_distance_mm) {
    return false;
  }

  const double displacement = distance_mm - GROUND_POSITION;
  height_mm = Constants::liftDistanceIncreasesAsLiftRises ? displacement : -displacement;
  return true;
}
}  // namespace

bool cascadeLift_initialize() {
  lift_control_enabled = false;
  cascadeLift.move_velocity(0);

  const int32_t ground_distance_mm = cascadeLiftDistanceSensor.get();
  if (ground_distance_mm == PROS_ERR || ground_distance_mm <= 0 ||
      ground_distance_mm > maximum_valid_distance_mm) {
    return false;
  }

  GROUND_POSITION = ground_distance_mm;
  TARGET_POSITION = 0.0;
  liftPID.variables_reset();
  liftPID.target_set(TARGET_POSITION);
  cascadeLift.set_brake_mode(pros::v5::MotorBrake::hold);
  lift_control_enabled = true;
  return true;
}

void cascadeLift_control_step() {
  if (!lift_control_enabled) {
    set_lift(0);
    return;
  }

  double height_mm;
  if (!get_lift_height_mm(height_mm)) {
    lift_control_enabled = false;
    set_lift(0);
    master.rumble("---");
    return;
  }

  height_mm = clamp(height_mm, 0.0, lift_max_height_mm);
  const double error_mm = TARGET_POSITION - height_mm;
  if (std::abs(error_mm) <= lift_position_tolerance_mm) {
    set_lift(0);
    return;
  }

  double velocity_rpm = liftPID.compute(height_mm);
  velocity_rpm = clamp(velocity_rpm, -lift_max_velocity_rpm, lift_max_velocity_rpm);
  if (std::abs(velocity_rpm) < lift_min_velocity_rpm) {
    velocity_rpm = std::copysign(lift_min_velocity_rpm, error_mm);
  }
  set_lift(static_cast<int>(velocity_rpm));
}

bool isCascadeLiftGrounded() {
  double height_mm;
  return lift_control_enabled && get_lift_height_mm(height_mm) &&
         height_mm <= lift_position_tolerance_mm;
}

void cascadeLift_up() {
  TARGET_POSITION = clamp(TARGET_POSITION + lift_step_mm, 0.0, lift_max_height_mm);
  //cascadeLift_control_step();
  cascadeLift.move(127);
  pros::delay(2000);
  cascadeLift.move(0);
}

void cascadeLift_down() {
  TARGET_POSITION = clamp(TARGET_POSITION - lift_step_mm, 0.0, lift_max_height_mm);
  //cascadeLift_control_step();
  cascadeLift.move(-127);
  pros::delay(2000);
  cascadeLift.move(0);
}

void cascadeLift_ground() {
  if (!lift_control_enabled) {
    master.rumble("---");
    return;
  }

  TARGET_POSITION = 0.0;
  liftPID.target_set(TARGET_POSITION);
}

void cascadeLift_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_R1)) {
    cascadeLift_up();
  }

  if (master.get_digital_new_press(DIGITAL_R2)) {
    cascadeLift_down();
  }
}
