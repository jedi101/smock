/**
 * \file usb_structs.cpp
 * \brief Data structures defining the USB keyboard and serial device.
 *
 * Copyright (c) 2009-2015 Texas Instruments Incorporated.  All rights reserved.
 * Software License Agreement
 *
 * Texas Instruments (TI) is supplying this software for use solely and
 * exclusively on TI's microcontroller products. The software is owned by
 * TI and/or its suppliers, and is protected under applicable copyright
 * laws. You may not combine this software with "viral" open-source
 * software in order to form a larger program.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
 * NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
 * NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
 * CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * This is part of revision 2.1.1.71 of the DK-TM4C129X Firmware Package.
 */

#include <stdint.h>
#include <stdbool.h>
#include "usblib/usblib.h"
#include "usblib/usbhid.h"
#include "usblib/usb-ids.h"
#include "usblib/device/usbdevice.h"
#include "usblib/device/usbdcomp.h"
#include "usblib/device/usbdhid.h"
#include "usblib/device/usbdhidkeyb.h"
#include "usblib/usbcdc.h"
#include "usb_structs.h"
#include "usblib/usbcdc.h"

/**
 * \var uint32_t g_ui32USBFlags
 *
 * Flags for Keyboard and Mouse shared states.
 */
volatile uint32_t g_ui32USBFlags;

/**
 * \var const uint8_t g_pui8LangDescriptor[]
 *
 * The languages supported by this device.
 */
const uint8_t g_pui8LangDescriptor[] = {
    4,
    USB_DTYPE_STRING,
    USBShort(USB_LANG_GERMAN)
};

/**
 * \var const uint8_t g_pui8ManufacturerString[]
 *
 * The manufacturer string.
 */
const uint8_t g_pui8ManufacturerString[] = {
    (17 + 1) * 2,
    USB_DTYPE_STRING,
    'T', 0, 'e', 0, 'x', 0, 'a', 0, 's', 0, ' ', 0, 'I', 0, 'n', 0, 's', 0,
    't', 0, 'r', 0, 'u', 0, 'm', 0, 'e', 0, 'n', 0, 't', 0, 's', 0,
};

/**
 * \var const uint8_t g_pui8ProductString[]
 *
 * The product string.
 */
const uint8_t g_pui8ProductString[] = {
    (12 + 1) * 2,
    USB_DTYPE_STRING,
    'S', 0, 'm', 0, 'o', 0, 'c', 0, 'k', 0, ' ', 0, 'D', 0, 'e', 0, 'v', 0,
    'i', 0, 'c', 0, 'e', 0,
};

/**
 * \var const uint8_t g_pui8SerialNumberString[]
 *
 * The serial number string.
 */
const uint8_t g_pui8SerialNumberString[] = {
    (8 + 1) * 2,
    USB_DTYPE_STRING,
    '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0
};

/**
 * \var const uint8_t g_pui8ControlInterfaceString[]
 *
 * The control interface description string.
 */
const uint8_t g_pui8ControlInterfaceString[] = {
    2 + (21 * 2),
    USB_DTYPE_STRING,
    'A', 0, 'C', 0, 'M', 0, ' ', 0, 'C', 0, 'o', 0, 'n', 0, 't', 0,
    'r', 0, 'o', 0, 'l', 0, ' ', 0, 'I', 0, 'n', 0, 't', 0, 'e', 0,
    'r', 0, 'f', 0, 'a', 0, 'c', 0, 'e', 0
};

/**
 * \var const uint8_t g_pui8ConfigString[]
 *
 * The configuration description string.
 */
const uint8_t g_pui8ConfigString[] = {
    2 + (26 * 2),
    USB_DTYPE_STRING,
    'S', 0, 'e', 0, 'l', 0, 'f', 0, ' ', 0, 'P', 0, 'o', 0, 'w', 0,
    'e', 0, 'r', 0, 'e', 0, 'd', 0, ' ', 0, 'C', 0, 'o', 0, 'n', 0,
    'f', 0, 'i', 0, 'g', 0, 'u', 0, 'r', 0, 'a', 0, 't', 0, 'i', 0,
    'o', 0, 'n', 0
};

/**
 * \var const uint8_t * const g_pui8StringDescriptors[]
 *
 * The descriptor string table which describes the usb device,
 */
const uint8_t *const g_pui8StringDescriptors[] = {
     g_pui8LangDescriptor,
     g_pui8ManufacturerString,
     g_pui8ProductString,
     g_pui8SerialNumberString,
     g_pui8ControlInterfaceString,
     g_pui8ConfigString
};

/**
 * \var const unsigned int NUM_STRING_DESCRIPTORS
 *
 * Size of the string descriptor.
 */
const unsigned int NUM_STRING_DESCRIPTORS = (sizeof(g_pui8StringDescriptors) / sizeof(uint8_t *));

