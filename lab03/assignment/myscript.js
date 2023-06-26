let result = document.getElementById('result');
let expression = '';

function appendNumber(num) {
  expression += num;
  result.value = expression;
}

function appendOperator(operator) {
  expression += operator;
  result.value = expression;
}

function calculate() {
  try {
    let answer = eval(expression);
    result.value = answer;
    expression = '';
  } catch (error) {
    result.value = 'Error';
  }
}

function clearResult() {
  expression = '';
  result.value = '';
}

function calculateSin() {
  try {
    let value = parseFloat(result.value);
    let radian = value * (Math.PI / 180);
    let sinValue = Math.sin(radian);
    result.value = sinValue.toFixed(4);
  } catch (error) {
    result.value = 'Error';
  }
}

function calculateCos() {
  try {
    let value = parseFloat(result.value);
    let radian = value * (Math.PI / 180);
    let cosValue = Math.cos(radian);
    result.value = cosValue.toFixed(4);
  } catch (error) {
    result.value = 'Error';
  }
}

function calculateTan() {
  try {
    let value = parseFloat(result.value);
    let radian = value * (Math.PI / 180);
    let tanValue = Math.tan(radian);
    result.value = tanValue.toFixed(4);
  } catch (error) {
    result.value = 'Error';
  }
}

function calculateSquareRoot() {
  try {
    let value = parseFloat(result.value);
    let sqrtValue = Math.sqrt(value);
    result.value = sqrtValue.toFixed(4);
  } catch (error) {
    result.value = 'Error';
  }
}

function calculatePower() {
  try {
    let powerValue = eval(expression);
    let powValue = eval(powerValue);
    result.value = powValue;
    expression = '';
  } catch (error) {
    result.value = 'Error';
  }
}
