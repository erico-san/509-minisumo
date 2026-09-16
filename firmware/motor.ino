// Configuración de los pines y PWM para los motores
void config_motor(){
  // Configuración de los pines de los motores
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, a_red);  // Motor 1 - Canal A
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, a_black);  // Motor 1 - Canal B
  mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM0A, b_red);  // Motor 2 - Canal A
  mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM0B, b_black);  // Motor 2 - Canal B


  // Configuración del PWM
  mcpwm_config_t pwm_config;
  pwm_config.frequency = 1000;  // Frecuencia de 1kHz
  pwm_config.cmpr_a = 0;        // Ciclo de trabajo inicial canal A
  pwm_config.cmpr_b = 0;        // Ciclo de trabajo inicial canal B
  pwm_config.counter_mode = MCPWM_UP_COUNTER;
  pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

  mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);  // Motor 1
  mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_0, &pwm_config);  // Motor 2
}

void motor(int wa, int wb) {

  wa = constrain(wa, -99, 99);
  wb = constrain(wb, -99, 99);

  // Control Motor A
  if (wa > 0) {
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);  // IN2 bajo
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, wa);  // IN1 modulado
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  } else if (wa < 0) {
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);  // IN1 bajo
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, -wa);  // IN2 modulado
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  } else {
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);  // Mantener IN1 bajo
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);  // Mantener IN2 bajo
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 0);
  }

  // Control Motor B
  if (wb > 0) {
    mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_B);  // IN2 bajo
    mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A, wb);  // IN1 modulado
    mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  } else if (wb < 0) {
    mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A);  // IN1 bajo
    mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_B, -wb);  // IN2 modulado
    mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  } else {
    mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A);  // Mantener IN1 bajo
    mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_B);  // Mantener IN2 bajo
    mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM_OPR_A, 0);
  }
}
