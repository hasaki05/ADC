#include "public.h"
#include "Digitron.h"
#include "xpt2046.h"

void main()
{	
	u16 adc_value=0;
	u8 adc_buf[4];

	while(1)
	{				
		adc_value=xpt2046_read_adc_value(0xA4);
		adc_buf[0]=gsmg_code[adc_value/1000];
		adc_buf[1]=gsmg_code[adc_value%1000/100];
		adc_buf[2]=gsmg_code[adc_value%1000%100/10];
		adc_buf[3]=gsmg_code[adc_value%1000%100%10];
		smg_display(adc_buf,5);		
	}		
}
