#lang racket

(define stack empty)
(define (pop) (begin (define x (car stack)) (set! stack (cdr stack)) x))
(define (fetch) (begin (define x (car stack)) x))
(define (insert n) (set! stack (cons n stack)))


(define (error-check-2 op) (if (>= (length stack) 2) void
                               (error (string-append op ": This operation requires at least 2 elements to be in the stack. Stack currently hold only " (number->string (length stack)) " element."))))

(define (interp l) (cond [(empty? l) stack]
                         [true (begin (define x (car l))
                                      (match x
                                        [`(mult) (begin (error-check-2 "mult") (define a (pop)) (define b (pop)) (insert (* a b)))]
                                        [`(add) (begin (error-check-2 "add") (define a (pop)) (define b (pop)) (insert (+ a b)))]
                                        [`(sub) (begin (error-check-2 "sub") (define a (pop)) (define b (pop)) (insert (- a b)))]
                                        [`(div) (begin (error-check-2 "div") (define a (pop)) (define b (pop)) (insert (/ a b)))]
                                        [`(mod) (begin (error-check-2 "mod") (define a (pop)) (define b (pop)) (insert (remainder a b)))]
                                        [`(swap) (begin (error-check-2 "swap") (define a (pop)) (define b (pop)) (insert a) (insert b))]
                                        [`(push ,n) (begin (insert n))]
                                        [`(pop) (begin pop)]
                                        [`(print) (begin (println (fetch)))]
                                        )
                                      (interp (cdr l)))]))

(define prog `((push 3) (push 4) (mult) (print)))
(interp prog)






