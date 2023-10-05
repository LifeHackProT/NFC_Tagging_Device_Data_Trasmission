import serial

# 시리얼 포트와 통신할 객체 생성
ser = serial.Serial('COM3', 115200)  # COM 포트 번호와 보레이트(baud rate) 설정

# 파일에 저장할 경로와 파일 이름 설정
file_path = 'C:/dev/data.txt'

# 파일 열기
file = open(file_path, 'w')

# 시리얼 데이터 읽기 및 저장
try:
    while True:
        # 시리얼 데이터 읽기
        data = ser.readline().decode().strip()

        # 읽은 데이터를 파일에 저장
        file.write(data + '\n')
        file.flush()  # 버퍼 비우기

        print(data)  # 옵션: 콘솔에 데이터 출력

except KeyboardInterrupt:
    pass

# 파일과 시리얼 포트 닫기
file.close()
ser.close()
