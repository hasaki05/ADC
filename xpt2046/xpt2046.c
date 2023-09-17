#include "xpt2046.h"
#include "intrins.h"

void xpt2046_write_data(u8 dat)
{
	u8 i;
	
	CLK=0;
	_nop_();
	for(i=0;i<8;i++)
	{
		DIN=dat>>7;
		dat<<=1;
		CLK=0;
		_nop_();
		CLK=0;
	}
}

u16 xpt2046_read_data(void)
{
	u8 i;
	u16 dat=0;
	
	CLK=0;
	_nop_();
	for(i=0;i<12;i++)
	{
		dat <<=1;
		CLK=1;
		_nop_();
		CLK=0;
		_nop_();
		dat |=DOUT;
	}
	return dat;
}

u16 xpt2046_read_adc_value(u8 cmd)
{
	u16 adc_value=0;
	
	CLK=0;
	CS=0;
	xpt2046_write_data(cmd);
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	CLK=1;
	_nop_();
	CLK=0;
	_nop_();
	adc_value=xpt2046_read_data();
	CS=1;
	return adc_value;
}