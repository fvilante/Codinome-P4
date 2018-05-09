/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Queue.h"

#include "catch.hpp"


class Qualquer {     
    public: 
        int a = 77;
        Qualquer(int a): a(a) { }
        Qualquer() { }; //= delete;
};

TEST_CASE("Queue class Test", "[Queue]") {
    
    //arrage
    int signal[4] = { 100, 200, 300, 400 };
    Qualquer probe[4] = { 
        Qualquer(signal[0]), 
        Qualquer(signal[1]), 
        Qualquer(signal[2]), 
        Qualquer(signal[3])
    };
   
    
    auto fila = Queue<Qualquer>();
    
    //act assert
    
    SECTION("Testa construcao") {
        REQUIRE(fila.isEmpty() == true);
        REQUIRE(fila.size() == 0);
    }
    
    
    SECTION("Testa os metodos de modo basico") {
        
        //Insere um objeto na fila e testa
        fila.pushBack(probe[0]);
        REQUIRE(fila.isEmpty() == false);
        REQUIRE(fila.size() == 1);
        
        //Le objeto da fila, porém nao o retira da fila    
        REQUIRE (fila.peekFront().a == probe[0].a);
        REQUIRE(fila.isEmpty() == false);
        REQUIRE(fila.size() == 1);
        
        //insere um objeto no final da fila
        fila.pushBack(probe[1]);
        REQUIRE(fila.isEmpty() == false);
        REQUIRE(fila.size() == 2);
        
        //Le primeiro da fila (removendo objeto)
        int a = fila.pullFront().a;
        REQUIRE(fila.size() == 1);
        REQUIRE(fila.isEmpty() == false);
        REQUIRE(a == probe[0].a);

        //reinsere 2o elemento, e insere 3o novo elemento
        fila.pushBack(probe[1]);
        fila.pushBack(probe[2]);
        REQUIRE(fila.size() == 3);
        REQUIRE(fila.isEmpty() == false);
        
        
        //testa zerar a fila
        fila.clear();
        REQUIRE(fila.size() == 0);
        REQUIRE(fila.isEmpty() == true);
    }
    
    SECTION("Testa adicionar e ler 4 itens em sequencia") {
        
        fila.pushBack(signal[0]);
        fila.pushBack(signal[1]);
        fila.pushBack(signal[2]);
        fila.pushBack(signal[3]);
        
        REQUIRE(fila.pullFront().a == signal[0]);
        REQUIRE(fila.pullFront().a == signal[1]);
        REQUIRE(fila.pullFront().a == signal[2]);
        REQUIRE(fila.pullFront().a == signal[3]);        
        
    }
            
    
    
    
}