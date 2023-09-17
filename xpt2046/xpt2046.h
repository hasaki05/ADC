#ifndef _xpt2046_h
#define _xpt2046_h

#include "public.h"
#include <reg52.h>

sbit DOUT=P3^7;
sbit CLK=P3^6;
sbit DIN=P3^4;
sbit CS=P3^5;

u16 xpt2046_read_adc_value(u8 cmd);

#endif