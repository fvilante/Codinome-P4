/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Job.h"

//dependencies
#include "Matriz.h"
#include "Drawer.h"
#include "Cabecote.h"
#include "Receiver.h"
#include "CorDaTinta.h"
#include "BarCode.h"

#include "catch.hpp"


typedef bool T;


Matriz createMatriz() {
    return Matriz();
}



TEST_CASE("Job class Test", "[Job]") {
    
    SECTION("Testa construcao vazia e funcao isEmpty") {        
        Job job = Job();
        REQUIRE(job.isEmpty() == true);        
    }
    
    
    SECTION("Testa construcao e getters com parametros arbitrarios") {
        
        //arrange
        Matriz matriz = createMatriz();
        Cabecote::Id cab = Cabecote::Id::CABECOTE_1;
        Drawer::Id gavetaId = Drawer::Id::GAVETA1;
        BarCode barcode = BarCode("Teste");
        //act
        Job job = Job(barcode, gavetaId, matriz, cab);
        //assert
        REQUIRE(job.getCabecoteId() == cab);
        REQUIRE(job.getDrawerId() == gavetaId);
        REQUIRE(job.getMatriz() == matriz);
        REQUIRE(job.getBarCode() == barcode);
    }
    
    
}

