int pwmA = 32;
int pwmB = 33;
int pwmC = 25;


#define _constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

float voltage_power_supply=12.6;
float shaft_angle=0,open_loop_timestamp=0;
float zero_electric_angle=0,Ualpha,Ubeta=0,Ua=0,Ub=0,Uc=0,dc_a=0,dc_b=0,dc_c=0;


void setup() {
  // put your setup code here, to run once:
    //设置串口波特率
    Serial.begin(115200);
    //PWM设置

    pinMode(pwmA, OUTPUT);
    pinMode(pwmB, OUTPUT);
    pinMode(pwmC, OUTPUT);
    ledcAttachPin(pwmA, 0);
    ledcAttachPin(pwmB, 1);
    ledcAttachPin(pwmC, 2);
    ledcSetup(0, 30000, 8);  //pwm频道, 频率, 精度
    ledcSetup(1, 30000, 8);  //pwm频道, 频率, 精度
    ledcSetup(2, 30000, 8);  //pwm频道, 频率, 精度
    Serial.println("完成PWM初始化设置");
    delay(3000);
_normalizeAngle(1);
}

// 电角度求解
float _electricalAngle(float shaft_angle, int pole_pairs) {
  return (shaft_angle * pole_pairs);
}

float _normalizeAngle(float angle){
    float a = fmod(angle, 2);
    Serial.print(a,DEC);
   return a >= 0 ? a : (a + 2*PI);
}

void loop() {
  // put your main code here, to run repeatedly:
    
    delay(3000);
}
