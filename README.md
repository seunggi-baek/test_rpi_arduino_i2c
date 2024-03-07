# test_rpi_arduino_i2c

## i2c-tools 설치 (라즈비안에 이미 설치되어있음)
sudo apt-get install i2c-tools

## libi2c-dev 설치
sudo apt-get install libi2c-dev

## 아두이노 address 확인
sudo i2cdetect -y 1

## python3-smbus 설치 (라즈비안 이미 설치되어있음)
sudo apt-get install python3-smbus

## 기타 참고사항
### 라즈비안에서 raspi-config를 통한 I2C 활성화 가능
### vim /etc/modules 파일에 i2c-dev 확인

