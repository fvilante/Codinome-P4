/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JobConsumer.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 03:37
 */

#ifndef JOBEXECUTOR_H
#define JOBEXECUTOR_H

#include "JobProducer.h"

class JobConsumer {

    JobProducer& geradorDeJobs_;
    bool isEnabled_ = false;
    
    
public:
    
    JobConsumer() = delete;
    //JobConsumer(JobGenerator& j, JobExecutor e) : geradorDeJobs_(j) { }
    JobConsumer(const JobConsumer& orig) = delete;
    virtual ~JobConsumer() { };
    
    void enable() { isEnabled_ = true; }
    void disable() { isEnabled_ = false; }
    void executeNextJob() { 
        if(!isEnabled_) 
            return; 
        return;
    } 
    


};

#endif /* JOBEXECUTOR_H */

