#lang racket
(provide empty-q empty-q? enq deq)
 
;; imperatve implementation of a mutable Queue

(define-struct q (vec start end) #:transparent)

(define (empty-q size) (make-q (make-vector (add1 size)) 0 0))

(define (empty-q? q) (= (q-start q) (q-end q)))


(define (enq que el) (cond
                       [true
                        (begin
                          (define v (q-vec que))
                          (define new-start (remainder (add1 (q-start que)) (vector-length v)))
                          (vector-set! v (q-start que) el)
                          (make-q v new-start (q-end que)))]))

(define (deq que) (cond [(empty-q? que) que]
                        [(= (vector-length (q-vec que)) (q-end que)) (make-q (q-vec que) (q-start que) 0)]
                        [true (make-q (q-vec que) (q-start que) (add1 (q-end que)))]))

