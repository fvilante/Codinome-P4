/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: Flavio
 *
 * Created on 26 de Abril de 2018, 12:58
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <stddef.h>

template <class T>
class Queue {
    std::queue<T> fila_;

public:
    Queue() = default;
    Queue(const Queue& orig) = default;
    virtual ~Queue() { };

    //retorna uma copia do objeto, remove ele da fila
    T pullFront() {
        if(isEmpty()) {
            return T();
        } else {
            T item = fila_.front();
            fila_.pop();
            return item;
        }
    }
    
    //insere um objeto no final da fila
    void pushBack(const T obj) {
        fila_.push(obj);
        
    }
    //retorna uma copia do proximo objeto da fila porém nao o retira da fila
    T peekFront() const {
        T item = fila_.front();
        return item;
    }
    //numero de objetos na fila
    size_t size() {
        return fila_.size();
    }
    // verdadeiro se a fila estivar vazia
    bool isEmpty() const { 
        return fila_.empty();
    }

    void clear() {
        while(!fila_.empty()) {
            fila_.pop();
        }
    }

    //bool operator==(const Queue<T> other) {
    //    for (size_t k=0; k<fila_.s)
    //}

};

#endif /* QUEUE_H */

