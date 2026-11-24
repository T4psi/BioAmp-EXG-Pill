// This program will sample data from an EMG and calculate a muscle tension amplitude

#define SAMPLE_RATE 1000
#define BAUD_RATE 115200
#define BUFFER_SIZE 128
#define INPUT_PIN A0

int circular_buffer[BUFFER_SIZE];
int data_index;
int sum;
int sampling_time = 1000000/SAMPLE_RATE;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  static unsigned long last_time = 0;
  unsigned long current_time = micros();
  
  if ((current_time - last_time) > sampling_time) {
    last_time = current_time;
    int signal_raw = analogRead(INPUT_PIN);
    int signal_filt = filterSignal(signal_raw);
    float muscle_tension = calculate_envelop(signal_filt);
  }
}

float calculate_envelop(int signal) {
  sum -= circular_buffer[data_index];
  sum += signal;
  circular_buffer[data_index] = signal;
  data_index = (data_index + 1) % BUFFER_SIZE;
  return(sum/BUFFER_SIZE);
}
