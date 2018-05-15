
#include "common.h"
#include "include.h"

#define uint unsigned int
#define uchar unsigned char


uint8_t XFS_StopCom[]={0xFD,0X00,0X01,0X02};
uint8_t XFS_SuspendCom[]={0XFD,0X00,0X01,0X03};
uint8_t XFS_RecoverCom[]={0XFD,0X00,0X01,0X04};
uint8_t XFS_ChackCom[]={0XFD,0X00,0X01,0X21};
uint8_t XFS_PowerDownCom[]={0XFD,0X00,0X01,0X88};







void XFS_FrameInfo(uint8_t *HZdata)
{
		uchar Frame_Info[50]; 
    uint  HZ_Length;  
		uint i=0; 
		 HZ_Length =strlen(HZdata);
		 Frame_Info[0] = 0xFD ; 			
		 Frame_Info[1] = 0x00 ; 			
		 Frame_Info[2] = HZ_Length+2; 		
		 Frame_Info[3] = 0x01 ; 					 		 
		 Frame_Info[4] = 0x01;       
 
         memcpy(&Frame_Info[5], HZdata, HZ_Length);
         uart_putbuff(UART4,Frame_Info,HZ_Length+5);
}

void usart2_handler(void)
{
  char str[100];
  UARTn_e uartn = UART2;
  if(UART_S1_REG(UARTN[uartn]) & UART_S1_RDRF_MASK)
  {
    if(uart_querystr (UART2,str,sizeof(str)-1) != 0)                //查询是否接收到字符串
        {
            uart_putstr (UART2, "\n接收到字符串：");                    //发送字符串
            uart_putstr (UART2, (uint8 *)str); 
            XFS_FrameInfo(str);
  }
}
   

}

void main()
{
    char str[100];

    uart_init(UART4,9600);     //初始化串口(由于 printf 函数 所用的端口就是 UART3，已经初始化了，因此此处不需要再初始化)
    uart_init(UART2,115200);
    XFS_FrameInfo("欢迎使用智能报账系统");
    set_vector_handler(UART2_RX_TX_VECTORn,usart2_handler); 
    uart_rx_irq_en (UART2);
    while(1)
    {
      
    }
}


