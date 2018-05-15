#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"
#include "VCAN_camera.h"
#include "arm_math.h"


//关键宏定义

#define Qulv_H 3; //曲率计算采样行数




//特殊数据结构
typedef  struct
{
 int  m_Error;
 int  m_MiddleLine_k;  //中心线斜率
 int  m_MiddleLine_C;    //中心线曲率


}TrailInfo;



//特殊变量列表
extern uint8 g_OriImage[CAMERA_SIZE];  //原始图像数据
extern uint8 g_Image[CAMERA_H][CAMERA_W]; //解压后图像数据

extern uint8 g_MiddleLine[CAMERA_H];       //中心线原始数据
extern TrailInfo g_MiddleLineInfo;           //中心线特征数据



//函数
extern void ImageInit(void);    //图像采集初始化
extern void ImageGet(void);
extern uint8 ImageDeal(void);   //图像采集处理
extern void ImageExtract(void);  //图像解压
extern void GetMiddleInfo(void); //得到中心线的数据


extern float Qulv(float x1,float x2,float x3); //曲率计算函数
extern float Slope(void);







#endif
