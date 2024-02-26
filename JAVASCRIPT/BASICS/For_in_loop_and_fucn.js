let students = {
  Name: "saurav",
  Class: "10th",
  Roll_no: "10",
};

{
  // for in loop for object- it will print the key of the object
  for (let x in students) {
    console.log(x);
  }

  let arr = ["saurav", "sneha", "ashutosh"];

  // for in loop for array- it will print the index of the array
  for (let x in arr) {
    console.log(x);
  }

  //for of loop for array- it will print the value of the array
  for (let x of arr) {
    console.log(x);
  }
  //for of loop for object- it will give error
}

/*--------------FUNCTIONS-----------------*/

{
  //function expression with arrow function
  const sum = (a, b) => {
    console.log(a + b);
  };

  sum(69, 88);

  //function expression
  const sum1 = function (a, b) {
    console.log(a + b);
  };

  sum1(69, 88);
}
