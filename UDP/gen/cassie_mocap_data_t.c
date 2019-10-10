#include "cassie_mocap_data_t.h"
#include <stddef.h>
#include <string.h>





void pack_cassie_mocap_data_t(const cassie_mocap_data_t *bus, unsigned char
  bytes[12])
{
  float x;
  unsigned char y[4];
  unsigned char b_y[4];
  unsigned char c_y[4];
  int i0;
  x = (float)bus->x;
  memcpy((void *)&y[0], (void *)&x, (unsigned int)((size_t)4 * sizeof(unsigned
           char)));
  x = (float)bus->y;
  memcpy((void *)&b_y[0], (void *)&x, (unsigned int)((size_t)4 * sizeof(unsigned
           char)));
  x = (float)bus->z;
  memcpy((void *)&c_y[0], (void *)&x, (unsigned int)((size_t)4 * sizeof(unsigned
           char)));
  for (i0 = 0; i0 < 4; i0++) {
    bytes[i0] = y[i0];
    bytes[i0 + 4] = b_y[i0];
    bytes[i0 + 8] = c_y[i0];
  }
}

void unpack_cassie_mocap_data_t(const unsigned char bytes[12],
  cassie_mocap_data_t *bus)
{
  int i;
  float y;
  unsigned char x[4];
  for (i = 0; i < 4; i++) {
    x[i] = bytes[i];
  }

  memcpy((void *)&y, (void *)&x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->x = y;
  for (i = 0; i < 4; i++) {
    x[i] = bytes[i + 4];
  }

  memcpy((void *)&y, (void *)&x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->y = y;
  for (i = 0; i < 4; i++) {
    x[i] = bytes[i + 8];
  }

  memcpy((void *)&y, (void *)&x[0], (unsigned int)((size_t)1 * sizeof(float)));
  bus->z = y;
}
