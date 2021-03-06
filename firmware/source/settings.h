/******************************************************************************
* Name: settings.h
* Desc: Constants used by Andrew P. are included here.
* Date: 2012-06-26
* Author: pullin
******************************************************************************/
#ifndef __SETTINGS_H
#define __SETTINGS_H


//#error "REQUIRED: Review and set radio channel & network parameters in firmware/source/settings.h  , then comment out this line."
/////// Radio settings ///////
// Motile address ; all MRI robots were shipped with this configuration
#define RADIO_CHANNEL		0x0D
#define RADIO_SRC_ADDR 		0x2072
#define RADIO_SRC_PAN_ID  		0x2070
//Hard-coded destination address, must match basestation or XBee addr
#define RADIO_DST_ADDR		0x2071

// Radio queue sizes
#define RADIO_RXPQ_MAX_SIZE 	16
#define RADIO_TXPQ_MAX_SIZE	16

/////// System Service settings ///////
#define SYS_SERVICE_T1 // For legCtrl, hall
#define SYS_SERVICE_T2 // For hall, 400 Hz tick counter
#define SYS_SERVICE_T5 // For steering, telemetry

/////// Configuration options ///////
//Configure project-wide for Hall Sensor operation
//#define HALL_SENSORS

#endif //__SETTINGS_H
