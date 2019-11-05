# Code MQTT client for Esp8266 platform Arduino

### Server online :

- Server online test  : server itc team 
    - Broker address : itc-server.dynu.net
    - Broker port : 8883
    - Client ID : dfea65c5313c494c80f9aa9336c2d0dd
    - Enable SSL/TLS : CA signed server certificate 
    - Protocol : TLS v1.2
    - User name : user_mobile
    - Password : 123456

- Server online test  : server broker Cloud MQTT 
    - Broker address : 	tailor.cloudmqtt.com
    - Broker port :
        - port not SSL : 18989
        - port over SSL : 28989
        - port socket TSL only : 38989
    - User name : jwactjqv
    - Password : OtVca_zVKZO8
    - Client ID : name divice 
    - Enable SSL/TLS : CA signed server certificate 
    - Protocol : TLS v1.2
    - fingerprint  "39 DF B6 55 54 1D A4 53 12 70 65 DC 43 11 53 DA 3B A3 6E A8" .

### Library use ...
- thư viện mặc định của ESP8266 theo platfrom Arduino 
```
#include <ESP8266WiFi.h>
```

- The C Standard Library <stdint.h> header
```
#include <stdint.h>             
```

- Thư viện hỗ trợ MQTT của Adrafrit , dựa trên giao thức TCP/IP của ESP8266 .
- Toàn bộ Source code thư viện có trong folder /Library
```
#include <Adafruit_MQTT_Client.h>  
#include <Adafruit_MQTT.h>
```

- khai báo sử dụng class WiFiFlientSecure for SSL/TLS support 
```
WiFiClientSecure Client_SSL;
```

- cài đặt tham số đầu vào cho MQTT_Client
```
Adafruit_MQTT_Client MQTT_Client ( 
    &Client_SSL ,       // lấy từ khai báo sử dụng classs WiFiFlientSecure phía trên
    MQTT_SERVER ,       // tailor.cloudmqtt.com
    MQTT_SERVERPORT ,   // 28989 
    CID ,               // Client ID lấy tên của project hay tên của thiết bị đang hoạt động
    USERNAME,           // User name : jwactjqv lấy theo đăng ký với phía server
    PASSWORD            // Password : OtVca_zVKZO8
);       
```

- cài đặt tham số cho chắc năng publishing
```
Adafruit_MQTT_Publish MQTT_Publish (
    &MQTT_Client, 
    TOPIC ,         // TOPIC muốn tạo ví dụ  cliet1/channel1
    MQTT_QOS_1);    // Qos ( Qualities of service ) 
                    // #define MQTT_QOS_1 0x1  #define MQTT_QOS_0 0x0
                    // do vi xử lý thấp và đảm bảo tốc độ , nên thư viện chỉ hỗ trợ QoS0 QoS1 không có QoS2 
```
- cài đặt tham số cho chức năng subscribe
```
Adafruit_MQTT_Subscribe MQTT_Subscribe ( 
    &MQTT_Client, 
    TOPIC ,         // TOPIC muốn đăng ký vào 
    MQTT_QOS_1);    // QoS 
```

- cài đặt cấu hình wifi 
```
Function_Config_Wifi (WLAN_SSID , WLAN_PASS );
```
- chú ý : các hàm dưới đây phải để tuần tự không thay đổi .
- check fingerprint sác nhận chứng chỉ bảo mật (Security Certificate's Authentic Fingerprint)
- để lấy fingerprint có thể sử dụng thông qua web https://www.grc.com/fingerprints.htm hoặc nhiều cách khăc
```
Client_SSL.setFingerprint(fingerprint) ? s_pln ("/ Finger ok") : s_pln ("/ Finger not ok") ;
```
- gọi hàm sub trước khi chạy connect() , nếu để chạy sau sẽ không đăng ký đc 
```
MQTT_Client.subscribe (&MQTT_Subscribe);
```
- gọi hàm connect() và kiểm tra kết nối tới server , hàm này trả về giá trị 0 có nghĩ là đã kết nối thành công
```
MQTT_Client.connect() == 0 ? s_pln ("/ MQTT_Client connected ") : s_pln ("Error");
```

- Function đăng ký và pub data lên topic vừa đăng ký với server broker 
```
MQTT_Publish.publish(const char *data ); 
```

- Function nghe mes từ topic đăng ký với server với khoảng thời gian 
```
MQTT_Client.readSubscription(1000) ? 
    Serial.println((char *)MQTT_Subscribe.lastread) : // hàm này hiển thị mess đọc đc từ server 
    0x01;
```