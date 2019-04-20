#lang racket

(provide empty-q empty-q? enq deq)

;; pure functional implementation of Queues 

(struct q (front back))

(define empty-q (q empty empty))

(define (empty-q? q) (and (q? q) (empty? (q-front q)) (empty? (q-back q))))

(define (enq que el) (q (cons el (q-front que)) (q-back que)))

(define (deq que) (cond
                    [(empty-q? q) que]
                    [(not (empty? (q-back que))) (q (q-front que) (cdr (q-back que)))]
                    [true (q empty (cdr (reverse (q-front que))))]))


