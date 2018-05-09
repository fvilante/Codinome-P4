/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BusinessStateMachine.h
 * Author: Flavio
 *
 * Created on 22 de Abril de 2018, 17:23
 */

#ifndef BUSINESSSTATEMACHINE_H
#define BUSINESSSTATEMACHINE_H

//Esta classe abstrata encapssula a maquina de estados mas espera que 
//a sub-classe implemente as rotinas de input e output da maquina de estados.
class BusinessStateMachine {
  
public:
    enum class State {
        INICIAL, SETUP /*incluso referenciar eixos*/, 
        PRONTO, PROCESSANDO_JOB, ERRO 
    };
    
private:
    
    typedef BusinessStateMachine BSM;
    
    
    BSM::State state_;
    
    void setState(BSM::State s) { state_ = s; }
   
    // estados da maquina
    void state_INICIAL() { 
        if (existeAlgumaSituacaoDeErro()) 
            setState(BSM::State::ERRO);
        else if (estaAlgumEixoDesreferenciado()) 
            setState(BSM::State::SETUP);
        else
            setState(BSM::State::PRONTO);        
    }
    
    void State_SETUP() { 
        if (existeAlgumaSituacaoDeErro()) 
            setState(BSM::State::ERRO);
        else if (!estaAlgumEixoDesreferenciado()) 
            setState(BSM::State::PRONTO);
        else
            chamaRotinaDeReferenciaDosEixos();
    }
    
    void state_PRONTO() { 
        if (existeAlgumaSituacaoDeErro()) 
            setState(BSM::State::ERRO);
        else if (estaAlgumEixoDesreferenciado()) 
            setState(BSM::State::ERRO);
        else if (existeAlgumJobNaFilaASerProcessado())
            setState(BSM::State::PROCESSANDO_JOB);
        else
            doNothing();
    }
    
    void state_PROCESSANDO_JOB() { 
        if (existeAlgumaSituacaoDeErro()) 
            setState(BSM::State::ERRO);
        else if (estaAlgumEixoDesreferenciado()) 
            setState(BSM::State::ERRO);
        else if (!existeAlgumJobNaFilaASerProcessado())
            setState(BSM::State::PRONTO);
        else 
            liberaProcessadorDeJobsParaExecutarProximoJob();
            
        
    }
    
    void state_ERRO() { 
        if (!existeAlgumaSituacaoDeErro()) 
            setState(BSM::State::INICIAL);
    }
    
protected:
    
    //*************************************************************************
    //IO da maquina de estados: A ideia é que seja implementada pela sub-classe.
    //inputs para a maquina de estados
    virtual bool existeAlgumaSituacaoDeErro()=0;
    virtual bool estaAlgumEixoDesreferenciado()=0;
    virtual bool existeAlgumJobNaFilaASerProcessado()=0;
    //outputs da maquina de estados
    //atencao: pode ser chamado mais de uma vez em cada estado
    virtual void chamaRotinaDeReferenciaDosEixos()=0;
    virtual void liberaProcessadorDeJobsParaExecutarProximoJob()=0;
    void doNothing() { }
    //*************************************************************************
    
public:
    
    
    BusinessStateMachine() : state_(BSM::State::INICIAL) { }
    BusinessStateMachine(const BusinessStateMachine& orig);
    virtual ~BusinessStateMachine();

    void handleState() {
        switch (state_) {
            case BSM::State::INICIAL : state_INICIAL(); break;
            case BSM::State::SETUP : State_SETUP(); break;
            case BSM::State::PRONTO : state_PRONTO(); break;
            case BSM::State::PROCESSANDO_JOB : state_PROCESSANDO_JOB(); break;
            case BSM::State::ERRO : state_ERRO(); break;            
        }            
    }
    
    BusinessStateMachine::State getState() { return state_; }
 
};

#endif /* BUSINESSSTATEMACHINE_H */

