/*
 * Copyright (c) 2019 Agility Robotics
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef CASSIE_LINUX_DATA_T_H
#define CASSIE_LINUX_DATA_T_H

#define CASSIE_LINUX_DATA_T_PACKED_LEN 326

#include <stdbool.h>

typedef struct {
  double torque[10];
  short telemetry[9];
} cassie_user_in_t;

typedef struct {
  int type;
  double Kff1;
  double Kff2;
  double motorPositionsDesired[10];
  double motorVelocitiesDesired[10];
} struct0_T;

typedef struct {
  int enabled;
  double velocity[3];
} struct1_T;

typedef struct {
  double q[20];
  double dq[20];
} struct2_T;

typedef struct {
  cassie_user_in_t userInputs;
  struct0_T control;
  struct1_T inekf;
  struct2_T state;
} cassie_linux_data_t;


#ifdef __cplusplus
extern "C" {
#endif

void pack_cassie_linux_data_t(const cassie_linux_data_t *bus, unsigned char *bytes);
void unpack_cassie_linux_data_t(const unsigned char *bytes, cassie_linux_data_t *bus);

#ifdef __cplusplus
}
#endif
#endif // CASSIE_LINUX_DATA_T_H
