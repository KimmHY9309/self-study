## Folium
- 지도 데이터 시각화

#### 라이브러리 설치
```
pip install folium
import folium

folium.__version__ # 버전 확인
```

#### 지도 생성
```
center = [37.541, 126.986]                      # 서울의 위도, 경도
m = folium.Map(location=center, zoom_start=10)  # 위치, 확대 레벨
```

#### 원 만들기
```
folium.Circle(
  location,      # 위치(lat, lon), tuple[float, float]
  radius,        # 원 크기(meter), float
  popup=None,    # 클릭 시 보여주는 것?, string or folium.Popupm
  tooltip=None,  # 마우스 호버시 보여주는 것, str or folium.Tooltip
  **kwargs)      # other options
```
![image](https://user-images.githubusercontent.com/68420164/131621285-e2c90393-8649-4811-865e-a46220ee9d45.png)
