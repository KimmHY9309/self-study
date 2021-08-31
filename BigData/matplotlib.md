## matplotlib.pyplot

https://wikidocs.net/book/5011

#### 그래프 생성
```
plt.plot([list])        # list가 y라고 가정하고, x는 index로 자동 부여
plt.plot([list],[list]) # 두 개의 인자를 넣으면 x-y로 그려준다
plt.show()              # 만든 그래프를 화면에 띄워준다.
```

#### 스타일 지정
```
plt.plot(..., 'ro')                 # 마커모양과 색을 지정한다 'r': red, 'o': 원형
plt.axis([xmin, xmax, ymin, ymax])  # x와 y의 범위를 설정한다.
```

#### 여러개 그래프 그리기
```
plt.plot(t, t, 'r--', t, t**2, 'bs', t, t**3, 'g^') # 한 화면에 3개의 그래프가 그려진다.
```

#### 레이블이 있는 데이터(dict) 사용하기
```
data_dict = {'data_x': [1, 2, 3, 4, 5], 'data_y': [2, 3, 5, 10, 8]}

plt.plot('data_x', 'data_y', data=data_dict)  # 그래프를 만들 때 key 값을 넣고 data 파라미터로 딕셔너리를 지정한다.
plt.show()
```

#### 축 레이블 설정하기
```
plt.xlabel('X-Label')  # x축 이름
plt.ylabel('Y-Label')  # y축 이름

plt.xlabel('X-Axis', labelpad=15)  # 여백 설정
plt.ylabel('Y-Axis', labelpad=20)

plt.xlabel('X-Axis', labelpad=15, fontdict=font1)  # 폰트 설정
font1 = {'family': 'serif',
         'color': 'b',
         'weight': 'bold',
         'size': 14
         }
         
plt.xlabel('X-Axis', loc='right')   # 위치 지정
plt.ylabel('Y-Axis', loc='top')
```

#### 축 스케일 설정하기
```
plt.yscale('linear')  # 선형적으로 증가
plt.yscale('log')     # 지수적으로 증가
```

#### 여러 그래프 그리기(subplot)
```
plt.subplot(2, 1, 1)   # 가로 개수, 세로 개수, 순서 
plt.plot(...)

plt.subplot(2, 1, 2)
plt.plot(...)
```
