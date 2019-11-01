# Example MQTT for MCUs
 note : tổng hợp tài liệu và code ví dụ phát triển MQTT trên vi điều khiển .

![alt text](https://raw.githubusercontent.com/mana147/Example-MQTT/master/DOCUMENT/mqtt_broker.png)

## Khái niệm cơ bản về MQTT 

- MQTT (Message Queuing Telemetry Transport) là một giao thức gởi dạng publish/subscribe ( xuất bản / theo dõi ) . 
- Giao thức thường chạy trên TCP / IP . Tuy nhiên, bất kỳ giao thức mạng nào cung cấp các kết nối hai chiều, không mất dữ liệu đều có thể hỗ trợ MQTT . 
- Được sử dụng cho các thiết bị với băng thông thấp , độ tin cậy cao và khả năng được sử dụng trong mạng lưới không ổn định.

_note :_ đọc lại tài liệu và nắm rõ về giao thức mạng TCP/IP .  

### Kiến trúc bậc cao của MQTT gồm **Broker** và **Client** .

- Broker như máy chủ chung tâm điều phối dữ liệu , có thể hiểu Broker là một app chạy trên Server, nhiệm vụ của nó bao gồm :
    - nhận message từ publis .
    - xếp các messge theo hàng đợi .
    - chuyển các message tới một địa chỉ cụ thể .
    - bảo mật mess
    - lưu trữ mess
    - logs ...

- Client for MQTT được chia thành  **Publisher** and **Subscriber** , nhiệm vụ của nó :
    - Subscribe (theo dõi / đăng ký) một topic để nhận mess từ topic này .
    - Publish mess ( gửi data ) lên một topic cụ thể ( topic tương tự như một kênh thông tin đc điều phối bởi Broker)
    - hoặc có thể vừa Publish vừa Subscribe 

### Cơ chế hoạt động cụ thể của Publisher và Subscribe

- mỗi một client sẽ đăng ký một kênh (topic) ví dụ "/client1/channel1" , "/client1/channel2" ... Quá trình này gọi là Subscribe 
- mỗi một client sẽ nhận dữ liệu khi có client khác gửi thông tin vào kênh topic đó , việc client đẩy data lên topic gọi là Publish .

### Qos ( Qualities of service ) .

note : QoS levels càng cao thì càng tin cậy hơn , nhưng delay sẽ lâu hơn và có yêu cầu băng thông cao hơn.

0. QoS0 : Broker / client sẽ gửi dữ liệu đúng 1 lần . quá trình gửi đc sác nhận bởi giao thức TCP/IP
1. QoS1 : Broker / client sẽ gửi dữ liệu với ít nhất 1 lần sác nhận từ đầu kia 
2. Qos2 : Broker / client đảm bảo khi gửi dữ liệu thì phía nhận đc đúng 1 lần , quá trình này phải trải qua 4 bước bắt tay .

![alt text](https://raw.githubusercontent.com/mana147/Example-MQTT/master/DOCUMENT/mqtt-publish-flow-qos-1.jpg)

![alt text](https://raw.githubusercontent.com/mana147/Example-MQTT/master/DOCUMENT/mqtt-publish-flow-qos-2.jpg)

Một gói tin data có thể đc client gửi ở bất kì levels QoS nào . các client có thể đăng ký nhận data ở bất kỳ levels QoS , ví dụ A gửi data bằng phương thức QoS2 vào kênh , thì B có thể nhận data bằng QoS0 hoặc bất kỳ .

![alt text](https://raw.githubusercontent.com/mana147/Example-MQTT/master/DOCUMENT/Broker_Client.png)

![alt text](https://raw.githubusercontent.com/mana147/Example-MQTT/master/DOCUMENT/MQTT_Server.jpg)

### Retained Messages (Flag)
note : tất cả các messages có thể thiết lập đc giữ lại , điều này có nghĩa là broker sẽ giữ lại messages ngay cả khi nó đã đc gửi cho các client 
- Retain là một cờ (flag) đc gắn vào message của giao thức MQTT .
- Retain chỉ nhận giá trị 0 = false và 1 = true.
- Cơ chế hoạt động :
    - Nếu Retain = 1 : broker sẽ lưu lại message cuối cùng topic kèm theo QoS tương ứng , khi có client đăng ký vào topic thì clien này sẽ ngay lập tức nhận đc message. 


### MQTT Bridge 
note : MQTT Bridge là một tính năng của MQTT cho phép các MQTT Broker có thể tạo cầu nối (bridge) kết nối với nhau để chao đổi dữ liệu , cần 2 broker để tạo cầu nối , trong đó một broker bất kỳ đc cấy hình thành Bridge , cần những thông số sau :
- address : địa chỉ của broker cần kết nối 
- bridge_protocol_version : phiên bản giao thức MQTT đang được sử dụng chung cho 2 broker
- topic  phần này định nghĩa 3 tham số :
    - tên topic chao đổi dữ liệu giữa 2 broker
    - chiều chao đổi , 1 chiều hoặc 2 chiều
    - topic mapping giữa 2 broker
