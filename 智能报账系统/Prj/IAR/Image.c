#include "Image.h"

void ImageInit()
{
   camera_init(g_OriImage);

}

void ImageGet()
{
  camera_get_img();

}


void ImageExtract()
{
  img_extract(g_Image, g_OriImage, CAMERA_SIZE); 
}


uint8 ImageDeal();
{
	int k;
	int i;
	int FindStart=(int)CAMERA_W/2;
	int Left;
	int Right;

	//��ʼ�������һ������������

	for(k=(int)CAMERA_H-1;k>=0;k--)
		{
		  //��ʼÿһ�е�ɨ��Ѱ����߽�
		  
		  Left=0;
		  
		  for(i=FindStart;i>=0;i--)
		  	{

				if(g_Image[k][i]==1)
					Left=i;
				else
					continue;
                  
		  	}   //end of for(i=FindStart;i>=0;i--)

            //��ʼѰ��ÿһ�е��ұ߽�

			Right=CAMERA_W;

			for(i=FindStart;i<CAMERA_W;i++)
			{
			   if(g_Image[k][i]==1)
			   	Right=i;
			   else
			   	continue;
			   
			}  //end of for(i=FindStart;i<CAMERA_W;i++)

            g_MiddleLine[k]=(unit8)(Left+Right)/2;
			FindStart=g_MiddleLine[k];
			
		}//end of for(k=(int)CAMERA_H-1;k>=0;k--)

		return 1;

}



void float Qulv(float x1, float x2, float x3)
{
   float S;
   float *A,*B,*C;
   float out;
   
   S=((x2-x1)*-(x3-x1)*3)/2;  //ȱ��һ�������ֵ�㷨

    arm_sqrt_f32((x2-x1)*(x2-x1)+Qulv_H*Qulv_H,&A);
    arm_sqrt_f32((x3-x2)*(x3-x2)+Qulv_H*Qulv_H,&B);
    arm_sqrt_f32((x3-x1)*(x3-x1)+Qulv_H*Qulv_H,&C);

  	out=4*S/(A*B*C);

	return out;
}

void Slope(void)
{  
int i;
int k;
int counter=0;
int UpSigma=0;
int DownSigma=0;

//��ʼ������С���˷�
 
  

}

void GetMiddleInfo(void)
{
    int Count;
	int i;

	//��ʼ���������ߵ����

	for(i=0;i<sizeof(g_MiddleLine)/sizeof(uint8),i++)
		{
		
		Count+=g_MiddleLine[i];
		
		}  //end of for(i=0;i<sizeof(g_MiddleLine)/sizeof(uint8),i++)

		g_MiddleLineInfo.m_Error=(Count/(sizeof(g_MiddleLine)/sizeof(uint8)))-CAMERA_W/2;

		//��ʼ���������ߵ�б��


		//��ʼ���������ߵ�����
		g_MiddleLineInfo.m_MiddleLine_C=Qulv((float)g_MiddleLine[CAMERA_H],(float)g_MiddleLine[CAMERA_H-Qulv_H], float g_MiddleLine[CAMERA_H-Qulv_H*2]);
		

}



















