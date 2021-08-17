## 텍스트가 정해진 width를 넘어갈 때 처리하는 방법

#### 1. word-break
- 기본적으로 줄이 넘어갈 때는 단어 단위로 잘려서 넘어간다
- 한 단어가 width 보다 긴 경우 범위를 벗어나게 된다.
- 단어의 분리를 어떻게 할 것인가 결정하는 것이 word-break
- 언어에 따라 다양한 경우가 있지만, 한글과 영어에서 쉽게 보자면

```
word-break: normal;   // 공백 단위로 분리
word-break: break-all // 글자 단위로 분리
```

#### 2. word-wrap
- 단어가 width를 넘었을 때 넘친 단어를 줄바꿈 하고 싶다면 사용한다.
- 단어의 분리는 임의의 음절에서 시행
```
word-wrap: normal;     // 넘치는 단어 그대로
word-wrap: break-word; // 넘치는 단어 줄바꿈
```

#### 3. white-space
- 공백을 처리하는 방법(띄어쓰기, 탭, 엔터 등)
```
white-space: noraml;    // space, tap, enter -> 1칸 공백 / 자동 줄바꿈 o
white-space: nowrap;    // space, tap, enter -> 1칸 공백 / 자동 줄바꿈 x
white-space: pre;       // space, tap, enter -> 그대로 / 자동 줄바꿈 x
white-space: pre-wrap;  // space, tap, enter -> 그대로 / 자동 줄바꿈 o
white-space: pre-line;  // space, tap -> 1칸, enter -> 그대로 / 자동 줄바꿈 o
```
