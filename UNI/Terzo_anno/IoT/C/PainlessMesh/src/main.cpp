#include <painlessMesh.h>
#include <iot_board.h>

#define MESH_PREFIX   "iotMesh"     // mesh SSID, same on all nodes
#define MESH_PASSWORD "meshPass123" // WPA2 key of the mesh links
#define MESH_PORT     5555          // TCP port between nodes
 
Scheduler userScheduler;            // TaskScheduler, shared with mesh
painlessMesh mesh;


void sendMessage();
Task taskSendMessage(TASK_SECOND * 1, TASK_FOREVER, &sendMessage);

void sendMessage() {
  String msg = "Hi from node " + String(mesh.getNodeId());
  mesh.sendBroadcast(msg);
  taskSendMessage.setInterval(random(TASK_SECOND, TASK_SECOND * 5));
}

void receivedCallback(uint32_t from, String &msg) {
  Serial.printf("From %u: %s\n", from, msg.c_str());
}




void setup() {
  // put your setup code here, to run once:

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();


  mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT);
  mesh.onReceive(&receivedCallback);
  userScheduler.addTask(taskSendMessage);
  taskSendMessage.enable();


}

void loop() {
  // put your main code here, to run repeatedly:
  mesh.update();
}
