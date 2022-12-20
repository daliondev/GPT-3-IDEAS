(defn collatz [n]
  "Applies the Collatz conjecture to the number n until it reaches 1 and returns the list of numbers and the number of iterations."
  (loop [n n collatz-list [n] counter 1]
    (if (not= n 1)
      (if (even? n)
        (recur (quot n 2) (conj collatz-list (quot n 2)) (inc counter))
        (recur (+ (* n 3) 1) (conj collatz-list (+ (* n 3) 1)) (inc counter)))
      [collatz-list counter])))

(def collatz-list (first (collatz 27)))

; Print the list of numbers
(println collatz-list)

; Print the number of iterations
(println (count collatz-list))

; Find the maximum number in the list
(println (apply max collatz-list))
