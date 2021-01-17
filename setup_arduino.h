#ifndef SETUP_ARDUINO_H_OIVLOHCL
#define SETUP_ARDUINO_H_OIVLOHCL

#include "pinout_arduino.h"

#include "CommunicationBackend.h"
#include "GamecubeBackend.h"
#include "InputMode.h"
#include "Melee20Button.h"
#include "socd.h"
#include "state.h"

CommunicationBackend *gCurrentBackend;
InputMode *gCurrentMode;
state::InputState gInputState;

void initialise() {
  /* Only GameCube backend is available for Arduinos without native USB support.
     However, you can still use keyboard modes. */
  gCurrentBackend = new GamecubeBackend(125, pinout::GCC_DATA);

  /* Always start in Melee mode. Must set mode only after initialising the
     backend. */
  gCurrentMode =
      new Melee20Button(socd::SOCD_2IP_NO_REAC, gInputState, gCurrentBackend);

  // Uncomment the following to enable input viewer when USB and GameCube
  // cable are both connected.
  // Serial.begin(115200, SERIAL_8N1);
}

#endif /* end of include guard: SETUP_ARDUINO_H_OIVLOHCL */
