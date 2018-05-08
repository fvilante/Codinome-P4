/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 17:29
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include "Properties.h" //properties macros
#include "CorDaTinta.h"

#include <string>


class Matriz {
  
    
public:
    Matriz() = default;
    Matriz(const Matriz& orig) = default;
    virtual ~Matriz() = default;   
        
    //Propriedades
    PROPERTY(std::string, DescricaoDoConector, "");
    PROPERTY(int, FormatacaoDaImpressao, 0);
    PROPERTY(std::string, LeituraDoCodigoDeBarras, "");
    PROPERTY(std::string, TextoASerImpresso, "");
    PROPERTY(Cor, CorDaTintaAImprimir, Cor::PRETO);
    PROPERTY(std::string, FotoDoConector, ""); //endereço e nome do arquivo de imagem
    PROPERTY(int, OffsetDeAvanco, 0);
    PROPERTY(int, OffsetDeRetorno, 0);
    PROPERTY(int, AlturaDoEixoZ, 0);
    PROPERTY(int, Y1m, 0);
    PROPERTY(int, Y2m, 0);
    PROPERTY(int, X1m, 0);
    PROPERTY(int, X2m, 0);  
     
    
    bool operator==(const Matriz& other) const {        
        bool p1 = (getDescricaoDoConector() == other.getDescricaoDoConector());
        bool p2 = (getFormatacaoDaImpressao() == other.getFormatacaoDaImpressao());
        bool p3 = (getLeituraDoCodigoDeBarras() == other.getLeituraDoCodigoDeBarras());
        bool p4 = (getTextoASerImpresso() == other.getTextoASerImpresso());
        bool p5 = (getCorDaTintaAImprimir() == other.getCorDaTintaAImprimir());
        bool p6 = (getFotoDoConector() == other.getFotoDoConector());
        bool p7 = (getOffsetDeAvanco() == other.getOffsetDeAvanco());
        bool p8 = (getOffsetDeRetorno() == other.getOffsetDeRetorno());
        bool p9 = (getAlturaDoEixoZ() == other.getAlturaDoEixoZ());
        bool p10 = (getY1m() == other.getY1m());
        bool p11 = (getY2m() == other.getY2m());
        bool p12 = (getX1m() == other.getX1m());
        bool p13 = (getX2m() == other.getX2m());
        
        return (p1 && p2 && p3 && p4 && p5 && p6 && 
                p7 && p8 && p9 && p10 && p11 && p12 && p13) ? true : false;
        
    }

    
};

#endif /* MATRIZ_H */

