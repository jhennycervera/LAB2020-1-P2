/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX_LIN 80
void  ImprLin(char c, int cant){
    for(int i=0; i<cant; i++){
        printf("%c", c);
    }
    printf("\n");
}
void AcumularMonto(double *entrega_m_m, double*entrega_t_m,
        int hora, double  montVentaLin, double montVenta){
   
    if(hora<115959){
        *entrega_m_m+=(0.02*montVenta)+ (0.005*montVentaLin);
    }
    else *entrega_t_m+=(0.03*montVenta)+(0.005*montVentaLin);
    
}

void ProcesarMayorYMenorEntrega(int m1,int m2, int m3,double entTot_m2,double entTot_m1,double entTot_m3,
                int *mesMayor,int*mesMenor,double *entregaMayor, double*entregaMenor){
    
    if(entTot_m2>entTot_m1 && entTot_m2>entTot_m3){
        (*entregaMayor)=entTot_m2;
        (*mesMayor)=m2;
    }
    else{
        if(entTot_m1>entTot_m2 && entTot_m1>entTot_m3) {
        (*entregaMayor)=entTot_m1;
        (*mesMayor)=m1;
        }
        else{
        (*entregaMayor)=entTot_m3;
        (*mesMayor)=m3;
        } 
    }
    
    if(entTot_m2<entTot_m1 && entTot_m2<entTot_m3){
        (*entregaMenor)=entTot_m2;
        (*mesMenor)=m2;
    }
    else{
        if(entTot_m1<entTot_m2 && entTot_m1<entTot_m3){
        (*entregaMenor)=entTot_m1;
        (*mesMenor)=m1;
        }
        else {
        (*entregaMenor)=entTot_m3;
        (*mesMenor)=m3;
        }
    } 
    
}
    

void ImprimirRep(int mm1,int mm2, int mm3,double entrega_m_m1,double entrega_t_m1, 
        double entTot_m1, double entrega_m_m2,double entrega_t_m2, double entTot_m2, 
        double entrega_m_m3,double entrega_t_m3,double entTot_m3,
            double entregaMayor,double entregaMenor,int mesMayor,int mesMenor){
    
    printf("Mes: %01d\n",mm1 );
    printf("\n");
    printf("Por la entrega en la manana: S/.%.2lf\n",entrega_m_m1);
    printf("Por la entrega en la tarde: S/.%.2lf\n",entrega_t_m1);
    printf("Total por la entrega: S/.%.2lf\n",entTot_m1);
    ImprLin('=', MAX_LIN);
    
    printf("Mes: %01d\n",mm2 );
    printf("\n");
    printf("Por la entrega en la manana: S/.%.2lf\n",entrega_m_m2);
    printf("Por la entrega en la tarde: S/.%.2lf\n",entrega_t_m2);
    printf("Total por la entrega: S/.%.2lf\n",entTot_m2);
    ImprLin('=', MAX_LIN);
    
    printf("Mes: %01d\n",mm3 );
    printf("\n");
    printf("Por la entrega en la manana: S/.%.2lf\n",entrega_m_m3);
    printf("Por la entrega en la tarde: S/.%.2lf\n",entrega_t_m3);
    printf("Total por la entrega: S/.%.2lf\n",entTot_m3);
    ImprLin('=', MAX_LIN);
    
    printf("Mes con mayor pago al proveedor: %01d - S/.%.2lf\n",mesMayor,entregaMayor);
    printf("Mes con menor pago al proveedor: %01d - S/.%.2lf\n",mesMenor,entregaMenor);
    
    
    
    
    
}