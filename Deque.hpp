//
//  1.hpp
//  OO_as1
//
//  Created by Darren on 9/13/21.
//

#ifndef __hpp
#define __hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define Deque_DEFINE(t) \
    struct Deque_##t; \
    /* new struct */ \
    struct Deque_##t##_Iterator { \
        int index; \
        Deque_##t* deq; \
        /* functions below*/ \
        t &(*deref)(Deque_##t##_Iterator *); \
        void &(*inc)(Deque_##t##_Iterator *); \
\
    }; \
    /* new struct */\
    struct Deque_##t { \
        int head;\
        int tail;\
        int deq_size; \
        t* arr; \
        char type_name[6 + sizeof(t)] = "Deque_"#t;\
        \
        /* functions below */ \
        \
        t &(*front)(Deque_##t *); \
        t &(*back)(Deque_##t *); \
        void (*push_front)(Deque_##t *, t info); \
        void (*push_back)(Deque_##t *, t info); \
        void (*pop_front)(Deque_##t *); \
        void (*pop_back)(Deque_##t *); \
        int (*size)(Deque_##t *); \
        bool (*empty)(Deque_##t *); \
        Deque_##t##_Iterator (*begin)(Deque_##t *); \
        Deque_##t##_Iterator (*end)(Deque_##t *); \
        t &(*at)(Deque_##t *, int index); \
        void (*clear)(Deque_##t *); \
        void (*dtor)(Deque_##t *); \
    }; \
\
\
    /* function implement */ \
\
    t &Deque_##t##_front (Deque_##t* deq) { \
        return deq->arr[deq->head]; \
    } \
\
    t &Deque_##t##_back (Deque_##t* deq) { \
        return deq->arr[deq->tail]; \
    } \
\
    void Deque_##t##_push_front (Deque_##t* deq, t info) { \
        deq->tail ++; \
        for (int i=deq->tail; i>deq->head; i--) { \
            deq->arr[i] = deq->arr[i-1]; \
        } \
        deq->arr[deq->head] = info; \
        deq->deq_size ++; \
    } \
\
    void Deque_##t##_push_back (Deque_##t* deq, t info) { \
        deq->tail ++; \
        deq->arr[deq->tail] = info; \
        deq->deq_size ++; \
    } \
\
    void Deque_##t##_pop_front (Deque_##t* deq) { \
        if (deq->deq_size > 0) { \
            for (int i=deq->head; i<deq->tail; i++) { \
                deq->arr[i] = deq->arr[i+1]; \
            } \
            deq->tail --; \
            deq->deq_size --; \
        } else { \
            printf("Pop Front: Nothing to pop!\n"); \
        } \
    } \
\
    void Deque_##t##_pop_back (Deque_##t* deq) { \
        if (deq->deq_size > 0) { \
            deq->tail --; \
            deq->deq_size --; \
        } else { \
            printf("Pop Back: Nothing to pop!\n"); \
        } \
    } \
\
    int Deque_##t##_size (Deque_##t* deq) { \
        return deq->deq_size\
    } \
\
    bool Deque_##t##_empty (Deque_##t* deq){ \
        if (deq->deq_size == 0){ \
            return true; \
        } else { \
            return false; \
        }\
    }\
\
    Deque_##t##_Iterator (*begin)(Deque_##t* deq) { \
        Deque_##t##_Iterator it; \
        it->index = deq->head; \
        it->deq = deq; \
    } /* not finished */\
\
    Deque_##t##_Iterator (*end)(Deque_##t* deq) { \
        Deque_##t##_Iterator it; \
        it->index = deq->tail; \
        it->deq = deq; \
    } /* not finished */\
\
    t &Deque_##t##_at (Deque_##t* deq, int index) { \
        if (index < 0 && index >= deq->deq_size) { \
            printf("At: Bad index!\n");\
            return null; \
        } else { \
            return deq->arr[deq->head + i];\
        } \
    } \
\
    void Deque_##t##_clear (Deque_##t* deq) { \
        deq->head = 0; \
        deq->tail = 0; \
        deq->deq_size = 0; \
    } \
\
    void Deque_##t##_dtor (Deque_##t* deq) { \
        free(deq->arr); \
        deq = nullptr; \
    } \
\
    /* outside functions */\
    void Deque_##t##_ctor (Deque_##t* deq, bool (*less)(const t &, const t &)) { \
        deq->head = 0; \
        deq->tail = 0; \
        deq->deq_size = 0; \
        deq->arr = (t*)malloc(100 * sizeof(t)); \
        deq->type_name = "Deque_"#t; \
        deq->front = &Deque_##t##_front; \
        deq->back = &Deque_##t##_back; \
        deq->push_front = &Deque_##t##_push_front; \
        deq->push_back = &Deque_##t##_push_back; \
        deq->pop_front = &Deque_##t##_pop_front; \
        deq->pop_back = &Deque_##t##_pop_back; \
        deq->size = &Deque_##t##_size; \
        deq->empty = &Deque_##t##_empty; \
        deq->at = &Deque_##t##_at; \
        deq->clear = &Deque_##t##_clear; \
        deq->dtor = &Deque_##t##_dtor; \
    } \
\


#endif
