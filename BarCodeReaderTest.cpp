/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BarCodeReader.h"
#include "Receiver.h"

#include "catch.hpp"
#include <string>
#include <vector>

    TEST_CASE( "BarCodeReader class Test", "[BarCodeReader]" ) {
        
        //Parametros do teste
        const int maxSignals = 10;
        typedef std::string T; 
        T initialValue = "Oi Cara"; 
        std::vector<T> signals = { "M#12341234", "M#09782344", "M#asdf1234" ,
        "M#*********", "diferentao", "igualzao", "igualzao", "M#123ffff4",
        "M#1uytyi34", "mensagem grandinha e com espaco viu?"};
        
        //Arrange
        Receiver<T>& stub = *(new Receiver<T>(initialValue)); 
        //cria a classe em teste
        BarCodeReader leitorBarCode = BarCodeReader(stub);

        SECTION("Testa variacao no sinal de entrada") {
            
            SECTION("Retorno com std::string") {
            
                for (auto i : signals) {
                    stub.put(i); //send signal                
                    REQUIRE(leitorBarCode.getCode() == i); //read signal
                }
            }       
        
            SECTION("Retorno com classe BarCode") {

                for (auto i : signals) {
                    stub.put(i); //send signal              
                    REQUIRE(leitorBarCode.getBarCode() == BarCode(i)); //read signal
                }
            }

        } 

    };