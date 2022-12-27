(defn word-lengths [string]
  ;; Split the string into a list of words
  (let [words (clojure.string/split string #"\s+")]
    ;; Create the result map with a map comprehension
    (into {} (for [word words] [word (count word)]))))

;; Test the function
(word-lengths "Hello everyone")
;; Returns: {"Hello" 5, "everyone" 8}
