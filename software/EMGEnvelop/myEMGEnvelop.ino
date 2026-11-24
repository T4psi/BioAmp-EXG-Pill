// This program will sample data from an EMG and calculate a muscle tension amplitude

#define SAMPLE_RATE 1000
#define BAUD_RATE 115200
#define BUFFER_SIZE 128
#define INPUT_PIN A0

int circular_buffer[BUFFER_SIZE];
int data_index;
int sum;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  static unsigned long last_time = 0;
  if () {
    unsigned long current_time = micros()
    static int emg_raw = analogRead(INPUT_PIN);
    int muscle_tension = calculate_envelop(emg_raw);
  }
}

int calculate_envelop(int raw_signal) {

}
