//date is a object in javascipt  which is calculated in milliseconds from 1 jan 1970

let  date =new Date();

console.log(date);
console.log(date.toString());
console.log(date.toDateString());
console.log(date.toTimeString().slice(0,8));

let timestamp=date.now();
console.log(timestamp);