/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 30 de abril de 2020, 13:16
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 80
#include "FuncAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    int codDist_I, aa, mm1, mm2, mm3;
    
    scanf("%d\n%d %d %d %d", &codDist_I, &aa, &mm1, &mm2, &mm3);
    
    int dni, ddv,mmv,aav,hh,min,seg, codDist, cantProd;
    double montVenta, montVentaLin;
    double entrega_m_m1=0, entrega_t_m1=0, entTot_m1=0,entrega_m_m2=0, entrega_t_m2=0,
                            entTot_m2=0,entrega_m_m3=0, entrega_t_m3=0,
                            entTot_m3=0;
    double entregaMayor=0, entregaMenor=99999999;
    int hora, mesMayor, mesMenor;
    
    printf("      PAGOS AL PROVEEDOR DE ENTREGA A DOMICILIO TP2020\n");
    printf("Distrito:%d\n",codDist_I);
    printf("Anho: %d\n",aa );
    ImprLin('=', MAX_LIN);
    while(1){
       scanf("%d %d/%d/%d %d:%d:%d %d %lf %d",&dni, &ddv,&mmv,&aav,&hh,&min,&seg,
                                        &codDist,&montVenta,&cantProd);
       hora=hh*10000 + min*100 + seg;
       if(feof(stdin)) break;
       if(codDist_I==codDist && aa==aav){
           montVentaLin=montVenta*cantProd;
           if(mmv==mm1){
               AcumularMonto(&entrega_m_m1,&entrega_t_m1,hora,
                                            montVentaLin,montVenta);
           }
           if(mmv==mm2){
                AcumularMonto(&entrega_m_m2,&entrega_t_m2,hora,
                                            montVentaLin, montVenta);
           }
           if(mmv==mm3){
               AcumularMonto(&entrega_m_m3,&entrega_t_m3,hora,
                                            montVentaLin, montVenta);
           }
       }
    }
    entTot_m1=entrega_m_m1+entrega_t_m1;
    entTot_m2=entrega_m_m2+entrega_t_m2;
    entTot_m3=entrega_m_m3+entrega_t_m3;
    
    ProcesarMayorYMenorEntrega(mm1,mm2,mm3,entTot_m2,entTot_m1,entTot_m3, &mesMayor,& mesMenor,
            &entregaMayor, &entregaMenor);
    
    ImprimirRep(mm1,mm2, mm3,entrega_m_m1,entrega_t_m1, entTot_m1,entrega_m_m2,
                      entrega_t_m2, entTot_m2, entrega_m_m3,entrega_t_m3, entTot_m3,
            entregaMayor,entregaMenor,mesMayor,mesMenor);
    
    return (EXIT_SUCCESS);
}

