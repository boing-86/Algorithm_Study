def solution(mats, park):
    answer = 0
    
    new_matrix = []
    
    for i in park :
        i_mats = []
        for j in i :
            if j.lstrip("-").isdigit() :
                i_mats.append(1)
            else :
                i_mats.append(0)
        new_matrix.append(i_mats)
        
    # print(new_matrix)
    
    dx = [-1, 0, -1]
    dy = [0, -1, -1]
    
    x = len(new_matrix)
    y = len(new_matrix[0])
    max_val = 0
    
    for i in range(1, x) :
        for j in range(1, y) :
            if (new_matrix[i][j] != 0) :
                around = []
                for k in range(0, 3) :
                    nx = i + dx[k]
                    ny = j + dy[k]
                    around.append(new_matrix[nx][ny])
                new_matrix[i][j] = min(around) + 1
                max_val = max(max_val, new_matrix[i][j])
    if max_val == 0 :
        return -1
    
    answer = -1
    for x in mats :
        if (x <= max_val) :
            answer = max(answer, x)
    
    return answer