//filtering

//filtering is a method that creates a new array with all elements that pass the test implemented by the provided function.

//syntax
// const newArray = arr.filter(callback(element[, index[, array]])[, thisArg])

//callback: Function is a predicate, to test each element of the array. Return true to keep the element, false otherwise. It accepts three arguments:
//element: The current element being processed in the array.
//index (optional): The index of the current element being processed in the array.
//array (optional): The array filter was called upon.
//thisArg (optional): Object to use as this when executing callback.

//Example 1

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];

const newArr = arr.filter((value) => {
    return value >= 7 || value <= 3;
})

console.log(newArr);