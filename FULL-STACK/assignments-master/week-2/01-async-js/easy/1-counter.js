let counter=prompt("Enter a time in seconds");
let duration=counter;
let interval=setInterval(()=>{
    counter--;
    console.log(counter);
    if(counter==0){
        clearInterval(interval);
    }
},1000);

// what is setInterval in the above code?
// setInterval is a function that calls a function or evaluates an expression at specified intervals (in milliseconds).
// It will continue calling the function until clearInterval() is called or the window is closed.
// It returns an interval ID which uniquely identifies the interval, so we can remove it later by calling clearInterval().
// setInterval(function, milliseconds, param1, param2, ...)
// function: The function that will be executed
// milliseconds: The intervals (in milliseconds) on how often to execute the code
// param1, param2, ...: Additional parameters that will be passed to the function

