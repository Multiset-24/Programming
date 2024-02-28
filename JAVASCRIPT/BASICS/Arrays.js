/*-------------This covers the methods of arrays in javascript-----------------*/
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

{
//toString() method
arr = arr.toString(); // returns "1,2,3,4,5,6,7,8,9,10"
console.log(arr);
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
} //just like a string now every character is printed

//join() method
let arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr1.join("-")); // returns "1-2-3-4-5-6-7-8-9-10"
for (let i = 0; i < arr1.length; i++) {
  console.log(arr1[i]);
} //This is still a array so every element is printed

//pop() method  
let arr2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr2.pop()); // removes the last element from the array and returns it

//push() method
let arr3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr3.push(11)); // adds a new element to the end of the array and returns the new length

//shift() method
let arr4 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr4.shift()); // removes the first element from the array and returns it

//unshift() method
let arr5 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr5.unshift(0)); // adds a new element to the beginning of the array and returns the new length

//splice() method
let arr6 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr6.splice(2, 0, 11, 12, 13)); // adds new elements to the array and returns the removed elements
console.log(arr6); // returns [1, 2, 11, 12, 13, 3, 4, 5, 6, 7, 8, 9, 10]

//concat() method
let arr7 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let arr8 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
console.log(arr7.concat(arr8)); // returns a new array by joining two arrays

//slice() method
let arr9 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr9.slice(2, 5)); // returns a new array by extracting elements from the array

//sort() method
let arr10 = [10, 5, 8, 3, 6, 7, 2, 9, 4, 1];
console.log(arr10.sort()); // returns the sorted array

//reverse() method
let arr11 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr11.reverse()); // returns the reversed array

//indexOf() method
let arr12 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr12.indexOf(5)); // returns the index of the specified element

//lastIndexOf() method
let arr13 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5];
console.log(arr13.lastIndexOf(5)); // returns the last index of the specified element

//includes() method
let arr14 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(arr14.includes(5)); // returns true if the array contains the specified element, otherwise false

}


//find() method
let arr15 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
function findElement(element) {
  return element > 5;
}

console.log(arr15.find(findElement)); // returns the first element that satisfies the condition

//findIndex() method
let arr16 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
function findIndexElement(element) {
  return element > 5;
}

console.log(arr16.findIndex(findIndexElement)); // returns the index of the first element that satisfies the condition

//filter() method
let arr17 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
function filterElement(element) {
  return element > 5;
}

console.log(arr17.filter(filterElement)); // returns a new array containing the elements that satisfy the condition



                    /*-------------For loops in javascript-----------------*/
{

//For each loop
let arr18 = [-1, -2, -3, -4, -5, -6, -7, -8, -9, -10];
arr18.forEach((element,index,array)=>{
    console.log(element*element);
});

//element function is called for each element of the array

//from() method
let name='saurav';
let arr19=Array.from(name);
console.log(arr19); // returns ["s", "a", "u", "r", "a", "v"]
//Array.from() method returns an array object from any object with a length property or an iterable object


//map method

let b=[1,2,3,4,5,6,7,8,9,10];

let c=b.map((element,index,array)=>{
    console.log(element);
    return 2**element-index;
})

console.log(c);


//filter method
let d=b.filter((element)=>{
    return element>6;
});

console.log(d);

//reduce method

function add(a,b){
    return a+b;
}
console.log(b.reduce(add));
}



