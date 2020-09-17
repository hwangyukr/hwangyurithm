import numpy as np
from collections import defaultdict

def solution(words, queries):
    answer = []
    
    w = np.array(words)
    q = np.array(queries)
    d1 = defaultdict(lambda :defaultdict(lambda: 0))
    d2 = defaultdict(lambda :defaultdict(lambda: 0))
    
    for word in words:
        sz = len(word)
        for iter in range(sz):
            subword1 = word[iter:sz]
            d1[iter][subword1] += 1
            subword2 = word[0:sz-iter]
            d2[iter][subword2] += 1
    
    for query in queries:
        sz = len(query)
        head = tail = 0
        for iter in range(sz):
            if query[iter] == '?':
                head += 1
            else:
                break
        for iter in range(sz):
            if query[sz - 1 - iter] == '?':
                tail += 1
            else:
                break
        
        if head >= tail:
            answer.append(d1[head][query[head: sz]])
        else:
            answer.append(d2[tail][query[0: sz-tail]])
    return answer

def test():
    w = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    q = ["fro??", "????o", "fr???", "fro???", "pro?"]
    print(solution(w,q))
   print('aa')
   test()