//remember to use the console to check the output of the code since we are using prompt and alert
//to get the user input and display the output


//function to get a random number between 1 and 100
function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}


let randomNumber = getRandomInt(1, 100);


// Path: JAVASCRIPT/BASICS/random_num_game.js
let number = -1;
let chances=0;
while (number != randomNumber) {
    let user_number = prompt(`Enter a number between 1 and ${100}`);
    number = Number(user_number);
    if (number > randomNumber) {
        alert("You are too high");
        chances++;
    } else if(number<randomNumber){
        alert("You are too low");
        chances++;
    }
    else{
    alert(`Wallah ! you won and you took ${chances} chances to win the game and the number was ${randomNumber}`);
    }
    
}