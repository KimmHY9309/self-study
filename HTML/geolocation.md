# Geolocation API 사용하기
- 사용자의 위치를 가져오는 API

![image](https://user-images.githubusercontent.com/68420164/129735592-9f295d4a-ad04-479b-867d-45ccc4e416e6.png)

- script에서 바로 확인 가능
```
if('geolocation' in navigator) {
  /* 위치정보 사용 가능 */
} else {
  /* 위치정보 사용 불가능 */
}
```
- 위도와 경도를 받을 수 있다.
```
navigator.geolocation.getCurrentPosition((position) => {
  let lat = position.coords.latitude;  // 위도
  let lng = position.coords.longitude; // 경도
});
```
