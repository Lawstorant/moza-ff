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
 * Do not search for autocenter. Set SPRING effect as autocenter
*/
#define PIDFF_QUIRK_AUTOCENTER_WITH_SPRING BIT(2)

int hid_pidff_init(struct hid_device *hid);
int hid_pidff_init_with_quirks(struct hid_device *hid, unsigned quirks);

#endif
