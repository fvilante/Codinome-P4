/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BusinessStateMachine.h"

#include "catch.hpp"


struct Inputs {
    bool existeAlgumaSituacaoDeErro = false;
    bool existeAlgumEixoDesreferenciado = true;
    bool existeAlgumJobNaFilaASerProcessado = false;        
};
struct Outputs {
    bool chamaRotinaDeReferenciaDosEixos = false;
    bool liberaProcessadorDeJobsParaExecutarProximoJob = false;
};

class BSM_Tester : public BusinessStateMachine {
    
protected:
    //IO da maquina de estados:
    //inputs para a maquina de estados
    bool existeAlgumaSituacaoDeErro() override { return inputs_.existeAlgumaSituacaoDeErro;  } 
    bool estaAlgumEixoDesreferenciado() override { return inputs_.existeAlgumEixoDesreferenciado; };
    bool existeAlgumJobNaFilaASerProcessado() override { return inputs_.existeAlgumJobNaFilaASerProcessado; };    
    //outputs da maquina de estados
    //atencao: pode ser chamado mais de uma vez em cada estado
    void chamaRotinaDeReferenciaDosEixos() override { outputs_.chamaRotinaDeReferenciaDosEixos = true;}
    void liberaProcessadorDeJobsParaExecutarProximoJob() override { outputs_.liberaProcessadorDeJobsParaExecutarProximoJob = true; }
        
public:    
    
    Inputs inputs_;    
    Outputs outputs_;    
};


typedef BusinessStateMachine BSM;

TEST_CASE("BusinesStateMachine class Test", "[BusinessStateMachine]") {
    
    //instantiate a machine
    BSM_Tester bsm = BSM_Tester();
    
    //OBS: Para saber o estado inicial dos inputs e outputs da maquina neste
    //teste veja definicao do structs Input e Outputs acima
    
    SECTION("Testa construcao em estado inicial") {        
        REQUIRE (bsm.getState()==BSM::State::INICIAL);        
    }
    
    SECTION("Testa transicoes a partir de estado INICIAL") {
        
        CHECK(bsm.getState()==BSM::State::INICIAL);
        
        SECTION("Iniciar a maquina em erro, estado deve ir pra estado ERRO") {
            bsm.inputs_.existeAlgumaSituacaoDeErro = true;
            bsm.handleState();
            REQUIRE (bsm.getState()==BSM::State::ERRO);
        }
        
        SECTION("Iniciar a maquina desreferenciado, deve ir para estado SETUP") {
            bsm.inputs_.existeAlgumEixoDesreferenciado = true;
            bsm.handleState();
            REQUIRE (bsm.getState()==BSM::State::SETUP);
        }
        
        SECTION("Iniciar a maquina ja esta referenciado, deve ir para estado PRONTO") {
            bsm.inputs_.existeAlgumEixoDesreferenciado = false;
            bsm.handleState();
            REQUIRE (bsm.getState()==BSM::State::PRONTO);
        }
        
        
        SECTION("Testa transicoes a partir de estado SETUP  ") {

            bsm.handleState(); //vai pra estado Setup.
            CHECK(bsm.getState()==BSM::State::SETUP);

            SECTION("Se condicao de erro, vai para estado ERRO") {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }  
            SECTION("Se nenhum eixo desreferenciado, vai para estado PRONTO") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = false;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::PRONTO);
            } 
            SECTION("Se tem eixo desreferenciado, chama rotina de referencia") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = true;
                CHECK (bsm.outputs_.chamaRotinaDeReferenciaDosEixos == false);
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::SETUP); 
                REQUIRE (bsm.outputs_.chamaRotinaDeReferenciaDosEixos == true);
            } 

        }

        
        SECTION("Testa transicoes a partir de estado PRONTO  ") {

            //arrange: entra em estado pronto
            bsm.handleState(); //SETUP
            bsm.inputs_.existeAlgumEixoDesreferenciado = false;
            bsm.handleState(); //PRONTO
            CHECK (bsm.getState()==BSM::State::PRONTO);
            
            SECTION("Se condicao de erro, vai para estado ERRO") {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }  
            SECTION("Se algum eixo desreferenciado, vai para estado ERRO") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            } 
            
            SECTION("Se algum eixo desreferenciado, vai para estado ERRO (Ainda que tenha JOB a ser processado)") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = true;
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;                
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }
            
            SECTION("Se tem algum JOB na fila, muda para estado PROCESSANDO_JOBS") {
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;
                CHECK (bsm.outputs_.liberaProcessadorDeJobsParaExecutarProximoJob == false);
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::PROCESSANDO_JOB); 
            } 

        }
        
        
        SECTION("Testa transicoes a partir de estado PROCESSANDO_JOB  ") {

            //arrange: entra em estado PROCESSANDO_JOB
            bsm.handleState(); //SETUP
            bsm.inputs_.existeAlgumEixoDesreferenciado = false;
            bsm.handleState(); //PRONTO
            bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;
            bsm.handleState(); //PROCESSANDO_JOB
            CHECK (bsm.getState()==BSM::State::PROCESSANDO_JOB);
            
            SECTION("Se condicao de erro, vai para estado ERRO") {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }  
            
            SECTION("Se condicao de erro, vai para estado ERRO (Ainda que tenha Job na fila)" ) {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }
            
            SECTION("Se algum eixo desreferenciado, vai para estado ERRO") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = true;
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            } 
            
            SECTION("Se algum eixo desreferenciado, vai para estado ERRO (Ainda que tenha jobs na fila)") {
                bsm.inputs_.existeAlgumEixoDesreferenciado = true;
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            } 
            
                        
            SECTION("Enquanto tiver JOBs na fila, mantem processador de JOBS operante") {
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = true;
                bsm.handleState();
                REQUIRE (bsm.outputs_.liberaProcessadorDeJobsParaExecutarProximoJob == true);                
                REQUIRE (bsm.getState()==BSM::State::PROCESSANDO_JOB); 
                bsm.handleState();
                REQUIRE (bsm.outputs_.liberaProcessadorDeJobsParaExecutarProximoJob == true);
                REQUIRE (bsm.getState()==BSM::State::PROCESSANDO_JOB); 
            } 
            
            SECTION("Quando nao houver mais Jobs na fila a serem processados, retorna para estado PRONTO") {
                bsm.inputs_.existeAlgumJobNaFilaASerProcessado = false;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::PRONTO);
            }            

        }     
        
        
        
         SECTION("Testa transicoes a partir de estado ERRO") {

            //arrange: entra em estado ERRO
            bsm.inputs_.existeAlgumaSituacaoDeErro = true;
            bsm.handleState();
            CHECK(bsm.getState()==BSM::State::ERRO);
            
            SECTION("Se condicao de erro permanece, mantem estado de ERRO") {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            } 
            
            SECTION("Se condicao de erro some, muda para estado de INICIO") {
                bsm.inputs_.existeAlgumaSituacaoDeErro = true;
                bsm.handleState();
                REQUIRE (bsm.getState()==BSM::State::ERRO);
            }
            
            
         }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
}