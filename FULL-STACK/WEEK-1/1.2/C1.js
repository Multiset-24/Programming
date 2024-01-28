//this is just the basic of the javascript
{
  console.log("hello saurav");

  //there is no data type in the javascript
  let a = 5;
  a = "i am ghost";

  // this is how you print some thing in the console
  console.log(a);

  //this is how you use for loop in the js
  for (let i = 0; i < 5; i++) {
    console.log(i);
  }

  //this is how you form arrays in javascript
  const ages = [12, 21, 45, 2, 25];

  for (let i = 0; i < ages.length; i++) {
    console.log(ages[i]);
  }

  //this is how you find the max value in the array
  let num = Number.MIN_VALUE;

  for (let i = 0; i < ages.length; i++) {
    if (num < ages[i]) {
      num = ages[i];
    }
  }
  console.log(num);

  const person1 = {
    name: "Saurav",
    age: 21,
    city: "delhi",
  };

  const person2 = {
    name: "sneha",
    age: 20,
    city: "Mumbai",
  };

  console.log(person1.name, person2.name);

  const array_objects = [
    {
      name: "saurav",
      age: 21,
      city: "delhi",
    },
    {
      name: "sneha",
      age: 20,
      city: "Mumbai",
    },
  ];

  console.log(array_objects[0].name, array_objects[1].name);

  var b = 5;

  console.log(b);
  b = 10;

  console.log(b);

  function result(a, b, type) {
    if (type == "addition") {
      return a + b;
    } else if (type == "subtraction") {
      return a - b;
    } else if (type == "multiplication") {
      return a * b;
    } else if (type == "division") {
      return a / b;
    }

  }
  let c = 1*result(2, 3, "division");
  console.log(c);

  //callback
{
  function add(a, b) {
    return a + b;
  }

  function subtract(a, b) { 
    return a - b;
  }

  function multiply(a, b) {
    return a * b;
  }

  function divide(a, b) {
    return a / b;
  }

  function calculate(a, b, arithmetic) {
     return arithmetic(a,b);
  }

  let dig=calculate(3,4,add);
  console.log(dig);
}


}
