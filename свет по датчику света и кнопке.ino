// Пин, через который датчик света передает данные
#define light_pin A2
// Пин, на котором установлен светодиод
#define led_pin 13
// Пин, на котором установлена кнопка
#define btn_pin 3

int light_state; // Переменная для хранения состояния света
bool btn_state; // Булева переменная, отвечающая за состояние кнопки (нажата/не нажата)

void setup() {
  pinMode(led_pin, OUTPUT); // Установка режима пина светодиода на вывод
  pinMode(light_pin, INPUT); // Установка режима пина датчика света на ввод
  pinMode(btn_pin, INPUT); // Установка режима пина кнопки на ввод
  Serial.begin(9600); // Инициализация последовательной связи для вывода данных в монитор порта
}

void loop() {
  light_state = analogRead(light_pin); // Считывание значения с датчика света
  Serial.println(light_state); // Вывод значения состояния света в монитор порта
  btn_state = digitalRead(btn_pin); // Считывание значения с кнопки
  if (light_state <= 500 && btn_state) {
    digitalWrite(led_pin, HIGH); // Включение светодиода, если значение света ниже или равно 500 и кнопка нажата
  }
  else {
    digitalWrite(led_pin, LOW); // Выключение светодиода в противном случае
  }
}
