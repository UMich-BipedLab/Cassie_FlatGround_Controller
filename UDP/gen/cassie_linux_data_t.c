#include "cassie_linux_data_t.h"
#include <stddef.h>
#include <string.h>





void pack_cassie_linux_data_t(const cassie_linux_data_t *bus, unsigned char
  bytes[70])
{
  int i0;
  unsigned char y[40];
  float x[10];
  unsigned char b_y[18];
  short b_x[9];
  float c_x;
  unsigned char c_y[4];
  unsigned char d_y[4];
  unsigned char e_y[4];
  for (i0 = 0; i0 < 10; i0++) {
    x[i0] = (float)bus->userInputs.torque[i0];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)40 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 9; i0++) {
    b_x[i0] = bus->userInputs.telemetry[i0];
  }

  memcpy((void *)&b_y[0], (void *)&b_x[0], (unsigned int)((size_t)18 * sizeof
          (unsigned char)));
  c_x = (float)bus->x;
  memcpy((void *)&c_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->y;
  memcpy((void *)&d_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  c_x = (float)bus->z;
  memcpy((void *)&e_y[0], (void *)&c_x, (unsigned int)((size_t)4 * sizeof
          (unsigned char)));
  for (i0 = 0; i0 < 40; i0++) {
    bytes[i0] = y[i0];
  }

  for (i0 = 0; i0 < 18; i0++) {
    bytes[i0 + 40] = b_y[i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0 + 58] = c_y[i0];
    bytes[i0 + 62] = d_y[i0];
    bytes[i0 + 66] = e_y[i0];
  }
}

void unpack_cassie_linux_data_t(const unsigned char bytes[70],
  cassie_linux_data_t *bus)
{
  int i;
  float y[10];
  unsigned char x[40];
  double t0_torque[10];
  short t0_telemetry[9];
  unsigned char b_x[18];
  float b_y;
  unsigned char c_x[4];
  for (i = 0; i < 40; i++) {
    x[i] = bytes[i];
  }

  memcpy((void *)&y[0], (void *)&x[0], (unsigned int)((size_t)10 * sizeof(float)));
  for (i = 0; i < 10; i++) {
    t0_torque[i] = y[i];
  }

  for (i = 0; i < 18; i++) {
    b_x[i] = bytes[i + 40];
  }

  memcpy((void *)&t0_telemetry[0], (void *)&b_x[0], (unsigned int)((size_t)9 *
          sizeof(short)));
  memcpy(&bus->userInputs.torque[0], &t0_torque[0], 10U * sizeof(double));
  for (i = 0; i < 9; i++) {
    bus->userInputs.telemetry[i] = t0_telemetry[i];
  }

  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 58];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->x = b_y;
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 62];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->y = b_y;
  for (i = 0; i < 4; i++) {
    c_x[i] = bytes[i + 66];
  }

  memcpy((void *)&b_y, (void *)&c_x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->z = b_y;
}
