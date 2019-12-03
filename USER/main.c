/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��˫CANͨѶʵ�飬�����������֣���ӻ�����ABCD         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "can.h"

__IO uint32_t flag = 0xff;		 //���ڱ�־�Ƿ���յ����ݣ����жϺ����и�ֵ
CanTxMsg TxMessage;			     //���ͻ�����
CanRxMsg RxMessage;				 //���ջ�����
/* 
 * ��������main
 * ����  : "����"��������
 * ����  ����
 * ���  : ��
 */
 
void my_delay_ms(uint16_t time)
{
	uint16_t i = 0;
	while(time--)
	{
		i = 12000;
		while(i--);
	}
	 
}
 
int main(void)
{
	/*��ʼ������ģ��*/
 	USART1_Config();
 			
 	/* ����CANģ�� */
	CAN_Config();  

	printf( "\r\n***** ����һ��˫CANͨѶʵ��******** \r\n");
	printf( "\r\n ���� �������ˡ� �ķ�����Ϣ�� \r\n");

	/*����Ҫͨ��CAN���͵���Ϣ*/
	 CAN_SetMsg();

	 printf("\r\n��Ҫ���͵ı�������Ϊ��\r\n");
	 printf("\r\n ��չID��ExtId��0x%x",TxMessage.ExtId);
	 printf("\r\n ���ݶε�����:Data[0]=0x%x ��Data[1]=0x%x \r\n",TxMessage.Data[0],TxMessage.Data[1]);
	
	 /*������Ϣ ��ABCD��**/
	 CAN_Transmit(CAN1, &TxMessage);

	 		
	// while( flag == 0xff );					//flag =0 ,success

//	printf( "\r\n �ɹ����յ����ӻ������ص�����\r\n ");	
//	printf("\r\n ���յ��ı���Ϊ��\r\n"); 
//	printf("\r\n ��չID��ExtId��0x%x",RxMessage.ExtId);	 
//	printf("\r\n ���ݶε�����:Data[0]= 0x%x ��Data[1]=0x%x \r\n",RxMessage.Data[0],RxMessage.Data[1]);

	while(1)
	{
		my_delay_ms(1000);
		CAN_Transmit(CAN1, &TxMessage);
	};
	
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


