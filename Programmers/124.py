def solution(n):
    answer = ''
    result = ''
    while (n):
        
        if (n % 3 == 0):
            answer = answer + '4'
            n = n//3-1
            
        else:
            answer = answer + str(n % 3)
            n = n//3
    
    result = "".join(reversed(answer))
    return result
