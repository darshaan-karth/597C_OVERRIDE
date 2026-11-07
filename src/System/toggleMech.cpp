#include "main.h"

void toggle_mech() {
  toggle_mech_state = !toggle_mech_state;
}

bool isToggleColorMatching(){
    pros::c::optical_rgb_s_t RGB_values;
    RGB_values = opticalSensor.get_rgb();

    if (Constants::isBlue){
        if (RGB_values.red < 100 && RGB_values.green < 100 && RGB_values.blue > 100){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (RGB_values.red > 100 && RGB_values.green < 100 && RGB_values.blue < 100){
            return true;
        }
        else{
            return false;
        }
    }
}

void toggleMech_opcontrol() {
  if (master.get_digital_new_press(DIGITAL_DOWN)) {
    toggle_mech();
  }
}