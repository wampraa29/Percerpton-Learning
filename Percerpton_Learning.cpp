#include<stdio.h>
#include<stdlib.h>
#include<math.h>



double d=-1;
double dw[1][3];
double nw[1][3];
double cikis;
double c=1;
double x1[3][1]={-1,1,1};
double x2[3][1]={-1,-1,0};


double *xd=x1[0];


void dizi_yazdir(double dizi[][3]){
	//printf("\n\ndizi_yazdir_fonksiyonuna_girildi.\n\n");
printf("\n");
 int i=0;
 
      for(int j=0;j<=2;j++){
       printf("%f\t",dizi[i][j]);
}
printf("\n");

}



void fonsiyon_cikisi( double x)
{
//printf("\n\nfonksiyon_cikisi_fonksiyonuna_girildi.\n\n");
	
//	printf("\n--xn::%f--\n",1/(1+exp(-x)));
printf("\n x:%f\n",x);
if(x>0)
x=1;
else
x=-1;
//double a=1/(1+exp(-x));

cikis=x;	
printf("-----------------");
printf("\n|cikis:%f |\n",cikis);
printf("-----------------\n");

}

double deger_ata(double *a)
{
//printf("\n\ndeger_ata_fonksiyonuna_girildi.\n\n");
a[0]=*xd; 
a[1]=*(xd+1);
a[2]=*(xd+2);
printf("\nxd :%f xd+2 :%f xd+3 :%f\n",*xd,*(xd+1),*(xd+2));
}
double matris_carpim(double w[1][3]){
//printf("\n\nmatris_carpim_fonksiyonuna_girildi.\n\n");	
double Toplam=0;
double x[3][1];
deger_ata(x[0]);

//printf("0:%f 1:%f 2:%f\n",w[0][0],w[0][1],w[0][2]);
//printf("\n%f\n",x[1][1]);
int i=0;
  for(int j=0;j<=2;j++){
        Toplam=Toplam+w[i][j]*x[j][i];
   //printf("\n Toplam:%f = %f + %f*%f\n",Toplam,Toplam,w[i][j],x[j][i]);
}
        fonsiyon_cikisi(Toplam);
       // printf("Carpim:%f\n",Toplam);
		return Toplam;
		
}

void agirlik_degisimi(double *a ){
 //printf("\n\nagirlik_degisim_fonksiyonuna_girildi.\n\n");
 
double yk=cikis;
 

double x[3][1];
deger_ata(x[0]);

 if(d==yk)
 {
 	dw[0][0]=0;
 	dw[0][1]=0;
 	dw[0][2]=0;
 }
 else
 {
 	printf("\n--d:%f--\n",d);
 dw[0][0]=c*(d-yk)*x[0][0];
 dw[0][1]=c*(d-yk)*x[1][0];
 dw[0][2]=c*(d-yk)*x[2][0];
 }

}

void agirlik_hesabi(double w[1][3]){
 
//printf("\n\nagirlik_hesabi_fonksiyonuna_girildi.\n\n");
 
 nw[0][0]= w[0][0] +dw[0][0];
 nw[0][1]= w[0][1] +dw[0][1];
 nw[0][2]= w[0][2] +dw[0][2];
// printf("\nnw %f  + \n",nw[0][0],);
}

void xdegersec(int n){
//	printf("\n\nxdegersec_fonksiyonuna_girildi.\n\n");
	switch(n){
		case  1:
		xd=x1[0];
		d=-1;
		break;
		case 2:
		xd=x2[0];
		d=1;
		break;
	}
	
}



int main(){
	

double  w[1][3]={0,1,0};
//x[0][0]=1; x[1][0]=-2;



matris_carpim(w);   
agirlik_degisimi(xd);
agirlik_hesabi(w);
dizi_yazdir(nw);


int i=2,t=1;


while(t!=-1)
{
	
printf("\n------------------------------------------i:%d",i);

if(3>i){
xdegersec(i);
matris_carpim(nw);  
agirlik_degisimi(xd);
agirlik_hesabi(nw);
dizi_yazdir(nw);
++i;
}
else 
i=1;

printf("\nCikmak icin -1 giriniz:");
scanf("%d",&t);
}


}

