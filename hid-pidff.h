/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __HID_PIDFF_H
#define __HID_PIDFF_H

/* PIDFF Quirks to solve issues with certain devices */

/*
 * Substitute 0 length with 0xffff to resolve issues with
 * infinite effects coming from windows API
*/
#define PIDFF_QUIRK_FIX_0_INFINITE_LENGTH BIT(0)

/*
 * Ignore direction for spring/damping/friction/inertia effects
 * and always set 16384
*/
#define PIDFF_QUIRK_FIX_WHEEL_DIRECTION BIT(1)

/*
 * Always set a value > 0 for PERIODIC envelope attack and fade level
*/
#define PIDFF_QUIRK_FIX_PERIODIC_ENVELOPE BIT(2)

/*
 * Treat 0 magnitude in periodic effects as max
 * This works similiar to the infinite length quirk
*/
#define PIDFF_QUIRK_FIX_0_PERIODIC_MAGNITUDE BIT(3)

int hid_pidff_init(struct hid_device *hid);
int hid_pidff_init_with_quirks(struct hid_device *hid, unsigned quirks);

#endif
