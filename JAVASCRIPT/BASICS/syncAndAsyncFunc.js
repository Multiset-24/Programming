function find_sum(a, b) {
    return (a + b);
 }
 
 function findsum2(a,b){
   console.log(find_sum(a,b));
 }
 
 setTimeout(() => findsum2(60,9), 1000);//This is an asynchronous function call and it will be executed after 1 second
 
 console.log("This is a message after the setTimeout function");

 //fs.readFile() is an asynchronous function
const fs = require('fs');
fs.readFile('file.txt', 'utf8', function(err, data) {//this function will be executed after the file is read
    if (err) {//if there is an error for eg. file not found
        console.log(err);
    } else {
        console.log(data);
    }
});

console.log("This is a message after the fs.readFile function");//This message will be printed before the file is read