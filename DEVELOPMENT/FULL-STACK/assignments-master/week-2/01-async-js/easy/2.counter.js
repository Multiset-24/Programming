let duration = prompt("Enter a time in seconds");

let counter = 0;

function incrementCounter() {
    if (counter < duration) {
        console.log(counter);
        counter++;
        setTimeout(incrementCounter, 1000);
    }
}

setTimeout(incrementCounter, 1000);