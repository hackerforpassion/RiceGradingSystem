#include<stdio.h>
#include<math.h>
#include <stdio.h>    
#include <stdlib.h> 
#include <stdint.h>   
#include <string.h> 
#include <unistd.h>  
#include <fcntl.h>    
#include <errno.h>    
#include <termios.h>  
#include <sys/ioctl.h>
#include <getopt.h>

void main()
{

	char character;

	float gauss_gradient(float a[ ][3],int row,int column,int count);

	FILE  *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8,*fp9,*fp10,*fp10a,*fp10b,*fp11,*fp12,*fp13,*fp14,*fp15,*fp16,*fp17,*fp18,*fp19,*fp20,*fp21,*fp22,*fp23,*fp24,*fp24a,*fp25,*fp26,*fp27,*fp28,*fp29,*fp29a,*fp29b,*fp30,*fp31,*fp32,*fp33,*fp34,*fp35,*fp36,*fp37;
	int i,j,array[96][149][3],plane=0,row,red[96][149],green[96][149],blue[96][149],p,q,k,l,s,t,count_value,
	theta_in_degrees_approx[99][153],zero_padded_theta[99][153],m,n,array_for_non_maximal_suppression[3][3],value=0,column,z,count_freq,count_freq_value[97],count_next,count_before,lower_cut_off_value,upper_cut_off_value,pixel_count,count_f[100]={0},j1,j2,j3,adt_30,ir20,a_ponni,asd_kar2;
	int briyani_rice_x,j13,kponni,kulsar_hybrid,mattai2,p_ponni,zeera,wponni,ponni_kurunai,md_thoppi,kdx_sb,kdx_samba,kdx_mo,k_kar_idly,ppt,r=0,g=0,b=0,min;

	static int u=1,v=1,u1=1,v1=1,u2=1,v2=1,u3=1,v3=1,ks=2,ls=0,constant,tex=0;

	float grayscale[96][149],zero_array[99][153],zero_array1[97][151],dummy[99][153],dummy_for_gradient_x_direc[99][153],dummy_for_gradient_y_direc[99][153],dummy_for_gradient_x_direc_mod[99][153],dummy_for_gradient_y_direc_mod[99][153],func_pass_array[3][3],func_pass_array_gradient_x_direc[3][3],func_pass_array_gradient_y_direc[3][3],mid_pixel,mid_pixel_gradient_x_direc,mid_pixel_gradient_y_direc,theta[99][153],theta_in_degrees[99][153],magnitude[99][153],magnitude_for_suppression[3][3],magnitude_after_suppression[99][153],zero_padded_magnitude[99][153],dummy_for_suppression[3][3],array_for_edge_linking[14647],temp=0,lower_threshold,higher_threshold,matrix_after_applying_lower_threshold[99][153],matrix_after_applying_higher_threshold[99][153],matrix_after_applying_cut_off[99][153],last_value,intensity=0;

	double perimeter,major_axis_length,minor_axis_length,minor_axis_length_value,area,area_value,saturation,ab=0,hue=0,
	feret_diameter,features[8],standard_features[10][5]={{5.390000,1.347500,0.827606,28.980522,9.229466},{1.001000,0.250250,0.153698,0.185627,0.059117},{0.686000,0.171500,0.105332,0.059746,0.019028}};

 


	fp2=fopen("./files/edge_linking/results/singlerice_normal_req_3_intensity_3_plane_column_rgb.doc","w+");
	fp3=fopen("./files/edge_linking/results/red_values.doc","w+");
	fp4=fopen("./files/edge_linking/results/green_values.doc","w+");
	fp5=fopen("./files/edge_linking/results/blue_values.doc","w+");
	fp6=fopen("./files/edge_linking/results/grayscale_values.doc","w+");
	fp7=fopen("./files/edge_linking/results/array_of_zeroes.doc","w+");
	fp8=fopen("./files/edge_linking/results/dummy_array_of_zeroes.doc","w+");
	fp9=fopen("./files/edge_linking/results/zero_padded_image.doc","w+");
	fp10=fopen("./files/edge_linking/results/gaussian_mask_applied_image.doc","w+");
	fp10a=fopen("./files/edge_linking/results/x.doc","w+");
	fp10b=fopen("./files/edge_linking/results/y.doc","w+");
	fp11=fopen("./files/edge_linking/results/values_passed_to_function.doc","w+");
	fp12=fopen("./files/edge_linking/results/middle_pixel_values.doc","w+");
	fp13=fopen("./files/edge_linking/results/values_passed_to_func_to_find_gradient_x_direc.doc","w+");
	fp14=fopen("./files/edge_linking/results/middle_pixel_values_gradient_horizontal.doc","w+");
	fp15=fopen("./files/edge_linking/results/dummy_array_for_gradient_horizontal.doc","w+");
	fp16=fopen("./files/edge_linking/results/values_passed_to_func_to_find_gradient_y_direc.doc","w+");
	fp17=fopen("./files/edge_linking/results/middle_pixel_values_gradient_vertical.doc","w+");
	fp18=fopen("./files/edge_linking/results/dummy_array_for_gradient_vertical.doc","w+");
	fp19=fopen("./files/edge_linking/results/magnitude_of_G(x).doc","w+");
	fp20=fopen("./files/edge_linking/results/magnitude_of_G(y).doc","w+");
	fp21=fopen("./files/edge_linking/results/Magnitude.doc","w+");
	fp22=fopen("./files/edge_linking/results/angle.doc","w+");
	fp23=fopen("./files/edge_linking/results/approximated_angles.doc","w+");
	fp24=fopen("./files/edge_linking/results/zero_padded_approximated_angles_array.doc","w+");
	fp24a=fopen("./files/edge_linking/results/zero_padded_magnitude_values.doc","w+");
	fp25=fopen("./files/edge_linking/results/Angle_values_sent_to_func_non_maximal_suppression.doc","w+");
	fp26=fopen("./files/edge_linking/results/Magnitude_values_sent_for_non_maximal_suppression.doc","w+");
	fp27=fopen("./files/edge_linking/results/Magnitude_values_after_non_maximal_suppression.doc","w+");
	fp28=fopen("./files/edge_linking/results/array_of_mag_for_suppression.doc","w+");
	fp29=fopen("./files/edge_linking/results/ascendingorder_values_of_magnitude_after_suppression.doc","w+");
	fp29a=fopen("./files/edge_linking/results/count_of_value_lying_in_the_range.doc","w+");
	fp29b=fopen("./files/edge_linking/results/lower_and_higher_threshold_values.doc","w+");
	fp30=fopen("./files/edge_linking/results/matrix_after_applying_lower_threshold.doc","w+");
	fp31=fopen("./files/edge_linking/results/matrix_after_applying_higher_threshold.doc","w+");
	fp32=fopen("./files/edge_linking/results/matrixcontaining_freqofmag_afterapplying_higherthresh.doc","w+");
	fp33=fopen("./files/edge_linking/results/lower_and_upper_cut_off_values_for_edge_linking.doc","w+");
	fp34=fopen("./files/edge_linking/results/matrix_containing_edgeofrice_afterapplying_uppercutoff.doc","w+");
	fp35=fopen("./files/edge_linking/results/matrix_containing_edge_of_rice.doc","w+");
	fp36=fopen("./files/edge_linking/results/matrix_containing_edge_of_rice_same_intensity.doc","w+");
	fp37=fopen("./files/edge_linking/results/features_idly_array_gp.doc","w+");

	printf("\n New Sample or testing ?? \n");
	printf("\n Press 'N' for New Sample or 'T' for Testing \n");
	scanf("%c",&character);

	system("./imcapture");
	system("./savebmps");
	fp1=fopen("./files/img.bmp","r+");

	// To obtain RGB planes separately

	row=1;

	for(k=0;k<3;k++)
	{
		fprintf(fp2," \n plane %d \n",plane);
		plane++;

		for(i=0;i<96;i++)
		{
			fprintf(fp2," \n Row %d\n",row);

			if(plane==1)
			fprintf(fp3," \n Row %d\n",row);
			else if(plane==2)
			fprintf(fp4," \n Row %d\n",row);

			else if(plane==3)
			fprintf(fp5," \n Row %d\n",row);

			row++;
			if(row==97)
			row=1;

			for(j=0;j<149;j++)
			{
				array[i][j][k]=getc(fp1);
				fprintf(fp2," %d \t",array[i][j][k]);
				tex+=array[i][j][k];
				if(plane==1)
				{
				red[i][j]=array[i][j][k];
				fprintf(fp3," %d \t",red[i][j]);
				}

				else if(plane==2)
				{
				green[i][j]=array[i][j][k];
				fprintf(fp4," %d \t",green[i][j]);
				}

				else if(plane==3)
				{
				blue[i][j]=array[i][j][k];
				fprintf(fp5," %d \t",blue[i][j]);
				}

			}
		}
		
		if(array[i][j][k]==EOF)
		printf(" EOF = %d ", array[i][j][k]);
	}

	// To obtain grayscale image from RGB image

	row=1;
	
	for(i=0;i<96;i++)
	{
		fprintf(fp6,"\n \n Row %d \n \n",row);
		row++;

		for(j=0;j<149;j++)
		{
			grayscale[i][j]=(0.2989*red[i][j])+(0.5870*green[i][j])+(0.1140*blue[i][j]);
			fprintf(fp6,"%f \t",grayscale[i][j]);
		}
	}

	// Padding of zeroes to the grayscale image to alter the size of image to a value divisible by 3

	row=1;
	for(i=0;i<99;i++)
	{
		fprintf(fp7,"\n \n Row %d \n \n",row);
		fprintf(fp8,"\n \n Row %d \n \n",row);
		row++;

		for(j=0;j<153;j++)
		{
			zero_array[i][j]=0;
			dummy[i][j]=0;
			fprintf(fp7,"%f \t",zero_array[i][j]);
			fprintf(fp8,"%f \t",dummy[i][j]);
		}
		
		fprintf(fp7,"\n");
		fprintf(fp8,"\n");
	}

	for(i=0;i<96;i++)
	{
		for(j=0;j<149;j++)
		{
			dummy[i+2][j+2]=zero_array[i+2][j+2]+grayscale[i][j];
		}
	}

	row=1;
	for(i=0;i<99;i++)
	{
		fprintf(fp9,"\n \n Row %d \n \n",row);
		row++;
		
		for(j=0;j<153;j++)
		{
			fprintf(fp9,"%f \t",dummy[i][j]);
		}
		
		fprintf(fp9,"\n");
	}

	// Applying gaussian mask

	count_value=1;
	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
			s=0;
			t=0;

			for(k=i;k<i+3;k++)
			{
				for(l=j;l<j+3;l++)
				{
					func_pass_array[s][t]=dummy[k][l];
					fprintf(fp11,"%f \t",func_pass_array[s][t]);
					t++;
				}

				fprintf(fp11,"\n \n \n");
				s++;
				t=0;
			}

			mid_pixel=gauss_gradient(func_pass_array,3,3,count_value);
			fprintf(fp12,"%f \t",mid_pixel);
			dummy[u][v]=mid_pixel;

			if(v==151)
			{
				u++;
				v=1;
			}

			else
			{
				v++;
			}
		}
	}
	
	row=0;

	for(p=0;p<99;p++)
	{
		fprintf(fp10,"\n \n Row %d \n \n",row);
		row++;

		for(q=0;q<153;q++)
		{
			dummy_for_gradient_x_direc[p][q]=dummy[p][q];
			dummy_for_gradient_y_direc[p][q]=dummy[p][q];
			fprintf(fp10,"%f \t",dummy[p][q]);
			fprintf(fp10a,"%f \t",dummy_for_gradient_x_direc[p][q]);
			fprintf(fp10b,"%f \t",dummy_for_gradient_y_direc[p][q]);
		}
		
			fprintf(fp10,"\n");
			fprintf(fp10a,"\n");
			fprintf(fp10b,"\n");
	}

	// To find G(x)

	count_value=2;
	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
			s=0;
			t=0;

			for(k=i;k<i+3;k++)
			{
				for(l=j;l<j+3;l++)
				{
					func_pass_array_gradient_x_direc[s][t]=dummy_for_gradient_x_direc[k][l];
					fprintf(fp13,"%f \t",func_pass_array_gradient_x_direc[s][t]);
					t++;
				}
				
				fprintf(fp13,"\n \n");
				s++;
				t=0;
			}

			mid_pixel_gradient_x_direc=gauss_gradient(func_pass_array_gradient_x_direc,3,3,count_value);
			fprintf(fp14,"%f \t",(mid_pixel_gradient_x_direc*16));
			dummy_for_gradient_x_direc[u1][v1]=mid_pixel_gradient_x_direc;

			if(v1==151)
			{
				u1++;
				v1=1;
			}

			else
			{
				v1++;
			}

		}
	}

	row=1;
	
	for(p=0;p<99;p++)
	{
		fprintf(fp15,"\n \n Row %d \n \n",row);
		row++;

		for(q=0;q<153;q++)
		{	
			fprintf(fp15,"%f \t",dummy_for_gradient_x_direc[p][q]);
		}
		
		fprintf(fp15,"\n");
	}

	// To find G(y)

	count_value=3;
	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
			s=0;
			t=0;

			for(k=i;k<i+3;k++)
			{
				for(l=j;l<j+3;l++)
				{
					func_pass_array_gradient_y_direc[s][t]=dummy_for_gradient_y_direc[k][l];
					fprintf(fp16,"%f \t",func_pass_array_gradient_y_direc[s][t]);
					t++;
				}

				fprintf(fp16,"\n \n");
				s++;
				t=0;
			}

			mid_pixel_gradient_y_direc=gauss_gradient(func_pass_array_gradient_y_direc,3,3,count_value);
			fprintf(fp17,"%f \t",(mid_pixel_gradient_y_direc*16));
			dummy_for_gradient_y_direc[u2][v2]=mid_pixel_gradient_y_direc;

			if(v2==151)
			{
				u2++;
				v2=1;
			}

			else
			{
				v2++;
			}

		}
	}

	row=1;
	for(p=0;p<99;p++)
	{
		fprintf(fp18,"\n \n Row %d \n \n",row);
		row++;

		for(q=0;q<153;q++)
		{
			fprintf(fp18,"%f \t",dummy_for_gradient_y_direc[p][q]);
		}
			
		fprintf(fp18,"\n");
	}

	// To find modulus of G(x) values

	for(i=1;i<98;i++) // 'i' and 'j' start from '1' and end at '98' and '152' resp to eliminate the zero padding in the 1st and last rows
	{
		for(j=1;j<152;j++)
		{

			if(((dummy_for_gradient_x_direc[i][j])>0)||((dummy_for_gradient_x_direc[i][j])==0))
			{
				dummy_for_gradient_x_direc_mod[i][j]=(dummy_for_gradient_x_direc[i][j]);
				fprintf(fp19,"%f \t",dummy_for_gradient_x_direc_mod[i][j]);
			}

			else if((dummy_for_gradient_x_direc[i][j])<0)
			{
				dummy_for_gradient_x_direc_mod[i][j]=-(dummy_for_gradient_x_direc[i][j]);
				fprintf(fp19,"%f \t",dummy_for_gradient_x_direc_mod[i][j]);
			}

		}
	}

	// To find modulus of G(y) values

	for(i=1;i<98;i++)  // 'i' and 'j' start from '1' and end at '98' and '152' resp to eliminate the zero padding in the 1st and last rows
	{
		for(j=1;j<152;j++)
		{

			if(((dummy_for_gradient_y_direc[i][j])>0)||((dummy_for_gradient_x_direc[i][j])==0))
			{
				dummy_for_gradient_y_direc_mod[i][j]=(dummy_for_gradient_y_direc[i][j]);
				fprintf(fp20,"%f \t",dummy_for_gradient_y_direc_mod[i][j]);
			}

			else if((dummy_for_gradient_y_direc[i][j])<0)
			{
				dummy_for_gradient_y_direc_mod[i][j]=-(dummy_for_gradient_y_direc[i][j]);
				fprintf(fp20,"%f \t",dummy_for_gradient_y_direc_mod[i][j]);
			}

		}
	}

	// To find the sum of |G(x)| and |G(y)|

	row=1;
	
	for(i=1;i<98;i++)
	{
		fprintf(fp21,"\n \n ROW %d \n \n",row);

		for(j=1;j<152;j++)
		{
			magnitude[i][j]=(dummy_for_gradient_x_direc_mod[i][j]+dummy_for_gradient_y_direc_mod[i][j]);
			fprintf(fp21,"%f \t",magnitude[i][j]);
		}
		
		row++;
	}

	// To find the angle

	row=1;
	for(i=1;i<98;i++)  
	{                  
		fprintf(fp22,"\n \n Row %d \n \n",row);

		for(j=1;j<152;j++)
		{
			theta[i][j]=atan(dummy_for_gradient_x_direc[i][j]/dummy_for_gradient_y_direc[i][j]);
			theta_in_degrees[i][j]=(theta[i][j]*180)/3.14159;
			fprintf(fp22,"%f \t",theta_in_degrees[i][j]);
		}
		
		row++;
	}

	// Approximating the angles

	row=1;
	for(i=1;i<98;i++)
	{
		fprintf(fp23,"\n \n Row %d \n \n",row);

		for(j=1;j<152;j++)
		{
			if(((0<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<22.5))||((-22.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<0))||((157.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<180))||((-180<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<-157.5)))
			{
				theta_in_degrees_approx[i][j]=0;
				fprintf(fp23,"\t %d \t",theta_in_degrees_approx[i][j]);
			}
			else if(((22.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<67.5))||((-157.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<-112.5)))
			{
				theta_in_degrees_approx[i][j]=45;
				fprintf(fp23,"\t %d \t",theta_in_degrees_approx[i][j]);
			}
			else if(((67.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<112.5))||((-112.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<-67.5)))
			{
				theta_in_degrees_approx[i][j]=90;
				fprintf(fp23,"\t %d \t",theta_in_degrees_approx[i][j]);
			}
			else if(((112.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<157.5))||((-67.5<=theta_in_degrees[i][j])&&(theta_in_degrees[i][j]<-22.5)))
			{
				theta_in_degrees_approx[i][j]=135;
				fprintf(fp23,"\t %d \t",theta_in_degrees_approx[i][j]);
			}
		}
		row++;
	}

	// Padding zeroes to the array of approximated angles so that it can be divided by 3

	for(i=0;i<99;i++)
	{
		for(j=0;j<153;j++)
		{
			zero_padded_theta[i][j]=0;
			zero_padded_magnitude[i][j]=0;
		}
	}

	for(i=0;i<97;i++) //((No.of rows)-2) done to pad a 97*151 array in the middle of 98*152 array
	{
		for(j=0;j<151;j++) //((No.of rows)-2) done to pad a 97*151 array in the middle of 98*152 array
		{
			zero_padded_theta[i+1][j+1]=zero_array[i+1][j+1]+theta_in_degrees_approx[i+1][j+1];
			zero_padded_magnitude[i+1][j+1]=zero_array[i+1][j+1]+magnitude[i+1][j+1];
		}
	}

	row=1;
	for(i=0;i<99;i++)
	{
		fprintf(fp24,"\n \n Row %d \n \n",row);
		fprintf(fp24a,"\n \n Row %d \n \n",row);
		
		for(j=0;j<153;j++)
		{
			fprintf(fp24,"%d \t",zero_padded_theta[i][j]);
			fprintf(fp24a,"%f \t",zero_padded_magnitude[i][j]);
		}
		row++;
	}

	//Non Maximal Suppression

	u3=1;
	v3=1;
	column=1;
	row=1;
	s=0;
	t=0;

	for(i=0;i<97;i++)
	{
		fprintf(fp25,"\n \n ROW %d \n \n",row);
		fprintf(fp26,"\n \n ROW %d \n \n",row);

		for(j=0;j<151;j++)
		{
			s=0;
			t=0;

			fprintf(fp25,"\n \n COLUMN %d \n \n ",column);
			fprintf(fp26,"\n \n COLUMN %d \n \n ",column);


			for(k=i;k<i+3;k++)
			{
				for(l=j;l<j+3;l++)
				{
					array_for_non_maximal_suppression[s][t]=zero_padded_theta[k][l];
					magnitude_for_suppression[s][t]=zero_padded_magnitude[k][l];

					fprintf(fp25,"%d \t",array_for_non_maximal_suppression[s][t]);
					fprintf(fp26,"%f \t",magnitude_for_suppression[s][t]);

					dummy_for_suppression[s][t]=magnitude_for_suppression[s][t];

					if((s==1)&&(t==1))
					{
					z=array_for_non_maximal_suppression[s][t];
					}
					t++;
				}
				
				fprintf(fp25,"\n \n");
				fprintf(fp26,"\n \n");
				 s++;
				t=0;
			}
			
			fprintf(fp25,"\n Mid elt %d \n ",z);
			fprintf(fp25,"\n first elt %d \n",array_for_non_maximal_suppression[s][t]);
			fprintf(fp26,"\n \n");
			fprintf(fp28,"%f \t",dummy_for_suppression[1][1]);

			switch(z)
			{
			case 0:

				   if((dummy_for_suppression[1][0]>dummy_for_suppression[1][1])||(dummy_for_suppression[1][2]>dummy_for_suppression[1][1]))
				   {
				   dummy_for_suppression[1][1]=0;
				   zero_padded_magnitude[u3][v3]=dummy_for_suppression[1][1];
				   }
					break;

			case 45:
			   if((dummy_for_suppression[0][2]>dummy_for_suppression[1][1])||(dummy_for_suppression[2][0]>dummy_for_suppression[1][1]))
				   {
				   dummy_for_suppression[1][1]=0;
				   zero_padded_magnitude[u3][v3]=dummy_for_suppression[1][1];
				   }
				   break;

			case 90:
					  if((dummy_for_suppression[0][1]>dummy_for_suppression[1][1])||(dummy_for_suppression[2][1]>dummy_for_suppression[1][1]))
				   {
				   dummy_for_suppression[1][1]=0;
				   fprintf(fp27,"%f \t",dummy_for_suppression[1][1]);
				   zero_padded_magnitude[u3][v3]=dummy_for_suppression[1][1];
				   }
				   break;

			case 135:
				   if((dummy_for_suppression[0][0]>dummy_for_suppression[1][1])||(dummy_for_suppression[2][2]>dummy_for_suppression[1][1]))
				   {
				   dummy_for_suppression[1][1]=0;
				   fprintf(fp27,"%f \t",dummy_for_suppression[1][1]);
				   zero_padded_magnitude[u3][v3]=dummy_for_suppression[1][1];
				   }
				   break;

			default:
				   zero_padded_magnitude[u3][v3]=dummy_for_suppression[1][1];
			}

			if(v3==151)
			{
				u3++;
				v3=1;
			}

			else
			{
				v3++;
			}
				column++;
		}

		fprintf(fp28,"\n \n");
		column=1;
		row++;
	}

	row=1;
	for(i=0;i<97;i++)
	{
	fprintf(fp27,"\n \n ROW %d \n \n",row);

	for(j=0;j<151;j++)
	{
	fprintf(fp27,"%f \t",zero_padded_magnitude[i][j]);
	}
	row++;
	fprintf(fp27,"\n");
	}
	fprintf(fp27,"\n \n");

	// Edge_linking:
	// Ascending order program for edge_linking

	k=0;
	
	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
			array_for_edge_linking[k]=zero_padded_magnitude[i][j];
			k++;
		}
	}
	
	for(i=0;i<14647;i++)
	{
		for(j=i+1;j<14647;j++)
		{
	
			if(array_for_edge_linking[i]>array_for_edge_linking[j])
			{
	
				temp=array_for_edge_linking[i];
				array_for_edge_linking[i]=array_for_edge_linking[j];
				array_for_edge_linking[j]=temp;
			}
		}
	}

	last_value=array_for_edge_linking[14617];

	for(i=0;i<14617;i++)
	{
		fprintf(fp29,"%f \t",array_for_edge_linking[i]);
	}

	// Counting Frequency of a number/pixel intensity

	for(i=0;i<14617;i++)
	{
		for(j=0;j<100;j++)
		{
		  if(array_for_edge_linking[i]<j)
		  {  
			  j1=j-1;
			  count_f[j1]++;
			  break;
		  }

		  else
		  continue;
		}
	}

	for(i=1;i<100;i++)
	{
		fprintf(fp29a,"Frequency of %d : %d \n",i,count_f[i]);
	}

	// Finding the pixel value that occurs the most
	j2=0;
	for(i=1;i<100;i++)
	{
		for(j=i+1;j<100;j++)
		{
		  if(count_f[i]>count_f[j])
		  {
		  j2++;
		  continue;
		  }
		}

		if(j2==(99-i))
		{
		  j3=i;
		  break;
		}

		j2=0;
	}  

	fprintf(fp29a,"\n Highest frequency pixel :%d \t and frequency is : %d \n",j3,count_f[j3]);
 
	// Setting thresholds

	lower_threshold=(j3-1);
	fprintf(fp29b,"\n Lower Threshold : %f \n",lower_threshold);
	higher_threshold=((lower_threshold+last_value)/2);
	fprintf(fp29b,"\n Higher Threshold : %f \n",higher_threshold);

	// Applying lower threshold

	row=1;
	
	for(i=0;i<97;i++)
	{
		fprintf(fp30,"\n \n Row %d \n \n",row);
		for(j=0;j<151;j++)
		{
		  if(zero_padded_magnitude[i][j]<lower_threshold)
		  {
		  matrix_after_applying_lower_threshold[i][j]=0;
		  fprintf(fp30,"%f \t",matrix_after_applying_lower_threshold[i][j]);
		  }

		  else if(zero_padded_magnitude[i][j]>lower_threshold)
		  {
		  matrix_after_applying_lower_threshold[i][j]=zero_padded_magnitude[i][j];
		  fprintf(fp30,"%f \t",matrix_after_applying_lower_threshold[i][j]);
		  }
		}
		row++;
	}

	// Applying higher threshold

	row=1;
	for(i=0;i<97;i++)
	{
		fprintf(fp31,"\n \n Row %d \n \n",row);
		for(j=0;j<151;j++)
		{
		  if(zero_padded_magnitude[i][j]<higher_threshold)
		  {
			  matrix_after_applying_higher_threshold[i][j]=0;
			  fprintf(fp31,"%f \t",matrix_after_applying_higher_threshold[i][j]);
		  }

		  else if(zero_padded_magnitude[i][j]>higher_threshold)
		  {
		  matrix_after_applying_higher_threshold[i][j]=255;
		  fprintf(fp31,"%f \t",matrix_after_applying_higher_threshold[i][j]);
		  }
		}
		
		row++;
	}

	//Finding frequency of magnitudes which are greater than higher threshold

	row=1;
	count_freq=0;

	for(i=0;i<97;i++)
	{
		fprintf(fp32,"\n \n Row %d \n \n",row);
		for(j=0;j<151;j++)
		{
		  if(matrix_after_applying_higher_threshold[i][j]==255)
		  {
		  count_freq++;
		  }
		}
		
		count_freq_value[row]=count_freq;
		fprintf(fp32,"%d \n",count_freq_value[row]);
		row++;
		count_freq=0;
	}



	// To find lower cut off value

	count_next=0;
	for(i=1;i<=97;i++)
	{
		if(count_freq_value[i]!=0)
		{
			for(j=i;j<i+5;j++)
			{
			  if(count_freq_value[j]>0)
			  {   
			  count_next++;
			  }
			}
			
			if(count_next>=4)
			{
			fprintf(fp33," Row %d \n",i);
			}   
		}
		
		if(count_next>=4)
		break;

		else
		count_next=0;
	}

	lower_cut_off_value=i;

	fprintf(fp33," Start Value %d \n",lower_cut_off_value);




	// To find upper cut off value

	count_next=0;
	count_before=0;

	for(i=lower_cut_off_value;i<=97;i++)
	{
		if(count_freq_value[i]!=0)
		{
		for(j=i+1;j<i+4;j++)
		{
		  if(count_freq_value[j]==0)
		  {   
		  count_next++;
		  }
		}
		for(k=i;k>1-5;k--)
		{
		  if(count_freq_value[k]>0)
		  {
		  count_before++;
		  }
		}
		if((count_next==3)&&(count_before>=3))
		{
		fprintf(fp33," Row %d \n",i);
		}   
		}
	
		if((count_next==3)&&(count_before>=3))
			break;

		else
		count_next=0;
		
		count_before=0;
	}

	upper_cut_off_value=i;

	fprintf(fp33," End Value %d \n",upper_cut_off_value);

	// Forming an array that contains the second image value

	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
			zero_array1[i][i]=0;
			matrix_after_applying_cut_off[i][j]=0;
		}
	}

	k=0;
	l=0;

	for(i=lower_cut_off_value;i<=upper_cut_off_value;i++)
	{
		for(j=0;j<151;j++)
		{
			matrix_after_applying_cut_off[i][j]=zero_array1[i][j]+matrix_after_applying_higher_threshold[i][j];
		}
	}

	row=1;

	for(i=0;i<97;i++)
	{
		fprintf(fp34,"\n \n Row %d \n \n",row);
		
		for(j=0;j<151;j++)
		{
			fprintf(fp34,"%f \t",matrix_after_applying_cut_off[i][j]);
		}

		fprintf(fp34,"\n");
		row++;
	}

	// Forming matrix containing edge of rice kernel

	for(i=lower_cut_off_value;i<upper_cut_off_value;i++)
	{
		for(j=0;j<151;j++)
		{
			if((matrix_after_applying_lower_threshold[i][j]>0)&&(matrix_after_applying_higher_threshold[i][j]>0))
			{
			continue;
			}

			else if((matrix_after_applying_lower_threshold[i][j]>0)&&(matrix_after_applying_higher_threshold[i][j]==0))
			{
			matrix_after_applying_cut_off[i][j]+=matrix_after_applying_lower_threshold[i][j];
			}
		}
	}

	row=1;  

	for(i=0;i<97;i++)
	{
		fprintf(fp35,"\n \n Row %d \n \n",row);
		
		for(j=0;j<151;j++)
		{
			fprintf(fp35,"%f \t",matrix_after_applying_cut_off[i][j]);
		}
		
		row++;
	}

	row=1;  
	for(i=0;i<97;i++)
	{
		fprintf(fp36,"\n \n Row %d \n \n",row);
		
		for(j=0;j<151;j++)
		{
			if(matrix_after_applying_cut_off[i][j]>0)
			{
			matrix_after_applying_cut_off[i][j]=255;
			}

			fprintf(fp36,"%f \t",matrix_after_applying_cut_off[i][j]);
		}
		
		row++;
	}

	// Feature Extraction

	pixel_count=0;
	
	for(i=0;i<97;i++)
	{
		for(j=0;j<151;j++)
		{
		  if(matrix_after_applying_cut_off[i][j]==255)
		  {
		  pixel_count++;
		  }
		}
	}

	if((character=='t')||(character=='T'))
	{
		fprintf(fp37,"\n Pixel Count : %d \n",pixel_count);

		perimeter=(pixel_count*0.35)/11;
		fprintf(fp37,"\n Perimeter : %lf \n",perimeter*0.001*100*1000000);
		features[0]=perimeter*0.001*100*1000000;

		major_axis_length=(perimeter/4);
		fprintf(fp37,"\n Major Axis Length : %lf  \n",major_axis_length*0.001*100*1000000);
		features[1]=major_axis_length*0.001*100*1000000;

		minor_axis_length_value=(((perimeter*perimeter)/(3.14*3.14))-(2*(major_axis_length*major_axis_length)));

		if(minor_axis_length_value>0)
		minor_axis_length_value=minor_axis_length_value;

		else if(minor_axis_length_value<0)
		minor_axis_length_value=-minor_axis_length_value;

		minor_axis_length=sqrt(minor_axis_length_value);
		fprintf(fp37,"\n Minor Axis Length : %lf  \n",minor_axis_length*0.001*100*1000000);
		features[2]=minor_axis_length*0.001*100*1000000;

		area=3.14*minor_axis_length_value*0.001*100*major_axis_length*0.001*100*100000;
		fprintf(fp37,"\n Area : %lf  \n",area);
		features[3]=area;
		double feret_diameter_value;
		feret_diameter_value=area/3.14;
		double feret_diameter=sqrt(feret_diameter_value);
		fprintf(fp37,"\n Feret Diameter : %lf  \n",feret_diameter*2);
		features[4]=feret_diameter*2;
		//printf(" red = %d \n",red[0][0]);
		//printf("green = %d \n",green[0][0]);
		 //printf(" blue= %d \n",blue[0][0]);
		r=red[0][0];
		b=blue[0][0];
		g=green[0][0];
		features[5]=g;
		fprintf(fp37,"\n g : %d  \n",g);
		features[6]=b;
		fprintf(fp37,"\n b : %d  \n",b);
		intensity=(r+g+b)/3;
		//printf(" intensity= %f \n",intensity);
		features[7]=intensity; 
		fprintf(fp37,"\n colour : %f  \n",intensity); 
		
		if((r<g)&&(r<b))
			min=r;
		else
		{
			if((b<r)&&(b<g))
			min=b;
			else
			min=g;
		}
		
		features[8]=tex/pixel_count;
		//printf(" min= %d \n",min);
		saturation=1-(3/(r+g+b))*min;
		//printf("saturation =%f \n",saturation);
		ab=(double)(((r-g)+(r-b))/2)/(((r-g)^2)+(r-b)*((g-b)^(1/2)));
		hue=acos(ab);
		//printf("hue= %d \n",hue);


	// Comparing Features

	adt_30=0;
	ir20=0;
	a_ponni=0;
	asd_kar2=0;
	briyani_rice_x=0;
	j13=0;
	kponni=0;
	kulsar_hybrid=0;
	mattai2=0;
	p_ponni=0;
	zeera=0;
	wponni=0;
	ponni_kurunai=0;
	md_thoppi=0;
	kdx_sb=0;
	kdx_samba=0;
	kdx_mo=0;
	k_kar_idly=0;
	ppt=0;
	//feature[0]
	/*if(features[0]>=13153636)
	k_kar_idly++;
	else
	{
	if(features[0]>14610000)
	kdx_samba++; 
	else
	{
	if(features[0]>14550000)
	j13++;
	else
	{
	if(features[0]>14340000)
	k_kar_idly++;
	else 
	{
	if(features[0]>14160000)
		briyani_rice_x++;
	else 
	{
	if(features[0]>14100000)
		p_ponni++;
	else 
	{
	if(features[0]>13900000)
	a_ponni++;
	else 
	{
	if(features[0]>13690000)
	md_thoppi++;
	else
	{
	if(features[0]>13650000)
	wponni++;
	else
	{
	if(features[0]>13580000)
	kdx_mo++;
	else
	{
	if(features[0]>13550000)
	adt_30++;
	else 
	{
	if(features[0]>13520000)
	kponni++;
	else 
	{
	if(features[0]>13410000)
	mattai2++;
	else 
	{
	if(features[0]>13150000)
	ponni_kurunai++;
	else
	{
	if(features[0]>13100000)
	ppt++;
	else
	{
	if(features[0]>12980000)
	asd_kar2++;
	else 
	{
	if(features[0]>12770000)
	kdx_sb++;
	else
	{
	if(features[0]>12760000)
	ir20++;
	else 
	{
	if(features[0]>12660000)
	kulsar_hybrid++;
	else
	printf("sorry");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	//feature[1];
	if(features[1]>=3288409)
	k_kar_idly++;
	else
	{
	if(features[1]>3654000)
	kdx_samba++;
	 else 
	{
	if(features[1]>3637000)
	j13++;
	else 
	{
	if(features[1]>3586000)
	k_kar_idly++;
	else
	{
	if(features[1]>3542000)
	  briyani_rice_x++;
	  else 
	{
	if(features[1]>3526000)
	p_ponni++;
	else 
	{
	if(features[1]>3476000)
	a_ponni++;
	else 
	{
	if(features[1]>3423000)
	md_thoppi++;
	else
	{
	if(features[1]>3412000)
	wponni++;
	else
	{
	if(features[1]>3395000)
	kdx_mo++;
	else 
	{
	if(features[1]>3388000)
	adt_30++;
	else 
	{
	if(features[1]>3380000)
	kponni++;
	else 
	{
	if(features[1]>3354000)
	mattai2++;
	else 
	{
	if(features[1]>3288000)
	ponni_kurunai++;
	else
	{
	if(features[1]>3276000)
	ppt++;
	else
	{
	if(features[1]>3246000)
	asd_kar2++;
	else 
	{
	if(features[1]>3194000)
	kdx_sb++;
	else
	{
	if(features[1]>3192000)
	ir20++;
	else 
	{
	if(features[1]>3165000)
	kulsar_hybrid++;
	else
	printf("sorry");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}

	//feature[2]
	if(features[2]>=2019672)
	k_kar_idly++;
	else
	{
	if(features[2]>2244000)
	kdx_samba++;
	 else 
	{
	if(features[2]>2234000)
	j13++;
	else 
	{
	if(features[2]>2202000)
	k_kar_idly++;
	else
	{
	if(features[2]>2175000)
	  briyani_rice_x++;
	  else 
	{
	if(features[2]>2165000)
	p_ponni++;
	else 
	{
	if(features[2]>2135000)
	a_ponni++;
	else 
	{
	if(features[2]>2102000)
	md_thoppi++;
	else
	{
	if(features[2]>2095000)
	wponni++;
	else
	{
	if(features[2]>2085000)
	kdx_mo++;
	else 
	{
	if(features[2]>2081000)
	adt_30++;
	else 
	{
	if(features[2]>2076000)
	kponni++;
	else 
	{
	if(features[2]>2060000)
	mattai2++;
	else 
	{
	if(features[2]>2019000)
	ponni_kurunai++;
	else
	{
	if(features[2]>2012000)
	ppt++;
	else
	{
	if(features[2]>1993000)
	asd_kar2++;
	else 
	{
	if(features[2]>1962000)
	kdx_sb++;
	else
	{
	if(features[2]>1960000)
	ir20++;
	else 
	{
	if(features[2]>1944000)
	kulsar_hybrid++;
	else
	printf("sorry");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}


	//feature[3]
	if(features[3]>=42118937)
	k_kar_idly++;
	else
	{
	if(features[3]>57800000)
	kdx_samba++;
	 else 
	{
	if(features[3]>57010000)
	j13++;
	else 
	{
	if(features[3]>54650000)
	k_kar_idly++;
	else
	{
	if(features[3]>52640000)
	  briyani_rice_x++;
	  else 
	{
	if(features[3]>51930000)
	p_ponni++;
	else 
	{
	if(features[3]>49780000)
	a_ponni++;
	else 
	{
	if(features[3]>47530000)
	md_thoppi++;
	else
	{
	if(features[3]>47060000)
	wponni++;
	else
	{
	if(features[3]>46340000)
	kdx_mo++;
	else 
	{
	if(features[3]>46080000)
	adt_30++;
	else 
	{
	if(features[3]>45760000)
	kponni++;
	else 
	{
	if(features[3]>44700000)
	mattai2++;
	else 
	{
	if(features[3]>42110000)
	ponni_kurunai++;
	else
	{
	if(features[3]>41660000)
	ppt++;
	else
	{
	if(features[3]>40510000)
	asd_kar2++;
	else 
	{
	if(features[3]>38610000)
	kdx_sb++;
	else
	{
	if(features[3]>38520000)
	ir20++;
	else 
	{
	if(features[3]>37580000)
	kulsar_hybrid++;
	else
	printf("sorry");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}


	//feature[4]
	if(features[4]>=7324)
	k_kar_idly++;
	else
	{
	if(features[4]>8580)
	kdx_samba++;
	 else 
	{
	if(features[4]>8520)
	j13++;
	else 
	{
	if(features[4]>8340)
	k_kar_idly++;
	else
	{
	if(features[4]>8180)
	  briyani_rice_x++;
	  else 
	{
	if(features[4]>8130)
	p_ponni++;
	else 
	{
	if(features[4]>7960)
	a_ponni++;
	else 
	{
	if(features[4]>7780)
	md_thoppi++;
	else
	{
	if(features[4]>7740)
	wponni++;
	else
	{
	if(features[4]>7680)
	kdx_mo++;
	else 
	{
	if(features[4]>7670)
	adt_30++;
	else 
	{
	if(features[4]>7630)
	kponni++;
	else 
	{
	if(features[4]>7540)
	mattai2++;
	else 
	{
	if(features[4]>7320)
	ponni_kurunai++;
	else
	{
	if(features[4]>7280)
	ppt++;
	else
	{
	if(features[4]>7180)
	asd_kar2++;
	else 
	{
	if(features[4]>7010)
	kdx_sb++;
	else
	{
	if(features[4]>7000)
	ir20++;
	else 
	{
	if(features[4]>6910)
	kulsar_hybrid++;
	else
	printf("sorry");
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}*/
	//colour feature

	if(features[7]>=60)
	{
		ir20++;
		wponni++;
	}
	else
	{
		if((features[7]>57)&&(features[8]>5580))
		ppt++;
		
		else 
		{
			if((features[7]>57)&&(features[8]>1700))
				j13++;
			else
			{
				if((features[7]>57)&&(features[8]>1330))
					md_thoppi++;
				else
				{
					if((features[7]>57)&&(features[8]>540))
						asd_kar2++;
					else 
					{
						if((features[7]>57)&&(features[8]>500))
							kponni++;
						else
						{
							if((features[7]>56)&&(features[8]>6160))
								adt_30++;
							else
							{
								if((features[7]>56)&&(features[8]>510))
									mattai2++;
								else
								{
									if((features[7]>55)&&(features[8]>5180))
										p_ponni++;
									else
									{
										if((features[7]>55)&&(features[8]>520))
											kdx_mo++;
										else
										{
											if(features[7]>54)
												briyani_rice_x++;
											else
											{
												if(features[7]>53)
													zeera++;
												else
												{
													if(features[7]>52)
														kulsar_hybrid++;
													else
														//printf("sorry");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
		
	//feature[8]
	if(features[8]>=6163)
		adt_30++;
		else
		{
			if(features[8]>5580)
				ppt++;
		 	else 
			{	
				if(features[8]>5360)
					zeera++;
				else 
				{
					if(features[8]>5180)
						p_ponni++;
					else
					{
						if(features[8]>5100)
						  ir20++;
						else 
						{
							if(features[8]>4640)
								wponni++;
							else 
							{
								if(features[8]>4410)
									kulsar_hybrid++;
								else 
								{
									if(features[8]>2010)
										kdx_sb++;
									else
									{
										if(features[8]>1700)
											j13++;
										else
										{
											if(features[8]>1330)
												md_thoppi++;
											else 
											{
												if(features[8]>540)
													asd_kar2++;
												else 
												{
													if(features[8]>520)
														kdx_mo++;
													else 
													{
														if(features[8]>511)
															briyani_rice_x++;
														else 
														{
															if(features[8]>510)
																mattai2++;
															else
															{
																if(features[8]>500)
																	kponni++;
																else
																{
																	if(features[8]>140)
																		kdx_samba++;
																	else 
																	{
																		//printf("sorry");
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//comparing

		printf("\nf0 :%lf\n",features[0]);
		printf("\nf1 :%lf\n",features[1]);
		printf("\nf2 :%lf\n",features[2]);
		printf("\nf3 :%lf\n",features[3]);
		printf("\nf4 :%lf\n",features[4]);
		printf("\nf7 :%lf\n",features[7]);
		printf("\nf8 :%lf\n",features[8]);



		if(a_ponni>=1)
		{
			printf("\n a_ponni rice \n");

		}
		else 
		{
			if(ir20>=1)
			{
				printf("\n IR 20 \n");

			}
			else 
			{
				if(adt_30>=1)
				{
					printf("\n adt_30 arisi \n");

				}
				else 
				{
					if(asd_kar2>=1)
					{
						printf("\n asd kar2 \n");

					}
					else 
					{
						if(briyani_rice_x>=1)
						{
							printf("\n briyani_rice_x\n");

						}
						else 
						{
							if(j13>=1)
							{
								printf("\n j13 \n");

							}
							else 
							{
								if(kponni>=1)
								{
									printf("\n kponni \n");

								}
								else 
								{
									if(kulsar_hybrid>=1)
									{
										printf("\n kulsar_hybrid \n");

									}
									else 
									{
										if(p_ponni>=1)
										{
											printf("\n p_ponni \n");

										}
										else 
										{
											if(mattai2>=1)
											{
												printf("\n mattai2 \n");
											}
											else 
											{
												if(zeera>=1)
												{
													printf("\n zeera \n");
												}
												else 
												{
													if(wponni>=1)
													{
														printf("\n wponni \n");
													}
													else 
													{
														if(ponni_kurunai>=1)
														{
															printf("\n ponni_kurunai \n");
														}
														else 
														{
															if(md_thoppi>=1){
																printf("\n md_thoppi_boiled\n");
															}
															else 
															{
																if(kdx_sb>=1){
																	printf("\n kdx_sb \n");
																}
																else 
																{
																	if(kdx_samba>=1)
																	{
																		printf("\n kdx_samba \n");
																	}
																	else 
																	{
																		if(kdx_mo>=1)
																		{
																			printf("\n kdx_mo_rice \n");
																		}
																		else 
																		{
																			if(k_kar_idly>=1)
																			{
																				printf("\n k_kar_idly_rice \n");
																			}
																			else {
																				printf("\nmattai2\n");
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		}    

		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		fclose(fp5);
		fclose(fp6);
		fclose(fp7);
		fclose(fp8);
		fclose(fp9);
		fclose(fp10);
		fclose(fp10a);
		fclose(fp10b);
		fclose(fp11);
		fclose(fp12);
		fclose(fp13);
		fclose(fp14);
		fclose(fp15);
		fclose(fp16);
		fclose(fp17);
		fclose(fp18);
		fclose(fp19);
		fclose(fp20);
		fclose(fp21);
		fclose(fp22);
		fclose(fp23);
		fclose(fp24);
		fclose(fp24a);
		fclose(fp25);
		fclose(fp26);
		fclose(fp27);
		fclose(fp28);
		fclose(fp29);
		fclose(fp29a);
		fclose(fp29b);
		fclose(fp30);
		fclose(fp31);
		fclose(fp32);
		fclose(fp33);
		fclose(fp34);
		fclose(fp35);
		fclose(fp36);
		fclose(fp37);
	}

	// Function to apply masks

	float gauss_gradient(float a2[ ][3],int r2,int c2,int count)
	{
		int m,n;
		float sum=0,sum1=0,sum2=0,mul_value[3][3],mul_value1[3][3],mul_value2[3][3],y[3][3],y1[3][3],y2[3][3],mask[3][3]={{1,2,1},{2,4,2},{1,2,1}},mask_for_gradient_x_direc[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}},mask_for_gradient_y_direc[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

		if(count==1)
		{

			for(m=0;m<r2;m++)
			{
				for(n=0;n<c2;n++)
				{
					y[m][n]=a2[m][n];
					mul_value[m][n]=y[m][n]*mask[m][n];
					sum+=mul_value[m][n];
				}
			}

			return (sum/16);
		}

		else if(count==2)
		{

			for(m=0;m<r2;m++)
			{
				for(n=0;n<c2;n++)
				{
					y1[m][n]=a2[m][n]; // mask_for_gradient_direc and mask_for_gradient_direc are Sobel Operators
					mul_value1[m][n]=y1[m][n]*mask_for_gradient_x_direc[m][n];
					sum1+=mul_value1[m][n];
				}
			}

			return (sum1/16);
		}

		else if(count==3)
		{

			for(m=0;m<r2;m++)
			{
				for(n=0;n<c2;n++)
				{
					y2[m][n]=a2[m][n];
					mul_value2[m][n]=y2[m][n]*mask_for_gradient_y_direc[m][n];
					sum2+=mul_value2[m][n];
				}
			}
			
			return (sum2/16);
		}
	}

 
