#include <Arduino.h>
#include "include/config.h"

// Environment configuration

// Stick control
boolean stickCtrl = false;
// External radio control
boolean radioEnabled = true; 
// Manual microswitch control?
boolean manual = true;
// Full automatic mode
boolean fullAuto = false;
// torque converter lock
boolean tccLock = true;
// gear evaluation to determine real running gear, this prevents shifts if previous shift has not completed
boolean evalGear = true;


// Do we have TPS?
boolean tpsSensor = true;
// Do we have boost sensor?
boolean boostSensor = true;
// Exhaust pressure sensor
boolean exhaustPresSensor = false;

// Old style w124 speed meter controlling
boolean w124speedo = true;
// Old style w124 rpm meter pwm
boolean w124rpm = true;
// Boost control
boolean boostLimit = true;
// control fuel pumps (turn off below certain rpm)
boolean fuelPumpControl = false;
// Initial state of fuel pumps
boolean fuelPumps = true;
// Initial state of horn
boolean horn = false;

// calculate vehicleSpeed from engine RPM
boolean rpmSpeed = true; 
// calculate vehicleSpeed from diff abs sensor
boolean diffSpeed = true; 

// Adaptive pressure
boolean adaptive = false;
// Battery monitor
boolean batteryMonitor = true;

// Default power mode
boolean truePower = false;
// Output to serial console
boolean debugEnabled = true;
// Datalogging (enabling this disables debug)
boolean datalogger = true;

struct ConfigParam readConfig()
{
  struct ConfigParam config;
  config.boostMax = 700; // boost sensor max kpa
  config.boostDrop = 50; // kpa to drop on shifts
  config.boostSpring = 120; // kpa for wastegate spring pressure
  config.fuelMaxRPM = 2000; // RPM limit to turn on fuel pumps
  config.maxRPM = 7000; // Max engine RPM
  config.tireWidth = 195;
  config.tireProfile = 65;
  config.tireInches = 15;
  config.diffRatio = 3.27;
  config.rearDiffTeeth = 29; // number of teeth in diff
  config.nextShiftDelay = 2000; // ms. to wait before next shift to avoid accidental overshifting.
  config.maxSlip = 0.5; // Maximum allowed slip before error
  config.stallSpeed = 2200; // torque converter stall speed
  config.batteryLimit = 11500; // battery voltage limit in 11.5v
  config.firstTccGear = 5; // first gear when tcc is used.
  config.triggerWheelTeeth = 6; // number of teeth in trigger wheel for RPM calculation
  config.tpsAgre = 2; // 1-10 how aggressive slope tps has
  return config;
}

// End of environment conf

// Do not change any of these.
// Default for blocking gear switches (do not change.)
boolean shiftBlocker = false;
boolean shiftPending = false;
// everything starts with ignition (do not change.)
boolean ignition = true;
boolean carRunning = false;
byte page = 1; // first page to show in UI
boolean drive = false;
// fault mode for speed sensors
boolean speedFault = false; 
// fault mode for battery fault
boolean batteryFault = false;
// fault mode for excess slip
boolean slipFault = false;