# Example MQTT for MCUs
 note : tổng hợp tài liệu và code ví dụ phát triển MQTT trên vi điều khiển .

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
 