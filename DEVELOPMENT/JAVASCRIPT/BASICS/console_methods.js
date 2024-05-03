//console methods

//console.log() method
console.log("This is a message");//This is a message

//console.error() method
console.error("This is an error message");//This is an error message

//console.warn() method
console.warn("This is a warning message");//This is a warning message

//console.info() method
console.info("This is an info message");//This is an info message


//console.table() method
let students = [
    { name: 'John', age: 20, city: 'New York' },
    { name: 'Doe', age: 25, city: 'London' },
    { name: 'Smith', age: 30, city: 'Paris' }
];
console.table(students);

//console.time() and console.timeEnd() methods
console.time('Time taken to execute the for loop');//start the timer

for (let i = 0; i < 1000000; i++) {
    //do nothing
}

console.timeEnd('Time taken to execute the for loop');//end the timer

//console.group() and console.groupEnd() methods
console.group('Group 1');//start the group

console.log('This is a message inside group 1');
console.log('This is another message inside group 1');

console.groupEnd('Group 1');//end the group
