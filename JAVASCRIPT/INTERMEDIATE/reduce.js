//reduce function
//reduce is a function that takes an array and reduces it to a single value

//syntax
// const result = arr.reduce(callback(accumulator, currentValue[, index[, array]])[, initialValue]);
//callback: Function to execute on each element in the array, taking four arguments:
//accumulator: The accumulator accumulates the callback's return values. It is the accumulated value previously returned in the last invocation of the callback, or initialValue, if supplied (see below).
//currentValue: The current element being processed in the array.
//index (optional): The index of the current element being processed in the array. Starts from index 0 if an initialValue is provided. Otherwise, it starts from index 1.
//array (optional): The array reduce was called upon.
//initialValue (optional): A value to use as the first argument to the first call of the callback. If no initialValue is supplied, the first element in the array will be used as the initial accumulator value and skipped as currentValue. Calling reduce() on an empty array without an initialValue will throw a TypeError.
//Example 1
//sum of all elements in an array
const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
const sum = arr.reduce((accumulator, currentValue)=>{
    return accumulator + currentValue;
},0)
console.log(sum);
