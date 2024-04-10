/*
  Implement a class `Calculator` having below methods
    - initialise a result variable in the constructor and keep updating it after every arithmetic operation
    - add: takes a number and adds it to the result
    - subtract: takes a number and subtracts it from the result
    - multiply: takes a number and multiply it to the result
    - divide: takes a number and divide it to the result
    - clear: makes the `result` variable to 0
    - getResult: returns the value of `result` variable
    - calculate: takes a string expression which can take multi-arithmetic operations and give its result
      example input: `10 +   2 *    (   6 - (4 + 1) / 2) + 7`
      Points to Note: 
        1. the input can have multiple continuous spaces, you're supposed to avoid them and parse the expression correctly
        2. the input can have invalid non-numerical characters like `5 + abc`, you're supposed to throw error for such inputs

  Once you've implemented the logic, test your code by running
*/

class Calculator {
    result;
       constructor(){
        this.result = 0;
      }

      add(num){
        this.result += num;
      }

      subtract(num){
        this.result -= num;
      }

      multiply(num){
        this.result *= num;
      }

      divide(num){
        if(num!=0){
        this.result /= num;
        }
        else{
          throw new Error('Division by zero is not allowed');//throwing error if division by zero means num=0
        }
      }

      clear(){
        this.result = 0;
      }


      getResult(){
        return this.result;
      }
      
      calculate(expression){
        let result = 0;
        let num = 0;
        let operator = '+';
        let stack = [];
        for(let i = 0; i < expression.length; i++){
          if(expression[i] === ' '){
            continue;
          }
          if(expression[i] === '('){
            stack.push(result);
            stack.push(operator);
            result = 0;
            operator = '+';
          }else if(expression[i] === ')'){
            num = result;
            operator = stack.pop();
            result = stack.pop();
            if(operator === '+'){
              result += num;
            }else if(operator === '-'){
              result -= num;
            }else if(operator === '*'){
              result *= num;
            }else if(operator === '/'){
              result /= num;
            }
          }else if(expression[i] === '+' || expression[i] === '-' || expression[i] === '*' || expression[i] === '/'){
            operator = expression[i];
          }else{
            let j = i;
            while(j < expression.length && expression[j] >= '0' && expression[j] <= '9'){
              num = num * 10 + parseInt(expression[j]);
              j++;
            }
            i = j - 1;
            if(operator === '+'){
              result += num;
            }else if(operator === '-'){
              result -= num;
            }else if(operator === '*'){
              result *= num;
            }else if(operator === '/'){
              result /= num;
            }
          }
        }
        return result;
      }


}

module.exports = Calculator;
