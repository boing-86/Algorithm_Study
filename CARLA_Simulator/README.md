Coursera Introduction to Self-Driving Cars

*구체적인 것은 CARLA setup for Windows 공식 문서를 참고해주세요!

### 준비하기

1. HW : 여러가지 스펙 요구사항이 있었지만 저에겐 어차피 실습실 컴퓨터밖에 답이 없었기 때문에 그냥 했습니다.
2. Software : CARLA 시뮬레이터 다운로드 받아서 압출 풀고 시작함
    - 윈도우7 64bit 이상
    - 2000~2002 방화벽 포트 접근 가능
    - OpenGL 3.3 이상, DirectX10 이상 → CARLA 바이너리 불러올 때 알아서 됨
    - Python : 3.6.x
        
        ```powershell
        >python —version
        ```
        
        ```powershell
        >python -m pip —version
        ```
        ```powershell
        > python -m pip install -r C:\(위치)\CarlaSimulator\requirements.txt--user
        ```
 
### 설치하기

- CARLA Window 버전 설치하고 아래 실행
- Default Map 으로 시뮬레이터를 로딩하기
    
    ```powershell
    >CarlaUE4.exe -windowed -carla-no-networking
    ```
    ```powershell
    >CarlaUE4.exe /Game/Maps/RaceTrack -windowed -carla-server -benchmark -fps=20
    ```
