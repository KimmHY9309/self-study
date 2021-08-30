## pandas.DataFrame
#### DataFrame 조회
```
DataFrame.loc[[index], [columns]]
- 배열 형태가 아닐 경우 값만 리턴 ex) df.loc['1월', '이익'] => 25
- 배열 형태로 넣을 경우 DF 리턴   ex) df.loc[['1월'], ['이익']]
- 조건 넣을 수 있음               ex) df.loc[:, df.columns != '매출액']
- ':': 전체 선택
- 매개변수 하나만 넣을 경우 행으로 인식 -> [[]] , 전체 행 + 특정 열 선택하는 경우 -> loc[:, []] 
```

#### DataFrame 정렬
```
DataFrame.sort_values(
        by=['score'],     # 정렬할 기준 변수
        axis=0,           # 0 or 'index' / 1 or 'columns'
        ascending=False,  # True: 오름차순 / False: 내림차순
        inplace,          # DataFrame 자체를 정렬해서 저장
        kind='quicksort', # 정렬 알고리즘
        ma_position='last'# NaN 데이터를 'first'에 두거나 'last'에 두거나
    )
```

#### DataFrame 평균
```
DataFrame.mean( axis=None,          # 'row' or 0 / 'columns' or 1
                skipna=None,        # NaN 값 포함(True) / 제외(False)
                level=None,         # 축이 multiindex인 경우 특정 수준과 함께 계산
                numeric_only=None,  # numeric_only = True의 경우 float,int 및boolean 열만 포함합니다
                **kwargs)           # 함수에 대한 추가 키워드 인수입니다.
```
