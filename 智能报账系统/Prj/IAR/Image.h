#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"
#include "VCAN_camera.h"
#include "arm_math.h"


//�ؼ��궨��

#define Qulv_H 3; //���ʼ����������




//�������ݽṹ
typedef  struct
{
 int  m_Error;
 int  m_MiddleLine_k;  //������б��
 int  m_MiddleLine_C;    //����������


}TrailInfo;



//��������б�
extern uint8 g_OriImage[CAMERA_SIZE];  //ԭʼͼ������
extern uint8 g_Image[CAMERA_H][CAMERA_W]; //��ѹ��ͼ������

extern uint8 g_MiddleLine[CAMERA_H];       //������ԭʼ����
extern TrailInfo g_MiddleLineInfo;           //��������������



//����
extern void ImageInit(void);    //ͼ��ɼ���ʼ��
extern void ImageGet(void);
extern uint8 ImageDeal(void);   //ͼ��ɼ�����
extern void ImageExtract(void);  //ͼ���ѹ
extern void GetMiddleInfo(void); //�õ������ߵ�����


extern float Qulv(float x1,float x2,float x3); //���ʼ��㺯��
extern float Slope(void);







#endif
