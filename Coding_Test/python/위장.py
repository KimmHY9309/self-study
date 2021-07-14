def solution(clothes):
    answer = 1
    
    # {종류 : 갯수} 딕셔너리 생성
    # 입력(clothes)을 조회하면서 의상의 종류를 key로 넣고 초기 개수를 1로 설정
    # 이미 있는 종류일 경우 value값을 +1 해준다
    clothe = {}
    for i in clothes:
        if i[1] in clothe:
            clothe[i[1]] += 1
        else:
            clothe[i[1]] = 1
            
    # 모든 경우의 수를 구하기 위해 각 종류+1(안입는 경우 포함)의 값을 곱해주고
    # 모두 안 입는 경우인 1을 빼준다
    for i2 in clothe:
        answer *= (clothe[i2]+1)
    return answer - 1
